#!/bin/sh
g++ -c testadd.c
g++ -c testuseadd.c
ar -crv libtestadd.a testadd.o
ar -crv libtestuseadd.a testuseadd.o

#g++ main.c -L.  -ltestadd -ltestuseadd -o main
#g++ main.c -L.   -ltestuseadd -ltestadd -o main

#g++ main.c -o main  -Xlinker "-("  libtestadd.a libtestuseadd.a  -Xlinker "-)"
#g++ main.c -o main  -Xlinker "-(" -L. -ltestadd -ltestuseadd  -Xlinker "-)"
