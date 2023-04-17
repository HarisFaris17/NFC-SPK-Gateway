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

from doatools.doatools.estimation import source_number, esprit, preprocessing

# protect the phase so that it is in range [-pi, pi]
# in this scenario it is not possible that between two phase difference more than pi, since that will represent undersampling (F_SAMPLING < 1/2 Freq), hence we don't have to consider it


def spatial_smoothing_iss1(received_data, size_of_subarray):
    L = size_of_subarray
    N = received_data.shape[0]
    M = N - L + 1

    R = np.zeros((L, L), dtype = complex)
    for i in range(M):
        r_i = received_data[i:(i + L), :].copy()
        for j in range(M):
            if i == j:
                r_j = r_i
            else :
                r_j = received_data[j:(j + L), :].copy()

            R_ij = r_i @ r_j.conj().T / N
            R_ji = r_j @ r_i.conj().T / N

            R += R_ij @ R_ji + np.flip(R_ij).conj() @ np.flip(R_ji).conj()

    R /= (2 * M)
    return R

def spatial_smoothing_iss2(received_data, size_of_subarray):
    L = size_of_subarray
    N = received_data.shape[0]
    M = N - L + 1

    R = np.zeros((L, L), dtype = complex)
    for i in range(M):
        R_ii = received_data[i:(i + L), :].copy()
        R_ii = R_ii @ R_ii.conj().T / N
        for j in range(M):
            if i == j :
                R_jj = R_ii.copy()
            else :
                R_jj = received_data[j:(j + L), :].copy()
                R_jj = R_jj @ R_jj.conj().T / N

            R += R_ii @ R_jj + np.flip(R_ii).conj() @ np.flip(R_jj).conj()

    R /= (2 * M)
    return R

def spatial_smoothing_ess(received_data, size_of_subarray):
    return spatial_smoothing_iss1(received_data, size_of_subarray) + spatial_smoothing_iss2(received_data, size_of_subarray)

import scipy.linalg as LA
def spatial_smoothing_ess_ss(received_data, size_of_subarray):
    L = size_of_subarray
    N = received_data.shape[0]
    M = N - L + 1

    
    V = np.zeros((M, L), dtype = complex)
    for i in range(M):
        R_i = received_data[i:(i + L), :].copy()
        R_i = R_i @ R_i.conj().T / L
        eigen_values_i, eigen_vectors_i= LA.eig(R_i)
        index = np.flip(np.argsort(eigen_values_i))
        v_i = eigen_vectors_i[:, index][:, 0]

        V[i, :] = v_i

    write_protocol_data(CMD_INFO, f"VVVVVVVVVVVVVVVVVVV {V}")

    G = np.zeros((M, M, L, L), dtype = complex)
    G_bar = np.zeros((M, M, L, L), dtype = complex)

    for i in range(M):
        G_ii = np.reshape(V[i, :], (-1, 1)) @ np.reshape(V[i, :].conj(), (1, -1))
        G[i, i] = G_ii
        G_bar[i, i] = np.flip(G_ii).conj()
        for j in range(M):
            if i == j : continue

            G_ij = np.reshape(V[i, :], (-1, 1)) @ np.reshape(V[j, :].conj(), (1, -1))
            G_ij_bar = np.flip(G_ij).conj()

            G[i, j] = G_ij.copy()
            G_bar[i, j] = G_ij_bar.copy()
            # if i == j:
            #     G_ji = G_ij.copy()
            #     G_ji_bar = G_ij_bar.copy()
            # else:
            #     G_ji = V[j] @ V[i].conj().T
            #     G_ji_bar = np.flip(G_ji).conj()
            
            # G_ii 
    

    write_protocol_data(CMD_INFO, f"GGGGGGGGGGGGGGGGGGGGG {G}")
    
    R = np.zeros((L, L), dtype = complex)
    for i in range(M):
        for j in range(M):
            R += (G[i, j, :, :] @ G[j, i, :, :] + G_bar[i, j, :, :] @ G_bar[j, i, :, :]) + (G[i, i, :, :] @ G[j, j, :, :] + G_bar[i, i, :, :] @ G_bar[j, j, :, :] )

    R /= 2 * M
    return R