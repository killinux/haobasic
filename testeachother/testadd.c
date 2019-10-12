#include <stdio.h>
#include "testsub.h"
int add(int i)
{
    int c = i + 1; 
    int d = sub(c , i) ;
    printf("this is add \n");
    return d;
}
