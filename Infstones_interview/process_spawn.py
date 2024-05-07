import sys
import os
import time


FILE_NAME = "./process_names.txt"

f = open(FILE_NAME, "r")


# Check if name is unique
is_unique = True
for line in f:
    if line.split()[2] == sys.argv[1]:
        print("Process name already exists")
        f.close()
        is_unique = False
        break

if is_unique:
    # Write to text file the process number and process name
    f = open(FILE_NAME, "a")
    f.write(str(os.getpid()) + " forever " + sys.argv[1] + "\n")
    f.close()

    # Create a new process
    while True:
        time.sleep(1) # does sleep suspend the process


