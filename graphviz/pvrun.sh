#!/bin/sh
#gcc -g -finstrument-functions test.c  my_debug.c -o test
g++ -g -finstrument-functions test.cpp  instrument.c -o test
./test
pvtrace test
sed -i 's/()//g' graph.dot
dot -Tjpg graph.dot -o graph.jpg
