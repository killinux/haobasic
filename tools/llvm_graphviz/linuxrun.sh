#!/bin/sh
clang++ -S -emit-llvm main1.cpp -o - | opt -analyze   -dot-callgraph
cat callgraph.dot |c++filt | sed 's,>,\\>,g; s,-\\>,->,g; s,<,\\<,g' | gawk '/external node/{id=$1} $1 != id' | dot -Tpng -ocallgraph.png
