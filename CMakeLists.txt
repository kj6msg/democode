################################################################################
# Demo Code Collection
# Copyright (C) 2022 Ryan Clarke <kj6msg@icloud.com>
################################################################################

cmake_minimum_required(VERSION 3.17)

project(democode VERSION 1.0.0 DESCRIPTION "Demo Code Collection" LANGUAGES CXX)
find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(fire)
add_subdirectory(plasma)
add_subdirectory(xor)
