cmake_minimum_required(VERSION 3.14)

# name of the folder as project name
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME})

# C and C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch libs

# Raylib
find_package(raylib)
if (NOT raylib_FOUND)
    message(STATUS "Raylib not found.")
    
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
    )
    message(STATUS "Starting raylib download. Please wait ...")
    FetchContent_MakeAvailable(raylib)
    message(STATUS "Raylib download complete.")
endif()

# Enable Metal support on macOS for raylib
if(APPLE)
    set(USE_METAL ON CACHE BOOL "" FORCE)
endif()

# Raygui
find_package(raygui)
if (NOT raygui_FOUND)
    message(STATUS "Raygui not found.")

    set(RAYGUI_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) 

    include(FetchContent)
    FetchContent_Declare(
        raygui
        GIT_REPOSITORY https://github.com/raysan5/raygui.git
        GIT_TAG "master"
        GIT_PROGRESS TRUE
    )
    message(STATUS "Starting raygui download. Please wait ...")
    FetchContent_MakeAvailable(raygui)
    message(STATUS "Raygui download complete.")
endif ()

# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.hpp")
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/")

# Přidání složky assets do výstupu
add_custom_target(CopyAssets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
)

# Declaring our executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(${PROJECT_NAME} PRIVATE ${raygui_SOURCE_DIR})

add_dependencies(${PROJECT_NAME} CopyAssets)
