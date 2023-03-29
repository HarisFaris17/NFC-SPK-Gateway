import numpy as np

ENABLE_LOG_FILE = True

CALCULATE_ANGLE_WITH_MUSIC = True
MUSIC_WITH_SPATIAL_SMOOTHING = True
CALCULATE_COORDINATES_WITH_AOA_ONLY = True

MAX_BATCH_COUNT_TO_RESET = 5
MAX_ANGLES_PER_MAC_PER_LOCATOR = 10

MIN_BATCH_COUNT_SINGLE_LOCATOR_CONVENIENT = 5

CMD_ERROR = "ERROR"
CMD_OK = "OK"
CMD_INFO = "INFO"

CMD_RECV_DATA = "DATA"
CMD_RECV_SET = "SET"

SET_RSSI_TYPE = "RSSI"
SET_LOCATOR_PARAMS_TYPE = "LOCATOR"

CONVENIENT_METHOD = "CONVENIENT"
AOA_METHOD = "AOA"

PER_LOCATOR_DATA = "LOCATOR"
CUMULATIVE_DATA = "CUMULATIVE"

COORD_MEAN_TYPE = "COORD_MEAN_TYPE"
COORD_ELEMENT_TYPE = "COORD_ELEMENT_TYPE"

ANGLES_AOA = "ANGLE"
COORD_AOA = "COORD"

# COORD_AOA_TWO_LOCATORS_TYPE = "COORD_TWO_LOCATORS_TYPE"

LOCATOR_PARAMS_FILE = r"/../locator_params.ini"
RSSI_FILE = r"/../rssi.ini"

MUSIC_FILE = r"/../Test AoA/MUSIC.csv"
MUSIC_2_FILE = r"/../Test AoA/MUSIC_2.csv"
MUSIC_SMOOTHING_FILE = r"/../Test AoA/MUSIC_SMOOTHING.csv"
MUSIC_MULTIPLE_ANGLE_FILE = r"/../Test AoA/_MULTIPLE_ANGLE_MUSIC_SMOOTHING.csv"
ESPRIT_ANGLE_FILE = r"/../Test AoA/ESPRIT_ANGLE_FILE.csv"
TLS_ESPRIT_ANGLE_FILE = r"/../Test AoA/TLS_ESPRIT_ANGLE_FILE.csv"
MUSIC_2D = r"/../Test AoA/MUSIC_2D.csv"
MUSIC_L_SHAPED = r"/../Test AoA/MUSIC_L_SHAPED.csv"
ROOT_MUSIC_FILE = r"/../Test AoA/ROOT_MUSIC.csv"

MUSIC_CUMUL_DIFF_PHASE_FILE = r"/../Test AoA/MUSIC_CUMUL_DIFF_PHASE_FILE.csv"
MUSIC_2_CUMUL_DIFF_PHASE_FILE = r"/../Test AoA/MUSIC_2_CUMUL_DIFF_PHASE_FILE.csv"
ESPRIT_CUMUL_DIFF_PHASE_FILE = r"/../Test AoA/ESPRIT_DIFF_PHASE_FILE.csv"

LOG_FILE = r"/../Test AoA/aoa_calculator.log"

DISTANCE_ESTIMATOR_FILE = r"/../distance_estimator/distance_estimator.joblib"

PRINT_INFO_ENABLED = True
PRINT_OK_ENABLED = True
PRINT_ERROR_ENABLED = True

MM = 10**-3
CM = 10**-2
M = 10**0

GHZ = 10**9
MHZ = 10**6

F_SAMPLING = 1 * MHZ
T_SAMPLING = 1/F_SAMPLING # 1us

ANGLE_UPPER_BOUND = 2.81799
ANGLE_LOWER_BOUND = 0.32359

APPLY_ANGLE_TWEAK = True

T_SAMPLING_SLOT_SPACE = 2
T_SWITCH_SLOT_SPACE = 2
NUMBER_OF_REFERENCE_IQ = 8

MAX_COORDS_PER_LOCATOR_PER_MAC = 15
MIN_COORDS_PER_LOCATOR_PER_MAC = 5

MIN_AOA_COORDS_FILTER_OUTLIERS = 5
MIN_AOA_ANGLES_FILTER_OUTLIERS = 5

MAX_STD_EXACT_COORD = 0.5
MAX_STD_SECTION_COORD = 1.5

MAX_DISTANCE_PER_AXIS = 30 * M

FREQ_CARRIER = 2402 * MHZ

d = 50 * MM
dx = d #cm
dy = d #cm

ANT_12 = 0
ANT_11 = 2
ANT_10 = 1

ANT_3 = 4
ANT_1 = 5
ANT_2 = 6

ANT_6 = 8
ANT_4 = 9
ANT_5 = 10

ANT_9 = 12
ANT_7 = 13
ANT_8 = 14

antenna_pos = np.zeros((15, 2))
# ANT_11 as reference in distance
antenna_pos[ANT_1] =  [2*dx, 0*dy]
antenna_pos[ANT_2] =  [3*dx, 0*dy]
antenna_pos[ANT_3] =  [3*dx, 1*dy]
antenna_pos[ANT_4] =  [3*dx, 2*dy]
antenna_pos[ANT_5] =  [3*dx, 3*dy]
antenna_pos[ANT_6] =  [2*dx, 3*dy]
antenna_pos[ANT_7] =  [1*dx, 3*dy]
antenna_pos[ANT_8] =  [0*dx, 3*dy]
antenna_pos[ANT_9] =  [0*dx, 2*dy]
antenna_pos[ANT_10] = [0*dx, 1*dy]
antenna_pos[ANT_11] = [0*dx, 0*dy]
antenna_pos[ANT_12] = [1*dx, 0*dy]


reference_sampling_antenna = ANT_5
# switch_pattern = [ANT_12, ANT_10]
switch_pattern_x = [ANT_12, ANT_1, ANT_2]
switch_pattern_y = [ANT_10, ANT_9, ANT_8]

SIZE_OF_ANT_ARRAY = 4
SIZE_OF_SUBARRAY = SIZE_OF_ANT_ARRAY - 2

NUM_OF_AXIS = 2

RSSI_1M = -40
N = 2.4
R = 62.46761

# Z = 8.4 * M

PROTOCOL_DATA = "{command}\n{body}"
# BODY_DISTANCE_PER_LOCATOR = "DISTANCE\n{mac} {locator_idx} {rssi}"
BODY_CONVENIENT_COORD_PER_LOCATOR  = "CONVENIENT\nLOCATOR\n{data_type}\n{mac} {ar1_idx} {coordinates_x} {coordinates_y} {coordinates_z}"
BODY_CONVENIENT_COORD_CUMULATIVE   = "CONVENIENT\nCUMULATIVE\n{mac} {coordinates_x} {coordinates_y} {coordinates_z}"

BODY_AOA_ANGLES = "AOA\nANGLES\n{mac} {ar1_idx} {angle_x} {angle_y}"
BODY_AOA_COORD_TWO_LOCATORS_ELEMENT_TYPE = "AOA\nCOORD\nTWO_LOCATOR\n{mac} {locator_1},{locator_2} {x_1},{y_1},{z_1} {x_2},{y_2},{z_2}"
BODY_AOA_COORD_SINGLE_LOCATOR_ELEMENT_TYPE = "AOA\nCOORD\nLOCATOR\n{mac} {locator} {x},{y},{z}"

BODY_AOA_COORD_CUMULATIVE = "AOA\nCOORD\nCUMULATIVE\n{mac} {x} {y} {z}"

locator_ref = 0
locator_distance_ref = [[0, 0, 8.4], [3, 0, 8.4], [6, 0, 8.4], [9, 0, 8.4]]

NUM_OF_OFFLINE_GENERATIONS = 50
NUM_OF_PARENTS_MATING = 4
SOL_PER_POP = 5

Q3 = 0.63
Q1 = 0.25
C1 = 0.
C2 = 0.5

MIN_LENGTH_SEPERATE_LOCATOR = 0.5

MIN_STD_SPLIT_MULTIPATH = 0.4

MAX_ESPRIT_TO_MEAN = 0.3

MAX_IQS_BUNDLE = 60



