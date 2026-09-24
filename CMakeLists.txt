cmake_minimum_required(VERSION 3.22)

# Project Name
project(
    task_manager
    LANGUAGES CXX
)

# Set Languages version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add source files
add_executable(
    task
    src/main.cpp
    src/domain/Task.cpp
    src/domain/TaskStatus.cpp
    src/repository/InMemoryTaskRepository.cpp
)

# Include files
target_include_directories(
    task PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

