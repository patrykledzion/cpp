cmake_minimum_required(VERSION 3.23)
project(automate)

set(CMAKE_CXX_STANDARD 23)

add_executable(automate main.cpp xmlformatter.cpp xmlformatter.h test.cpp test.h)
