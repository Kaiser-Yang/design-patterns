cmake_minimum_required(VERSION 3.14)

project(design-patterns)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

find_program(CLANG_TIDY_EXE NAMES clang-tidy)

function(add_sub_project SUB_PROJECT_NAME)
    file(GLOB_RECURSE ${SUB_PROJECT_NAME}_SOURCE src/${SUB_PROJECT_NAME}/*.cpp)

    if (NOT ${SUB_PROJECT_NAME}_SOURCE)
        return()
    endif()

    add_executable(${SUB_PROJECT_NAME} ${${SUB_PROJECT_NAME}_SOURCE})

    set_target_properties(
        ${SUB_PROJECT_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/${SUB_PROJECT_NAME}")

    if (CLANG_TIDY_EXE)
        set_target_properties(
            ${SUB_PROJECT_NAME}
            PROPERTIES
            CXX_CLANG_TIDY
            "${CLANG_TIDY_EXE}")
    endif()

    if (EXISTS src/${SUB_PROJECT_NAME}/include)
        target_include_directories(
            ${SUB_PROJECT_NAME}
            PRIVATE
            src/${SUB_PROJECT_NAME}/include)
    endif()
endfunction()

file(GLOB SUB_DIRECTORY RELATIVE ${CMAKE_SOURCE_DIR}/src src/*)
foreach(SUB_PROJECT ${SUB_DIRECTORY})
    add_sub_project(${SUB_PROJECT})
endforeach()

