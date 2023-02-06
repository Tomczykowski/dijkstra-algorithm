cmake_minimum_required(VERSION 3.22)
project(aisdgrafysekulatomczykowskipon8)

set(CMAKE_CXX_STANDARD 14)

include_directories(DijkstraAlgorithm)
include_directories(FileIO)
include_directories(BoardFiles)
include_directories(UnitTest)

add_library(DijkstraLib DijkstraAlgorithm/DijkstraAlgorithm.cpp DijkstraAlgorithm/DijkstraAlgorithm.h)
add_library(FileIO FileIO/FileIO.cpp FileIO/FileIO.h)
add_library(GlobalLib FileIO/FileIO.cpp FileIO/FileIO.h )

add_executable(DijkstraApp DijkstraApp.cpp DijkstraAlgorithm/DijkstraAlgorithm.cpp DijkstraAlgorithm/DijkstraAlgorithm.h)
target_link_libraries(DijkstraApp GlobalLib)

#testy
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
if(WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(UnitTest UnitTest/UnitTest.cpp)
target_link_libraries(UnitTest PUBLIC gtest_main DijkstraLib)

include(GoogleTest)
gtest_discover_tests(UnitTest)
