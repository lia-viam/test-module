
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(sensors
    DESCRIPTION "Viam C++ sensors Module"
    LANGUAGES CXX
)

# Everything needs threads, and prefer -pthread if available
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(viam-cpp-sdk CONFIG REQUIRED COMPONENTS viamsdk)

add_executable(sensors
    main.cpp
    src/mysensor.cpp
)

target_include_directories(sensors PUBLIC src)

target_link_libraries(sensors
    viam-cpp-sdk::viamsdk
)

install(
    FILES meta.json
    DESTINATION .
)

install(TARGETS sensors)

set(CPACK_PACKAGE_NAME "sensors")
set(CPACK_PACKAGE_FILE_NAME "module")
set(CPACK_GENERATOR "TGZ")
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY 0)
include(CPack)

