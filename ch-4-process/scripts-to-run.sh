#!/bin/bash

# Q1
python process-run.py -l 5:100,5:100 -c -p
# CPU is busy for 10 seconds

# Q2
python process-run.py -l 4:100,1:0 -c -p
# CPU is busy for 6 and IO is busy for 5 seconds

# Q3
python process-run.py -l 1:0,4:100 -c -p

# Q4
python process-run.py -l 1:0,4:100 -c -S SWITCH_ON_END

# Q5
python process-run.py -l 1:0,4:100 -c -S SWITCH_ON_IO

# Q6
python process-run.py -l 1:0,4:100 -c -p -I IO_RUN_LATER

python process-run.py -l 3:0,5:100,5:100,5:100 -c -p -S SWITCH_ON_IO -I IO_RUN_LATER

# Q7
python process-run.py -l 3:0,5:100,5:100,5:100 -c -p -S SWITCH_ON_IO -I IO_RUN_IMMEDIATE
# this is much more efficient as the IO is run immediately after the process is created and the CPU is not idle

# Q8
python process-run.py -s 1 -l 3:50,3:50 -c -p

python process-run.py -s 2 -l 3:50,3:50 -c -p

python process-run.py -s 3 -l 3:50,3:50 -c -p
python process-run.py -s 3 -l 3:50,3:50 -c -p -I IO_RUN_IMMEDIATE 
# improvement in the performance of the system as the IO is run immediately after the process is created and the CPU is not idle