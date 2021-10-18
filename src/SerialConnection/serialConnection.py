import serial
import config



class SerialConnection():

    serial: serial.serialposix.Serial


    def __init__(self) -> None:
        self.serial = serial.Serial(config.TTY_DEVICE, config.BAUD_RATE, timeout=config.TIMEOUT)
        self.serial.flush()

    def readline(self) -> str:
        return self.serial.readline().decode('utf-8').rstrip()

    def is_waiting(self) -> bool:
        return self.serial.in_waiting > 0
