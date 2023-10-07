cmake_minimum_required(VERSION 3.20)
project(repr)

set(SOURCES
    src/repr.cpp
)

add_library(repr ${SOURCES})

target_include_directories(repr
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(repr PUBLIC cxx_std_20)

install(TARGETS repr
    DESTINATION lib
)

# examples

add_executable(example1 examples/example1.cpp)
add_executable(example2 examples/example2.cpp)
add_executable(example3 examples/example3.cpp)
target_link_libraries(example1 repr)
target_link_libraries(example2 repr)
target_link_libraries(example3 repr)
