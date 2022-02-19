################################################################################
# XOR Demo
# Copyright (C) 2022 Ryan Clarke <kj6msg@icloud.com>
################################################################################

add_executable(xor main.cpp xordemo.cpp)

target_compile_features(xor PRIVATE cxx_std_20)
target_compile_options(xor PRIVATE -Wall -Wextra)
target_link_libraries(xor PRIVATE Microsoft.GSL::GSL
                                  sfml-system
                                  sfml-window
                                  sfml-graphics)
