cmake_minimum_required(VERSION 3.24)
project(program_watchdog)

set(BUILD_PID_TEST_PROGRAM ON)

if (${BUILD_PID_TEST_PROGRAM})
    project(pid_test)
    add_executable(pid_test test/test_program.cpp)
endif ()

SET(SOURCE
        src/main.cpp)

include_directories(libraries)

add_library(pid_controller STATIC
        libraries/PID_Controller/PID_Controller.cpp libraries/PID_Controller/PID_Controller.h)

add_library(arguments_decode STATIC
        libraries/ArgumentsDecode/ArgumentsDecode.cpp libraries/ArgumentsDecode/ArgumentsDecode.h)

add_executable(program_watchdog ${SOURCE})

target_link_libraries(program_watchdog pid_controller arguments_decode)


