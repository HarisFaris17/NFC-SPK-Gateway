
from numpy import sin, cos, abs, pi, mean, std, sqrt


from aoa_constants import *

def eval_determiner_angles_xy_invalid(angles):
    determiner_value_pair = (sin(angles[0]) - cos(angles[1])) * (sin(angles[0]) + cos(angles[1]))
    return determiner_value_pair

def eval_determiner_two_angles_xy_invalid(angles1, angles2):
    determiner_value_pair1 = (sin(angles1[0]) - cos(angles1[1])) * (sin(angles1[0]) + cos(angles1[1]))
    determiner_value_pair2 = (sin(angles2[0]) - cos(angles2[1])) * (sin(angles2[0]) + cos(angles2[1]))

    return (determiner_value_pair1, determiner_value_pair2)

def eval_coordinates_two_angles(angles1, locator_idx1, angles2, locator_idx2):
    determiner_value_pair2 = eval_determiner_angles_xy_invalid(angles2)
    h = locator_distance_ref[locator_idx2][0] - locator_distance_ref[locator_idx1][0]
    k = locator_distance_ref[locator_idx2][1] - locator_distance_ref[locator_idx1][1]
    t = locator_distance_ref[locator_idx2][2] - locator_distance_ref[locator_idx1][2]

    if abs(h) >= MIN_LENGTH_SEPERATE_LOCATOR and abs(k) < MIN_LENGTH_SEPERATE_LOCATOR :
        hypotenuse1 = abs(h * sin(pi - angles2[0]) / sin(angles2[0] - angles1[0]))
        hypotenuse2 = abs(hypotenuse1 * sin(angles1[0]) / sin(angles2[0]))
    elif abs(k) >= MIN_LENGTH_SEPERATE_LOCATOR and abs(h) < MIN_LENGTH_SEPERATE_LOCATOR :
        hypotenuse1 = abs(h * sin(pi - angles2[1]) / sin(angles2[1] - angles1[1]))
        hypotenuse2 = abs(hypotenuse1 * sin(angles1[1]) / sin(angles2[1]))
    elif abs(k) >= MIN_LENGTH_SEPERATE_LOCATOR and  abs(h) >= MIN_LENGTH_SEPERATE_LOCATOR :
        hypotenuse2 = abs((k * cos(angles1[0]) - h * cos(angles1[1])) / (cos(angles2[0]) * cos(angles1[1]) - cos(angles2[1]) * cos(angles1[0])))

    x_2 = hypotenuse2 * cos(angles2[0])
    y_2 = hypotenuse2 * cos(angles2[1])
    z_2 = hypotenuse2 * sqrt(determiner_value_pair2)

    x_1 = x_2 + h
    y_1 = y_2 + k
    z_1 = z_2 + t

    x = x_1 + locator_distance_ref[locator_idx1][0]
    y = y_1 + locator_distance_ref[locator_idx1][1]
    z = z_1 + locator_distance_ref[locator_idx1][2]

    return (hypotenuse2, h, k, t, x_2, y_2, z_2, x_1, y_1, z_1, x, y, z)

def split_multipath(angles):
    splitted_angles = []

    standard_dev_angles = std(angles)
    if standard_dev_angles < MIN_STD_SPLIT_MULTIPATH :
        splitted_angles.append(angles)

    elif standard_dev_angles >= MIN_STD_SPLIT_MULTIPATH:
        angles_mean = mean(angles)
        greater_than_mean_angles = []
        lesser_than_mean_angles = []
        for angle in angles:
            if angle >= angles_mean : greater_than_mean_angles.append(angle)
            else : lesser_than_mean_angles.append(angle)

        splitted_angles.append(greater_than_mean_angles)
        splitted_angles.append(lesser_than_mean_angles)

    return splitted_angles
    
def mean_multipath_angles(angles):
    splitted_angles = split_multipath(angles)
    mean_splitted_angles = [mean(angles) for angles in splitted_angles]

    return mean_splitted_angles

def check_if_coord_make_sense(locator_idx1, locator_idx2, x1, x2, y1, y2):
    x_locator1 = locator_distance_ref[locator_idx1][0]
    x_locator2 = locator_distance_ref[locator_idx2][0]
    y_locator1 = locator_distance_ref[locator_idx1][1]
    y_locator2 = locator_distance_ref[locator_idx2][1]

    if abs(x_locator2 - x_locator1) >= MIN_LENGTH_SEPERATE_LOCATOR:
        if x_locator1 <= x_locator2 :
            if x2 >= 0 and x1 < 0 : return False
            else : return True
        else :
            if x1 >= 0 and x2 < 0 : return False
            else : return True
    
    if abs(y_locator2 - y_locator1) >= MIN_LENGTH_SEPERATE_LOCATOR:
        if y_locator1 <= y_locator2 :
            if y2 >= 0 and y1 < 0 : return False
            else : return True
        else :
            if y1 >= 0 and y2 < 0 : return False
            else : return True


def tweak_angle(angle, recipro_scaler = 6, ref = np.pi / 2):
    deviation = angle - ref
    return angle + (-1) * ((deviation))**2 / recipro_scaler * ((deviation) / np.abs(deviation))

def append_angle_to_angle_buffer(angle_buffer : dict, angle, locator_idx, mac):
    if mac not in angle_buffer:
        angle_buffer[mac] = {}

    if locator_idx not in angle_buffer[mac].keys():
        angle_buffer[mac][locator_idx] = []

    if (len(angle_buffer[mac][locator_idx]) > MAX_ANGLES_PER_MAC_PER_LOCATOR):
        angle_buffer[mac][locator_idx].pop(0)

    angle_buffer[mac][locator_idx].append(angle.copy())