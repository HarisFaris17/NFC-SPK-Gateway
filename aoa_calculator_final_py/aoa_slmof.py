from aoa_constants import *
import pygad
from queue import Queue
import numpy as np

from aoa_communication import *
from itertools import combinations
                        #q1     q3      c1    c2   
function_offline_input = [0.25, 0.75,  0.5,  0.5, ]

def slmof_filter(new_angles_from_waiting_per_batch_queue : Queue, angle_buffer : dict):
    while True:
        new_batch_mac = new_angles_from_waiting_per_batch_queue.get()

def ga_offline(inputs, mutation_prob : float, num_of_iter : int):
    num_of_params = len(inputs)
    ga_instance = pygad.GA(NUM_OF_OFFLINE_GENERATIONS, NUM_OF_PARENTS_MATING, fitness_func = fitness, sol_per_pop = SOL_PER_POP, )

def fitness_offline(solution, solution_idx) :
    # sum_square_err = 0
    # for param_idx in len(solution) :

    #     sum_square_err += solution[param_idx] - 
    # cos_offline = 
    # return 1 / (cost_offline(x_true, y_true, x, y) + 0.000001 )
    print("")

def cost_offline(x_true, y_true, x, y) :
    return np.sqrt((x - x_true)**2 + (y - y_true)**2)


def mean_optimization_filter(input_array_1d : np.ndarray, q3, q1, c1, c2, l, r) :
    filtered_outlier_input = get_rid_outlier_1d_array(input_array_1d, q3, q1, c1, c2, l, r)
    # unduplicated_filtered_input = set(filtered_outlier_input)
    print(filtered_outlier_input)

    set_of_sorted_values_combination = sorted(combinations(filtered_outlier_input, 2), key = sorting_key)
    print(set_of_sorted_values_combination)

    optimal_average = np.mean(filtered_outlier_input)
    previous_optimal_average = optimal_average
    print("initial average", optimal_average)
    while True:
        P_right = np.array([], dtype = np.float64)
        P_left = np.array([], dtype = np.float64)

        for values_combination in set_of_sorted_values_combination:
            lower_bound_interval = -999999
            upper_bound_interval = 999999
            if values_combination[0] <= values_combination[1] :
                upper_bound_interval = values_combination[1]
                lower_bound_interval = values_combination[0]
            else:
                upper_bound_interval = values_combination[0]
                lower_bound_interval = values_combination[1]

            if lower_bound_interval <= optimal_average <= upper_bound_interval :
                optimum_interval = (lower_bound_interval, upper_bound_interval)
                break


        for value in filtered_outlier_input:
            if value > optimal_average :
                P_right = np.append(P_right, value)
            elif value < optimal_average:
                P_left = np.append(P_left, value)
        
        print("C_right ", P_right - optimal_average)
        print("C_left ", P_left - optimal_average)
        C_right = inverse_std(P_right - optimal_average)
        C_left = inverse_std(P_left - optimal_average)

        print(P_right, P_left, C_right, C_left, P_right - optimal_average, P_left - optimal_average)
        if C_right > C_left:
            optimal_average = np.mean([optimum_interval[0], optimal_average])
        elif C_right < C_left:
            optimal_average = np.mean([optimal_average, optimum_interval[1]])
        else:
            break

        if optimal_average == previous_optimal_average:
            break

        previous_optimal_average = optimal_average
        
    return optimal_average

def inverse_std(values_1d):
    return 1 / np.std(values_1d)

def sorting_key(combination_two_value : tuple) :
    return np.abs(combination_two_value[0] - combination_two_value[1])

#the variable is in n x m dimension, whereas filtered variable has m x ...
# def get_rid_outlier_1d_array(variable_array : np.ndarray, q3, q1, c1, c2, l, r) -> list:
#     if q3 < q1 :
#         write_protocol_data(CMD_INFO, "Q3 lesser than Q1")
#         return

#     quartile3 = np.quantile(variable_array, q = q3)
#     quartile1 = np.quantile(variable_array, q = q1)

#     iqr = quartile3 - quartile1
#     # coordinates_mean = mean(coordinates, axis = 0)

#     upper_threshold = quartile3 + c1 * iqr
#     lower_threshold = quartile1 - c2 * iqr

#     print(quartile3, quartile1, iqr, upper_threshold, lower_threshold)

#     filtered_variable = []
#     for value in variable_array:
#         if value <= upper_threshold and value >= lower_threshold:
#             filtered_variable.append(value)

#     body_info = f"Filtered variables {filtered_variable}"
#     write_protocol_data(command = CMD_INFO, body = body_info)
#     print(body_info)
#     return filtered_variable

# #the variable is in n x m dimension, whereas filtered variable has m x ...
# def get_rid_outlier(variables_arrays : np.ndarray, q3, q1, c1, c2, l, r) -> list:
#     num_of_variables = variables_arrays.shape[1]
#     filtered_variables = []

#     if q3 < q1 :
#         write_protocol_data(CMD_INFO, "Q3 lesser than Q1")
#         pass
#         return

#     quartile3 = np.quantile(variables_arrays, q = q3, axis = 0)
#     quartile1 = np.quantile(variables_arrays, q = q1, axis = 0)

    

#     iqr = [quartile3[variable] - quartile1[variable] for variable in range(num_of_variables)]
#     # coordinates_mean = mean(coordinates, axis = 0)

#     upper_threshold = [quartile3[variable] + c1 * iqr[variable] for variable in range(num_of_variables)]
#     lower_threshold = [quartile1[variable] - c2 * iqr[variable] for variable in range(num_of_variables)]

#     print(quartile3, quartile1, iqr, upper_threshold, lower_threshold)

#     for variable in range(num_of_variables):
#         filtered_variable = []
#         for value_per_variable in variables_arrays[:, variable]:
#             if value_per_variable <= upper_threshold[variable] and value_per_variable >= lower_threshold[variable]:
#                 filtered_variable.append(value_per_variable)

#         # mean_filtered_angle = mean(filtered_angle)
#         # filtered_mean_angles.append(mean_filtered_angle)
#         # for awhile the std will not be used 
#         # std_filtered_angle = std(filtered_angle)
#         filtered_variables.append(filtered_variable)
#         # body_info = f"Angle {'X' if angle == 0 else 'Y'} Filtered angle : {filtered_angle}, Mean filtered angle {filtered_mean_angles}, Angle mean : {mean_filtered_angle}, Std filtered angle : {std_filtered_angle}"
#         # write_protocol_data(command = CMD_INFO, body = body_info)

#         # angles_info += f"angle {'X' if angle == 0 else 'Y'}, Filtered angle : {filtered_angle}, Angle mean : {mean_filtered_angle}, Std filtered angle : {std_filtered_angle}\n"
#     # body_info  = f"-- AOA -- : mac {mac} locator {locator_idx}\n {angles_info}"
#     body_info = f"Filtered variables {filtered_variables}"
#     write_protocol_data(command = CMD_INFO, body = body_info)
#     print(body_info)
#     return filtered_variables
