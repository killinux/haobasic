#include <cstdio>
#include <iostream>
using namespace std;
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
    printf("this is");
    puts(" a cpp ");
    cout << "Hello world \n" << endl;
    say();
    return 0;
}
//int main()
//{
//  say();
//  return 0;
//}
