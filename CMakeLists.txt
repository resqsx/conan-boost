cmake_minimum_required (VERSION 3.12.0)

project(spielwiese)

# Load Conan
include(${CMAKE_SOURCE_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.txt
BASIC_SETUP CMAKE_TARGETS BUILD missing)

add_executable(spielwiese spielwiese.cpp)

target_link_libraries(spielwiese CONAN_PKG::boost)

