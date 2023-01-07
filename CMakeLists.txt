project(Program_Watchdog)

SET(SOURCE
        src/main.cpp)

include_directories(libraries)

add_library(pid_controller SHARED
        libraries/PID_Controller/PID_Controller.cpp libraries/PID_Controller/PID_Controller.h)

add_library(arguments_decode SHARED
        libraries/ArgumentsDecode/ArgumentsDecode.cpp libraries/ArgumentsDecode/ArgumentsDecode.h)

add_executable(Program_Watchdog ${SOURCE})

target_link_libraries(Program_Watchdog pid_controller arguments_decode)