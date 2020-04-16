cmake_minimum_required (VERSION 3.12.0)

project(spielwiese)

# Load Conan
include(${CMAKE_SOURCE_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.txt
BASIC_SETUP CMAKE_TARGETS BUILD missing)

set(CMAKE_EXE_LINKER_FLAGS "-Wl,--disable-new-dtags")

install(DIRECTORY "${CMAKE_BINARY_DIR}/bin" DESTINATION ".")
string(REGEX REPLACE "[\\]" "/" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,.")

add_executable(spielwiese spielwiese.cpp)

target_link_libraries(spielwiese CONAN_PKG::boost)
