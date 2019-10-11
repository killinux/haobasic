# haobasic
总结下：

1.系统里的定义了htonll
2.thrift-0.8.9定义了zk里定义了htonll
3.zk里定义了htonll
4.cthrift里面先#undefine htonll ，然后引入zk的 htonll

所以这里乱了
使用zk的时候如果用  -lzookeeper_mt ，这里不行，因为zookeeper的lib路径同时包含了.so 和.a  默认先找.so去了？？？这里没懂

最终解决方案：
可行的是，库名字全变成  -l库名字 ，zk的时候用静态库名字，直接 libzookeeper_mt.a 解决   

在加一层保险：
gcc -o output.bin -Xlinker "-(" liba.ar libb.ar -Xlinker "-)" -lrt
