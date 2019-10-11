gcc -fpic -shared -o libtestadd.so testadd.c
gcc -fpic -shared  -L. -ltestadd -o libtestuseadd.so testuseadd.c
#gcc main.c -L. -ltestuseadd -ltestadd -o main
gcc main.c -L.  -ltestadd -ltestuseadd -o main

g++ -fpic -shared -o libtestadd.so testadd.c
g++ -fpic -shared  -L. -ltestadd -o libtestuseadd.so testuseadd.c
#g++ main.c -L. -ltestuseadd -ltestadd -o main
g++ main.c -L.  -ltestadd -ltestuseadd -o main

./main
需要设置 环境变量才能运行 LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/opt/mt/testcmake/testgcc


###########
https://wenku.baidu.com/view/bbb4a170842458fb770bf78a6529647d272834cf.html

delf -d libtestuseadd.so
查看依赖关系

ldd libtestuseadd.so

#########
gcc 编译过程：预处理 编译 汇编 连接
https://www.cnblogs.com/wjchao/p/7460375.html
