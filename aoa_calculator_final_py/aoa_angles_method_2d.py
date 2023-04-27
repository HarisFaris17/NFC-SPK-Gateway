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

from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt

angles_x = np.linspace(0, pi, int(180))
angles_y = np.linspace(0, pi, int(180))
X, Y = np.meshgrid(angles_x, angles_y, indexing = 'ij')
def music_2d(new_angles_ : Queue, diff_phase_buffer : dict, mag_buffer : dict):
    z = np.zeros(X.shape, dtype = complex)
    file_music_2d = open(os.path.dirname(__file__) + MUSIC_2D_FILE, mode = "a")
    while True:
        new_angles_from = new_angles_.get()

        for mac, locator_idx_list in new_angles_from.items():
            for locator_idx in locator_idx_list:
                diff_phase = diff_phase_buffer[mac][locator_idx]
                mag = mag_buffer[mac][locator_idx]
                try:
                    mag_diff_phase = mag * np.exp(1j * diff_phase)
                except:
                    continue
                R = corr_matrix_estimate(mag_diff_phase.T, imp="fast")
                En = noise_subspace(R, 1)
                for (i, angle_x) in enumerate(angles_x):
                    for (j, angle_y) in enumerate(angles_y):
                        steering = steering_2d(angle_x, angle_y)
                        z[i, j] = power_music(En, steering)
                # fig = plt.figure()
                # ax = plt.axes(projection = '3d')
                # ax.plot_surface(X, Y, z, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
                # plt.show()
        
                index_x, index_y = np.unravel_index(np.argmax(z), z.shape)
                determiner = eval_determiner_angles_xy_invalid((angles_x[index_x], angles_y[index_y]))
                r = locator_distance_ref[locator_idx][2] / sqrt(determiner)
                x = r * cos(angles_x[index_x])
                y = r * cos(angles_y[index_y])
                print(f"Angle {angles_x[index_x]}, {angles_y[index_y]} coord {x}, {y}", file = file_music_2d, flush = True)




import scipy.linalg as LA
def noise_subspace(corr_mat, signal_dimension):
    _, E = LA.eigh(corr_mat)
    return E[:, :-signal_dimension]

def power_music(noise_subspace, steering_vec):
    return  1 / np.abs(steering_vec.conj().T @ noise_subspace @ noise_subspace.conj().T @ steering_vec)

