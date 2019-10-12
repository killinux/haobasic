#!/bin/sh
g++ -c testadd.c
g++ -c testsub.c
ar -crv libtestadd.a testadd.o
ar -crv libtestsub.a testsub.o

#g++ main.c -L.   -ltestsub -ltestadd -o main

#g++ main.c -o main  -Xlinker "-("  libtestadd.a libtestuseadd.a  -Xlinker "-)"
#g++ main.c -o main  -Xlinker "-(" -L. -ltestadd -ltestuseadd  -Xlinker "-)"

#this will make error
g++ main.c   -L. -ltestadd -ltestsub  -o main
# this is right
g++ main.c   -L. -ltestsub -ltestadd  -o main
#g++ main.c  -Xlinker "-(" -L. -ltestadd -ltestsub -Xlinker "-)" -o main
#g++ main.c  -Xlinker "-(" -L. -ltestadd -ltestsub -Xlinker "-)" -Xlinker -Map=output.map -o main

#用静态库，顺序要严格，被依赖的库放在右边 ，link顺序是从右往左，-Xlinker参数可以忽略顺序
