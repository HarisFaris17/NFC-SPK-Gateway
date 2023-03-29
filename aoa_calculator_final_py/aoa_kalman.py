from aoa_communication import *
from aoa_constants import *

# from pykalman import KalmanFilter
from filterpy.kalman import KalmanFilter
from filterpy.common import Q_discrete_white_noise

import numpy as np
from numpy import pi, float64

kalman_filters = {}

observation_matrix = np.asarray([[1., 0., 0., 0., 0., 0.], [0., 1., 0., 0., 0., 0.]])
transition_matrices = np.asarray([[1., 0., 1., 0., 0.5, 0.], [0., 1., 0., 1., 0., 0.5], [0, 0., 1., 0., 1., 0.], [0., 0., 0., 1., 0., 1.], [0., 0., 0., 0., 1., 0.], [0., 0., 0., 0., 0., 1.]])
transpose_transisition_matrices = np.transpose(transition_matrices)
estimation_uncertainity = np.asarray([[1000., 0., 0., 0., 0., 0.],[0., 1000., 0., 0., 0., 0.],[0., 0., 1000., 0., 0., 0.],[0., 0., 0., 1000., 0., 0.],[0., 0., 0., 0., 1000., 0.],[0., 0., 0., 0., 0., 1000.]])
measurement_noise = np.asarray([[10.],[10.]], dtype = float64)
input_transition_matrices = np.asarray([])
process_noise = Q_discrete_white_noise(dim=2, dt=1.0, var=0.13, block_size = 3, order_by_dim = True)

print(process_noise)

def filter_with_kalman(mac, locator_idx, new_angles_elevation):
    write_protocol_data(CMD_INFO, f"anglesssssssssssssssss {new_angles_elevation}")
    # for angles in new_angles_elevation:
    angle = np.asarray([[new_angles_elevation[0]],[new_angles_elevation[1]]])
    if mac not in kalman_filters :
        kalman_filters[mac] = {}

    if locator_idx not in kalman_filters[mac] :
        filter = KalmanFilter(dim_x = 6, dim_z = 2)
        filter.x = np.array([pi/2, pi/2, 0., 0., 0., 0.], dtype = float64)
        filter.F = transition_matrices
        filter.H = observation_matrix
        filter.Q = process_noise
        kalman_filters[mac][locator_idx] = filter

    kalman_filters[mac][locator_idx].predict()
    kalman_filters[mac][locator_idx].update(angle)


    write_protocol_data(CMD_INFO, f"Current state {kalman_filters[mac][locator_idx].x}")
    return kalman_filters[mac][locator_idx].x
    
    # kalman_filters[mac][locator_idx]
    # input 
    # kalman_filters[mac][locator_idx] = #KalmanFilter(transition_matrices )
