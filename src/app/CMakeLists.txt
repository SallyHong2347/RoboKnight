message(STATUS "Starting configuration of app submodule")

# external package
find_package(spdlog CONFIG REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/app/*.cpp")
add_library(app_lib ${SOURCE_FILES})

# link external library
target_link_libraries(app_lib PRIVATE spdlog::spdlog)

message(STATUS "Finished configuration of app submodule")