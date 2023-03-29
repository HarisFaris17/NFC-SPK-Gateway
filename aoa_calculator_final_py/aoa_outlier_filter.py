from aoa_constants import *
import pygad
from queue import Queue
import numpy as np

from aoa_communication import *
from itertools import combinations

#the variable is in n x m dimension, whereas filtered variable has m x ...
def get_rid_outlier_1d_array(variable_array : np.ndarray, q3, q1, c1, c2, l, r) -> list:
    if q3 < q1 :
        write_protocol_data(CMD_INFO, "Q3 lesser than Q1")
        return

    quartile3 = np.quantile(variable_array, q = q3)
    quartile1 = np.quantile(variable_array, q = q1)

    iqr = quartile3 - quartile1
    # coordinates_mean = mean(coordinates, axis = 0)

    upper_threshold = quartile3 + c1 * iqr
    lower_threshold = quartile1 - c2 * iqr

    print(quartile3, quartile1, iqr, upper_threshold, lower_threshold)

    filtered_variable = []
    for value in variable_array:
        if value <= upper_threshold and value >= lower_threshold:
            filtered_variable.append(value)

    body_info = f"Filtered variables {filtered_variable}"
    write_protocol_data(command = CMD_INFO, body = body_info)
    print(body_info)
    return filtered_variable

#the variable is in n x m dimension, whereas filtered variable has m x ...
def get_rid_outlier(variables_arrays : np.ndarray, q3, q1, c1, c2, l, r) -> list:
    num_of_variables = variables_arrays.shape[1]
    filtered_variables = []

    if q3 < q1 :
        write_protocol_data(CMD_INFO, "Q3 lesser than Q1")
        pass
        return

    quartile3 = np.quantile(variables_arrays, q = q3, axis = 0)
    quartile1 = np.quantile(variables_arrays, q = q1, axis = 0)

    

    iqr = [quartile3[variable] - quartile1[variable] for variable in range(num_of_variables)]
    # coordinates_mean = mean(coordinates, axis = 0)

    upper_threshold = [quartile3[variable] + c1 * iqr[variable] for variable in range(num_of_variables)]
    lower_threshold = [quartile1[variable] - c2 * iqr[variable] for variable in range(num_of_variables)]

    print(quartile3, quartile1, iqr, upper_threshold, lower_threshold)

    for variable in range(num_of_variables):
        filtered_variable = []
        for value_per_variable in variables_arrays[:, variable]:
            if value_per_variable <= upper_threshold[variable] and value_per_variable >= lower_threshold[variable]:
                filtered_variable.append(value_per_variable)

        # mean_filtered_angle = mean(filtered_angle)
        # filtered_mean_angles.append(mean_filtered_angle)
        # for awhile the std will not be used 
        # std_filtered_angle = std(filtered_angle)
        filtered_variables.append(filtered_variable)
        # body_info = f"Angle {'X' if angle == 0 else 'Y'} Filtered angle : {filtered_angle}, Mean filtered angle {filtered_mean_angles}, Angle mean : {mean_filtered_angle}, Std filtered angle : {std_filtered_angle}"
        # write_protocol_data(command = CMD_INFO, body = body_info)

        # angles_info += f"angle {'X' if angle == 0 else 'Y'}, Filtered angle : {filtered_angle}, Angle mean : {mean_filtered_angle}, Std filtered angle : {std_filtered_angle}\n"
    # body_info  = f"-- AOA -- : mac {mac} locator {locator_idx}\n {angles_info}"
    body_info = f"Filtered variables {filtered_variables}"
    write_protocol_data(command = CMD_INFO, body = body_info)
    print(body_info)
    return filtered_variables

def angles_bound_filter(variables_arrays : np.ndarray, upper_bound, lower_bound):
    num_of_variables = variables_arrays.shape[1]
    filtered_variables = []

    if upper_bound < lower_bound:
        write_protocol_data(CMD_ERROR, f"The upper_bound lower than lower_bound")
        return
    
    for variable in range(num_of_variables):
        filtered_variable = []
        for value_per_variable in variables_arrays[:, variable]:
            if value_per_variable <= upper_bound and value_per_variable >= lower_bound:
                filtered_variable.append(value_per_variable)
        
        filtered_variables.append(filtered_variable)

    return filtered_variables