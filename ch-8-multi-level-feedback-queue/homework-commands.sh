# Q1
python ./mlfq.py -j 2 -n 2 -M 0 -s 98

# Q2
python ./mlfq.py -l 0,200,0 -c

# Q3
python ./mlfq.py -n 1 -M 0 -s 23 -c

# Q4
python ./mlfq.py -S -i 1 -l 0,297,99:0,60,0 -q 100 -n 3 -I -c

# Q5
python ./mlfq.py -n 3 -q 10 -l 0,200,0:0,200,1:0,200,1 -i 1 -S -B 200 -c

# Q6
python ./mlfq.py -n 2 -q 10 -l 0,50,0:0,50,11 -i 1 -S -c
python ./mlfq.py -n 2 -q 10 -l 0,50,0:0,50,11 -i 1 -S -I -c