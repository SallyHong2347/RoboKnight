message(STATUS "Starting configuration of input_simulation submodule")

# external package
find_package(spdlog CONFIG REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/input_simulation/*.cpp")
add_library(input_simulation_lib ${SOURCE_FILES})

file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/src/input_simulation/include/*.h")
target_include_directories(input_simulation_lib PUBLIC ${HEADER_FILES})

# link external library
target_link_libraries(input_simulation_lib PRIVATE spdlog::spdlog)

message(STATUS "Finished configuration of input_simulation submodule")