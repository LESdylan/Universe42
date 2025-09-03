## Overview
This project is about to discover for the first time to track down and think about resolve a sorting algorithm with the less possible movements. As this project to me can only be resolved in a try-hard way. I wanted to be able to work on different algorithm at the same time to learn from the concept of each one of them. 


## what expect from this project ?


the project push_swap has been thought in a modularize and extensible way. 


```bash

# alias `turco` from 42 students, it is based comparative algorithm 
# that try out to verify all the algorihtm
make greedy

# not implemented yet
make lis

# Chunk algorithm is the most quick algorithm that exists and ultra optimized
make chunk

# k_sort is an algorithm from a german guy I've followed and my mates adviced me to do
make k_sort

# Compile the radix algorithm
make radix

# Not implemented yet, but I wanted to train myself on queue algo
# so I've kept it in case I want to finish this
make queue

make bonus
make checker_visual
[you've understood... you can even imagine your algorithm later and just plug it into the implementation really easily]

```


all right once the compilation are done, we must try out the different algorithm
No fancy tricks, we just want to check different seq between 1-500 without duplication

```bash
RUN=$(seq 1 <max> | shuf) ; ./push_swap $RUN | wc -l # This line is for knowing how many movement the algorithm takes to resolve the issue
RUN=$(seq 1 <max> | shuf) ; ./push_swap $RUN | ./checker $RUN # this line is for knowing
make visual_checker && \
RUN=$(seq 1 <max> | shuf) ; ./push_swap $RUN | ./checker $RUN run the visualizer to see the behavior of each command from the two stack. really useful to detect innefficiency. 
```


[cd]