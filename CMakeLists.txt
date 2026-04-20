
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(bullseye-test
    DESCRIPTION "Viam C++ bullseye-test Module"
    LANGUAGES CXX
)

# Everything needs threads, and prefer -pthread if available
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(viam-cpp-sdk CONFIG REQUIRED COMPONENTS viamsdk)

add_executable(bullseye-test
    main.cpp
    src/bseye.cpp
)

target_include_directories(bullseye-test PUBLIC src)

target_link_libraries(bullseye-test
    viam-cpp-sdk::viamsdk
)

install(
    FILES meta.json
    DESTINATION .
)

install(TARGETS bullseye-test)

set(CPACK_PACKAGE_NAME "bullseye-test")
set(CPACK_PACKAGE_FILE_NAME "module")
set(CPACK_GENERATOR "TGZ")
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY 0)
include(CPack)

