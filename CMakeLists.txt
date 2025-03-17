cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

find_package(httplib REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(Calculator src/main.cpp src/Calculator.cpp src/server.cpp)

target_link_libraries(Calculator PRIVATE httplib::httplib nlohmann_json::nlohmann_json)
