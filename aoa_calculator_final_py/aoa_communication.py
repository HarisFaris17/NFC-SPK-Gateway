from queue import Queue

from sys import stdout as out
from sys import stderr as err

from aoa_constants import *

import os

buffered_data = Queue()
buffered_out = Queue()

if (ENABLE_LOG_FILE) : 
    log_file = os.path.dirname(__file__) + LOG_FILE
    file = open(log_file, mode = 'a')

def get_input_data(buffered_data_var : Queue):
    global buffered_data
    buffered_data = buffered_data_var
    while True:
        input_data = input()
        buffered_data.put(input_data)
        
def write_out_data(buffered_out_var : Queue):
    global buffered_out
    buffered_out = buffered_out_var
    while True:
        data_out = buffered_out.get()
        # print(data_out, flush= True, end = None)
        out.write(data_out)

        if (ENABLE_LOG_FILE) : 
            print(data_out, file = file, flush= True)
        out.flush()
        


def write_protocol_data(command, body):
    if (command != CMD_OK and command != CMD_INFO and command != CMD_ERROR) : return

    if (command == CMD_OK and not PRINT_OK_ENABLED) : return
    elif(command == CMD_INFO and not PRINT_INFO_ENABLED) : return
    elif(command == CMD_ERROR and not PRINT_ERROR_ENABLED) : return

    buffered_out.put(PROTOCOL_DATA.format(command = command, body = body) + "\t\n")
