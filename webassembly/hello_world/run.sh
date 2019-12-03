#!/bin/sh
#rustup toolchain install nightly-x86_64-unknown-linux-gnu
#rustup target add wasm32-unknown-unknown --toolchain nightly
rustc +nightly --target=wasm32-unknown-unknown -O --crate-type=cdylib src/lib.rs -o build/hello.wasm
