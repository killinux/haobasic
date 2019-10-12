#!/bin/sh
g++ -fpic -shared -o libtestadd.so testadd.c
g++ -fpic -shared -o libtestsub.so testsub.c
#g++ main.c -L.  -ltestadd -ltestuseadd -o main

g++ main.c  -L. -ltestadd -ltestsub  -o main
#g++ main.c -Wl,--export-dynamic  -L. -ltestadd -ltestsub  -o main
#用动态库顺序前后都可以
