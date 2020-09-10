import control
import curses
from curses import wrapper

# Raspberry Pi "/dev/ttyACM0"
# Arduino Uno "COM5"


def main(stdscr):
    stdscr.clear()
    Gateway = control.Control("/dev/ttyACM0")

    Power = True
    State = 0

    while Power is True:

        if State is 0: # State Standby
            stdscr.addstr("\nThe robocar is currently standby.")
            Gateway.Standby()
            stdscr.addstr("\n0: Standby")
            stdscr.addstr("\n1: Follow Wall")
            stdscr.addstr("\n3: Bounce")
            stdscr.addstr("\n3: Manual")
            stdscr.addstr("\n4: Exit")
            stdscr.addstr("\n5: ping(@)")
            stdscr.addstr("\nInput here: ")
            c = stdscr.getch()
            stdscr.clear()
            if c == ord('0'):
                State = 0
            elif c == ord('1'):
                State = 1
            elif c == ord('2'):
                State = 2
            elif c == ord('3'):
                State = 3
            elif c == ord('4'):
                State = 4
            elif c == ord('5'):
                State = 5

            if State is 3:
                stdscr.addstr("\nThe robocar is now listening to your commands!")
                Gateway.Manual()
                stdscr.addstr("\nUse the qweasd keys and m for stop, to control the car.")
                stdscr.addstr("\nTo exit press p!")

        elif State is 1: # State Follow Wall
            stdscr.addstr("\nThe robocar is currently following a wall.")
            Gateway.Follow_Wall()
            stdscr.addstr("\n0: Standby")
            stdscr.addstr("\n1: Follow Wall")
            stdscr.addstr("\n2: Bounce")
            stdscr.addstr("\n3: Manual")
            stdscr.addstr("\n4: Exit")
            stdscr.addstr("\nInput here: ")
            c = stdscr.getch()
            stdscr.clear()
            if c == ord('0'):
                State = 0
            elif c == ord('1'):
                State = 1
            elif c == ord('2'):
                State = 2
            elif c == ord('3'):
                State = 3
            elif c == ord('4'):
                State = 4

            if State is 3:
                stdscr.addstr("\nThe robocar is now listening to your commands!")
                Gateway.Manual()
                stdscr.addstr("\nUse the qweasd keys and m for stop, to control the car.")
                stdscr.addstr("\nTo exit press p!")

        elif State is 2: # State BOUNCE
            stdscr.addstr("\nThe robocar is currently bouncing around the room.")
            Gateway.Bounce()
            stdscr.addstr("\n0: Standby")
            stdscr.addstr("\n1: Follow Wall")
            stdscr.addstr("\n2: Bounce")
            stdscr.addstr("\n3: Manual")
            stdscr.addstr("\n4: Exit")
            stdscr.addstr("\nInput here: ")
            c = stdscr.getch()
            stdscr.clear()
            if c == ord('0'):
                State = 0
            elif c == ord('1'):
                State = 1
            elif c == ord('2'):
                State = 2
            elif c == ord('3'):
                State = 3
            elif c == ord('4'):
                State = 4

            if State is 3:
                stdscr.addstr("\nThe robocar is now listening to your commands!")
                Gateway.Manual()
                stdscr.addstr("\nUse the qweasd keys and m for stop, to control the car.")
                stdscr.addstr("\nTo exit press p!")

        elif State is 3: # State Manual
            c = stdscr.getch()
            stdscr.clear()

            if c == ord('w'):
                Gateway.Forwards()
            elif c == ord('s'):
                Gateway.Backwards()
            elif c == ord('a'):
                Gateway.Left()
            elif c == ord('d'):
                Gateway.Right()
            elif c == ord('q'):
                Gateway.RotLeft()
            elif c == ord('e'):
                Gateway.RotRight()
            elif c == ord('m'):
                Gateway.Stop()
            elif c == ord('p'):
                State = 0

        elif State is 4: # State EXIT
            stdscr.addstr("\nNow exiting the program!")
            Gateway.Standby()
            Power = False

        elif State is 5: # Will ping the Arduino
            stdscr.addstr("\nNow sending ping!")
            Gateway.Ping()
            State = 0

        else: # ERROR!
            stdscr.addstr("\nAn error occurred! Returning to Standby...")
            State = 0

wrapper(main)
exit()
