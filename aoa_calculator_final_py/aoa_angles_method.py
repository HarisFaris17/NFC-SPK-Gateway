from queue import Queue

import numpy as np

from aoa_constants import *
from aoa_communication import *
from aoa_outlier_filter import *
from aoa_kalman import *
from aoa_common import *
from aoa_phase_calculator import *

from numpy import std, cos, sin, sqrt, absolute, mean, pi, float64

from itertools import combinations

def location_aoa_calculator(new_angles_from_waiting_per_batch_queue : Queue, angles_aoa_waiting_queue : Queue, location_waiting_queue : Queue, new_angles_to_calculated_per_locator_queue : Queue, angle_buffer : dict, batch_count : dict, single_locator_catched_count : dict, location_buffer_aoa : dict):
    while True:
        new_angles_from = new_angles_from_waiting_per_batch_queue.get()

        write_protocol_data(CMD_INFO, f"New angles from current batch are coming from {new_angles_from}")

 
        
        for mac in new_angles_from.keys():
            continue_to_process = True
            angles_per_mac = angle_buffer[mac]

            # the mac only has angles catched by one locator, but AoA implementation requires using two or more locators
            if (len(angles_per_mac.keys()) == 1) : 
                write_protocol_data(CMD_INFO, f"There is only one locator caching angles data of mac {mac} : {angles_per_mac}")
                if not CALCULATE_COORDINATES_WITH_AOA_ONLY:
                    if mac not in single_locator_catched_count:
                        single_locator_catched_count[mac] = 0
                    single_locator_catched_count[mac] += 1

                    if single_locator_catched_count[mac] >= MIN_BATCH_COUNT_SINGLE_LOCATOR_CONVENIENT : location_waiting_queue.put(mac)
                
                continue_to_process = False
            
            else : 
                if not CALCULATE_COORDINATES_WITH_AOA_ONLY: single_locator_catched_count[mac] = 0

            new_angles_to_calculated_per_locator_queue.put(mac)
            # the mac only catched by single locator
            if not continue_to_process:
                continue
            
            
            from itertools import combinations
            # in this method, we not yet implement xyz calculator when coordinates in y axis of a locator is different than the others
            # location = {}
            # angles_mean_per_mac = {locator_idx : np.mean(angles, axis = 0) for (locator_idx, angles) in angles_per_mac.items()}
            angles_mean_per_mac = {locator_idx : angles[-1] for (locator_idx, angles) in angles_per_mac.items()}
            for ((locator_idx1, angles1), (locator_idx2, angles2)) in combinations(angles_mean_per_mac.items(), 2):
                write_protocol_data(CMD_INFO, f"Angles mean in location_aoa_calculator {angles_mean_per_mac}")
                determiner_value_pair1 = (sin(angles1[0]) - cos(angles1[1])) * (sin(angles1[0]) + cos(angles1[1]))
                determiner_value_pair2 = (sin(angles2[0]) - cos(angles2[1])) * (sin(angles2[0]) + cos(angles2[1]))
                if determiner_value_pair1 < 0 or determiner_value_pair2 < 0:
                    write_protocol_data(CMD_ERROR, f"The value of determiners {determiner_value_pair1} and/or {determiner_value_pair2} less than 0 ")
                    continue

                distance_in_x_between_locators = abs(locator_distance_ref[locator_idx2][0] - locator_distance_ref[locator_idx1][0])
                if abs(angles2[0] - angles1[0]) < np.deg2rad(1) and abs(angles2[1] - angles1[1]) < np.deg2rad(1):
                    write_protocol_data(CMD_ERROR, f"The difference of angle between the two {abs(angles2[0] - angles1[0])} a")
                    continue

                hypotenuse1 = abs(distance_in_x_between_locators * sin(pi - angles2[0]) / sin(angles2[0] - angles1[0]))
                hypotenuse2 = abs(hypotenuse1 * sin(angles1[0]) / sin(angles2[0]))
                # hypotenuse2 = distance_in_x_between_locators * sin(pi - angles2[0]) / sin(angles2[0] - angles1[0])
                x_1 = hypotenuse1 * cos(angles1[0]) #+ locator_distance_ref[locator_idx1][0]
                y_1 = hypotenuse1 * cos(angles1[1]) #+ locator_distance_ref[locator_idx1][1]
                z_1 = hypotenuse1 * sqrt(determiner_value_pair1) #+ locator_distance_ref[locator_idx1][2]

                x_2 = hypotenuse2 * cos(angles2[0]) #+ locator_distance_ref[locator_idx2][0]
                y_2 = hypotenuse2 * cos(angles2[1]) #+ locator_distance_ref[locator_idx2][1]
                z_2 = hypotenuse2 * sqrt(determiner_value_pair2) #+ locator_distance_ref[locator_idx2][2]

                write_protocol_data(CMD_INFO, f"nnnnnnnnnnnnnnnnnnnnnnnnnnnnnn {distance_in_x_between_locators} {locator_idx1} {hypotenuse1} {locator_idx2} {hypotenuse2}")

                hyp2 = distance_in_x_between_locators * cos(angles1[1]) / (cos(angles2[1]) * cos(angles1[0]) - cos(angles2[0]) * cos(angles1[1]))
                write_protocol_data(CMD_INFO, f"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmm {distance_in_x_between_locators}  {cos(angles1[1])} {cos(angles2[1])} {cos(angles1[0])} {cos(angles2[0])} {hyp2}")
                x = np.mean([x_1, x_2])
                y = np.mean([y_1, y_2])
                z = np.mean([z_1, z_2])

                write_protocol_data(CMD_INFO, f"oooooooooooooooooooooooooooooooooooooooooooo {x_1} {y_1} {z_1} {x_2} {y_2} {z} {x} {y} {z}")

                body_ok = BODY_AOA_COORD_TWO_LOCATORS_ELEMENT_TYPE.format(mac = mac, locator_1 = locator_idx1, locator_2 = locator_idx2, x_1 = x_1, y_1 = y_1, z_1 = z_1, x_2 = x_2, y_2 = y_2, z_2 = z_2)
                write_protocol_data(CMD_OK, body_ok)
                write_protocol_data(CMD_INFO, "ppppppppppppppppppppppppppppppppppppppppp")
                coordinates = [[x_1, y_1, z_1], [x_2, y_2, z_2]]
                # coordinates = [[1, 1, 1]]
                write_protocol_data(CMD_INFO, "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii")

                if mac not in location_buffer_aoa:
                    location_buffer_aoa[mac] = np.array(coordinates, dtype = float64)
                else : np.append(location_buffer_aoa[mac], coordinates, axis = 0)

                write_protocol_data(CMD_INFO, f"The x,y,z of mac {mac} from locators {locator_idx1} and {locator_idx2} to reference are {coordinates}")

            write_protocol_data(CMD_INFO, f"The location {location_buffer_aoa}")
            angles_aoa_waiting_queue.put(mac)
       


# def location_cumulative_aoa_calculator2(angles_aoa_waiting_queue : Queue, angle_buffer : dict):
#     while(True):
#         mac = angles_aoa_waiting_queue.get()

#         body_info = f"-- AOA -- Locator buffer aoa {angle_buffer}"
#         write_protocol_data(command = CMD_INFO, body = body_info)

#         filtered_mean_angles_all_locator = dict()
#         for locator_idx, angles_per_locator in angle_buffer[mac].items():
#             # filtered_mean_angles = []
#             num_of_angles = len(angles_per_locator)

#             if (num_of_angles >= MIN_AOA_ANGLES_FILTER_OUTLIERS) :
#                 body_info = f"-- AOA -- The number of angles of mac {mac} from locator {locator_idx} is {num_of_angles} in which the angles is permissable to be filtered using std"
#                 # write_protocol_data(command = CMD_INFO, body = body_info)

#                 # quartile3 = np.quantile(angles_per_locator, q = 0.75, axis = 0)
#                 # quartile1 = np.quantile(angles_per_locator, q = 0.25, axis = 0)

#                 # iqr = [quartile3[angle] - quartile1[angle] for angle in range(2)]
#                 # # coordinates_mean = mean(coordinates, axis = 0)

#                 # high_threshold = [quartile3[angle] + 0.5 * iqr[angle] for angle in range(2)]
#                 # low_threshold = [quartile1[angle] - 0.5 * iqr[angle] for angle in range(2)]

#                 # body_info = f"-- AOA -- Statistics tool performed on mac {mac} of locator {locator_idx} with angles {angles_per_locator} : Q3 = {quartile3}, Q1 = {quartile1}, IQR = {iqr}, Upper Threshold = {high_threshold}, Lower Threshold = {low_threshold}"
#                 # write_protocol_data(command = CMD_INFO, body = body_info)

#                 # angles_info = f"-- AOA -- Angles info : "
#                 # write_protocol_data(command = CMD_INFO, body = angles_info)
#                 # for angle in range(2): 
#                 #     filtered_angle = [] 
#                 #     for angles in angles_per_locator:
#                 #         if angles[angle] <= high_threshold[angle] and angles[angle] >= low_threshold[angle]:
#                 #             filtered_angle.append(angles[angle])

#                 #     mean_filtered_angle = mean(filtered_angle)
#                 #     filtered_mean_angles.append(mean_filtered_angle)
#                 #     # for awhile the std will not be used 
#                 #     std_filtered_angle = std(filtered_angle)

#                 #     body_info = f"Angle {'X' if angle == 0 else 'Y'} Filtered angle : {filtered_angle}, Mean filtered angle {filtered_mean_angles}, Angle mean : {mean_filtered_angle}, Std filtered angle : {std_filtered_angle}"
#                 #     write_protocol_data(command = CMD_INFO, body = body_info)

#                 #     angles_info += f"angle {'X' if angle == 0 else 'Y'}, Filtered angle : {filtered_angle}, Angle mean : {mean_filtered_angle}, Std filtered angle : {std_filtered_angle}\n"
#                 # body_info  = f"-- AOA -- : mac {mac} locator {locator_idx}\n {angles_info}"
#                 bounded_angles = angles_bound_filter(np.asarray(angles_per_locator), ANGLE_UPPER_BOUND, ANGLE_LOWER_BOUND)
#                 filtered_angles_x = get_rid_outlier_1d_array(np.asarray(bounded_angles[0]), Q3, Q1, C1, C2)
#                 filtered_angles_y = get_rid_outlier_1d_array(np.asarray(bounded_angles[1]), Q3, Q1, C1, C2)

#                 filtered_angles = []
#                 filtered_angles.append(filtered_angles_x)
#                 filtered_angles.append(filtered_angles_y)

#                 filtered_mean_angles = [np.mean(angle) for angle in filtered_angles]

#                 body_info = f"Filtered angels of mac {mac} and locator {locator_idx} is {filtered_angles} and unfiltered angles are {angles_per_locator}"
#                 write_protocol_data(command = CMD_INFO, body = body_info)

#             else :
#                 filtered_mean_angles = np.mean(angles_per_locator, axis = 0)

#             filtered_mean_angles_all_locator[locator_idx] = filtered_mean_angles
        
#         write_protocol_data(CMD_INFO, f"Filtered mean angles all locator {filtered_mean_angles_all_locator}")
#         calculated_coordinates = []
#         for ((locator_idx1, angles1), (locator_idx2, angles2)) in combinations(filtered_mean_angles_all_locator.items(), 2):
                
#                 (determiner_value_pair1, determiner_value_pair2) = eval_determiner_two_angles_xy_invalid(angles1, angles2)
#                 # determiner_value_pair1 = (sin(angles1[0]) - cos(angles1[1])) * (sin(angles1[0]) + cos(angles1[1]))
#                 # determiner_value_pair2 = (sin(angles2[0]) - cos(angles2[1])) * (sin(angles2[0]) + cos(angles2[1]))
#                 if determiner_value_pair1 < 0 or determiner_value_pair2 < 0:
#                     write_protocol_data(CMD_ERROR, f"The value of determiners {determiner_value_pair1} and/or {determiner_value_pair2} less than 0 ")
#                     continue

#                 # h = locator_distance_ref[locator_idx2][0] - locator_distance_ref[locator_idx1][0]
#                 # k = locator_distance_ref[locator_idx2][1] - locator_distance_ref[locator_idx1][1]
#                 # t = locator_distance_ref[locator_idx2][2] - locator_distance_ref[locator_idx1][2]

#                 # this is indicating the locator_idx1, locator_idx1 and beacon is on the same imaginary line, hence it is not possible to determine the beacon's exact location
#                 if abs(angles2[0] - angles1[0]) < 0.1 and abs(angles2[1] - angles1[1]) < 0.1:
#                     write_protocol_data(CMD_ERROR, f"The difference of angle in X and Y between of beacon detected on two locators are {abs(angles2[0] - angles1[0])} and {abs(angles2[1] - angles1[1])}, respectively")
#                     continue

#                 # hypotenuse1 = abs(h * sin(pi - angles2[0]) / sin(angles2[0] - angles1[0]))
#                 # hypotenuse2 = abs(hypotenuse1 * sin(angles1[0]) / sin(angles2[0]))
#                 # hypotenuse2 = abs((k * cos(angles1[0]) - h * cos(angles1[1])) / (cos(angles2[0]) * cos(angles1[1]) - cos(angles2[1]) * cos(angles1[0])))
#                 # hypotenuse2 = distance_in_x_between_locators * sin(pi - angles2[0]) / sin(angles2[0] - angles1[0])
#                 # x_1 = hypotenuse1 * cos(angles1[0]) #+ locator_distance_ref[locator_idx1][0]
#                 # y_1 = hypotenuse1 * cos(angles2[1]) #+ locator_distance_ref[locator_idx1][1]
#                 # z_1 = hypotenuse1 * sqrt(determiner_value_pair1) #+ locator_distance_ref[locator_idx1][2]

#                 # x_2 = hypotenuse2 * cos(angles2[0]) #+ locator_distance_ref[locator_idx2][0]
#                 # y_2 = hypotenuse2 * cos(angles2[1]) #+ locator_distance_ref[locator_idx2][1]
#                 # z_2 = hypotenuse2 * sqrt(determiner_value_pair2) #+ locator_distance_ref[locator_idx2][2]

#                 # x_2 = hypotenuse2 * cos(angles2[0])
#                 # y_2 = hypotenuse2 * cos(angles2[1])
#                 # z_2 = hypotenuse2 * sqrt(determiner_value_pair2)
            
#                 # x_1 = x_2 + h
#                 # y_1 = y_2 + k
#                 # z_1 = z_2 + t

#                 # x = x_1 + locator_distance_ref[locator_idx1][0]
#                 # y = y_1 + locator_distance_ref[locator_idx1][1]
#                 # z = z_1 + locator_distance_ref[locator_idx1][2]

#                 (hypotenuse2, h, k, t, x_2, y_2, z_2, x_1, y_1, z_1, x, y, z) = eval_coordinates_two_angles(angles1, locator_idx1, angles2, locator_idx2)

#                 if not check_if_coord_make_sense(locator_idx1, locator_idx2, x_1, x_2, y_1, y_2) : continue

#                 write_protocol_data(CMD_INFO, f"nnnnnnnnnnnnnnnnnnnnnnnnnnnnnn, [h, k, t] : {[h, k, t]}, locator_idx1 : {locator_idx1}, locator_idx2 : {locator_idx2}, hypotenuse2 : {hypotenuse2}, [x_2, y_2, z_2] : {[x_2, y_2, z_2]}, [x_1, y_1, z_1] : {[x_1, y_1, z_1]}")

#                 calculated_coordinates.append([x, y, z])

#                 write_protocol_data(CMD_INFO, f"calculated coordinates from locator_idx1 : {locator_idx1} and locator_idx2 : {locator_idx2} is {calculated_coordinates}")

#         if len(calculated_coordinates) == 0:
#             body_info = f"There is no cumulatively calculated"
#             write_protocol_data(CMD_INFO, body_info)
#             continue
#         mean_coordinates = np.mean(calculated_coordinates, axis = 0)
#         write_protocol_data(CMD_INFO, f"Mean coordinates of mac {mac} : {mean_coordinates}")
        

#         body_ok = BODY_AOA_COORD_CUMULATIVE.format(mac = mac, x = mean_coordinates[0], y = mean_coordinates[1], z = mean_coordinates[2])
#         write_protocol_data(CMD_OK, body_ok)

def location_cumulative_aoa_calculator2(angles_aoa_waiting_queue : Queue, angle_buffer : dict):
    while(True):
        mac = angles_aoa_waiting_queue.get()

        body_info = f"-- AOA -- Locator buffer aoa {angle_buffer}"
        write_protocol_data(command = CMD_INFO, body = body_info)

        filtered_mean_angles_all_locator = dict()
        for locator_idx, angles_per_locator in angle_buffer[mac].items():
            # filtered_mean_angles = []
            num_of_angles = len(angles_per_locator)

            if (num_of_angles >= MIN_AOA_ANGLES_FILTER_OUTLIERS) :
                body_info = f"-- AOA -- The number of angles of mac {mac} from locator {locator_idx} is {num_of_angles} in which the angles is permissable to be filtered using std"
                # write_protocol_data(command = CMD_INFO, body = body_info)

                # quartile3 = np.quantile(angles_per_locator, q = 0.75, axis = 0)
                # quartile1 = np.quantile(angles_per_locator, q = 0.25, axis = 0)

                # iqr = [quartile3[angle] - quartile1[angle] for angle in range(2)]
                # # coordinates_mean = mean(coordinates, axis = 0)

                # high_threshold = [quartile3[angle] + 0.5 * iqr[angle] for angle in range(2)]
                # low_threshold = [quartile1[angle] - 0.5 * iqr[angle] for angle in range(2)]

                # body_info = f"-- AOA -- Statistics tool performed on mac {mac} of locator {locator_idx} with angles {angles_per_locator} : Q3 = {quartile3}, Q1 = {quartile1}, IQR = {iqr}, Upper Threshold = {high_threshold}, Lower Threshold = {low_threshold}"
                # write_protocol_data(command = CMD_INFO, body = body_info)

                # angles_info = f"-- AOA -- Angles info : "
                # write_protocol_data(command = CMD_INFO, body = angles_info)
                # for angle in range(2): 
                #     filtered_angle = [] 
                #     for angles in angles_per_locator:
                #         if angles[angle] <= high_threshold[angle] and angles[angle] >= low_threshold[angle]:
                #             filtered_angle.append(angles[angle])

                #     mean_filtered_angle = mean(filtered_angle)
                #     filtered_mean_angles.append(mean_filtered_angle)
                #     # for awhile the std will not be used 
                #     std_filtered_angle = std(filtered_angle)

                #     body_info = f"Angle {'X' if angle == 0 else 'Y'} Filtered angle : {filtered_angle}, Mean filtered angle {filtered_mean_angles}, Angle mean : {mean_filtered_angle}, Std filtered angle : {std_filtered_angle}"
                #     write_protocol_data(command = CMD_INFO, body = body_info)

                #     angles_info += f"angle {'X' if angle == 0 else 'Y'}, Filtered angle : {filtered_angle}, Angle mean : {mean_filtered_angle}, Std filtered angle : {std_filtered_angle}\n"
                # body_info  = f"-- AOA -- : mac {mac} locator {locator_idx}\n {angles_info}"
                # bounded_angles = angles_bound_filter(np.asarray(angles_per_locator), ANGLE_UPPER_BOUND, ANGLE_LOWER_BOUND)

                write_protocol_data(CMD_INFO, f"Current angles, locator {locator_idx} {mac} {angles_per_locator}")
                bounded_angles = angles_bound_filter(np.asarray(angles_per_locator), ANGLE_UPPER_BOUND, ANGLE_LOWER_BOUND)
                if len(bounded_angles) != 2 or len(bounded_angles[0]) == 0 or len(bounded_angles[1]) == 0: 
                    write_protocol_data(CMD_ERROR, "Only one or zero variable exist in bounded_angles")
                    continue

                filtered_angles_x = get_rid_outlier_1d_array(np.asarray(bounded_angles[0]), Q3, Q1, C1, C2, 1, 1)
                filtered_angles_y = get_rid_outlier_1d_array(np.asarray(bounded_angles[1]), Q3, Q1, C1, C2, 1, 1)

                filtered_angles = []
                filtered_angles.append(filtered_angles_x)
                filtered_angles.append(filtered_angles_y)

                filtered_mean_angles = [np.mean(angle) for angle in filtered_angles]

                body_info = f"Filtered angels of mac {mac} and locator {locator_idx} is {filtered_angles} and unfiltered angles are {angles_per_locator}"
                write_protocol_data(command = CMD_INFO, body = body_info)

            else :
                filtered_mean_angles = np.mean(angles_per_locator, axis = 0)

            filtered_mean_angles_all_locator[locator_idx] = filtered_mean_angles
        
        write_protocol_data(CMD_INFO, f"Filtered mean angles all locator {filtered_mean_angles_all_locator}")
        calculated_coordinates = []
        for ((locator_idx1, angles1), (locator_idx2, angles2)) in combinations(filtered_mean_angles_all_locator.items(), 2):
                
                (determiner_value_pair1, determiner_value_pair2) = eval_determiner_two_angles_xy_invalid(angles1, angles2)
                # determiner_value_pair1 = (sin(angles1[0]) - cos(angles1[1])) * (sin(angles1[0]) + cos(angles1[1]))
                # determiner_value_pair2 = (sin(angles2[0]) - cos(angles2[1])) * (sin(angles2[0]) + cos(angles2[1]))
                if determiner_value_pair1 < 0 or determiner_value_pair2 < 0:
                    write_protocol_data(CMD_ERROR, f"The value of determiners {determiner_value_pair1} and/or {determiner_value_pair2} less than 0 ")
                    continue

                # h = locator_distance_ref[locator_idx2][0] - locator_distance_ref[locator_idx1][0]
                # k = locator_distance_ref[locator_idx2][1] - locator_distance_ref[locator_idx1][1]
                # t = locator_distance_ref[locator_idx2][2] - locator_distance_ref[locator_idx1][2]

                # this is indicating the locator_idx1, locator_idx1 and beacon is on the same imaginary line, hence it is not possible to determine the beacon's exact location
                if abs(angles2[0] - angles1[0]) < 0.1 and abs(angles2[1] - angles1[1]) < 0.1:
                    write_protocol_data(CMD_ERROR, f"The difference of angle in X and Y between of beacon detected on two locators are {abs(angles2[0] - angles1[0])} and {abs(angles2[1] - angles1[1])}, respectively")
                    continue

                # hypotenuse1 = abs(h * sin(pi - angles2[0]) / sin(angles2[0] - angles1[0]))
                # hypotenuse2 = abs(hypotenuse1 * sin(angles1[0]) / sin(angles2[0]))
                # hypotenuse2 = abs((k * cos(angles1[0]) - h * cos(angles1[1])) / (cos(angles2[0]) * cos(angles1[1]) - cos(angles2[1]) * cos(angles1[0])))
                # hypotenuse2 = distance_in_x_between_locators * sin(pi - angles2[0]) / sin(angles2[0] - angles1[0])
                # x_1 = hypotenuse1 * cos(angles1[0]) #+ locator_distance_ref[locator_idx1][0]
                # y_1 = hypotenuse1 * cos(angles2[1]) #+ locator_distance_ref[locator_idx1][1]
                # z_1 = hypotenuse1 * sqrt(determiner_value_pair1) #+ locator_distance_ref[locator_idx1][2]

                # x_2 = hypotenuse2 * cos(angles2[0]) #+ locator_distance_ref[locator_idx2][0]
                # y_2 = hypotenuse2 * cos(angles2[1]) #+ locator_distance_ref[locator_idx2][1]
                # z_2 = hypotenuse2 * sqrt(determiner_value_pair2) #+ locator_distance_ref[locator_idx2][2]

                # x_2 = hypotenuse2 * cos(angles2[0])
                # y_2 = hypotenuse2 * cos(angles2[1])
                # z_2 = hypotenuse2 * sqrt(determiner_value_pair2)
            
                # x_1 = x_2 + h
                # y_1 = y_2 + k
                # z_1 = z_2 + t

                # x = x_1 + locator_distance_ref[locator_idx1][0]
                # y = y_1 + locator_distance_ref[locator_idx1][1]
                # z = z_1 + locator_distance_ref[locator_idx1][2]

                (hypotenuse2, h, k, t, x_2, y_2, z_2, x_1, y_1, z_1, x, y, z) = eval_coordinates_two_angles(angles1, locator_idx1, angles2, locator_idx2)

                if not check_if_coord_make_sense(locator_idx1, locator_idx2, x_1, x_2, y_1, y_2) : continue

                write_protocol_data(CMD_INFO, f"nnnnnnnnnnnnnnnnnnnnnnnnnnnnnn, [h, k, t] : {[h, k, t]}, locator_idx1 : {locator_idx1}, locator_idx2 : {locator_idx2}, hypotenuse2 : {hypotenuse2}, [x_2, y_2, z_2] : {[x_2, y_2, z_2]}, [x_1, y_1, z_1] : {[x_1, y_1, z_1]}")

                calculated_coordinates.append([x, y, z])

                write_protocol_data(CMD_INFO, f"calculated coordinates from locator_idx1 : {locator_idx1} and locator_idx2 : {locator_idx2} is {calculated_coordinates}")

        if len(calculated_coordinates) == 0:
            body_info = f"There is no cumulatively calculated"
            write_protocol_data(CMD_INFO, body_info)
            continue
        mean_coordinates = np.mean(calculated_coordinates, axis = 0)
        write_protocol_data(CMD_INFO, f"Mean coordinates of mac {mac} : {mean_coordinates}")
        

        # body_ok = BODY_AOA_COORD_CUMULATIVE.format(mac = mac, x = mean_coordinates[0], y = mean_coordinates[1], z = mean_coordinates[2])
        # write_protocol_data(CMD_OK, body_ok)


def location_aoa_calculator_single_locator(new_angles_to_calculated_per_locator_queue : Queue, angle_buffer : dict) :
    while True:
        mac = new_angles_to_calculated_per_locator_queue.get()
        for locator_idx,angles in angle_buffer[mac].items() :
            # if mac not in angle_buffer :
            #     write_protocol_data(CMD_ERROR, f"mac {mac} is not in angle_buffer {angle_buffer}")
            #     continue
            # if len(angle_buffer[mac].keys()) < 1:
            #     write_protocol_data(CMD_ERROR, f"There is more or less than one key in {angle_buffer[mac]}")
            #     continue
            # locator_idx = angle_buffer[mac].keys()[0]
            # angles = angle_buffer[mac].values()[0]
            write_protocol_data(CMD_INFO, f"Current angles, locator {locator_idx} {mac} {angles}")
            bounded_angles = angles_bound_filter(np.asarray(angles), ANGLE_UPPER_BOUND, ANGLE_LOWER_BOUND)
            if len(bounded_angles) != 2 or len(bounded_angles[0]) == 0 or len(bounded_angles[1]) == 0: 
                write_protocol_data(CMD_ERROR, "Only one or zero variable exist in bounded_angles")
                continue

            write_protocol_data(CMD_INFO, f"Current angles, locator {locator_idx} {mac} {bounded_angles}")
            filtered_angles_x = get_rid_outlier_1d_array(np.asarray(bounded_angles[0]), Q3, Q1, C1, C2, 1, 1)
            filtered_angles_y = get_rid_outlier_1d_array(np.asarray(bounded_angles[1]), Q3, Q1, C1, C2, 1, 1)
            # filtered_angles = get_rid_outlier(np.asarray(angles), 0.63, 0.25, 0, 0.5, 1, 1)

            filtered_angles = []
            filtered_angles.append(filtered_angles_x)
            filtered_angles.append(filtered_angles_y)

            angle_mean = [mean(angle) for angle in filtered_angles]

            write_protocol_data(CMD_INFO, f"Catched AoA angles by single locator, locator : {locator_idx}, angles {angles}, bounded angles {bounded_angles}, filtered angles {filtered_angles}, mean of angles {angle_mean} ")

            # determiner_value = (sin(angle_mean[1]) - cos(angle_mean[0])) * (sin(angle_mean[1]) + cos(angle_mean[0]))
            determiner_value = eval_determiner_angles_xy_invalid(angle_mean)
            if determiner_value < 0 : continue

            z = locator_distance_ref[locator_idx][2]

            hypotenuse = z / sqrt(determiner_value)

            x = hypotenuse * cos(angle_mean[0])
            y = hypotenuse * cos(angle_mean[1])

            # body_ok = BODY_AOA_COORD_SINGLE_LOCATOR_ELEMENT_TYPE.format(mac = mac, locator = locator_idx, x = x, y = y, z = z)
            # write_protocol_data(CMD_OK, body_ok)


import os  
def location_aoa_calculator_cumul_phase_diff_single_locator_music(new_angles_to_calculated_cumul_phase_diff_per_locator_queue : Queue, diff_phase_buffer : dict, mag_buffer : dict) :
    file_cumul_diff_phase = open(os.path.dirname(__file__) + MUSIC_CUMUL_DIFF_PHASE_FILE, mode = "a")
    file_cumul_2_diff_phase = open(os.path.dirname(__file__) + MUSIC_2_CUMUL_DIFF_PHASE_FILE, mode = "a")

    while True:
        # (mac, locator_idx_set) = new_angles_to_calculated_cumul_phase_diff_per_locator_queue.get()
        new_angles_from = new_angles_to_calculated_cumul_phase_diff_per_locator_queue.get()
        write_protocol_data(CMD_INFO, f"Location cumul phase {new_angles_from}")

        for (mac, locator_idx_set) in new_angles_from.items():
            write_protocol_data(CMD_INFO, f"AoA calculator phase diff cumulative of mac {mac} from locators {locator_idx_set}")
            for locator_idx in locator_idx_set:
                diff_phase = diff_phase_buffer[mac][locator_idx]
                mag_array = mag_buffer[mac][locator_idx]
                num_iq_sets_per_axis_per_array = diff_phase.shape[2]
                received_data = np.zeros((SIZE_OF_ANT_ARRAY, num_iq_sets_per_axis_per_array), dtype = complex)
                received_data_2 = np.zeros((SIZE_OF_ANT_ARRAY, num_iq_sets_per_axis_per_array), dtype = complex)
                calculated_angle = []
                calculated_angle_with_mag = []
                continue_to_process = True
                for axis in range(NUM_OF_AXIS):
                    diff_phase_per_axis = diff_phase[axis]
                    mag_per_axis = mag_array[axis]
                    # representing phase difference to antenna reference, which means has a phaes difference 0 to reference
                    for ant in range(SIZE_OF_ANT_ARRAY):
                        try :
                            received_data[ant, :] = [np.exp(1j * diff_phase_element) for diff_phase_element in diff_phase_per_axis[ant]]
                            received_data_2[ant, :] = [mag_element * np.exp(1j * diff_phase_element) for mag_element, diff_phase_element in zip(mag_per_axis[ant], diff_phase_per_axis[ant])]
                        except:
                            continue_to_process = False
                            break
                    
                    if not continue_to_process : break
                    # if MUSIC_WITH_SPATIAL_SMOOTHING:
                    # calculated_angle = calculate_angle_music_spatial_smoothing(received_data, wave_length)
                    calculated_angle_music_per_axis = calculate_angle_music_spatial_smoothing(received_data, 0.12, axis)
                    calculated_angle_music_with_mag_per_axis = calculate_angle_music_spatial_smoothing(received_data_2, 0.12, axis)
                    # calculated_angle_music_per_axis = calculate_angle_music(received_data, 0.12)
                    # calculated_angle_music_with_mag_per_axis = calculate_angle_music(received_data_2, 0.12)

                    if calculated_angle_music_per_axis >= np.pi - 0.1 or calculated_angle_music_per_axis <= 0.1:
                        continue_to_process = False
                        break

                    if APPLY_ANGLE_TWEAK :
                        # calculated_angle_music_per_axis += (-1) * (calculated_angle_music_per_axis - np.pi / 2) / 5
                        # calculated_angle_music_per_axis += (-1) * ((calculated_angle_music_per_axis - np.pi / 2))**2 / 6 * ((calculated_angle_music_per_axis - np.pi / 2) / np.abs(calculated_angle_music_per_axis - np.pi / 2))
                        calculated_angle_music_per_axis = tweak_angle(calculated_angle_music_per_axis)

                        # calculated_angle_music_with_mag_per_axis += (-1) * ((calculated_angle_music_with_mag_per_axis - np.pi / 2))**2 / 6 * ((calculated_angle_music_with_mag_per_axis - np.pi / 2) / np.abs(calculated_angle_music_with_mag_per_axis - np.pi / 2))
                        calculated_angle_music_with_mag_per_axis = tweak_angle(calculated_angle_music_with_mag_per_axis)

                    write_protocol_data(CMD_INFO, f"calculated_angle_music_per_axis {calculated_angle_music_per_axis}")
                    if calculated_angle_music_per_axis > ANGLE_UPPER_BOUND or calculated_angle_music_per_axis < ANGLE_LOWER_BOUND:
                        continue_to_process = False
                        break

                    

                    if calculated_angle_music_per_axis == -1 : 
                        # write_protocol_data(CMD_INFO, f"Calculated angle using Spatial Smoothing MUSIC algorith {calculated_angle}")
                        break
                    calculated_angle.append(calculated_angle_music_per_axis)
                    calculated_angle_with_mag.append(calculated_angle_music_with_mag_per_axis)

                if not continue_to_process : break
                write_protocol_data(CMD_INFO, f"Calculated cumulative phase diff : {locator_idx}, mac {mac}, calculated angle {calculated_angle}, calculated angle with mag {calculated_angle_with_mag}")


                # determiner_value = (sin(angle_mean[1]) - cos(angle_mean[0])) * (sin(angle_mean[1]) + cos(angle_mean[0]))
                determiner_value = eval_determiner_angles_xy_invalid(calculated_angle)
                if determiner_value < 0 : continue

                z = locator_distance_ref[locator_idx][2]

                hypotenuse = z / sqrt(determiner_value)

                x = hypotenuse * cos(calculated_angle[0]) + locator_distance_ref[locator_idx][0]
                y = hypotenuse * cos(calculated_angle[1]) + locator_distance_ref[locator_idx][1]

                determiner_value_2 = eval_determiner_angles_xy_invalid(calculated_angle_with_mag)
                # if determiner_value_2 < 0 : continue

                z = locator_distance_ref[locator_idx][2]

                hypotenuse_2 = z / sqrt(determiner_value_2)

                x_2 = hypotenuse_2 * cos(calculated_angle_with_mag[0])
                y_2 = hypotenuse_2 * cos(calculated_angle_with_mag[1])

                # body_ok = BODY_AOA_COORD_SINGLE_LOCATOR_ELEMENT_TYPE.format(mac = mac, locator = locator_idx, x = x, y = y, z = z)
                # write_protocol_data(CMD_OK, body_ok)
                write_protocol_data(CMD_INFO, f"Calculated x,y from cumul phase diff of mac {mac} in locator {locator_idx} : {x},{y}")
                print(f"Locator {locator_idx} angle : {calculated_angle}, coordinate : {x}, {y}", file = file_cumul_diff_phase, flush=True)
                print(f"Locator {locator_idx} angle : {calculated_angle_with_mag}, coordinate : {x_2}, {y_2}", file = file_cumul_2_diff_phase, flush=True)
                body_ok = BODY_AOA_COORD_SINGLE_LOCATOR_ELEMENT_TYPE.format(mac = mac, locator = locator_idx, x = x, y = y, z = z)
                write_protocol_data(CMD_OK, body_ok)


def location_aoa_calculator_cumul_phase_diff_single_locator_music_extended(new_angles_to_calculated_cumul_phase_diff_per_locator_queue : Queue, diff_phase_buffer : dict, mag_buffer : dict, angle_buffer:dict, new_angles_cumul_phase_diff_cumul_angle_buffer : Queue) :
    file_cumul_diff_phase = open(os.path.dirname(__file__) + MUSIC_CUMUL_DIFF_PHASE_FILE, mode = "a")
    # file_cumul_2_diff_phase = open(os.path.dirname(__file__) + MUSIC_2_CUMUL_DIFF_PHASE_FILE, mode = "a")

    while True:
        # (mac, locator_idx_set) = new_angles_to_calculated_cumul_phase_diff_per_locator_queue.get()
        new_angles_from = new_angles_to_calculated_cumul_phase_diff_per_locator_queue.get()
        write_protocol_data(CMD_INFO, f"Location cumul phase {new_angles_from}")

        succeed_calculated_angles = dict()
        for (mac, locator_idx_set) in new_angles_from.items():
            succeed_calculated_angles[mac] = set()
            write_protocol_data(CMD_INFO, f"AoA calculator phase diff cumulative of mac {mac} from locators {locator_idx_set}")

            for locator_idx in locator_idx_set:
                diff_phase = diff_phase_buffer[mac][locator_idx]
                mag_array = mag_buffer[mac][locator_idx]
                num_iq_sets_per_axis_per_array = diff_phase.shape[2]
                received_data = np.zeros((SIZE_OF_ANT_ARRAY, num_iq_sets_per_axis_per_array), dtype = complex)
                # received_data_2 = np.zeros((SIZE_OF_ANT_ARRAY, num_iq_sets_per_axis_per_array), dtype = complex)
                calculated_angle = []
                # calculated_angle_with_mag = []
                continue_to_process = True
                for axis in range(NUM_OF_AXIS):
                    diff_phase_per_axis = diff_phase[axis]
                    mag_per_axis = mag_array[axis]
                    # representing phase difference to antenna reference, which means has a phaes difference 0 to reference
                    for ant in range(SIZE_OF_ANT_ARRAY):
                        try :
                            received_data[ant, :] = [np.exp(1j * diff_phase_element) for diff_phase_element in diff_phase_per_axis[ant]]
                            # received_data_2[ant, :] = [mag_element * np.exp(1j * diff_phase_element) for mag_element, diff_phase_element in zip(mag_per_axis[ant], diff_phase_per_axis[ant])]
                        except:
                            continue_to_process = False
                            break
                    
                    if not continue_to_process : break

                    if MUSIC_CALCULATOR == MUSIC_CALCULATOR_SPATIAL_SMOOTHING:  calculate_angle_music_spatial_smoothing(received_data, 0.12, axis)
                    else : calculated_angle_music_per_axis = calculate_angle_music(received_data, 0.12)

                    # calculated_angle_music_with_mag_per_axis = calculate_angle_music_spatial_smoothing(received_data_2, 0.12, axis)
                    # calculated_angle_music_per_axis = calculate_angle_music(received_data, 0.12)
                    # calculated_angle_music_with_mag_per_axis = calculate_angle_music(received_data_2, 0.12)

                    if calculated_angle_music_per_axis >= np.pi - 0.1 or calculated_angle_music_per_axis <= 0.1:
                        continue_to_process = False
                        break

                    if APPLY_ANGLE_TWEAK :
                        calculated_angle_music_per_axis = tweak_angle(calculated_angle_music_per_axis)
                        # calculated_angle_music_with_mag_per_axis = tweak_angle(calculated_angle_music_with_mag_per_axis)

                    write_protocol_data(CMD_INFO, f"calculated_angle_music_per_axis {calculated_angle_music_per_axis}")
                    if calculated_angle_music_per_axis > ANGLE_UPPER_BOUND or calculated_angle_music_per_axis < ANGLE_LOWER_BOUND:
                        continue_to_process = False
                        break

                    

                    if calculated_angle_music_per_axis == -1 : 
                        # write_protocol_data(CMD_INFO, f"Calculated angle using Spatial Smoothing MUSIC algorith {calculated_angle}")
                        break
                    calculated_angle.append(calculated_angle_music_per_axis)
                    # calculated_angle_with_mag.append(calculated_angle_music_with_mag_per_axis)

                if not continue_to_process : break
                write_protocol_data(CMD_INFO, f"Calculated cumulative phase diff : {locator_idx}, mac {mac}, calculated angle {calculated_angle}")


                # determiner_value = (sin(angle_mean[1]) - cos(angle_mean[0])) * (sin(angle_mean[1]) + cos(angle_mean[0]))
                determiner_value = eval_determiner_angles_xy_invalid(calculated_angle)
                if determiner_value < 0 : continue

                append_angle_to_angle_buffer(angle_buffer, calculated_angle)
                succeed_calculated_angles[mac].add(locator_idx)


                z = locator_distance_ref[locator_idx][2]

                hypotenuse = z / sqrt(determiner_value)

                x = hypotenuse * cos(calculated_angle[0]) + locator_distance_ref[locator_idx][0]
                y = hypotenuse * cos(calculated_angle[1]) + locator_distance_ref[locator_idx][1]

                # determiner_value_2 = eval_determiner_angles_xy_invalid(calculated_angle_with_mag)
                # # if determiner_value_2 < 0 : continue

                # z = locator_distance_ref[locator_idx][2]

                # hypotenuse_2 = z / sqrt(determiner_value_2)

                # x_2 = hypotenuse_2 * cos(calculated_angle_with_mag[0])
                # y_2 = hypotenuse_2 * cos(calculated_angle_with_mag[1])

                # body_ok = BODY_AOA_COORD_SINGLE_LOCATOR_ELEMENT_TYPE.format(mac = mac, locator = locator_idx, x = x, y = y, z = z)
                # write_protocol_data(CMD_OK, body_ok)
                write_protocol_data(CMD_INFO, f"Calculated x,y from cumul phase diff of mac {mac} in locator {locator_idx} : {x},{y}")
                print(f"Locator {locator_idx} angle : {calculated_angle}, coordinate : {x}, {y}", file = file_cumul_diff_phase, flush=True)
                # print(f"Locator {locator_idx} angle : {calculated_angle_with_mag}, coordinate : {x_2}, {y_2}", file = file_cumul_2_diff_phase, flush=True)
                body_ok = BODY_AOA_COORD_SINGLE_LOCATOR_ELEMENT_TYPE.format(mac = mac, locator = locator_idx, x = x, y = y, z = z)
                write_protocol_data(CMD_OK, body_ok)
        
        new_angles_cumul_phase_diff_cumul_angle_buffer.put(succeed_calculated_angles)

def location_aoa_calculator_cumul_phase_diff_single_locator_esprit(new_angles_to_calculated_cumul_phase_diff_per_locator_esprit_queue : Queue, diff_phase_buffer : dict, mag_buffer : dict, *args) :
    file_cumul_diff_phase_esprit = open(os.path.dirname(__file__) + ESPRIT_CUMUL_DIFF_PHASE_FILE, mode = "a")
    while True:
        # (mac, locator_idx_set) = new_angles_to_calculated_cumul_phase_diff_per_locator_queue.get()
        new_angles_from = new_angles_to_calculated_cumul_phase_diff_per_locator_esprit_queue.get()
        write_protocol_data(CMD_INFO, f"Location cumul phase {new_angles_from}")

        succeed_calculated_angles = dict()
        succeed_calculated_angles[mac] = set()
        for (mac, locator_idx_set) in new_angles_from.items():
            write_protocol_data(CMD_INFO, f"AoA calculator phase diff cumulative of mac {mac} from locators {locator_idx_set}")
            for locator_idx in locator_idx_set:
                diff_phase = diff_phase_buffer[mac][locator_idx]
                magnitude = mag_buffer[mac][locator_idx]
                num_iq_sets_per_axis_per_array = diff_phase.shape[2]
                received_data = np.zeros((SIZE_OF_ANT_ARRAY, num_iq_sets_per_axis_per_array), dtype = complex)
                calculated_angle = []
                calculated_angle_tls = []
                continue_to_process = True
                for axis in range(NUM_OF_AXIS):
                    diff_phase_per_axis = diff_phase[axis]
                    magnitude_per_axis = magnitude[axis]
                    # representing phase difference to antenna reference, which means has a phaes difference 0 to reference
                    try:
                        for ant in range(SIZE_OF_ANT_ARRAY):
                            received_data[ant, :] = [np.exp(1j * diff_phase_element) for (diff_phase_element, mag) in zip(diff_phase_per_axis[ant], magnitude_per_axis[ant])]
                    except:
                        continue_to_process = False
                        break

                    # if MUSIC_WITH_SPATIAL_SMOOTHING:
                    # calculated_angle = calculate_angle_music_spatial_smoothing(received_data, wave_length)
                    calculated_angle_esprit_per_axis = calculate_angle_esprit(received_data, 0.12, axis)
                    calculated_angle_esprit_tls_per_axis = calculate_angle_tls_esprit(received_data, 0.12, axis)

                    if calculated_angle_esprit_tls_per_axis >= np.pi - 0.1 or calculated_angle_esprit_tls_per_axis <= 0.1:
                        continue_to_process = False
                        break

                    if APPLY_ANGLE_TWEAK :
                        # calculated_angle_music_per_axis += (-1) * (calculated_angle_music_per_axis - np.pi / 2) / 5
                        # (-1) * ((calculated_angle_esprit_per_axis - np.pi / 2))**2 / 6 * ((calculated_angle_esprit_per_axis - np.pi / 2) / np.abs(calculated_angle_esprit_per_axis - np.pi / 2))
                        calculated_angle_esprit_per_axis = tweak_angle(calculated_angle_esprit_per_axis, 5)
                        # calculated_angle_esprit_tls_per_axis += (-1) * ((calculated_angle_esprit_tls_per_axis - np.pi / 2))**2 / 6 * ((calculated_angle_esprit_tls_per_axis - np.pi / 2) / np.abs(calculated_angle_esprit_tls_per_axis - np.pi / 2))
                        calculated_angle_esprit_tls_per_axis = tweak_angle(calculated_angle_esprit_tls_per_axis, 5)

                    # if calculated_angle_esprit_per_axis == -1 : 
                    #     # write_protocol_data(CMD_INFO, f"Calculated angle using Spatial Smoothing MUSIC algorith {calculated_angle}")
                    #     break
                    calculated_angle.append(calculated_angle_esprit_per_axis[0])
                    calculated_angle_tls.append(calculated_angle_esprit_tls_per_axis[0])

                if not continue_to_process: continue
                
                write_protocol_data(CMD_INFO, f"Calculated cumulative phase diff using ESPRIT method: {locator_idx}, mac {mac}, calculated angle {calculated_angle}")
                write_protocol_data(CMD_INFO, f"Calculated cumulative phase diff using TLS ESPRIT method: {locator_idx}, mac {mac}, calculated angle {calculated_angle_tls}")

                # determiner_value = (sin(angle_mean[1]) - cos(angle_mean[0])) * (sin(angle_mean[1]) + cos(angle_mean[0]))
                determiner_value = eval_determiner_angles_xy_invalid(calculated_angle_tls)
                if determiner_value < 0 : continue

                # if CALCULATOR_ANGLE_BUFFER == ESPRIT_CALCULATOR:
                #     angle_buffer : dict = args[0]
                #     if ESPRIT_CALCULATOR == ESPRIT_CALCULATOR_LS:
                #         append_angle_to_angle_buffer(angle_buffer, calculated_angle, locator_idx, locator_idx, mac)
                #     elif ESPRIT_CALCULATOR == ESPRIT_CALCULATOR_TLS:
                #         append_angle_to_angle_buffer(angle_buffer, calculated_angle_tls, locator_idx, mac)

                z = locator_distance_ref[locator_idx][2]

                hypotenuse = z / sqrt(determiner_value)

                x = hypotenuse * cos(calculated_angle_tls[0])
                y = hypotenuse * cos(calculated_angle_tls[1])

                # body_ok = BODY_AOA_COORD_SINGLE_LOCATOR_ELEMENT_TYPE.format(mac = mac, locator = locator_idx, x = x, y = y, z = z)
                # write_protocol_data(CMD_OK, body_ok)
                write_protocol_data(CMD_INFO, f"Calculated x,y from cumul phase diff of mac {mac} in locator {locator_idx} : {x},{y}")
                # print(f"angle : {calculated_angle_tls}, coordinate : {x}, {y}", file = file_cumul_diff_phase_esprit, flush = True)
                print(f"angle : {calculated_angle_tls}, coordinate : {x}, {y}", file = file_cumul_diff_phase_esprit, flush = True)

        # if CALCULATOR_ANGLE_BUFFER == ESPRIT_CALCULATOR:
        #     new_angles_cumul_phase_diff_cumul_angle_buffer : Queue = args(1)
        #     new_angles_cumul_phase_diff_cumul_angle_buffer.put(succeed_calculated_angles)


def location_aoa_calculator_cumul_phase_diff_single_locator_esprit_extended(new_angles_to_calculated_cumul_phase_diff_per_locator_esprit_queue : Queue, diff_phase_buffer : dict, mag_buffer : dict, angle_buffer:dict, new_angles_cumul_phase_diff_cumul_angle_buffer : Queue) :
    file_cumul_diff_phase_esprit = open(os.path.dirname(__file__) + ESPRIT_CUMUL_DIFF_PHASE_FILE, mode = "a")
    while True:
        # (mac, locator_idx_set) = new_angles_to_calculated_cumul_phase_diff_per_locator_queue.get()
        new_angles_from = new_angles_to_calculated_cumul_phase_diff_per_locator_esprit_queue.get()
        write_protocol_data(CMD_INFO, f"Location cumul phase {new_angles_from}")

        succeed_calculated_angles = dict()
        for (mac, locator_idx_set) in new_angles_from.items():
            succeed_calculated_angles[mac] = set()
            write_protocol_data(CMD_INFO, f"AoA calculator phase diff cumulative of mac {mac} from locators {locator_idx_set}")
            for locator_idx in locator_idx_set:
                diff_phase = diff_phase_buffer[mac][locator_idx]
                magnitude = mag_buffer[mac][locator_idx]
                num_iq_sets_per_axis_per_array = diff_phase.shape[2]
                received_data = np.zeros((SIZE_OF_ANT_ARRAY, num_iq_sets_per_axis_per_array), dtype = complex)
                calculated_angle = []
                # calculated_angle_tls = []
                continue_to_process = True
                for axis in range(NUM_OF_AXIS):
                    diff_phase_per_axis = diff_phase[axis]
                    magnitude_per_axis = magnitude[axis]
                    # representing phase difference to antenna reference, which means has a phaes difference 0 to reference
                    try:
                        for ant in range(SIZE_OF_ANT_ARRAY):
                            received_data[ant, :] = [np.exp(1j * diff_phase_element) for (diff_phase_element, mag) in zip(diff_phase_per_axis[ant], magnitude_per_axis[ant])]
                    except:
                        continue_to_process = False
                        break
                    
                    if ESPRIT_CALCULATOR == ESPRIT_CALCULATOR_LS:
                        calculated_angle_esprit_per_axis = calculate_angle_esprit(received_data, 0.12, axis)
                    elif ESPRIT_CALCULATOR == ESPRIT_CALCULATOR_TLS:
                        calculated_angle_esprit_per_axis = calculate_angle_tls_esprit(received_data, 0.12, axis)

                    if calculated_angle_esprit_per_axis >= np.pi - 0.1 or calculated_angle_esprit_per_axis <= 0.1:
                        continue_to_process = False
                        break

                    if APPLY_ANGLE_TWEAK :
                        # calculated_angle_music_per_axis += (-1) * (calculated_angle_music_per_axis - np.pi / 2) / 5
                        # (-1) * ((calculated_angle_esprit_per_axis - np.pi / 2))**2 / 6 * ((calculated_angle_esprit_per_axis - np.pi / 2) / np.abs(calculated_angle_esprit_per_axis - np.pi / 2))
                        calculated_angle_esprit_per_axis = tweak_angle(calculated_angle_esprit_per_axis, 5)
                        # calculated_angle_esprit_tls_per_axis += (-1) * ((calculated_angle_esprit_tls_per_axis - np.pi / 2))**2 / 6 * ((calculated_angle_esprit_tls_per_axis - np.pi / 2) / np.abs(calculated_angle_esprit_tls_per_axis - np.pi / 2))
                        # calculated_angle_esprit_tls_per_axis = tweak_angle(calculated_angle_esprit_tls_per_axis, 5)

                    # if calculated_angle_esprit_per_axis == -1 : 
                    #     # write_protocol_data(CMD_INFO, f"Calculated angle using Spatial Smoothing MUSIC algorith {calculated_angle}")
                    #     break
                    calculated_angle.append(calculated_angle_esprit_per_axis[0])
                    # calculated_angle_tls.append(calculated_angle_esprit_tls_per_axis[0])

                if not continue_to_process: continue
                
                write_protocol_data(CMD_INFO, f"Calculated cumulative phase diff using ESPRIT method: {locator_idx}, mac {mac}, calculated angle {calculated_angle}")
                # write_protocol_data(CMD_INFO, f"Calculated cumulative phase diff using TLS ESPRIT method: {locator_idx}, mac {mac}, calculated angle {calculated_angle_tls}")

                # determiner_value = (sin(angle_mean[1]) - cos(angle_mean[0])) * (sin(angle_mean[1]) + cos(angle_mean[0]))
                determiner_value = eval_determiner_angles_xy_invalid(calculated_angle)
                if determiner_value < 0 : continue
            
                append_angle_to_angle_buffer(angle_buffer, calculated_angle, locator_idx, mac)
                succeed_calculated_angles[mac].add(locator_idx)

                z = locator_distance_ref[locator_idx][2]

                hypotenuse = z / sqrt(determiner_value)

                x = hypotenuse * cos(calculated_angle[0])
                y = hypotenuse * cos(calculated_angle[1])

                # body_ok = BODY_AOA_COORD_SINGLE_LOCATOR_ELEMENT_TYPE.format(mac = mac, locator = locator_idx, x = x, y = y, z = z)
                # write_protocol_data(CMD_OK, body_ok)
                write_protocol_data(CMD_INFO, f"Calculated x,y from cumul phase diff of mac {mac} in locator {locator_idx} : {x},{y}")
                # print(f"angle : {calculated_angle_tls}, coordinate : {x}, {y}", file = file_cumul_diff_phase_esprit, flush = True)
                print(f"angle : {calculated_angle}, coordinate : {x}, {y}", file = file_cumul_diff_phase_esprit, flush = True)

        new_angles_cumul_phase_diff_cumul_angle_buffer.put(succeed_calculated_angles)

    

def location_aoa_calculator_cumul_phase_diff_multiple_locator(new_angles_cumul_phase_diff_multiple_locator_queue : Queue, diff_phase_buffer : dict, mag_buffer : dict):
    while True:
        new_angles_from = new_angles_cumul_phase_diff_multiple_locator_queue.get()

        for (mac, locator_idx_set) in new_angles_from.items():
            write_protocol_data(CMD_INFO, f"AoA calculator phase diff cumulative of mac {mac} from locators {locator_idx_set}")
            calculated_coordinate = []
            for locator_idx in locator_idx_set:
                diff_phase = diff_phase_buffer[mac][locator_idx]
                mag_array = mag_buffer[mac][locator_idx]
                num_iq_sets_per_axis_per_array = diff_phase.shape[2]
                received_data = np.zeros((SIZE_OF_ANT_ARRAY, num_iq_sets_per_axis_per_array), dtype = complex)
                # received_data_2 = np.zeros((SIZE_OF_ANT_ARRAY, num_iq_sets_per_axis_per_array), dtype = complex)
                calculated_angle = []
                # calculated_angle_with_mag = []
                continue_to_process = True
                for axis in range(NUM_OF_AXIS):
                    diff_phase_per_axis = diff_phase[axis]
                    mag_per_axis = mag_array[axis]
                    # representing phase difference to antenna reference, which means has a phaes difference 0 to reference
                    for ant in range(SIZE_OF_ANT_ARRAY):
                        try :
                            received_data[ant, :] = [np.exp(1j * diff_phase_element) for diff_phase_element in diff_phase_per_axis[ant]]
                            # received_data_2[ant, :] = [mag_element * np.exp(1j * diff_phase_element) for mag_element, diff_phase_element in zip(mag_per_axis[ant], diff_phase_per_axis[ant])]
                        except:
                            continue_to_process = False
                            break
                    
                    if not continue_to_process : break
                    # if MUSIC_WITH_SPATIAL_SMOOTHING:
                    # calculated_angle = calculate_angle_music_spatial_smoothing(received_data, wave_length)
                    # calculated_angle_per_axis = calculate_angle_music_spatial_smoothing(received_data, 0.12, axis)
                    calculated_angle_per_axis = calculate_angle_tls_esprit(received_data, 0.12, axis)[0]

                    
                    # calculated_angle_music_with_mag_per_axis = calculate_angle_music_spatial_smoothing(received_data_2, 0.12, axis)
                    # calculated_angle_per_axis = calculate_angle_music(received_data, 0.12)
                    # calculated_angle_music_with_mag_per_axis = calculate_angle_music(received_data_2, 0.12)

                    if calculated_angle_per_axis >= np.pi - 0.1 or calculated_angle_per_axis <= 0.1:
                        continue_to_process = False
                        break

                    if APPLY_ANGLE_TWEAK :
                        # calculated_angle_per_axis += (-1) * (calculated_angle_per_axis - np.pi / 2) / 5
                        # calculated_angle_per_axis += (-1) * ((calculated_angle_per_axis - np.pi / 2))**2 / 6 * ((calculated_angle_per_axis - np.pi / 2) / np.abs(calculated_angle_per_axis - np.pi / 2))
                        calculated_angle_per_axis = tweak_angle(calculated_angle_per_axis)

                    if calculated_angle_per_axis > ANGLE_UPPER_BOUND or calculated_angle_per_axis < ANGLE_LOWER_BOUND:
                        continue_to_process = False
                        break

                    

                    if calculated_angle_per_axis == -1 : 
                        continue_to_process = False
                        break
                    calculated_angle.append(calculated_angle_per_axis)
                    # calculated_angle_with_mag.append(calculated_angle_music_with_mag_per_axis)

                if not continue_to_process : continue
                write_protocol_data(CMD_INFO, f"Calculated cumulative phase diff : {locator_idx}, mac {mac}, calculated angle {calculated_angle}")


                # determiner_value = (sin(angle_mean[1]) - cos(angle_mean[0])) * (sin(angle_mean[1]) + cos(angle_mean[0]))
                determiner_value = eval_determiner_angles_xy_invalid(calculated_angle)
                if determiner_value < 0 : continue

                z = locator_distance_ref[locator_idx][2]

                hypotenuse = z / sqrt(determiner_value)

                x = hypotenuse * cos(calculated_angle[0]) + locator_distance_ref[locator_idx][0]
                y = hypotenuse * cos(calculated_angle[1]) + locator_distance_ref[locator_idx][1]

                calculated_coordinate.append([x, y, z])

                # determiner_value_2 = eval_determiner_angles_xy_invalid(calculated_angle_with_mag)
                # # if determiner_value_2 < 0 : continue

                # z = locator_distance_ref[locator_idx][2]

                # hypotenuse_2 = z / sqrt(determiner_value_2)

                # x_2 = hypotenuse_2 * cos(calculated_angle_with_mag[0])
                # y_2 = hypotenuse_2 * cos(calculated_angle_with_mag[1])

                # body_ok = BODY_AOA_COORD_SINGLE_LOCATOR_ELEMENT_TYPE.format(mac = mac, locator = locator_idx, x = x, y = y, z = z)
                # write_protocol_data(CMD_OK, body_ok)
                write_protocol_data(CMD_INFO, f"Cumul phase diff multiple locator of mac {mac} in locator {locator_idx} : {x},{y}")
            
            if not continue_to_process or len(calculated_coordinate) == 0: continue
            write_protocol_data(CMD_INFO, f"MEANNNNNNNNNNNNNNNNNNNNNN {calculated_coordinate}")
            mean_coordinates = np.mean(calculated_coordinate, axis = 0)
            # write_protocol_data(CMD_OK, )

            # body_ok = BODY_AOA_COORD_CUMULATIVE.format(mac = mac, x = mean_coordinates[0], y = mean_coordinates[1], z = mean_coordinates[2])
            # write_protocol_data(CMD_OK, body_ok)


def location_aoa_calculator_L_shaped_cumul_phase_diff(new_angles_L_shaped_cumul_phase_diff : Queue, diff_phase_buffer : dict, mag_buffer : dict):
    file_L_shaped = open(os.path.dirname(__file__) + MUSIC_L_SHAPED, mode = "a")
    while True:
        new_angles_from = new_angles_L_shaped_cumul_phase_diff.get()
        for (mac, locator_idx_set) in new_angles_from.items():
            for locator_idx in locator_idx_set:
                diff_phase_array = diff_phase_buffer[mac][locator_idx]
                mag_array = mag_buffer[mac][locator_idx]
                num_of_iq_sets = diff_phase_array.shape[2]
                received_data = np.zeros((NUM_OF_AXIS * SIZE_OF_ANT_ARRAY, num_of_iq_sets), dtype = complex)
                continue_to_process = True
                for axis in range(NUM_OF_AXIS):
                    diff_phase_per_axis = diff_phase_array[axis]
                    magnitude_per_axis = mag_array[axis]
                    try :
                        for ant in range(SIZE_OF_ANT_ARRAY):
                            received_data[axis * SIZE_OF_ANT_ARRAY + ant, :] = [mag * np.exp(1j * diff_phase) for mag, diff_phase in zip(magnitude_per_axis[ant], diff_phase_per_axis[ant])]
                    except:
                        continue_to_process = False
                        break
                
                if not continue_to_process : break
                write_protocol_data(CMD_INFO, f"Received data L Shaped {received_data.shape}")
                calculated_angle = calculate_angle_L_shaped_music(received_data, 0.12)
                write_protocol_data(CMD_INFO, f"Angle x and y of mac {mac} locator {locator_idx} L shaped cumul phase diff {calculated_angle[0]}, {calculated_angle[1]}")
                if APPLY_ANGLE_TWEAK:
                    # calculated_angle = (-1) * ((calculated_angle - np.pi / 2))**2 / 6 * ((calculated_angle - np.pi / 2) / np.abs(calculated_angle - np.pi / 2))
                    calculated_angle = tweak_angle(calculated_angle)

                write_protocol_data(CMD_INFO, f"Angle x and y of mac {mac} locator {locator_idx} L shaped cumul phase diff {calculated_angle[0]}, {calculated_angle[1]}")
                determiner_value = eval_determiner_angles_xy_invalid(calculated_angle)
                if determiner_value < 0 : continue

                z = locator_distance_ref[locator_idx][2]

                hypotenuse = z / sqrt(determiner_value)

                x = hypotenuse * cos(calculated_angle[0]) + locator_distance_ref[locator_idx][0]
                y = hypotenuse * cos(calculated_angle[1]) + locator_distance_ref[locator_idx][1]


                write_protocol_data(CMD_INFO, f"Angle x and y of mac {mac} locator {locator_idx} L shaped cumul phase diff {calculated_angle[0]}, {calculated_angle[1]}")
                # file_L_shaped.write(f"Angle {angle_x}, {angle_y}\n")
                # file_L_shaped.flush()
                print(f"Angle {calculated_angle[0]}, {calculated_angle[1]}, {np.arcsin(np.sqrt(np.cos(calculated_angle[0])**2 + np.cos(calculated_angle[1])**2))}, {np.arctan2(np.cos(calculated_angle[1]), np.cos(calculated_angle[0]))}, {x}, {y}", file = file_L_shaped, flush= True)


def location_aoa_calculator_cumul_phase_diff_cumul_angle_buffer(new_angles_cumul_phase_diff_cumul_angle_buffer : Queue, angle_buffer : dict):
    while True:
        new_angles_from = new_angles_cumul_phase_diff_cumul_angle_buffer.get()
        for (mac, locator_idx_set) in new_angles_from.items():
            calculated_coordinates = []
            for locator_idx in locator_idx_set:
                angles = angle_buffer[mac][locator_idx]

                filtered_angles = angles_bound_filter(np.asarray(angles), ANGLE_UPPER_BOUND, ANGLE_LOWER_BOUND)
                if len(filtered_angles) != 2 or len(filtered_angles[0]) == 0 or len(filtered_angles[1]) == 0: 
                    write_protocol_data(CMD_ERROR, "Only one or zero variable exist in bounded_angles")
                    continue

                write_protocol_data(CMD_INFO, f"Current angles, locator {locator_idx} {mac} {filtered_angles}")

                # if len(filtered_angles[0]) >= MIN_ANGLES_COUNT_GET_RID_OUTLIER :
                #     filtered_angles_x = get_rid_outlier_1d_array(np.asarray(filtered_angles[0]), Q3, Q1, C1, C2, 1, 1)
                #     filtered_angles[0] = filtered_angles_x

                # if len(filtered_angles[1]) >= MIN_ANGLES_COUNT_GET_RID_OUTLIER :
                #     filtered_angles_y = get_rid_outlier_1d_array(np.asarray(filtered_angles[1]), Q3, Q1, C1, C2, 1, 1)
                #     filtered_angles[1] = filtered_angles_y

                mean_angle = [np.mean(angle) for angle in filtered_angles]

                write_protocol_data(CMD_INFO, f"Cumulative phase diff coordinates {mean_angle} {filtered_angles}")

                determiner_value = eval_determiner_angles_xy_invalid(mean_angle)
                if determiner_value < 0:
                    continue

                z = locator_distance_ref[locator_idx][2]

                hypotenuse = z / sqrt(determiner_value)

                x = hypotenuse * cos(mean_angle[0]) + locator_distance_ref[locator_idx][0]
                y = hypotenuse * cos(mean_angle[1]) + locator_distance_ref[locator_idx][1]

                calculated_coordinates.append([x, y, z])

            if len(calculated_coordinates) == 0 : continue
            mean_calculated_coordinates = np.mean(calculated_coordinates, axis = 0)
            

            write_protocol_data(CMD_INFO, f"Cumulative phase diff coordinates {mean_calculated_coordinates} {angle_buffer[mac][locator_idx]}")

            body_ok = BODY_AOA_COORD_CUMULATIVE.format(mac = mac, x = mean_calculated_coordinates[0], y = mean_calculated_coordinates[1], z = mean_calculated_coordinates[2])
            write_protocol_data(CMD_OK, body_ok)

            