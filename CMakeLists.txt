
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(sensors2
    DESCRIPTION "Viam C++ sensors2 Module"
    LANGUAGES CXX
)

# Everything needs threads, and prefer -pthread if available
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(viam-cpp-sdk CONFIG REQUIRED COMPONENTS viamsdk)

add_executable(sensors2
    main.cpp
    src/mysensor.cpp
)

target_include_directories(sensors2 PUBLIC src)

target_link_libraries(sensors2
    viam-cpp-sdk::viamsdk
)

install(
    FILES meta.json
    DESTINATION .
)

install(TARGETS sensors2)

set(CPACK_PACKAGE_NAME "sensors2")
set(CPACK_PACKAGE_FILE_NAME "module")
set(CPACK_GENERATOR "TGZ")
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY 0)
include(CPack)

