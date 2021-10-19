#!/usr/bin/env python3

import time

from SerialConnection import SerialConnection


if __name__ == "__main__":

    connection = SerialConnection()

    while (True):
        connection.send("Data sent from rpi.")
        print(connection.listen())
        time.sleep(1)
