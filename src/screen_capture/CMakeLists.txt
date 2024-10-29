message(STATUS "Starting configuration of screen_capture submodule")

find_package(OpenCV REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/screen_capture/*.cpp")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/src/screen_capture/include/*.h")

add_library(screen_capture_lib ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(screen_capture_lib PUBLIC ${CMAKE_SOURCE_DIR}/include/screen_capture)
target_link_libraries(screen_capture_lib PRIVATE ${OpenCV_LIBS})

message(STATUS "Finished configuration of screen_capture submodule")