import serial
import pandas as pd
from time import time, ctime

# Set time in seconds (for file naming)
t = time()

# convert to local time
local_time = ctime(t)


# Define the COM port the microcontroller is connected to
CONTROLLER_COMM_PORT = ""

# Set baud rate
BAUD_RATE = 9600

# Open the COM port to start communications
serial_port = serial.Serial(CONTROLLER_COMM_PORT, BAUD_RATE, timeout=1)


while True:
    sensor_output = serial_port.readline().decode()

    if len(sensor_output > 0):
        # force, temp_1, temp_2, etc = (int(sensor) for sensor in sensor_output.split(","))
        force = sensor_output

        with open(f"Trial {local_time}.csv", "wb") as data:
            data.write(ctime(time()))
            data.write(",")
            data.write(force)
            data.write("\n")
