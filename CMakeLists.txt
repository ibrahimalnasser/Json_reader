#---------------------------------------------------------------------------------------------------------------------
# @file       CMakeLists.txt
#
# @brief      Core CMake definitions.
#
# @author     Ibrahim Al Naser
# @author     Fraunhofer IWU
#
# @date       10-10-2018
#--------------------------------------------------------------------------------------------------------------------- 


SET(execName Threshold)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4)
PROJECT(${execName})

if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 OLD)
	cmake_policy(SET CMP0015 OLD)
endif(COMMAND cmake_policy)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
SET(EXECUTABLE_OUTPUT_PATH ".")
find_package(OpenCV REQUIRED)


IF(NOT WIN32)
    add_definitions(-Wno-format-extra-args)
    SET(SPECIAL_OS_LIBS "pthread" "X11")
ENDIF()


include_directories(${OPENCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


link_directories(${OpenCV_LIBRARY_DIRS})

FILE(GLOB_RECURSE SRC_FILES src/*.cpp)
FILE(GLOB_RECURSE HDR_FILES include/*.h)

ADD_EXECUTABLE(${execName} ${HDR_FILES} ${SRC_FILES})
add_definitions(-std=c++11 -g -O3)
TARGET_LINK_LIBRARIES(${execName}
                         ${OpenCV_LIBRARIES})
