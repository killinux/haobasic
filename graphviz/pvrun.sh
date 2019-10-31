#!/bin/sh
gcc -g -finstrument-functions test.c  my_debug.c -o test
#g++ -g -finstrument-functions test.c  my_debug.c -o test
./test
pvtrace test
dot -Tjpg graph.dot -o graph.jpg
