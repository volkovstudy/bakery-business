cmake_minimum_required(VERSION 3.23)
project(bakery_business)

set(CMAKE_CXX_STANDARD 14)

add_executable(bakery_business main.cpp Baker/Baker.cpp Baker/Baker.h Courier/Courier.cpp Courier/Courier.h Client/Client.cpp Client/Client.h Order/Order.cpp Order/Order.h Status/Status.h Storage/Storage.cpp Storage/Storage.h OrderProcessing/OrderProcessing.cpp OrderProcessing/OrderProcessing.h Staff/Staff.cpp Staff/Staff.h)
