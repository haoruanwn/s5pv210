cmake_minimum_required(VERSION 3.15)
project(s5pv210 C ASM) # Enable C and ASM languages

# --- Output Directory Configuration ---
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin) # For older CMake compatibility

# --- Other Tools Configuration  ---
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)             # Enable compile command to ease indexing with e.g. clangd

# --- Toolchain Configuration ---
include(${CMAKE_SOURCE_DIR}/toolchain-arm-linaro.cmake)

# --- Compiler Flags (Project-Wide) ---
add_compile_options(
    -O3 -g0
    # C Specific
    $<$<COMPILE_LANGUAGE:C>:-std=c99>
    # C++ Specific
    # $<$<COMPILE_LANGUAGE:CXX>:-std=c++17> # 例如

    # Common Warnings
    -Wall -Wshadow -Wundef -Wmissing-prototypes -Wno-discarded-qualifiers -Wextra
    -Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith -fno-strict-aliasing
    -Wno-error=cpp -Wuninitialized -Wmaybe-uninitialized -Wno-unused-parameter
    -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess
    -Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default
    -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers
    -Wno-error=pedantic -Wno-sign-compare -Wno-error=missing-prototypes
    -Wdouble-promotion -Wclobbered -Wdeprecated -Wempty-body -Wtype-limits
    -Wshift-negative-value -Wstack-usage=2048 -Wno-unused-value
)



# --- Define the project executable ---
add_executable(${PROJECT_NAME}
    main.c
    start.S
    src/key/key.c
    src/led/led.c
    src/uart/uart.c
    src/timer/timer.c
    src/clock/clock.c
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_SOURCE_DIR}"  
    "${CMAKE_SOURCE_DIR}/src/key/"   
    "${CMAKE_SOURCE_DIR}/src/led/"
    "${CMAKE_SOURCE_DIR}/src/uart/" 
    "${CMAKE_SOURCE_DIR}/src/timer/" 
    "${CMAKE_SOURCE_DIR}/src/clock/" 
)

message(STATUS "CMakeLists.txt: Defined ${PROJECT_NAME} executable.")
message(STATUS "Top-Level CMake: CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
message(STATUS "Top-Level CMake: CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message(STATUS "Top-Level CMake: Output directory for executables: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")