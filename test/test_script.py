# import package
import os
import subprocess
import time

# print this program pid
print("This is a main program : {}".format(os.getpid()))

# the sub program pid list
pid_list = []

# to run 3 sub program
for _ in range(3):
    # to process sub program
    p = subprocess.Popen("pid_test.exe", shell=False, stdout=subprocess.PIPE)

    # print the sub program pid
    print("\tThe sub program : %s" % p.pid)

    # append sub program pid to pid_list
    pid_list.append(p.pid)

# basic program_watchdog format
# -m need to set this program pid
# when this program (-m part) is exit
# program_watchdog will terminate the pid_list program (-w part)
executable = "program_watchdog.exe -m {} -w ".format(os.getpid())
for pid in pid_list:
    executable += "{} ".format(pid)

# to run the program_watchdog
subprocess.Popen(executable, shell=False, stdout=subprocess.PIPE)

# infinite loop
while True:
    time.sleep(1000)