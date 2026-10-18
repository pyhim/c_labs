cmake_minimum_required(VERSION 4.3)
project(c_labs C)

set(CMAKE_C_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic -march=native)

set(UTILS_SOURCES
        #utils/src/string.c
        utils/src/array.c
        utils/src/vector.c
        utils/src/math.c
        utils/src/collections.c
        utils/src/safe_io.c
        utils/src/cli.c
        utils/src/functional.c
        utils/src/numbers.c
        utils/src/span.c
        utils/src/memory.c
)
set(UTILS_HEADERS
        #utils/include/utils/string.h
        utils/include/utils/array.h
        utils/include/utils/vector.h
        utils/include/utils/cli.h
        utils/include/utils/math.h
        utils/include/utils/collections.h
        utils/include/utils/safe_io.h
        utils/include/utils/functional.h
        utils/include/utils/memory.h
        utils/include/utils/numbers.h
        utils/include/utils/span.h
        utils/include/utils/defs.h
)
add_library(utils SHARED ${UTILS_HEADERS} ${UTILS_SOURCES})
target_link_libraries(utils PRIVATE m)

set(LAB2_SOURCES
        lab_two/src/cli.c
        lab_two/src/main.c
        lab_two/src/equations.c
)
set(LAB2_HEADERS
        lab_two/include/cli.h
        lab_two/include/equations.h
)
add_executable(lab2 ${LAB2_HEADERS} ${LAB2_SOURCES})
target_include_directories(lab2 PRIVATE utils/include/)
target_link_libraries(lab2 PRIVATE utils m)

set(LAB3_SOURCES
        lab_three/src/main.c
        lab_three/src/tasks.c
)
set(LAB3_HEADERS
        lab_three/include/tasks.h
)
add_executable(lab3 ${LAB3_HEADERS} ${LAB3_SOURCES})
target_include_directories(lab3 PRIVATE utils/include/)
target_link_libraries(lab3 PRIVATE utils)
