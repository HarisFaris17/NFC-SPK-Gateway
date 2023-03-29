from aoa_constants import *
from queue import Queue

from numpy import mean
import numpy as np

from aoa_communication import *
from numpy import std, cos, sin, sqrt, absolute, float64

location_list_each_locator = [[],[],[],[]]

def location_convenient_calculator(new_angle_convenient_queue : Queue, location_waiting_queue : Queue, location_buffer : dict):
        while True:
            new_angle_convenient = new_angle_convenient_queue.get()

            distance = new_angle_convenient["distance"]
            angle_elevation = new_angle_convenient["angle"]
            mac = new_angle_convenient["mac"]
            locator_idx = new_angle_convenient["locator_idx"]
            
            coordinates = np.zeros(3, float64)

            # if the below parameter true, it means it is not possible to derive z coordinate from the data, since it is not possible in this scenario (coordinate system from bluetooh AoA)
            determiner_value = (sin(angle_elevation[1]) - cos(angle_elevation[0])) * (sin(angle_elevation[1]) + cos(angle_elevation[0]))
            if (determiner_value < 0) : continue

            coordinates[0] = distance * cos(angle_elevation[0])
            coordinates[1] = distance * cos(angle_elevation[1])
            coordinates[2] = distance * (sqrt(determiner_value))

            continue_to_process = True
            for distance_in_axis in coordinates :
                # if there is distance in certain axis from the coordinate of that greater than MAX_DISTANCE_PER_AXIS, throw the coordinate
                if absolute(distance_in_axis) > MAX_DISTANCE_PER_AXIS:
                    continue_to_process = False
                    break

            if not continue_to_process:
                body_error = "There is a distance in certain axis from the coordinate {coordinates} that greater than {MAX_DISTANCE_PER_AXIS}".format(coordinates = coordinates, MAX_DISTANCE_PER_AXIS = MAX_DISTANCE_PER_AXIS)
                write_protocol_data(command = CMD_ERROR, body = body_error)
                continue

            body_ok = BODY_CONVENIENT_COORD_PER_LOCATOR.format(data_type = COORD_ELEMENT_TYPE, mac = mac, ar1_idx = locator_idx, coordinates_x = coordinates[0], coordinates_y = coordinates[1], coordinates_z = coordinates[2])
            # print(PROTOCOL_DATA.format(command = CMD_OK, body = body_ok))
            write_protocol_data(command = CMD_OK, body = body_ok)

            write_protocol_data(command = CMD_INFO, body = "One cycle calculated")

            if mac in location_buffer:
                if len(location_buffer[mac][locator_idx]) >= MAX_COORDS_PER_LOCATOR_PER_MAC:
                    location_buffer[mac][locator_idx].pop(0)

            else:
                location_buffer[mac] = location_list_each_locator.copy()

            location_buffer[mac][locator_idx].append(coordinates)
            # only the location_aoa_calculator decide whether the convenient cumulative location of mac could/should 
            location_waiting_queue.put(mac)

            body_info = "Location buffer in Sub Main Thread {location_buffer}".format(location_buffer = location_buffer)
            write_protocol_data(command = CMD_INFO, body = body_info)

def location_cumulative_convenient_calculator(location_waiting_queue : Queue, location_buffer : dict):
    while(True):
        mac = location_waiting_queue.get()
        coordinate_exact_per_locator = []
        coordinate_section_per_locator = []

        body_info = f"Locator buffer convenient {location_buffer}"
        write_protocol_data(command = CMD_INFO, body = body_info)

        for locator_idx, coordinates in enumerate(location_buffer[mac]) :
            num_of_data = len(coordinates)
            if (num_of_data < MIN_COORDS_PER_LOCATOR_PER_MAC) :
                body_info = "The number of data of mac {mac} from locator {locator_idx} is {num_of_data} still less than {MIN_COORDS_PER_LOCATOR_PER_MAC}, wait".format(mac = mac, locator_idx = locator_idx, num_of_data = num_of_data, MIN_COORDS_PER_LOCATOR_PER_MAC = MIN_COORDS_PER_LOCATOR_PER_MAC) 
                write_protocol_data(command = CMD_INFO, body = body_info)
                continue

            body_info = f"The standard deviation of locator index {locator_idx} "
            write_protocol_data(command = CMD_INFO, body = body_info)

            std_all_axis = std(coordinates, axis = 0)

            body_info = f"The standard deviation of locator index {locator_idx} is {std_all_axis}"
            write_protocol_data(command = CMD_INFO, body = body_info)

            is_std_greater_than_section_std = False
            is_std_greater_than_exact_std = False
            for std_per_axis in std_all_axis :
                if (std_per_axis > MAX_STD_SECTION_COORD):
                    is_std_greater_than_section_std = True
                    break
                elif (std_per_axis > MAX_STD_EXACT_COORD):
                    is_std_greater_than_exact_std = True
                    break


            if is_std_greater_than_section_std:
                body_error = "The standard deviation of Locator index {locator_idx} is {std_all_axis}, which means not acceptable".format(locator_idx = locator_idx, std_all_axis = std_all_axis)
                write_protocol_data(command = CMD_ERROR, body = body_error)
                continue

            # there is/are axis/axises in the range of exact std and section std 
            elif is_std_greater_than_exact_std :
                body_info = "The deviation of locator index {locator_idx} is in the range exact std and section std {std_all_axis}".format(locator_idx = locator_idx, std_all_axis = std_all_axis)
                write_protocol_data(command = CMD_INFO, body = body_info)
                coordinate_section_per_locator.append(locator_idx)

            # all data standard deviation of axes is lower than the exact std
            else :
                body_info = "The deviation of Locator index {locator_idx} is {std_all_axis}, which is in exact std scope".format(locator_idx = locator_idx, std_all_axis = std_all_axis)
                write_protocol_data(command = CMD_INFO, body = body_info)

                coordinates_mean = mean(coordinates, axis = 0)
                body_ok = BODY_CONVENIENT_COORD_PER_LOCATOR.format(data_type = COORD_MEAN_TYPE, mac = mac, ar1_idx = locator_idx, coordinates_x = coordinates_mean[0], coordinates_y = coordinates_mean[1], coordinates_z = coordinates_mean[2])
                write_protocol_data(command = CMD_OK, body = body_ok)
                coordinate_exact_per_locator.append(locator_idx)

        if len(coordinate_exact_per_locator) > 0:
            body_info = f"Calculate exact cumulative coordinates of locators {coordinate_exact_per_locator}"
            write_protocol_data(command = CMD_INFO, body = body_info)

            coordinates = []
            for locator_idx  in coordinate_exact_per_locator:
                list_coordinates = location_buffer[mac][locator_idx]
                for coordinate in list_coordinates:
                    coordinates.append([(coordinate[i] + locator_distance_ref[locator_idx][i]) for i in range(3)])
            exact_coordinates = np.mean(coordinates, axis = 0)
            body_ok = BODY_CONVENIENT_COORD_CUMULATIVE.format(mac = mac, coordinates_x = exact_coordinates[0], coordinates_y = exact_coordinates[1], coordinates_z = exact_coordinates[2])
            write_protocol_data(command = CMD_OK, body = body_ok)


        elif len(coordinate_section_per_locator) > 0:
            # evaluate per axis
            body_info = "Calculate section cumulative coordinates of locators {coordinate_section_per_locator}".format(coordinate_section_per_locator = coordinate_section_per_locator)
            write_protocol_data(command = CMD_INFO, body = body_info)

            coord_mean_per_locator = [[0, 0, 0] for i in range(len(coordinate_section_per_locator))]
            std_per_locator = [[0, 0, 0] for i in range(len(coordinate_section_per_locator))]
            for i, locator_idx in enumerate(coordinate_section_per_locator):
                coordinates = location_buffer[mac][locator_idx]
                quartile3 = np.quantile(coordinates, q = 0.75, axis = 0)
                quartile1 = np.quantile(coordinates, q = 0.25, axis = 0)

                iqr = [quartile3[axis] - quartile1[axis] for axis in range(3)]
                # coordinates_mean = mean(coordinates, axis = 0)

                high_threshold = [quartile3[axis] + 0.5 * iqr[axis] for axis in range(3)]
                low_threshold = [quartile1[axis] - 0.5 * iqr[axis] for axis in range(3)]

                body_info = "Statistics tool performed on locator {locator_idx} with coordinates {coordinates} : Q3 = {quartile3}, Q1 = {quartile1}, IQR = {iqr}, Upper Threshold = {high_threshold}, Lower Threshold = {low_threshold}".format(locator_idx = locator_idx, coordinates = coordinates, quartile3 = quartile3, quartile1 = quartile1, iqr = iqr, high_threshold = high_threshold, low_threshold = low_threshold)
                write_protocol_data(command = CMD_INFO, body = body_info)

                axis_info = "Axis info : "
                write_protocol_data(command = CMD_INFO, body = axis_info)
                for axis in range(3): 
                    filtered_axis = [] 
                    for coordinate in coordinates:
                        if coordinate[axis] <= high_threshold[axis] and coordinate[axis] >= low_threshold[axis]:
                            filtered_axis.append(coordinate[axis])

                    body_info = "Axis {axis} Filtered info : {filtered_axis}".format(axis = axis, filtered_axis = filtered_axis)
                    write_protocol_data(command = CMD_INFO, body = body_info)

                    mean_filtered_axis = mean(filtered_axis)
                    body_info = "Axis {axis} mean_filtered_axis : {mean_filtered_axis}, coord_mean_per_locator : {coord_mean_per_locator}, coord_mean_per_locator[i][axis] : {haha}".format(axis = axis, mean_filtered_axis = mean_filtered_axis, coord_mean_per_locator = coord_mean_per_locator, haha = coord_mean_per_locator[i][axis])
                    write_protocol_data(command = CMD_INFO, body = body_info)

                    coord_mean_per_locator[i][axis] = mean_filtered_axis

                    body_info = "Axis {axis} coord_mean_per_locator : {coord_mean_per_locator}".format(axis = axis, coord_mean_per_locator = coord_mean_per_locator)
                    write_protocol_data(command = CMD_INFO, body = body_info)


                    # for awhile the std will not be used 
                    std_filtered_axis = std(filtered_axis)
                    body_info = "Axis {axis} std_per_locator : {std_per_locator}".format(axis = axis, std_per_locator = std_per_locator)
                    write_protocol_data(command = CMD_INFO, body = body_info)

                    std_per_locator[i][axis] = std_filtered_axis

                    body_info = "Axis {axis} std_per_locator : {std_per_locator}".format(axis = axis, std_per_locator = std_per_locator)
                    write_protocol_data(command = CMD_INFO, body = body_info)

                    axis_info += "axis {axis}, filtered axis {filtered_axis}, mean of filtered axis {mean_filtered_axis}, standard deviation of filtered axis {std_filtered_axis}\n".format(axis = axis, filtered_axis = filtered_axis, mean_filtered_axis = mean_filtered_axis, std_filtered_axis = std_filtered_axis)
                body_info  = "Locator index : {locator_idx}\n {axis_info}".format(locator_idx = locator_idx, axis_info = axis_info)
                write_protocol_data(command = CMD_INFO, body = body_info)
            
            location_mean = []
            for i, coord_mean in enumerate(coord_mean_per_locator):
                location_mean.append([coord_mean[j] + locator_distance_ref[coordinate_section_per_locator[i]][j] for j in range(3)])
            location_cumulative_mean = mean(location_mean, axis = 0)
            body_ok = BODY_CONVENIENT_COORD_CUMULATIVE.format(mac = mac, coordinates_x = location_cumulative_mean[0], coordinates_y = location_cumulative_mean[1], coordinates_z = location_cumulative_mean[2])
            write_protocol_data(command = CMD_OK, body = body_ok)
