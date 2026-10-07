cmake_minimum_required(VERSION 4.3)
project(c_labs C)

set(CMAKE_C_STANDARD 17)

set(lab2_sources
        main.c
        lab_two/equations.c
        lab_two/equations.h
        lab_two/cli.c
        lab_two/cli.h
        utils/safe_io.c
        utils/safe_io.h
        utils/math.h
        utils/math.c)

add_executable(c_labs ${lab2_sources})
add_compile_options(-Wall -Wextra -Wpedantic -march=native)
target_link_libraries(c_labs PRIVATE m)