#!/bin/sh
g++ -fpic -shared -o libtestadd.so testadd.c
g++ -fpic -shared  -L. -ltestadd -o libtestuseadd.so testuseadd.c
g++ main.c -L.  -ltestadd -ltestuseadd -o main
