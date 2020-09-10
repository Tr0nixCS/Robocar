import serial


class Control:
    def __init__(self, port, baudrate=115200):
        self.__ser = serial.Serial()
        self.__ser.port = port
        self.__ser.baudrate = baudrate
        self.__ser.timeout = 0.1
        self.__ser.open()

    # MOVES

    def Forwards(self):
        self.__ser.write(b":MF\x0D")

    def Backwards(self):
        self.__ser.write(b":MB\x0D")

    def Stop(self):
        self.__ser.write(b":MS\x0D")

    def Left(self):
        self.__ser.write(b":ML\x0D")

    def Right(self):
        self.__ser.write(b":MR\x0D")

    def RotLeft(self):
        self.__ser.write(b":Ml\x0D")

    def RotRight(self):
        self.__ser.write(b":Mr\x0D")

    # SYSTEM

    def Standby(self):
        self.__ser.write(b":Ss\x0D")

    def Follow_Wall(self):
        self.__ser.write(b":Sf\x0D")

    def Bounce(self):
        self.__ser.write(b":Sb\x0D")

    def Manual(self):
        self.__ser.write(b":Sm\x0D")

    def Ping(self):
        self.__ser.write(b":@\x0D")
