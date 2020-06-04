#!/bin/sh
#emcc -s WASM=1 -O3 -o fib.js fib.cc
#emcc -s WASM=1 -O1 -s SIDE_MODULE=1  -s "EXPORTED_FUNCTIONS=['_fib']" -o fib.js fib.cc
#emcc  -O1  -s "EXPORTED_FUNCTIONS=['_fib']" -o fib.js fib.cc

emcc dependent.cc -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=["ccall"] --post-js post-script.js -o dependent.js
