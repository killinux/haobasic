#include <stdio.h>
#include "testadd.h"
int sub(int i,int j) 
{
    int c = i - j; 
//    int d = add(c); 
    printf("this is sub %d\n",c);
    return c;
}
int use_add(int k)
{
    int m = add(k);
    printf("this is use_add %d\n",m);
    return m;
}
