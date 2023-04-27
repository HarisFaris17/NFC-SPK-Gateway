import numpy as np
from sklearn import svm
from joblib import load
from pyargus.directionEstimation import *
from itertools import combinations

from aoa_constants import *
from aoa_phase_calculator import *
from aoa_kalman import *
from aoa_angles_method_2d import *

import types 


import threading, signal, sys, traceback, os, time

def send_kill_signal(etype : type[BaseException], value : BaseException, tb : types.TracebackType):
    body_error = "Process will be killed\n {etype} {value} {tb}".format(etype = etype, value = value, tb = tb)
    write_protocol_data(command = CMD_ERROR, body = body_error)
    traceback.print_exception(etype, value, tb)
    if ENABLE_LOG_FILE : traceback.print_exception(etype, value, tb, file = file)
    file.flush()
    sys.stdout.flush()
    time.sleep(1)
    os.kill(os.getpid(), signal.SIGINT)

original_thread_init = threading.Thread.__init__
def patched_init(self, *args, **kwargs):
    original_thread_init(self, *args, **kwargs)
    original_thread_run = self.run
    def patched_run(*args, **kw):
        try:
            original_thread_run(*args, **kw)
        except:
            sys.excepthook(*sys.exc_info())
    self.run = patched_run

sys.excepthook = send_kill_signal
threading.Thread.__init__ = patched_init

from aoa_communication import *

from queue import Queue

buffered_data = Queue()
buffered_out = Queue()

import sys

from numpy import std, cos, sin, sqrt, absolute
from math import log10

np.set_printoptions(linewidth = 50000)

from threading import Thread 

thread_input = Thread(target = get_input_data, args = (buffered_data, ))
thread_input.start()

thread_out = Thread(target = write_out_data, args = (buffered_out, ))
thread_out.start()

try:
    locator_params_file = open(os.path.dirname(__file__) + LOCATOR_PARAMS_FILE, mode = "r")
    locator_params_raw = locator_params_file.read()
    locator_config = locator_params_raw.split("\n")
    if (len(locator_config) == 8) :
        # locator_ref = eval(locator_config[0])
        for locator_idx, locator_to_ref in enumerate(locator_config) :
            locator_coordinate_to_ref = locator_to_ref.split(",")

            # the locator params doesn't have 3 coordinates relative distance to reference locator
            if (len(locator_coordinate_to_ref) != 3) : continue

            locator_distance_ref[locator_idx] = [eval(locator_coord) for locator_coord in locator_coordinate_to_ref]

        body_info = "Locator configuration from config file {locator_distance_ref}".format(locator_distance_ref = locator_distance_ref)
        write_protocol_data(command = CMD_INFO, body = body_info)
    else :
        body_error = "Error reading locator configuration"
        write_protocol_data(command = CMD_ERROR, body = body_error)
    locator_params_file.close()
except:
    body_error = "Locator parameters file failed to be opened"
    write_protocol_data(command = CMD_ERROR, body = body_error)


try:
    rssi_file = open(os.path.dirname(__file__) + RSSI_FILE, mode = "r")

    rssi_config_raw = rssi_file.read()
    rssi_config = rssi_config_raw.split("\n")
    if (len(rssi_config) == 2) :
        rssi_1m = eval(rssi_config[0])
        rssi_2m = eval(rssi_config[1])

        print(rssi_1m, rssi_2m)

        RSSI_1M = rssi_1m
        R = calculate_R(rssi_1m, rssi_2m)
        body_info = "RSSI configuration from config file RSSI_1M = {RSSI_1M}, R = {R}".format(RSSI_1M = RSSI_1M, R = R)
        write_protocol_data(command = CMD_INFO, body = body_info)
    else :
        body_error = "Error reading RSSI config"
        write_protocol_data(command = CMD_ERROR, body = body_error)
    # rssi_file.close()
except:
    body_error = "RSSI file failed to be opened or read the RSSIs"
    write_protocol_data(command = CMD_ERROR, body = body_error)


from aoa_angles_method import *

angle_buffer = {}
# coordinates_buffer = {}
# batch count after each locator per mac not receiving new angles
batch_count = {}

# count how many batch the angles of each mac only received by one locator
single_locator_catched_count = {}

# 
timer_buffer = {}

location_buffer_aoa = dict()


new_angles_from_waiting_per_batch_queue = Queue()

angles_aoa_cumulative_waiting_queue = Queue()

location_waiting_queue = Queue()

new_angles_to_calculated_per_locator_queue = Queue()

thread_location_calculator_aoa = Thread(target = location_aoa_calculator, args = (new_angles_from_waiting_per_batch_queue, angles_aoa_cumulative_waiting_queue, location_waiting_queue, new_angles_to_calculated_per_locator_queue, angle_buffer, batch_count, single_locator_catched_count, location_buffer_aoa))
thread_location_calculator_aoa.start()
############################################################
location_buffer = dict()

from aoa_convenient_method import *

if CALCULATE_COORDINATES_WITH_AOA_ONLY:
    thread_cumulative_convenient_location_calculator = Thread(target = location_cumulative_convenient_calculator, args = (location_waiting_queue, location_buffer))
    thread_cumulative_convenient_location_calculator.start()


############################################################
if CALCULATE_COORDINATES_WITH_AOA_ONLY:
    new_angle_convenient_queue = Queue()
    thread_convenient_location_calculator = Thread(target = location_convenient_calculator, args = (new_angle_convenient_queue, location_waiting_queue, location_buffer))
    thread_convenient_location_calculator.start()


############################################################ the purpose of this function is to calculate the cumulative location of certain mac but unlike the function above, this function uses the angles not coordinates

thread_aoa_location_calculator2 = Thread(target = location_cumulative_aoa_calculator2, args=(angles_aoa_cumulative_waiting_queue, angle_buffer))
thread_aoa_location_calculator2.start()

############################################################

thread_aoa_calculator_single_locator = Thread(target = location_aoa_calculator_single_locator, args = (new_angles_to_calculated_per_locator_queue, angle_buffer))
thread_aoa_calculator_single_locator.start()


############################################################
diff_phase_buffer = dict()
mag_buffer = dict()
new_angles_cumul_phase_diff_cumul_angle_buffer_queue = Queue()
new_angles_to_calculated_cumul_phase_diff_per_locator_queue = Queue()
if CALCULATOR_ANGLE_BUFFER == MUSIC_CALCULATOR : thread_location_aoa_calculator_cumul_phase_diff_single_locator_music = Thread(target = location_aoa_calculator_cumul_phase_diff_single_locator_music_extended, args = (new_angles_to_calculated_cumul_phase_diff_per_locator_queue, diff_phase_buffer, mag_buffer, angle_buffer, new_angles_cumul_phase_diff_cumul_angle_buffer_queue))
else : thread_location_aoa_calculator_cumul_phase_diff_single_locator_music = Thread(target = location_aoa_calculator_cumul_phase_diff_single_locator_music, args = (new_angles_to_calculated_cumul_phase_diff_per_locator_queue, diff_phase_buffer, mag_buffer, ))
thread_location_aoa_calculator_cumul_phase_diff_single_locator_music.start()

############################################################
new_angles_to_calculated_cumul_phase_diff_per_locator_esprit_queue = Queue()
if CALCULATOR_ANGLE_BUFFER == ESPRIT_CALCULATOR : thread_location_aoa_calculator_cumul_phase_diff_single_locator_esprit = Thread(target = location_aoa_calculator_cumul_phase_diff_single_locator_esprit_extended, args = (new_angles_to_calculated_cumul_phase_diff_per_locator_esprit_queue, diff_phase_buffer, mag_buffer, angle_buffer, new_angles_cumul_phase_diff_cumul_angle_buffer_queue))
else : thread_location_aoa_calculator_cumul_phase_diff_single_locator_esprit = Thread(target = location_aoa_calculator_cumul_phase_diff_single_locator_esprit, args = (new_angles_to_calculated_cumul_phase_diff_per_locator_esprit_queue, diff_phase_buffer, mag_buffer))
thread_location_aoa_calculator_cumul_phase_diff_single_locator_esprit.start()

############################################################
new_angles_cumul_phase_diff_multiple_locator_queue = Queue()
thread_location_aoa_calculator_cumul_phase_diff_multiple_locator = Thread(target = location_aoa_calculator_cumul_phase_diff_multiple_locator, args = (new_angles_cumul_phase_diff_multiple_locator_queue, diff_phase_buffer, mag_buffer))
thread_location_aoa_calculator_cumul_phase_diff_multiple_locator.start()

############################################################
new_angles_L_shaped_cumul_phase_diff = Queue()
thread_location_aoa_calculator_L_shaped_cumul_phase_diff = Thread(target = location_aoa_calculator_L_shaped_cumul_phase_diff, args = (new_angles_L_shaped_cumul_phase_diff, diff_phase_buffer, mag_buffer))
thread_location_aoa_calculator_L_shaped_cumul_phase_diff.start()

###########################################################
thread_location_aoa_calculator_cumul_phase_diff_cumul_angle_buffer = Thread(target = location_aoa_calculator_cumul_phase_diff_cumul_angle_buffer, args = (new_angles_cumul_phase_diff_cumul_angle_buffer_queue, angle_buffer))
thread_location_aoa_calculator_cumul_phase_diff_cumul_angle_buffer.start()

###########################################################
new_angles_2d = Queue()
thread_music_2d = Thread(target = music_2d, args = (new_angles_2d, diff_phase_buffer, mag_buffer))
thread_music_2d.start()

############################################################
def delete_buffers(mac, locator_idx):
    write_protocol_data(CMD_INFO, f"DELETINGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG {mac} {locator_idx}")
    if mac in diff_phase_buffer.keys():
        if locator_idx in diff_phase_buffer[mac].keys():
            del diff_phase_buffer[mac][locator_idx]
            if not MODE_12_ANT : del angle_buffer[mac][locator_idx]
            del batch_count[mac][locator_idx]

def new_or_update_timer(mac, locator_idx):
    if mac in timer_buffer.keys():
        if locator_idx in timer_buffer[mac]:
            timer_buffer[mac][locator_idx].cancel()

    timer = threading.Timer(TIMEOUT_DIFF_PHASE_DELETION, delete_buffers, args = (mac, locator_idx))
    timer.start()
    timer_buffer[mac][locator_idx] = timer


music_file = open(os.path.dirname(__file__) + MUSIC_FILE, mode = "a")
music_2_file = open(os.path.dirname(__file__) + MUSIC_2_FILE, mode = "a")
music_smoothing_file = open(os.path.dirname(__file__) + MUSIC_SMOOTHING_FILE, mode = "a")
def sub_main_thread(buffered_data):
    while (True):

        arguments = buffered_data.get()

        splitted_arguments = arguments.split(" ")

        command = splitted_arguments[0]
        if command == CMD_RECV_SET:
            body_info = "The command is SET"
            write_protocol_data(command = CMD_INFO, body = body_info)

            set_type = splitted_arguments[1]
            if (set_type == "RSSI"):
                if len(splitted_arguments) != 4 : 
                    body = "The arguments in SET command and RSSI type should be no more or less than 4"
                    # print(PROTOCOL_DATA.format(command = CMD_ERROR, body = body))
                    write_protocol_data(command = CMD_ERROR, body = body)
                    continue

                rssi_1m = eval(splitted_arguments[2])
                rssi_2m = eval(splitted_arguments[3])

                R = calculate_R(rssi_1m, rssi_2m)
                RSSI_1M = rssi_1m

                body_info = "Calibration succedd.\nRSSI 1 m : {rssi_1m} \nRSSI 2 m : {rssi_2m}\nR : {R}".format(rssi_1m = rssi_1m, rssi_2m = rssi_2m, R = R)
                # print(PROTOCOL_DATA.format(command = CMD_INFO, body = body_info))
                write_protocol_data(command = CMD_INFO, body = body_info)

            elif (set_type == "LOCATOR") :
                if (len(splitted_arguments) != 10) :
                    body_error = "The arguments in SET command and LOCATOR type should be no more or less than 7"
                    write_protocol_data(command = CMD_ERROR, body = body_error)
                    continue

                # locator_ref = eval(splitted_arguments[2])
                for locator_idx, locator_to_ref in enumerate(splitted_arguments[2:]) :
                    locator_coordinate_to_ref = locator_to_ref.split(",")

                    # the locator params doesn't have 3 coordinates relative distance to reference locator
                    if (len(locator_coordinate_to_ref) != 3) : continue

                    locator_distance_ref[locator_idx] = [eval(locator_coord) for locator_coord in locator_coordinate_to_ref]

                body_info = "Locator parameters set {locator_distance_ref}".format(locator_distance_ref = locator_distance_ref)
                write_protocol_data(command = CMD_INFO, body = body_info)

            elif (set_type == "Z") :
                if (len(splitted_arguments) != 3) :
                    body_error = f"To set the z value, the arguments should be no more or less than 3"
                    write_protocol_data(CMD_ERROR, body_error)
                
                try:
                    Z = eval(splitted_arguments[2])
                except:
                    body_error = f"The z value should be number"
                    write_protocol_data(CMD_ERROR, body_error)

            else :
                body_error = "SET type unrecognized"
                write_protocol_data(command = CMD_INFO, body = body_error)

        elif command == CMD_RECV_DATA:
            if (len(splitted_arguments)-1) %5 != 0 and (len(splitted_arguments)-1) == 0: 
                body_error = "The lenght arguments in DATA command should be multiply of 5 plus 1 and the data shouldn't be empty"
                write_protocol_data(command = CMD_ERROR, body = body_error)
                continue

            
            new_angle_queue = {}
            new_angle_convenient = {}
            for i in range(int((len(splitted_arguments)-1) / 5)):
                freq_carrier = eval(splitted_arguments[1 + i * 5]) * MHZ
                # if freq_carrier <= 2460 * MHZ : continue
                rssi = eval(splitted_arguments[2 + i * 5])
                mac = splitted_arguments[3 + i * 5]
                locator_idx = eval(splitted_arguments[4 + i * 5])
                iq_str = splitted_arguments[5 + i * 5].split(",")
                iq = np.array([eval(i) for i in iq_str])
                distance = calculate_distance(rssi)



                body_info = f"Freq carrier : {freq_carrier}\nrssi : {rssi}\nmac : {mac}\nLocator index : {locator_idx}\ndistance : {distance}\nIQ : {iq}"
                write_protocol_data(command = CMD_INFO, body = body_info)

                mag_phase = calc_mag_phase(iq)
                # phase_array = calc_mag_phase(iq)[:,1].flatten()
                phase_array = mag_phase[:,1].flatten()
                mag_array =  mag_phase[:, 0].flatten()
                reference_phase_array = phase_array[:NUMBER_OF_REFERENCE_IQ]
                actual_phase_array = phase_array[NUMBER_OF_REFERENCE_IQ:]
                actual_mag_array = mag_array[NUMBER_OF_REFERENCE_IQ:]

                # body_info = "Phase Array {phase_array}".format(phase_array = phase_array)
                # write_protocol_data(command = CMD_INFO, body = body_info)

                # body_info = "Reference phase {reference_phase_array}".format(reference_phase_array = reference_phase_array)
                # write_protocol_data(command = CMD_INFO, body = body_info)

                # body_info = "Actual Phase array {actual_phase_array}".format(actual_phase_array = actual_phase_array)
                # write_protocol_data(command = CMD_INFO, body = body_info)

                if USE_NLS_PHASE_DIFF:
                    phase_diff_mean = calculate_phase_diff_reference_2(iq[:2 * NUMBER_OF_REFERENCE_IQ:2], iq[1 : 2 * NUMBER_OF_REFERENCE_IQ + 1 : 2])
                    if phase_diff_mean < np.pi/2 - 0.2 or phase_diff_mean > np.pi/2 + 0.2 :
                        phase_diff_array = calculate_phase_diff_reference(reference_phase_array)
                        phase_diff_mean = np.mean(phase_diff_array)
                else:
                    phase_diff_array = calculate_phase_diff_reference(reference_phase_array)
                    phase_diff_mean = np.mean(phase_diff_array)

                    freq_offset_array = calculate_freq_offset(phase_diff_array)
                    # write_protocol_data(CMD_INFO, f"Frequency Offset Array {freq_offset_array}")

                    freq_offset_mean = np.mean(freq_offset_array)
                    # write_protocol_data(CMD_INFO, f"Frequency Offset Mean {freq_offset_mean}")

                    freq = freq_carrier + freq_offset_mean
                    wave_length = speed_of_light / freq
                    write_protocol_data(CMD_INFO, f"Wave length {wave_length}")

                body_info = "Phase Difference Mean {phase_diff_mean}".format(phase_diff_mean = phase_diff_mean)
                write_protocol_data(command = CMD_INFO, body = body_info)

                if mac not in diff_phase_buffer:
                    diff_phase_buffer[mac] = dict()
                    mag_buffer[mac] = dict()

                if MODE_12_ANT:
                    diff_phase = diff_actual_to_predict_phase_12_ant_mode(phase_array, phase_diff_mean)
                    reshaped_mag = mag_reshape_12_ant_mode(mag_array)

                    if locator_idx not in diff_phase_buffer[mac]:
                        diff_phase_buffer[mac][locator_idx] = diff_phase
                        mag_buffer[mac][locator_idx] = reshaped_mag
                    else:
                        num_of_IQs_per_axis_per_locator_per_batch = diff_phase.shape[1]
                        num_of_IQs = diff_phase_buffer[mac][locator_idx].shape[1]

                        write_protocol_data(CMD_INFO, f"Num of diff phase and magnitude of mac {mac} and locator {locator_idx} : {num_of_IQs}, {num_of_IQs_per_axis_per_locator_per_batch}")
                            
                        if num_of_IQs / num_of_IQs_per_axis_per_locator_per_batch > MAX_IQS_BUNDLE:
                            diff_phase_buffer[mac][locator_idx] = np.delete(diff_phase_buffer[mac][locator_idx], np.s_[:num_of_IQs_per_axis_per_locator_per_batch], axis = 1)
                            mag_buffer[mac][locator_idx] = np.delete(mag_buffer[mac][locator_idx], np.s_[:num_of_IQs_per_axis_per_locator_per_batch], axis = 1)
                        diff_phase_buffer[mac][locator_idx] = np.append(diff_phase_buffer[mac][locator_idx], diff_phase, axis = 1)
                        mag_buffer[mac][locator_idx] = np.append(mag_buffer[mac][locator_idx], reshaped_mag, axis = 1)

                else :
                    diff_phase = diff_actual_to_predict_phase_splitted_2(phase_array, phase_diff_mean)
                    reshaped_mag = mag_reshape(mag_array)
                    write_protocol_data(CMD_INFO, f"diff phase {diff_phase}")

                    if locator_idx not in diff_phase_buffer[mac]:
                        diff_phase_buffer[mac][locator_idx] = diff_phase
                        mag_buffer[mac][locator_idx] = reshaped_mag
                    else:
                        num_of_IQs_per_axis_per_locator_per_batch = diff_phase.shape[2]
                        num_of_IQs = diff_phase_buffer[mac][locator_idx].shape[2]

                        write_protocol_data(CMD_INFO, f"Num of diff phase and magnitude of mac {mac} and locator {locator_idx} : {num_of_IQs}, {num_of_IQs_per_axis_per_locator_per_batch}")
                            
                        if num_of_IQs / num_of_IQs_per_axis_per_locator_per_batch > MAX_IQS_BUNDLE:
                            diff_phase_buffer[mac][locator_idx] = np.delete(diff_phase_buffer[mac][locator_idx], np.s_[:num_of_IQs_per_axis_per_locator_per_batch], axis = 2)
                            mag_buffer[mac][locator_idx] = np.delete(mag_buffer[mac][locator_idx], np.s_[:num_of_IQs_per_axis_per_locator_per_batch], axis = 2)
                        diff_phase_buffer[mac][locator_idx] = np.append(diff_phase_buffer[mac][locator_idx], diff_phase, axis = 2)
                        mag_buffer[mac][locator_idx] = np.append(mag_buffer[mac][locator_idx], reshaped_mag, axis = 2)

                if mac not in new_angle_queue:
                    # set (himpunan in bahasa) all the locator that involved in catching certain mac in this batch
                    new_angle_queue[mac] = set()
                new_angle_queue[mac].add(locator_idx)

                if not CALCULATE_ONLY_CUMUL_PHASE_DIFF:
                    angle_elevation_music = np.zeros(NUM_OF_AXIS, float64)
                    angle_elevation_music_smoothing = np.zeros(NUM_OF_AXIS, float64)
                    angle_elevation = np.zeros(NUM_OF_AXIS, float64)
                    continue_to_process = True
                    num_iq_sets_per_axis_per_array = diff_phase.shape[2]
                    for axis in range(NUM_OF_AXIS):
                        diff_phase_per_axis = diff_phase[axis]
                        reshaped_mag_per_axis = reshaped_mag[axis]

                        received_data = np.zeros((SIZE_OF_ANT_ARRAY, num_iq_sets_per_axis_per_array), dtype = complex)
                        received_data_2 = np.zeros((SIZE_OF_ANT_ARRAY, num_iq_sets_per_axis_per_array), dtype = complex)
                        
                        # representing phase difference to antenna reference, which means has a phaes difference 0 to reference
                        for ant in range(SIZE_OF_ANT_ARRAY):
                            received_data[ant, :] = [np.exp(1j * diff_phase_element) for diff_phase_element in diff_phase_per_axis[ant]]
                            received_data_2[ant, :] = [mag_element * np.exp(1j * diff_phase_element) for mag_element, diff_phase_element in zip(reshaped_mag_per_axis[ant], diff_phase_per_axis[ant])]

                        # if MUSIC_WITH_SPATIAL_SMOOTHING:
                        # calculated_angle = calculate_angle_music_spatial_smoothing(received_data, wave_length)
                        calculated_angle_music_smoothing = calculate_angle_music_spatial_smoothing(received_data, wave_length, axis)

                        if calculated_angle_music_smoothing == -1 : 
                            # write_protocol_data(CMD_INFO, f"Calculated angle using Spatial Smoothing MUSIC algorith {calculated_angle}")
                            error = "Failed to calculate music smoothing"
                            continue_to_process = False
                            break
                        
                            
                        calculated_angle_esprit = calculate_angle_tls_esprit(received_data_2, wave_length, axis)
                        write_protocol_data(CMD_INFO, f"ESPRIT axis {'X' if axis == 0 else 'Y'} : {calculated_angle_esprit}")
                        # else :
                        # calculated_angle = calculate_angle_music(received_data, wave_length)
                        calculated_angle_music = calculate_angle_music(received_data, wave_length)
                        calculated_angle_music_2 = calculate_angle_music(received_data_2, wave_length)
                        write_protocol_data(CMD_INFO, f"Music 2 : {calculated_angle_music_2}")
                        print(f"Axis {axis} : {calculated_angle_music_2}", file = music_2_file, flush = True)
                        if calculated_angle_music == -1 : 
                            break
                            # write_protocol_data(CMD_INFO, f"Calculated angle using Spatial Smoothing MUSIC algorith {calculated_angle}")
                        angle_elevation_music[axis] = calculated_angle_music

                        calculated_angle = calculated_angle_music
                        if calculated_angle <= 0.1 or calculated_angle >= np.pi - 0.1:
                            if mac in angle_buffer :
                                if locator_idx in angle_buffer[mac]:
                                    backward_average = np.mean(angle_buffer[mac][locator_idx], axis = 0)[axis]
                                    if np.abs(calculated_angle_esprit - backward_average) <= np.abs(calculated_angle - backward_average):
                                        
                                        if np.abs(calculated_angle_esprit - backward_average) <= MAX_ESPRIT_TO_MEAN: calculated_angle = calculated_angle_esprit
                                else:
                                    calculated_angle = calculated_angle_esprit
                            else:
                                calculated_angle = calculated_angle_esprit
                            
                        angle_elevation[axis] = calculated_angle
                        angle_elevation_music_smoothing[axis] = calculated_angle_music_smoothing

                    print(f"{angle_elevation_music}", file = music_file, flush= True)
                    print(f"{angle_elevation_music_smoothing}", file = music_smoothing_file, flush= True)
                    
                    if not continue_to_process : 
                        write_protocol_data(command = CMD_ERROR, body = error)
                        continue

                    write_protocol_data(CMD_INFO, f"Angle elevation of mac {mac} in locator {locator_idx} in rad is {angle_elevation}")
                    write_protocol_data(CMD_OK, BODY_AOA_ANGLES.format(mac = mac, ar1_idx = locator_idx, angle_x = angle_elevation[0], angle_y = angle_elevation[1]))

                    determiner_value = (sin(angle_elevation[1]) - cos(angle_elevation[0])) * (sin(angle_elevation[1]) + cos(angle_elevation[0]))
                    if (determiner_value < 0) : continue

                    if mac not in angle_buffer:
                        angle_buffer[mac] = {}
                    
                    if locator_idx not in angle_buffer[mac].keys():
                        angle_buffer[mac][locator_idx] = []

                    if (len(angle_buffer[mac][locator_idx]) > MAX_ANGLES_PER_MAC_PER_LOCATOR):
                        angle_buffer[mac][locator_idx].pop(0)

                    angle_buffer[mac][locator_idx].append(angle_elevation.copy())
                    write_protocol_data(CMD_INFO, f"Angle buffer {angle_buffer}")

                # current_state = filter_with_kalman(mac, locator_idx, angle_elevation)
                # write_protocol_data(CMD_INFO, f"Current state of mac {mac} and locator {locator_idx} is {current_state}")
                    if CALCULATE_COORDINATES_WITH_AOA_ONLY:
                        continue
                    

                    new_angle_convenient["distance"] = distance
                    new_angle_convenient["angle"] = angle_elevation
                    new_angle_convenient["mac"] = mac
                    new_angle_convenient["locator_idx"] = locator_idx

                    new_angle_convenient_queue.put(new_angle_convenient)

            for mac in batch_count.keys():
                for locator_idx in batch_count[mac].keys():
                    batch_count[mac][locator_idx] += 1

            for (mac, locator_idx_set) in new_angle_queue.items():
                if mac not in batch_count: 
                    batch_count[mac] = {}
                    timer_buffer[mac] = {}
                for locator_idx in locator_idx_set:
                    batch_count[mac][locator_idx] = 0
                    new_or_update_timer(mac, locator_idx)

            list_delete = {}
            for mac in batch_count.keys():
                for locator_idx in batch_count[mac].keys():
                    if batch_count[mac][locator_idx] >= MAX_BATCH_COUNT_TO_RESET:
                        if mac not in list_delete:
                            list_delete[mac] = []
                        list_delete[mac].append(locator_idx)
            
            for mac in list_delete:
                for locator_idx in list_delete[mac]:
                    del batch_count[mac][locator_idx]
                    del angle_buffer[mac][locator_idx]
                    del diff_phase_buffer[mac][locator_idx]

            write_protocol_data(CMD_INFO, f"Current angle buffer {angle_buffer}, current batch count {batch_count}")
            write_protocol_data(CMD_INFO, f"New angle from {new_angle_queue}")

            if MODE_12_ANT:
                new_angles_2d.put(new_angle_queue)
            else :
                # new_angles_from_waiting_per_batch_queue.put(new_angle_queue) 
                new_angles_to_calculated_cumul_phase_diff_per_locator_queue.put(new_angle_queue)
                new_angles_to_calculated_cumul_phase_diff_per_locator_esprit_queue.put(new_angle_queue)     
                new_angles_cumul_phase_diff_multiple_locator_queue.put(new_angle_queue) 
                new_angles_L_shaped_cumul_phase_diff.put(new_angle_queue)

        else :
            body_error = "The command doesn't recognized"
            write_protocol_data(command = CMD_ERROR, body = body_error)

thread_sub_main_thread = Thread(target = sub_main_thread, args = (buffered_data, ))
thread_sub_main_thread.start()

thread_sub_main_thread.join()
thread_input.join()