https://stackoverflow.com/questions/5373714/how-to-generate-a-calling-graph-for-c-code
https://code-examples.net/zh-CN/q/51ff12
https://llvm.org/docs/Passes.html

clang++ -S -emit-llvm main1.cpp -o - | opt -analyze -dot-callgraph

opt是llvm  

centos7:
可能没有dot，opt，clang++命令

yum install epel-release
yum install clang
opt命令在llvm里面
yum install llvm 

dot的安装
yum install graphviz

运行
clang++ -S -emit-llvm main1.cpp -o - | opt -analyze   -dot-callgraph
cat callgraph.dot |c++filt | sed 's,>,\\>,g; s,-\\>,->,g; s,<,\\<,g' | gawk '/external node/{id=$1} $1 != id' | dot -Tpng -ocallgraph.png


静态分析


mac下运行：

如果缺少dot：
brew install graphviz
如果缺少opt
brew install llvm 
mac下的opt路径在 /usr/local/opt/llvm/bin 
没有默认加到环境变量
To use the bundled libc++ please add the following LDFLAGS:
  LDFLAGS="-L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib"
If you need to have llvm first in your PATH run:
  echo 'export PATH="/usr/local/opt/llvm/bin:$PATH"' >> ~/.bash_profile
For compilers to find llvm you may need to set:
  export LDFLAGS="-L/usr/local/opt/llvm/lib"
  export CPPFLAGS="-I/usr/local/opt/llvm/include"


/usr/local/opt/llvm/bin/clang++ -S -emit-llvm main1.cpp -o - | /usr/local/opt/llvm/bin/opt -analyze -dot-callgraph

cat callgraph.dot | 
   c++filt -n| 
   sed 's,>,\\>,g; s,-\\>,->,g; s,<,\\<,g' | 
   gawk '/external node/{id=$1} $1 != id' | 
   dot -Tpng -ocallgraph.png 



cat callgraph.dot | c++filt -n


注意 c++filt 在mac系统上需要加 -n 
参考
https://stackoverflow.com/questions/2424576/unmangling-c-names-on-mac-10-5












