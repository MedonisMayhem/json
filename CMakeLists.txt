cmake_minimum_required(VERSION 3.20)
project(json)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(json main.cpp)

target_link_libraries(json PRIVATE nlohmann_json::nlohmann_json)