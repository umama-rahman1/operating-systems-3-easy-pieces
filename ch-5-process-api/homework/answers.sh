 # Q1
 ./fork.py -s 10 -c 
 # this creates a random seed of a getting forked and creating child processes

./fork.py -s 10 -a 10 -c 
# runs 10 moves

# Q2
 ./fork.py -s 10 -a 10 -f 0.1 -c 

 ./fork.py -s 10 -a 100 -f 0.9 -c 

# -f flag controls probability of forking

# Q3
./fork.py -t -c 

# -t flag shows the tree of processes

# Q4
# creates a very specific tree of processes
./fork.py -A a+b,b+c,c+d,c+e,c- -c 

# local reparent true here means that orphaned processes will be reparented to the root process
./fork.py -A a+b,b+c,c+d,c+e,c- -R -c

# Q5
# show the steps and asks for final version of the tree
./fork.py -F -c

# Q6 
# gives the final tree and asks for the steps
./fork.py -F -t -c