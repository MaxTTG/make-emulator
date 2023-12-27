cmake_minimum_required(VERSION 3.0.0)
project(make_emulator VERSION 0.1.0 LANGUAGES C CXX)

add_executable(make_emulator main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(MyMakeFile)
include_directories(MyMakeFile)

target_link_libraries(make_emulator MyMakeFile_lib)
