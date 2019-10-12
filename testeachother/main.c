#include <stdio.h>
//#include "testuseadd.h"
//#include "testadd.h"
#include "testsub.h"
int main(){
    printf("main:hello\n");
//    int c  = add(10);
//    printf("main:world, add  %d \n",  c);
    //int d = use_add(c);
    int d = use_add(2);

    printf("main:world, useadd %d \n",  d);
}
