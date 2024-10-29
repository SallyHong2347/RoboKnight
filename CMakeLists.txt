cmake_minimum_required(VERSION 3.10)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
project(RoboKnight)

set(CMAKE_CXX_STANDARD 17)

# add project submodules
add_subdirectory(src/screen_capture)
add_subdirectory(src/input_simulation)
add_subdirectory(src/logger)
add_subdirectory(src/app)

add_executable(RoboKnight src/app/app.cpp)

# link all dependencies
target_link_libraries(RoboKnight PRIVATE input_simulation_lib screen_capture_lib app_lib logger_lib)
