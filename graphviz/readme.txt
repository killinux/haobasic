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


#scp root@118.25.212.122:/opt/mt/haobasic/graphviz/graph.jpg .

