cmake_minimum_required(VERSION 2.8)  
project( test )  
set(Thrid_DIR "/opt/mt/testcmake/thrid")  
INCLUDE_DIRECTORIES("${Thrid_DIR}/include")  

LINK_DIRECTORIES("${Thrid_DIR}/lib")  

  
add_executable(test main.cpp)  
  
target_link_libraries(test -L/opt/mt/testcmake/testcmake libtestuseadd.a)  
target_link_libraries(test -L/opt/mt/testcmake/testcmake libtestadd.a)  
