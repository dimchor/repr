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

add_executable(example1 examples/example1)
add_executable(example2 examples/example2)
target_link_libraries(example1 repr)
target_link_libraries(example2 repr)
