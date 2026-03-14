cmake_minimum_required(VERSION 3.10)
project(pong-raylib)

set(CMAKE_CXX_STANDARD 17)

# download raylib from github so it can compile in any platform
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) #disable raylib examples build
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) #disable example game build

#fetch raylib from github
find_package(raylib QUIET)

# If not found, download it
if (NOT raylib_FOUND)
    include(FetchContent)

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
        GIT_SHALLOW TRUE
    )

    FetchContent_MakeAvailable(raylib)
endif()

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

#linke raylib library
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

#windows extra dependency
if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE winmm)
endif()
