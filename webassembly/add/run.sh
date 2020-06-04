#!/bin/sh
 emcc -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=["ccall"] -O3 -o add.js add.c
