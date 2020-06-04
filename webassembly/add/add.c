#include <emscripten/emscripten.h>

#ifdef __cplusplus
extern "C" {
#endif

int EMSCRIPTEN_KEEPALIVE add(int a, int b) {
    return a + b;
}

#ifdef __cplusplus
}
#endif
