################################################################################
# Fire Demo
# Copyright (C) 2022 Ryan Clarke <kj6msg@icloud.com>
################################################################################

add_executable(fire main.cpp firedemo.cpp)

target_compile_features(fire PRIVATE cxx_std_20)
target_compile_options(fire PRIVATE -Wall -Wextra)
target_link_libraries(fire PRIVATE Microsoft.GSL::GSL
                                   sfml-system
                                   sfml-window
                                   sfml-graphics)
