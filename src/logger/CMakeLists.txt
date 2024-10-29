message(STATUS "Starting configuration of logger submodule")

# external package
find_package(spdlog CONFIG REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/logger/*.cpp")
add_library(logger_lib ${SOURCE_FILES})

# link external library
target_link_libraries(logger_lib PRIVATE spdlog::spdlog)

message(STATUS "Finished configuration of logger submodule")