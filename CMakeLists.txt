cmake_minimum_required(VERSION 4.3)
project(c_labs C)

set(CMAKE_C_STANDARD 17)

add_executable(c_labs main.c
        lab_two/equations.c
        lab_two/equations.h
        lab_two/cli.c
        lab_two/cli.h
        utils/safe_io.c
        utils/safe_io.h
        utils/collections/vector.c
        utils/collections/vector.h
        utils/collections/array.c
        utils/collections/array.h
        utils/collections/string.c
        utils/collections/string.h
        utils/debug.c
        utils/debug.h
        utils/math.h
        utils/math.c)
target_link_libraries(c_labs PRIVATE m)