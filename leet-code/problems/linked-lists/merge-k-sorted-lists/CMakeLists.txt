cmake_minimum_required(VERSION 3.20)

# Include Cmake settings and utils
include("../../../../cmake/common-setup.cmake")
common_setup("../../../../cmake")

# Create the project
project("merge-k-sorted-lists" LANGUAGES CXX)

project_intro_message(${PROJECT_NAME})

# Add project source files
set(project_include_files "solution.h")

set(project_src_files "main.cc")

# Add project libraries
add_executable(${PROJECT_NAME}
    ${project_include_files}
    ${project_src_files})

target_include_directories(${PROJECT_NAME} PRIVATE "../../../../")
