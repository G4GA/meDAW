cmake_minimum_required(VERSION 3.28)

project(meDAW)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(modules)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
                      polyCodec)
