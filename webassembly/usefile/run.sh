#!/bin/sh
python /opt/mt/emsdk/emscripten/incoming/tools/file_packager.py fp.data --preload dat_dir --js-output=fp.js
emcc packdir.cc -o packdir_sep.js -s FORCE_FILESYSTEM=1
