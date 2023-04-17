#ifndef CONSTANTS_H
#define CONSTANTS_H

#define DEBUG_MODE
//#define ACTIVE_DROP_TABLE

#define TABLE_NAME_DEVICES                          "device"
//#define TABLE_NAME_DATA                             "data"
#define TABLE_NAME_DEVICES_LOCATION                 "device_location"
//#define TABLE_NAME_DATA_LOCATION                    "data_location"

#define SETTING_FILE                                "setting.ini"
#define LOCATOR_PARAMS_FILE                         "locator_params.ini"
#define RSSI_FILE                                   "rssi.ini"
#define GATEWAY_MAC_FILE                            "gateway_mac.ini"

#define INSTANTANEOUS_RSSI_FILE                     "/Test AoA/INSTANTANEOUS_RSSI_%1_%2.csv"

#define AOA_IQ_FILE                                        "/Test AoA/IQ_%1_LOCATOR%2.csv"
#define CONVENIENT_COORDINATES_PER_LOCATOR_FILE            "/Test AoA/CONVENIENT_COORDINATE_LOCATOR%1_%2_%3.csv"
#define CONVENIENT_COORDINATES_CUMULATIVE_FILE             "/Test AoA/CONVENIENT_COORDINATE_%1.csv"

#define AOA_ANGLES_FILE                                    "/Test AoA/AOA_ANGLES_LOCATOR%1_%2.csv"
#define AOA_COORD_TWO_lOCATORS_ELEMENTS_FILE               "/Test AoA/AOA_COORDINATE_ELEMENT_LOCATOR%1_LOCATOR%2_%3.csv"
#define AOA_COORD_LOCATOR_ELEMENTS_FILE                    "/Test AoA/AOA_COORDINATE_ELEMENT_LOCATOR%1_%2.csv"
#define AOA_COORD_CUMULATIVE_FILE                          "/Test AoA/AOA_COORDINATE_%1.csv"

#define CALCULATOR_DATA                                     "/Test AoA/CALCULATOR_DATA.txt"


#ifndef DEBUG_MODE
    #define AOA_CALCULATOR_PROCESS                  "/aoa_calculator_final/aoa_calculator_final.exe"
#else
    #define PYTHON                                  "python"
    #define AOA_CALCULATOR_SCRIPT                   "aoa_calculator_final_py/aoa_calculator_final.py"
#endif

#define LOCATOR_IDX_OF_CUMULATIVE_DATA              -1

#define WIDTH_FIELD                                 100                 // m
#define HEIGHT_FIELD                                50                  // m

#define DEFAULT_WIDTH_WINDOW_COORDINATE                 0.9
#define DEFAULT_HEIGHT_WINDOW_COORDINATE                0.9

#define MINIMUM_WIDTH_WINDOW_COORDINATE                 0.7
#define MINIMUM_HEIGHT_WINDOW_COORDINATE                0.7

#define BEACON_POINT_RADIUS                             5
#define LOCATOR_POINT_RADIUS                            4

#define GRID_Y_SIZE                                     10
#define GRID_X_SIZE                                     20

#define AOA_PRIORITY_OVER_CONVENIENT
#define SINGLE_OVER_TWO_LOCATORS

#define DEFAULT_GATEWAY_1_MAC                           "AC233FC0CD2A"
#define DEFAULT_GATEWAY_2_MAC                           "AAAAAAAAAAAA"

#endif // CONSTANTS_H
