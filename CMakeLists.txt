cmake_minimum_required(VERSION 3.28)
project(demo1)

set(CMAKE_CXX_STANDARD 17)

#将所有的cpp文件单独生成可执行文件
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file}
            link_list.cpp
            2023_DS.cpp
            cmake-build-debug/2022_DS.cpp)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
