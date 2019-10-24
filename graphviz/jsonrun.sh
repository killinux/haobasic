#!/bin/sh
gcc -g -finstrument-functions test.c  my_debug.c -o test
./test
jsontrace test
