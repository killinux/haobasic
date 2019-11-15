#!/bin/sh
/usr/local/opt/llvm/bin/clang++ -S -emit-llvm main1.cpp -o - | /usr/local/opt/llvm/bin/opt -analyze -dot-callgraph
cat callgraph.dot| c++filt -n| sed 's,>,\\>,g; s,-\\>,->,g; s,<,\\<,g' | gawk '/external node/{id=$1} $1 != id'  > call.dot
dot -Tpng -ocall.png  call.dot
