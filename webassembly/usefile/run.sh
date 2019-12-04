#!/bin/sh
# file:
#emcc packfile.cc -o packfile.js --preload-file hello.txt

python /opt/mt/emsdk/emscripten/incoming/tools/file_packager.py fp.data --preload dat_dir --js-output=fp.js
emcc packdir.cc -o packdir_sep.js -s FORCE_FILESYSTEM=1

#idbfs:
#emcc idbfs.cc -lidbfs.js -o idbfs.js
