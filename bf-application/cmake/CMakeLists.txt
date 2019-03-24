cmake_minimum_required(VERSION 3.4.1)
project(bf-application)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -fno-rtti -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

set(OUT bf-application)
set(INCLUDE
        ../header
        ../../include)
set(SOURCE
        ../source/app.cpp
        ../source/app-base.cpp
        ../source/renderer.cpp
        ../source/renderer-opengl.cpp)
#set(LIB
#        ../../library/)

add_library(${OUT} ${SOURCE})
target_include_directories(${OUT} PUBLIC ${INCLUDE})
#target_link_libraries()