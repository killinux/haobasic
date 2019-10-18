#include <stdio.h>
int world(){
    printf(" world \n");
    return 0;
}
int hello(){
    printf("hello ");
    return 0;
}
int say(){
    printf("I say:\n");
    hello();
    world();
    return 0;
}
int main()
{
  say();
  return 0;
}
