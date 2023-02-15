# Jerry.py
# Ori P
# 15.2.23
#
# This script generates a random location on the screen
# and then moves the cursor there. Make sure to run in python 3.9!

# Imports
import win32api
import random
import time

# Constants
MAX_WIDTH  = 1280
MAX_LENGTH = 1024

def main():
    while(True):
        rand_x = random.randint(0,MAX_WIDTH)
        rand_y = random.randint(0,MAX_LENGTH)
        win32api.SetCursorPos((rand_x,rand_y))
        print(f'Hooray! Your cursor is at ({rand_x},{rand_y})')
        time.sleep(10)

if __name__ == "__main__":
    main()
