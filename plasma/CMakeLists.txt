################################################################################
# Plasma Demo
# Copyright (C) 2022 Ryan Clarke <kj6msg@icloud.com>
################################################################################

add_executable(plasma main.cpp plasmademo.cpp)

target_compile_features(plasma PRIVATE cxx_std_20)
target_compile_options(plasma PRIVATE -Wall -Wextra)
target_link_libraries(plasma PRIVATE Microsoft.GSL::GSL
                                     sfml-system
                                     sfml-window
                                     sfml-graphics)
