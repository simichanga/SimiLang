cmake_minimum_required(VERSION 3.24)
project(Simi__)

set(CMAKE_CXX_STANDARD 23)

add_executable(Simi__ main.cpp SimiVMStack.cpp SimiParser.cpp SimiVMRegister.cpp)
