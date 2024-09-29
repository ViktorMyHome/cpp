cmake_minimum_required(VERSION 3.0.0)

project(AbstractFactory VERSION 1.0.0)

add_subdirectory(hotdrinkfactory)

#add_library(drinkfactory drinkfactory.cpp)

#add_library(hotdrink hotdrink.cpp)

#add_library(hotdrinkfactory hotdrinkfactory.cpp)

add_executable(main main.cpp)

add_executable(main2 main.cpp)

target_link_libraries(main drinkfactory hotdrink hotdrinkfactory)

target_link_libraries(main2 drinkfactory hotdrink hotdrinkfactory)