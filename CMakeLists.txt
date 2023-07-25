cmake_minimum_required(VERSION 3.14 FATAL_ERROR) #FetchContent_MakeAvailable
project(cs)

# ------------------------------------
find_package(GTest QUIET)
if (NOT ${GTest_FOUND}) # GTest not found, FetchContent!
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.13.0)
FetchContent_MakeAvailable(googletest)
endif()
    
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# ------------------------------------



#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#   Grab all cpp files from includes folder
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
set(INCLUDES_FOLDER includes)
FILE(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS "${INCLUDES_FOLDER}/*.cpp")
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

ADD_EXECUTABLE(main
    main.cpp
    ${SOURCE_FILES}
)

ADD_EXECUTABLE(basic_test
    _tests/_test_files/basic_test.cpp
    ${SOURCE_FILES}
)

ADD_EXECUTABLE(testB
    _tests/_test_files/testB.cpp
    ${SOURCE_FILES}
)

TARGET_LINK_LIBRARIES(basic_test GTest::gtest_main)
TARGET_LINK_LIBRARIES(testB GTest::gtest_main)
