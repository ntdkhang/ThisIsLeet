# import subprocess
import sys
import os
import time

# subprocess.run(["python3", "./process_spawn.py", sys.argv[1]])
FILE_NAME = "./process_names.txt"

f = open(FILE_NAME, "r")


# Check if name is unique
is_unique = True
for line in f:
    if line.split()[2] == sys.argv[1]:
        print("Process name already exists")
        is_unique = False
        break

f.close()

if is_unique:
    # Write to text file the process number and process name
    fa = open(FILE_NAME, "a")
    fa.write(str(os.getpid()) + " forever " + sys.argv[1] + "\n")
    fa.close()

    # Create a new process
    while True:
        time.sleep(1) # does sleep suspend the process
