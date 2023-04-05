import numpy as np
from sklearn import svm
from joblib import load
from pyargus.directionEstimation import *
from itertools import combinations
import matplotlib.pyplot as plt

import os

from math import log10
from numpy import std, cos, sin, sqrt, absolute, arccos, log, float64, pi

from aoa_constants import *
from aoa_communication import *
from aoa_common import *

# protect the phase so that it is in range [-pi, pi]
# in this scenario it is not possible that between two phase difference more than pi, since that will represent undersampling (F_SAMPLING < 1/2 Freq), hence we don't have to consider it
def protect_phase(phase):
    if phase < -pi :
        phase = phase + 2 * pi
        if phase < -pi : 
            phase = protect_phase(phase)
    elif phase > pi:
        phase = phase - 2 * pi
        if phase > pi : 
            phase = protect_phase(phase)
    return phase

from numpy.core.memmap import ndarray

# calculate magnitude and phase of MWL01
def calc_mag_phase(data : ndarray):
    returned_data = np.zeros((int(data.shape[0]/2), 2));

    for idx in range(0, data.shape[0], 2) :
        iq = data[idx] + data[idx+1]*1j
        mag = np.abs(iq)
        phase = np.angle(iq, deg = False)
    #  phase = polar(cmplx)

        # #print(magnitude, pha)
        # #print("idx : ", idx)

        returned_data[int(idx/2)] = [mag, phase]
    return returned_data;

def calculate_freq_offset(phase_diff_reference_array : ndarray):
    return (phase_diff_reference_array)/(2 * pi * T_SAMPLING)

from numpy import pi, float64

def calculate_phase_diff_reference(reference_phase_array : ndarray):
    # this is the list of offset freq not the carrier freq (2.4** GHz radio freq)
    calc_phase_diff_array = np.zeros(NUMBER_OF_REFERENCE_IQ-1, float64);

    for i in range(NUMBER_OF_REFERENCE_IQ-1):
        differential_phase = reference_phase_array[i+1] - reference_phase_array[i]
        differential_phase = protect_phase(differential_phase)
        # #print(i, differential_phase)
        calc_phase_diff_array[i] = differential_phase

    return calc_phase_diff_array

def diff_actual_to_predict_phase(phase_array, phase_diff_mean):
        diff_phase_array = np.zeros(int((phase_array.shape[0]- NUMBER_OF_REFERENCE_IQ)/2), float64)

        i = 0
        phase_array_actual = phase_array[NUMBER_OF_REFERENCE_IQ:]
        length = phase_array_actual.shape[0]
        while i < length:
            base_phase = phase_array_actual[i]
            pred_phase = base_phase + 2 * phase_diff_mean
            act_phase = phase_array_actual[i+1]
            # #print("pred ", pred_phase, "act", act_phase)
            diff = protect_phase(pred_phase - act_phase)
            # if diff < (-pi/2):
            #     diff += pi
            # elif diff > (pi/2):
            #     diff -= pi
            diff_phase_array[int(i/2)] = diff
            i = i + 2

        return diff_phase_array

def diff_actual_to_predict_phase_splitted(phase_array, phase_diff_mean):
        num_of_iq_per_ant_per_axis = int ((phase_array.shape[0] - NUMBER_OF_REFERENCE_IQ) / (SIZE_OF_ANT_ARRAY * NUM_OF_AXIS))
        diff_phase_array = np.zeros((NUM_OF_AXIS, SIZE_OF_ANT_ARRAY, num_of_iq_per_ant_per_axis), float64)
        # diff_phase_array = np.zeros(int((phase_array.shape[0]- NUMBER_OF_REFERENCE_IQ)/2), float64)
        i = 0
        phase_array_actual = phase_array[NUMBER_OF_REFERENCE_IQ:]
        # length = phase_array_actual.shape[0]
        while i < num_of_iq_per_ant_per_axis * SIZE_OF_ANT_ARRAY * NUM_OF_AXIS:
            axis = int((i / SIZE_OF_ANT_ARRAY)) % NUM_OF_AXIS
            idx = int(i / (SIZE_OF_ANT_ARRAY * NUM_OF_AXIS))

            diff_phase_array[axis, 0, idx]= 0
            for k in range(SIZE_OF_ANT_ARRAY - 1):
                base_phase = phase_array_actual[k + i]
                pred_phase = base_phase + 2 * phase_diff_mean
                act_phase = phase_array_actual[k + i+1]
                diff = protect_phase(pred_phase - act_phase)
                # if diff < (-pi/2):
                #     diff += pi
                # elif diff > (pi/2):
                #     diff -= pi
                diff_phase_array[axis, k+1, idx]= diff
            i = i + 4

        return diff_phase_array

def diff_actual_to_predict_phase_splitted_2(phase_array, phase_diff_mean):
        num_of_iq_per_ant_per_axis = int ((phase_array.shape[0] - NUMBER_OF_REFERENCE_IQ) / (SIZE_OF_ANT_ARRAY * NUM_OF_AXIS))
        diff_phase_array = np.zeros((NUM_OF_AXIS, SIZE_OF_ANT_ARRAY, num_of_iq_per_ant_per_axis), float64)
        # diff_phase_array = np.zeros(int((phase_array.shape[0]- NUMBER_OF_REFERENCE_IQ)/2), float64)
        i = 0
        phase_array_actual = phase_array[NUMBER_OF_REFERENCE_IQ:]
        # length = phase_array_actual.shape[0]
        while i < num_of_iq_per_ant_per_axis * SIZE_OF_ANT_ARRAY * NUM_OF_AXIS:
            axis = int((i / SIZE_OF_ANT_ARRAY)) % NUM_OF_AXIS
            idx = int(i / (SIZE_OF_ANT_ARRAY * NUM_OF_AXIS))

            diff_phase_array[axis, 0, idx]= 0
            for k in range(SIZE_OF_ANT_ARRAY - 1):
                base_phase = phase_array_actual[k + i]
                pred_phase = base_phase + 2 * phase_diff_mean
                act_phase = phase_array_actual[k + i+1]
                diff = protect_phase((pred_phase - act_phase) + diff_phase_array[axis, k, idx])
                # if diff < (-pi/2):
                #     diff += pi
                # elif diff > (pi/2):
                #     diff -= pi
                diff_phase_array[axis, k+1, idx]= diff
            i = i + 4

        return diff_phase_array

def mag_reshape(mag_array):
    num_of_iq_per_ant_per_axis = int ((mag_array.shape[0] - NUMBER_OF_REFERENCE_IQ)/ (SIZE_OF_ANT_ARRAY * NUM_OF_AXIS))
    reshaped_mag_array = np.zeros((NUM_OF_AXIS, SIZE_OF_ANT_ARRAY, num_of_iq_per_ant_per_axis), float64)

    i = 0
    mag_array_actual = mag_array[NUMBER_OF_REFERENCE_IQ:]
    # length = phase_array_actual.shape[0]
    while i < num_of_iq_per_ant_per_axis * SIZE_OF_ANT_ARRAY * NUM_OF_AXIS:
        axis = int((i / SIZE_OF_ANT_ARRAY)) % NUM_OF_AXIS
        idx = int(i / (SIZE_OF_ANT_ARRAY * NUM_OF_AXIS))

        for k in range(SIZE_OF_ANT_ARRAY):
            reshaped_mag_array[axis, k, idx]= mag_array_actual[k + i]
        i = i + 4

    return reshaped_mag_array


from numpy import isnan, ceil, nan

# def divide_diff_phase(diff_phase_array : ndarray):
#     number_of_ant_pattern = len(switch_pattern)
#     number_of_phase_diff = diff_phase_array.shape[0]

#     diff_phase_per_axis = np.zeros((number_of_ant_pattern, int(ceil(number_of_phase_diff / number_of_ant_pattern))))
#     # nan representing invalid number or the angle doesn't exist. Later it will not be processed
#     diff_phase_per_axis.fill(nan)

#     for i, diff_phase in enumerate(diff_phase_array):
#         diff_phase_per_axis[i % number_of_ant_pattern][int(i / number_of_ant_pattern)] = diff_phase
#         # angle_array.append(arccos((diff_phase * 12.5 * CM)/(2 * pi * dx)))

#     return diff_phase_per_axis

pipeline_distance_estimator = load(os.path.dirname(__file__) + DISTANCE_ESTIMATOR_FILE)

from numpy import arccos
from scipy.constants import speed_of_light

def calculate_angle(diff_phase_per_ant_array : ndarray, wave_length):
    angle_array = np.zeros(0, float64) #diff_phase_per_ant_array.shape[0]

    for  diff_phase in diff_phase_per_ant_array:
        # #print("diff_phase ", diff_phase, "arccos ", (diff_phase * 12.5 * CM)/(2 * pi * dx), "theta", arccos((diff_phase * 12.5 * CM)/(2 * pi * dx)))
        angle = arccos((diff_phase * wave_length)/(2 * pi * dx))
        # #print(i, angle)
        if (isnan(angle)): continue

        angle_array = np.append(angle_array, angle)
        # angle_array.append(arccos((diff_phase * 12.5 * CM)/(2 * pi * dx)))

    return angle_array

# def calculate_distance(rssi):
#     return 10**((RSSI_1M - rssi)/R)
def calculate_angle_music(received_data, wave_length):
    # calculating spatial correlation matrix
    R = corr_matrix_estimate(received_data.T, imp = "fast")

    # this is an array that contains the distance per ant in desired axis to the reference (ANT_11 in this case). per axis we only consider two antena, which are ANT_11 and ANT_12 for X axis and ANT_11 and ANT_10 for Y axis. ANT_19 has a distance of dx to the reference ANT_11 in X axis and ANT_11 has a distance of dy to the reference ANT_11. But since dx is equal to dy, hence we can only assign the dx to the array
    ant_alignment = np.array([0 * dx, 1 * dx])
    incident_angle = np.arange(-90, 91, 1)
    scanning_vectors = np.zeros((2, incident_angle.shape[0]), dtype = complex)

    for i in range(incident_angle.shape[0]):
        scanning_vectors[:, i] = np.exp(ant_alignment * 1j * 2 * pi * sin(np.deg2rad(incident_angle[i])) / wave_length )

    power_distribution = DOA_MUSIC(R, scanning_vectors, signal_dimension = 1)
    if type(power_distribution) == tuple : 
        write_protocol_data(CMD_INFO, f"Power distribution failed to be calculated")
        return -1
    # DOA_plot(power_distribution, incident_angle, log_scale_min=None, alias_highlight=True, d=0.5, axes=None)
    # plt.show()
    normal_power = np.divide(np.abs(power_distribution), np.max(np.abs(power_distribution)))
    calculated_angle = float(incident_angle[np.where(normal_power == 1)[0]][0])
    # print(np.max(np.abs(power_distribution)))
    return np.deg2rad(90.0 - calculated_angle)

def calculate_angle_music(received_data, wave_length):
    # calculating spatial correlation matrix
    R = corr_matrix_estimate(received_data.T, imp = "fast")


    # this is an array that contains the distance per ant in desired axis to the reference (ANT_11 in this case). per axis we only consider two antena, which are ANT_11 and ANT_12 for X axis and ANT_11 and ANT_10 for Y axis. ANT_19 has a distance of dx to the reference ANT_11 in X axis and ANT_11 has a distance of dy to the reference ANT_11. But since dx is equal to dy, hence we can only assign the dx to the array
    ant_alignment = np.array([i * d for i in range(SIZE_OF_ANT_ARRAY)])
    incident_angle = np.arange(-90, 91, 1)
    scanning_vectors = np.zeros((SIZE_OF_ANT_ARRAY, incident_angle.shape[0]), dtype = complex)

    for i in range(incident_angle.shape[0]):
        scanning_vectors[:, i] = np.exp(ant_alignment * 1j * 2 * pi * sin(np.deg2rad(incident_angle[i])) / wave_length )

    power_distribution = DOA_MUSIC(R, scanning_vectors, signal_dimension = 1)
    if type(power_distribution) == tuple : 
        write_protocol_data(CMD_INFO, f"Power distribution failed to be calculated")
        return -1
    # DOA_plot(power_distribution, incident_angle, log_scale_min=None, alias_highlight=True, d=0.5, axes=None)
    # plt.show()
    normal_power = np.divide(np.abs(power_distribution), np.max(np.abs(power_distribution)))
    calculated_angle = float(incident_angle[np.where(normal_power == 1)[0]][0])
    # print(np.max(np.abs(power_distribution)))
    return np.deg2rad(90.0 - calculated_angle)

def calculate_angle_L_shaped_music(received_data, wave_length):
    received_data_x = received_data[:SIZE_OF_ANT_ARRAY, :]
    write_protocol_data(CMD_INFO, f"Received data x {received_data_x.shape}")
    R_x = spatial_smoothing(received_data_x.T, SIZE_OF_SUBARRAY, direction = "forward-backward")
    
    ant_alignment = np.array([i * d for i in range(SIZE_OF_SUBARRAY)], dtype = float64)
    incident_angle = np.arange(0, 181, 1)
    scanning_vectors = np.zeros((SIZE_OF_SUBARRAY, incident_angle.shape[0]), dtype = complex)

    for i in range(incident_angle.shape[0]):
        scanning_vectors[:, i] = np.exp(ant_alignment * 1j * 2 * pi * cos(np.deg2rad(incident_angle[i])) / wave_length )

    power_distribution = DOA_MUSIC(R_x, scanning_vectors, signal_dimension = 1)
    if type(power_distribution) == tuple : 
        write_protocol_data(CMD_INFO, f"Power distribution failed to be calculated")
        return -1
    
    normal_power = np.divide(np.abs(power_distribution), np.max(np.abs(power_distribution)))
    # DOA_plot(power_distribution, incident_angle, log_scale_min=None, alias_highlight=True, d=0.5, axes=None)
    # plt.show()
    try:
        angle_x = np.deg2rad(float(incident_angle[np.where(normal_power == 1)[0]][0]))
        write_protocol_data(CMD_INFO, f"ANGLEEEE {angle_x}")
    except:
        return -1
    
    R = corr_matrix_estimate(received_data.T, imp = "fast")

    ant_alignment = np.array([i * d for i in range(SIZE_OF_ANT_ARRAY)], dtype = float64)
    scanning_vectors = np.zeros((NUM_OF_AXIS * SIZE_OF_ANT_ARRAY, incident_angle.shape[0]), dtype = complex)
    scanning_vectors[:SIZE_OF_ANT_ARRAY, i] = np.exp(ant_alignment * 1j * 2 * pi * cos(angle_x) / wave_length )
    for i in range(incident_angle.shape[0]):
        scanning_vectors[SIZE_OF_ANT_ARRAY:, i] = np.exp(ant_alignment * 1j * 2 * pi * cos(np.deg2rad(incident_angle[i])) / wave_length )
    
    power_distribution = DOA_MUSIC(R, scanning_vectors, signal_dimension = 1)

    if type(power_distribution) == tuple : 
        write_protocol_data(CMD_INFO, f"Power distribution failed to be calculated")
        return -1
    
    normal_power = np.divide(np.abs(power_distribution), np.max(np.abs(power_distribution)))
    try:
        angle_y = np.deg2rad(float(incident_angle[np.where(normal_power == 1)[0]][0]))
    except:
        return -1
    
    return np.array([angle_x, angle_y], dtype = float64)


def calculate_angle_music_spatial_smoothing(received_data, wave_length, signal_dimension = 1):
    R = spatial_smoothing(received_data.T, SIZE_OF_SUBARRAY, direction = "forward-backward")

    write_protocol_data(CMD_INFO, f"The correlation matrix {R}")

    ant_alignment = np.array([i * d for i in range(SIZE_OF_SUBARRAY)], dtype = float64)
    incident_angle = np.arange(-90, 91, 1)
    scanning_vectors = np.zeros((SIZE_OF_SUBARRAY, incident_angle.shape[0]), dtype = complex)

    for i in range(incident_angle.shape[0]):
        scanning_vectors[:, i] = np.exp(ant_alignment * 1j * 2 * pi * sin(np.deg2rad(incident_angle[i])) / wave_length )

    power_distribution = DOA_MUSIC(R, scanning_vectors, signal_dimension = signal_dimension)
    if type(power_distribution) == tuple : 
        write_protocol_data(CMD_INFO, f"Power distribution failed to be calculated")
        return -1
    
    normal_power = np.divide(np.abs(power_distribution), np.max(np.abs(power_distribution)))
    # DOA_plot(power_distribution, incident_angle, log_scale_min=None, alias_highlight=True, d=0.5, axes=None)
    # plt.show()
    from scipy.signal import argrelextrema
    # index_normal_largest_power = np.argpartition(normal_power, -1 * 10)[-1 * 10 :]
    index_largest_peak_power = argrelextrema(normal_power, np.greater)
    largest_power_angles = incident_angle[index_largest_peak_power]
    # music_multiple_angles = open(os.path.dirname(__file__) + MUSIC_MULTIPLE_ANGLE_FILE, mode = "a")
    # music_multiple_angles.write(f"axis {axis} {largest_power_angles}\n")
    try:
        calculated_angle = float(incident_angle[np.where(normal_power == 1)[0]][0])
    except:
        return -1
    # print(np.max(np.abs(power_distribution)))
    # music_multiple_angles.close()
    return np.deg2rad(90.0 - calculated_angle)

def calculate_angle_esprit(received_data, wave_length, signal_dimension = 1):
    R = corr_matrix_estimate(received_data.T, imp = "fast")
    calculated_angle, eigen_values = DOA_LS_ESPRIT(R, signal_dimension, wave_length)
    # calculated_angle, eigen_values = DOA_ESPRIT(R, 1, wave_length)

    # esprit_file = open(os.path.dirname(__file__) + ESPRIT_ANGLE_FILE, mode = "a")
    # esprit_file.write(f"axis {axis} {calculated_angle}, eigen_values {eigen_values}\n")
    # esprit_file.close()

    return calculated_angle

def calculate_angle_tls_esprit(received_data, wave_length, signal_dimension = 1):
    received_data_t = received_data.T
    R = corr_matrix_estimate(received_data_t, imp = "fast")
    R = spatial_smoothing(received_data.T, 3, direction = "forward-backward")
    # R_11 = corr_matrix_estimate(received_data_t[:, :-1], imp = "fast")
    # R_22 = corr_matrix_estimate(received_data_t[:, 1:], imp = "fast")
    # write_protocol_data(CMD_INFO, f"Received data shape {received_data.shape}, R11 {R_11}, R22 {R_22}")
    # calculated_angle = DOA_TLS_ESPRIT_2(R_11, R_22, 1, wave_length)
    # num_of_signals = count_num_of_signals_mdl(R, received_data.shape[1])
    # num_of_signals = estimate_sig_dim(R)
    num_of_signals = count_num_of_signals_aic(R, received_data.shape[1])
    write_protocol_data(CMD_INFO, f"NUM_OF_SIGNALS {num_of_signals}")
    calculated_angle, eigen_values, ei = DOA_TLS_ESPRIT_3(R, signal_dimension, wave_length)
    # calculated_angle = DOA_TLS_ESPRIT(received_data_t, 1, wave_length)
    # tls_esprit_file = open(os.path.dirname(__file__) + TLS_ESPRIT_ANGLE_FILE, mode = "a")
    # tls_esprit_file.write(f"axis {axis} {calculated_angle}\n")
    # tls_esprit_file.close()

    return calculated_angle, eigen_values, ei

def calculate_angle_root_music(received_data, wave_length, axis):
    R = corr_matrix_estimate(received_data.T, imp = "fast")
    angles = DOA_ROOT_MUSIC(R, 2, wave_length)
    esprit_file = open(os.path.dirname(__file__) + ROOT_MUSIC_FILE, mode = "a")
    esprit_file.write(f"axis {axis} {angles}\n")
    esprit_file.close()
    

def calculate_distance(rssi):
    rssi_2d = [[rssi]]
    scaled_rssi_2d = pipeline_distance_estimator[0].transform(rssi_2d)
    scaled_distance = pipeline_distance_estimator[2].predict(scaled_rssi_2d)
    scaled_distance_2d = np.reshape(scaled_distance, (len(scaled_distance), 1))
    distance = pipeline_distance_estimator[1].inverse_transform(scaled_distance_2d)
    distance = distance.item()
    return distance

def calculate_R(rssi_1m, rssi_2m):
    return (rssi_1m - rssi_2m) / log10(2 * M)

from scipy import linalg as LA
def DOA_ESPRIT(covariance_matrix, num_of_signal_sources, wave_length) :
    eigen_values, eigen_vectors = LA.eig(covariance_matrix)
    N = covariance_matrix.shape[0]
    # sorting from highest to lowest eigenvalues
    # idx = eigen_values.argsort()[::-1]
    eig = []
    for i in range(N):
        eig.append([np.abs(eigen_values[i]), eigen_vectors[:, i]])

    write_protocol_data(CMD_INFO, f"{eig}")
    sorted_eig = sorted(eig, key = lambda eig : eig[0], reverse=True)

    # eigen_vectors = sorted_eig[:, 1]

    # eigen_vectors = eigen_vectors[idx]
    write_protocol_data(CMD_INFO, f"{len(sorted_eig)} {len(sorted_eig[0])}")
    sorted_signal_eigen_vectors = np.zeros((N, num_of_signal_sources))
    for i in range(num_of_signal_sources):
        sorted_signal_eigen_vectors[:, i] = sorted_eig[i][1]

    # signal_subspace = eigen_vectors[:, :]#num_of_signal_sources]
    phi = LA.pinv(sorted_signal_eigen_vectors[0:SIZE_OF_ANT_ARRAY-1]) @ sorted_signal_eigen_vectors[1:SIZE_OF_ANT_ARRAY]

    eigen_values, _ = LA.eig(phi)

    # return np.arccos((1j) * log(eigen_values) / d)
    angles = np.arcsin(np.angle(eigen_values)/(np.pi * 2 * d / wave_length))
    return (-1 * angles) + np.pi / 2, eigen_values

def DOA_LS_ESPRIT(covariance_matrix, num_of_signal_sources, wave_length) :
    eigen_values, eigen_vectors = LA.eig(covariance_matrix)
    N = covariance_matrix.shape[0]
    # sorting from highest to lowest eigenvalues
    # idx = eigen_values.argsort()[::-1]
    eig = []
    for i in range(N):
        eig.append([np.abs(eigen_values[i]), eigen_vectors[:, i]])

    for i, e in enumerate(eig):
        write_protocol_data(CMD_INFO, f"eig {i} {e}")
    sorted_eig = sorted(eig, key = lambda eig : eig[0], reverse=True)

    # eigen_vectors = sorted_eig[:, 1]

    # eigen_vectors = eigen_vectors[idx]
    # write_protocol_data(CMD_INFO, f"{len(sorted_eig)} {len(sorted_eig[0])}")
    for i, e in enumerate(sorted_eig):
        write_protocol_data(CMD_INFO, f"sorted eig {i} {e}")
    sorted_signal_eigen_vectors = np.zeros((N, num_of_signal_sources), dtype = complex)
    for i in range(num_of_signal_sources):
        sorted_signal_eigen_vectors[:, i] = sorted_eig[i][1]

    for i in range(num_of_signal_sources):
        write_protocol_data(CMD_INFO, f"sorted_signal_eigen_vectors {sorted_signal_eigen_vectors[:, i]}")
    signal_subspace = sorted_signal_eigen_vectors[:, :num_of_signal_sources]

    write_protocol_data(CMD_INFO, f"signal_subspace {signal_subspace}")
    Es1 = signal_subspace[0:N-1, :]
    Es2 = signal_subspace[1:N, :]

    write_protocol_data(CMD_INFO, f"Es1 {Es1}\n Es2 {Es2}")

    Es1_H = Es1.conj().T
    phi = LA.inv(Es1_H @ Es1) @ (Es1_H @ Es2)

    write_protocol_data(CMD_INFO, f"phi {phi}")

    eigen_values, _ = LA.eig(phi)

    write_protocol_data(CMD_INFO, f"eigen_values {eigen_values}")

    # return np.arccos((1j) * log(eigen_values) / d)
    angles = np.arccos(np.angle(eigen_values)/(np.pi * 2 * d / wave_length))
    return angles, eigen_values

def DOA_TLS_ESPRIT(received_data, num_of_signal_sources, wave_length) :
    U, sigma, Q_H = LA.svd(received_data)
    Q = Q_H.conj().T
    Q_s = Q[:, :num_of_signal_sources]
    Q_0 = Q_s[:-1, :]
    Q_1 = Q_s[1:, :]
    Q0Q1 = np.append(Q_0, Q_1, axis = 1)
    U, sigma, V_H = LA.svd(Q0Q1)
    V = V_H.conj().T
    V_12 = V[:num_of_signal_sources, num_of_signal_sources:]
    V_22 = V[num_of_signal_sources:, num_of_signal_sources:]

    mul = -V_12 @ LA.inv(V_22)
    eigen_values, _ = LA.eig(mul)
    return np.arccos(np.angle(eigen_values)/(np.pi * 2 * d / wave_length))

def DOA_TLS_ESPRIT_2(cor_mat_1, cor_mat_2, num_of_signal_sources, wave_length) :
    N = len(cor_mat_1)
    eigen_values_1, E_1 = LA.eig(cor_mat_1)
    eigen_values_2, E_2 = LA.eig(cor_mat_2)

    L = len(eigen_values_1)

    write_protocol_data(CMD_INFO, f"Eigen {E_1} \n eigen_values_1 {eigen_values_1} \n {E_2} \n eigen_values_2 {eigen_values_2}")

    sorted_E_1 = []
    sorted_E_2 = []

    for i in range(L):
        sorted_E_1.append((np.abs(eigen_values_1[i]), E_1[:, i]))
    sorted_E_1 = sorted(sorted_E_1, key = lambda eig : eig[0], reverse= True)

    for i in range(L):
        sorted_E_2.append((np.abs(eigen_values_2[i]), E_2[:, i]))
    sorted_E_2 = sorted(sorted_E_2, key = lambda eig : eig[0], reverse= True)

    sorted_eigen_vectors_1 = np.zeros((N, L), dtype = complex)
    sorted_eigen_vectors_2 = np.zeros((N, L), dtype = complex)

    for i in range(L):
        sorted_eigen_vectors_1[:, i] = sorted_E_1[i][1]
    for i in range(L):
        sorted_eigen_vectors_2[:, i] = sorted_E_2[i][1]

    Es_1 = sorted_eigen_vectors_1[:, :num_of_signal_sources]
    Es_2 = sorted_eigen_vectors_2[:, :num_of_signal_sources]
    Es_1_H = Es_1.conj().T
    Es_2_H = Es_2.conj().T
    C = np.append(Es_1_H, Es_2_H, axis = 0) @ np.append(Es_1, Es_2, axis = 1)
    eigen_values_c, E_c = LA.eig(C)
    sorted_C = []
    for i in range(len(eigen_values_c)):
        sorted_C.append((np.abs(eigen_values_c[i]), E_c[:, i]))

    sorted_C = sorted(sorted_C, key = lambda eig : eig[0], reverse = True)
    sorted_E_c = np.zeros((2 * num_of_signal_sources, 2 * num_of_signal_sources), dtype = complex)
    write_protocol_data(CMD_INFO, f"sorted_C {sorted_C}, \n E_c {E_c} \n C {C}")
    for i in range(len(eigen_values_c)):
        sorted_E_c[:, i] = sorted_C[i][1]

    write_protocol_data(CMD_INFO, f"sorted_E_C {sorted_E_c}")
    E_12 = sorted_E_c[:num_of_signal_sources, num_of_signal_sources:]
    E_22 = sorted_E_c[num_of_signal_sources:, num_of_signal_sources:]

    
    mul = - E_12 @ LA.inv(E_22)
    eigen_values, _ = LA.eig(mul)
    write_protocol_data(CMD_INFO, f"E_s1 {Es_1} \n Es_2 {Es_2} \n E_c {E_c} \n E_12 {E_12.shape} {E_12}\n E_22 {E_22.shape} {E_22} \n eigen_values {eigen_values}")
    return np.arccos(np.angle(eigen_values)/(np.pi * 2 * d / wave_length))

def DOA_TLS_ESPRIT_3(correlation_matrix, num_of_signal_sources, wave_length) :
    N = correlation_matrix.shape[0]
    eigen_values_cor, eigen_vectors = LA.eig(correlation_matrix)

    eig = []
    for i in range(N):
        eig.append([np.abs(eigen_values_cor[i]), eigen_vectors[:, i]])

    for i, e in enumerate(eig):
        write_protocol_data(CMD_INFO, f"eig {i} {e}")
    sorted_eig = sorted(eig, key = lambda eig : eig[0], reverse=True)

    # eigen_vectors = sorted_eig[:, 1]

    # eigen_vectors = eigen_vectors[idx]
    # write_protocol_data(CMD_INFO, f"{len(sorted_eig)} {len(sorted_eig[0])}")
    for i, e in enumerate(sorted_eig):
        write_protocol_data(CMD_INFO, f"sorted eig {i} {e}")
    sorted_signal_eigen_vectors = np.zeros((N, num_of_signal_sources), dtype = complex)
    sorted_signal_eigen_values = np.zeros(num_of_signal_sources, dtype = complex)
    for i in range(num_of_signal_sources):
        sorted_signal_eigen_vectors[:, i] = sorted_eig[i][1]
        sorted_signal_eigen_values[i] = sorted_eig[i][0]

    for i in range(num_of_signal_sources):
        write_protocol_data(CMD_INFO, f"sorted_signal_eigen_vectors {sorted_signal_eigen_vectors[:, i]}")
    signal_subspace = sorted_signal_eigen_vectors[:, :num_of_signal_sources]

    signal_eigen_values = np.zeros(N, dtype = complex)
    for i in range(N):
        signal_eigen_values[i] = sorted_eig[i][0]#sorted_signal_eigen_values[:num_of_signal_sources]

    write_protocol_data(CMD_INFO, f"signal_subspace {signal_subspace}")
    Es_1 = signal_subspace[0:N-1, :]
    Es_2 = signal_subspace[1:N, :]

    # for i in range(L):
    #     sorted_E_1.append((np.abs(eigen_values_1[i]), E_1[:, i]))
    # sorted_E_1 = sorted(sorted_E_1, key = lambda eig : eig[0], reverse= True)

    # for i in range(L):
    #     sorted_E_2.append((np.abs(eigen_values_2[i]), E_2[:, i]))
    # sorted_E_2 = sorted(sorted_E_2, key = lambda eig : eig[0], reverse= True)

    # sorted_eigen_vectors_1 = np.zeros((N, L), dtype = complex)
    # sorted_eigen_vectors_2 = np.zeros((N, L), dtype = complex)

    # for i in range(L):
    #     sorted_eigen_vectors_1[:, i] = sorted_E_1[i][1]
    # for i in range(L):
    #     sorted_eigen_vectors_2[:, i] = sorted_E_2[i][1]

    # Es_1 = sorted_eigen_vectors_1[:, :num_of_signal_sources]
    # Es_2 = sorted_eigen_vectors_2[:, :num_of_signal_sources]
    Es_1_H = Es_1.conj().T
    Es_2_H = Es_2.conj().T
    C = np.append(Es_1_H, Es_2_H, axis = 0) @ np.append(Es_1, Es_2, axis = 1)
    eigen_values_c, E_c = LA.eig(C)
    sorted_C = []
    for i in range(len(eigen_values_c)):
        sorted_C.append((np.real(eigen_values_c[i]), E_c[:, i]))

    sorted_C = sorted(sorted_C, key = lambda eig : eig[0], reverse = True)
    sorted_E_c = np.zeros((2 * num_of_signal_sources, 2 * num_of_signal_sources), dtype = complex)
    write_protocol_data(CMD_INFO, f"sorted_C {sorted_C}, \n E_c {E_c} \n C {C}")
    for i in range(len(eigen_values_c)):
        sorted_E_c[:, i] = sorted_C[i][1]

    write_protocol_data(CMD_INFO, f"sorted_E_C {sorted_E_c}")
    E_12 = sorted_E_c[:num_of_signal_sources, num_of_signal_sources:]
    E_22 = sorted_E_c[num_of_signal_sources:, num_of_signal_sources:]

    
    mul = - E_12 @ LA.inv(E_22)
    eigen_values, _ = LA.eig(mul)
    write_protocol_data(CMD_INFO, f"E_s1 {Es_1} \n Es_2 {Es_2} \n E_c {E_c} \n E_12 {E_12.shape} {E_12}\n E_22 {E_22.shape} {E_22} \n eigen_values {eigen_values}")
    # return np.arccos(np.angle(eigen_values)/(np.pi * 2 * d / wave_length)), signal_eigen_values, np.arccos(tweak_angle(np.angle(eigen_values), 10, 0)/(np.pi * 2 * d / wave_length))
    return np.arccos(tweak_angle(np.angle(eigen_values), 10, 0)/(np.pi * 2 * d / wave_length)), signal_eigen_values, np.arccos(tweak_angle(np.angle(eigen_values), 10, 0)/(np.pi * 2 * d / wave_length))

from sympy import solve, poly
from sympy.abc import z
def DOA_ROOT_MUSIC(covariance_matrix, num_of_signal_sources, wave_length):
    N = covariance_matrix.shape[0]
    _, eigen_vectors = LA.eig(covariance_matrix)
    noise_subspace = eigen_vectors[:, (-1 * num_of_signal_sources):]
    C = noise_subspace @ noise_subspace.conj().T
    # C_abs = np.abs(C)
    write_protocol_data(CMD_INFO, f"C Data {C}")
    inverse_power = poly(z, domain = 'CC')
    for l in range(-1 * (N - 1), N):
        write_protocol_data(CMD_INFO, f"terms {np.sum(np.diag(C, l))}")
        # addition = poly(np.sum(np.diag(C_abs, l)) * z**l)
        # inverse_power = inverse_power + addition
        inverse_power = inverse_power + np.sum(np.diag(C, l)) * z**l
    inverse_power = inverse_power - z
    write_protocol_data(CMD_INFO, f"Inverse power {inverse_power}")
    z_roots = solve(inverse_power)
    write_protocol_data(CMD_INFO, f"Z roos {z_roots}")
    filtered_z_roots = []
    for z_root in z_roots:
        if np.abs(z_root) <= 1 : filtered_z_roots.append(z_root)

    write_protocol_data(CMD_INFO, f"Filtered Z roos {filtered_z_roots}")
    filtered_z_roots.sort(reverse = False, key = np.abs)
    z_closest_to_unit_circle = filtered_z_roots[(-1 * num_of_signal_sources):]
    angles = np.arccos(np.angle(z_closest_to_unit_circle)/(np.pi * 2 * d / wave_length))
    return angles


from scipy.stats import gmean
def count_num_of_signals_mdl(cor_mat, num_of_snapshots):
    p = len(cor_mat)
    eig_values, _ = LA.eig(cor_mat)
    index = np.flip(np.argsort(eig_values))
    eig_values = eig_values[index]
    write_protocol_data(CMD_INFO, f"EIGGGGGGGGGGGGGG {eig_values}, {num_of_snapshots}, {p}")

    result = []
    for d in range(p):
        mdl = -1 * num_of_snapshots * np.log(np.prod(eig_values[d:]) / (np.mean(eig_values[d:])**(p-d))) + 1/2 * d * (2 * p - d) * np.log(num_of_snapshots)
        write_protocol_data(CMD_INFO, f"DDDDDDDDDDDDDDDDDDDD {d} {p} {num_of_snapshots} {np.prod(eig_values[d:])} {np.mean(eig_values[d:])} {eig_values[d:]}")
        result.append((d, mdl))

    write_protocol_data(CMD_INFO, f"MDLLLLLLLLLLLLLLL {result}")
    return result


def count_num_of_signals_aic(cor_mat, num_of_snapshots):
    p = len(cor_mat)
    eig_values, _ = LA.eig(cor_mat)
    index = np.flip(np.argsort(eig_values))
    eig_values = eig_values[index]
    write_protocol_data(CMD_INFO, f"EIGGGGGGGGGGGGGG {eig_values}, {num_of_snapshots}, {p}")

    result = []
    for d in range(p):
        mdl = -2 * num_of_snapshots * np.log(np.prod(eig_values[d:]) / (np.mean(eig_values[d:])**(p-d))) + 2 * d * (2 * p - d)
        write_protocol_data(CMD_INFO, f"DDDDDDDDDDDDDDDDDDDD {d} {p} {num_of_snapshots} {np.prod(eig_values[d:])} {np.mean(eig_values[d:])} {eig_values[d:]}")
        result.append((d, mdl))

    write_protocol_data(CMD_INFO, f"AICCCCCCCCCCCCCCCCCCCCCCC {result}")
    return result
    