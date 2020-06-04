#include <emscripten.h>
#include <iostream>
using namespace std;
#ifdef __cplusplus
extern "C" {
#endif
    void EMSCRIPTEN_KEEPALIVE echo (int x){
        cout<<"this number you input is:"<<x<<endl;
        return;
}
#ifdef __cplusplus
}
#endif
