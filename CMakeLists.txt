cmake_minimum_required(VERSION 3.23)
project(bakery_business)

set(CMAKE_CXX_STANDARD 14)

add_executable(bakery_business main.cpp Baker/Baker.cpp Baker/Baker.h Courier/Courier.cpp Courier/Courier.h)
