#include <stdio.h>
//#include "share_header.h"
#include "testuseadd.h"
#include "testadd.h"
int use_add(int l)
{
    int hehe = 2 * add(l);
    printf("this is 'use_add' \n");
    return hehe;
}
