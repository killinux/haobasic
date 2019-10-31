https://www.ibm.com/developerworks/cn/linux/l-graphvis/

gcc -Wl,-Map=test.map -g -o test test.c

yum install graphviz


1. this is used for jpg
gcc -g -finstrument-functions test.c  my_debug.c -o test
output:test
./test
output:trace.txt
pvtrace test
output:graph.dot
dot -Tjpg graph.dot -o graph.jpg
output:graph.jpg

2. this is used for vizceral
gcc -g -finstrument-functions test.c  my_debug.c -o test
output:test
./test
output:trace.txt
jsontrace test
output:graph.json

then

git clone https://github.com/killinux/vizceral-example
cp graph.json vizceral-example/src/sample_data.json

run this example:
npm run dev

#scp root@118.25.212.122:/opt/mt/haobasic/graphviz/graph.jpg .

c++ is a problem ,may be segmentfault with init
see:
https://stackoverflow.com/questions/12233416/using-gccs-function-instrumentation-why-does-using-c-stl-containers-or-strea


这里有个区别
对于addr2line 
c的时候直接会把地址转成函数

c++的时候还要 c++filt 转一次



