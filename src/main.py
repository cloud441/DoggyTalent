#!/usr/bin/env python3

import time
import pygame

from SerialConnection import SerialConnection
from Controller import PlaystationController


if __name__ == "__main__":

    connection = SerialConnection()
    if not (connection.serial.isOpen()):
        exit(1)

    controller = PlaystationController()

    while not controller.stop():
        steer = controller.get_steer()
        throttle = controller.get_throttle()
        input_data = f"{steer},{throttle}\n"

        connection.send(input_data)

        time.sleep(0.01)
