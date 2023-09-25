cmake_minimum_required(VERSION 3.26)
project(lqr)

set(CMAKE_CXX_STANDARD 23)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

# find python libraries
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)
find_package(PythonLibs 3.0 REQUIRED)
include_directories(${PYTHON3_INCLUDE_DIRS} ${NumPy_INCLUDE_DIRS})

# populate matplotlib repository
include(FetchContent)
FetchContent_Declare(
        matplotlib
        GIT_REPOSITORY https://github.com/lava/matplotlib-cpp.git
        GIT_TAG        f23347fca25219d1c42cbb91608b5556814bf572
)
FetchContent_GetProperties(matplotlib)
if(NOT matplotlib_POPULATED)
    FetchContent_Populate(matplotlib)
endif()
include_directories(SYSTEM ${matplotlib_SOURCE_DIR})

add_executable(lqr main.cpp
        matplotlibcpp.h)
target_link_libraries (lqr
        PUBLIC
        Eigen3::Eigen
        PRIVATE
        ${PYTHON_LIBRARIES}
        Python3::NumPy
)