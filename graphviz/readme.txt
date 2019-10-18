https://www.ibm.com/developerworks/cn/linux/l-graphvis/

gcc -Wl,-Map=test.map -g -o test test.c

yum install graphviz


gcc -g -finstrument-functions test.c  my_debug.c -o test
./test
pvtrace test
dot -Tjpg graph.dot -o graph.jpg

#scp root@118.25.212.122:/opt/mt/haobasic/graphviz/graph.jpg .
