#/bin/sh
#emcc debug.c -O1 -s WASM=1 -s SIDE_MODULE=1 -o debug.wasm
#emcc debug.c -O1 -s WASM=1 -s SIDE_MODULE=1 -s "EXPORTED_FUNCTIONS=['_sumOfSquare']" -o debug.wasm
emcc debug.c -O1 -s WASM=1 -s SIDE_MODULE=1 -s "EXPORTED_FUNCTIONS=['_sumOfSquare']" -o debug.wasm -g4 --source-map-base http://212.129.249.212/rusttest/debug/
