# Jerry.py
# Ori P
# 15.2.23
#
# This script generates a random location on the screen
# and then moves the cursor there. Make sure to run in python 3.9!

# Imports
import win32api
import random

# Constants
MAX_WIDTH  = 1280
MAX_LENGTH = 1024

def main():
    rand_x = random.randint(0,MAX_WIDTH)
    rand_y = random.randint(0,MAX_LENGTH)
    win32api.SetCursorPos((rand_x,rand_y))
    print(f'Hooray! Your cursor is at ({rand_x},{rand_y})')

if __name__ == "__main__":
    main()
