import os
import subprocess
import time


FILE_NAME = "./process_names.txt"
# FILE_NAME2 = "./process_names2.txt"
def check_pid(pid):
    try:
        os.kill(int(pid), 0)
    except OSError:
        return False
    else:
        return True

while True:
    process_to_spawn = -1
    lines_to_write = ""
    with open(FILE_NAME, "r") as fr:
        lines = fr.readlines()
        print(len(lines))
        for line in lines:
            pid = line.split()[0]
            if not check_pid(pid):
                process_to_spawn = line.split()[2]
            else:
                lines_to_write += line

    with open(FILE_NAME, "w") as fw:
        fw.writelines(lines_to_write)
    if process_to_spawn != -1:
        subprocess.run(["python3", "forever.py", process_to_spawn])
        process_to_spawn = -1
    fr.close()
    fw.close()

