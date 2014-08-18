cmake_minimum_required(VERSION 3.0)


################################
# Normal Libraries & Executables
################################

# Debug outputs for checking vars come in properly
#message(STATUS "src/SPARK_FIRMWARE_INCLUDE_DIRS: " ${SPARK_FIRMWARE_INCLUDE_DIRS})
#get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
#foreach(dir ${dirs})
#  message(STATUS "dir='${dir}'")
#endforeach()

add_library(spark_wiring_string_lib spark_wiring_string.cpp)

