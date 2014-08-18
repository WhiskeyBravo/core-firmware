#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 3.0)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME spark_core_firmware)
project(${PROJECT_NAME} C CXX)

################
# Windows or GNU?
################
if(CMAKE_COMPILER_IS_GNUCXX)
        add_definitions(-Wall -ansi -Wno-deprecated -pthread -std=c++11)
endif()
if(MSVC)
#vc 2012 fix for vararg templates
    set(MSVC_COMPILER_DEFS "-D_VARIADIC_MAX=10")
endif()

######################
# Options. Turn on with 'cmake -Dmyvarname=ON'.
######################
option(TEST "Build tests." OFF) # Makes boolean 'test' available.


#######################
# set common include folder for module
#######################
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/src)
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)


################################
# Spark.io libraries
################################
#include the spark core stuff
#SET(SPARK_COMMON_DIR ${EXT_PROJECTS_DIR}/spark_core-common-lib)
#SET(SPARK_COMMUNICATION_DIR ${EXT_PROJECTS_DIR}/spark_core-communication-lib)
#add_subdirectory(${SPARK_COMMON_DIR})
#add_subdirectory(${SPARK_COMMUNICATION_DIR})
#the common has a file which requires we define which microcontroller we are using
# for the spark.io that is STM32F10X_MD
#add_definitions(-DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER)
#this one is plural, does that work?
#include_directories(${SPARK_COMMON_INCLUDE_DIRS})
#include_directories(${SPARK_COMMUNICATION_INCLUDE_DIRS})


################################
# Our sources and includes
################################
include_directories(
  ${spark_core_firmware_SOURCE_DIR}/inc
  ${spark_core_firmware_SOURCE_DIR})
#add_subdirectory(src)
link_directories(${spark_core_firmware_BINARY_DIR}/src)
add_library(spark_wiring src/spark_wiring_all.cpp)

################################
# Normal Libraries & Executables
################################

#add_executable(dummy_main main.cpp)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere.


#setup the deps on the main
#target_link_libraries(dummy_main heatingsm_lib)
#target_link_libraries(dummy_main thermistor_lib)
#target_link_libraries(dummy_main utilities_lib)
#target_link_libraries(dummy_main sparkintervaltimer_lib)
# REMEMBER, template classes don't get libs...

################################
# Testing
################################
if (TEST)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(${EXT_PROJECTS_DIR}/gtest)
  enable_testing()
  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${GTEST_INCLUDE_DIRS})
  #our tests will need access to the other libraries
  include_directories(src)
  add_subdirectory(tests)


  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  #add_test(NAME test-utils COMMAND test-wibeanUtilities)
  #These lines added in test subdirectory cmake
endif()
