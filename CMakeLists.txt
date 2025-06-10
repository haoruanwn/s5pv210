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


# --- Source Files ---
# Collect all source files in the src directory
file(GLOB_RECURSE SRC_SOURCE 
    "${CMAKE_SOURCE_DIR}/src/*.c"
)

# --- Define the project executable ---
add_executable(${PROJECT_NAME}
    ${SRC_SOUCRE} 
    main.c
    start.S
)

# --- Include Directories ---
target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_SOURCE_DIR}"  
    "${CMAKE_SOURCE_DIR}/src/key/"   
    "${CMAKE_SOURCE_DIR}/src/led/"
    "${CMAKE_SOURCE_DIR}/src/uart/" 
    "${CMAKE_SOURCE_DIR}/src/timer/" 
    "${CMAKE_SOURCE_DIR}/src/clock/" 
)

# --- Linker Script --- 
target_link_options(${PROJECT_NAME} PRIVATE
    -nostdlib
    "-Wl,-Ttext=0xd0020010"
)

# --- Custom commands ---
# generate .bin .dis .elf files
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.bin
    COMMENT "Generating ${PROJECT_NAME}.bin from $<TARGET_FILE_NAME:${PROJECT_NAME}>"
    VERBATIM
)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_OBJDUMP} -D $<TARGET_FILE:${PROJECT_NAME}> > ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.dis
    COMMENT "Generating ${PROJECT_NAME}.dis from $<TARGET_FILE_NAME:${PROJECT_NAME}>"
    VERBATIM
)

# --- message output ---
message(STATUS "CMakeLists.txt: Defined ${PROJECT_NAME} executable.")
message(STATUS "Top-Level CMake: CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
message(STATUS "Top-Level CMake: CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message(STATUS "Top-Level CMake: Output directory for executables: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

get_target_property(TARGET_LINK_OPTIONS ${PROJECT_NAME} LINK_OPTIONS)
message(STATUS "Top-Level CMake: Target ${PROJECT_NAME} LINK_OPTIONS: ${TARGET_LINK_OPTIONS}")
message(STATUS "Top-Level CMake: CMAKE_OBJCOPY: ${CMAKE_OBJCOPY}")
message(STATUS "Top-Level CMake: CMAKE_OBJDUMP: ${CMAKE_OBJDUMP}")
message(STATUS "Top-Level CMake: CROSS_COMPILER_PREFIX from toolchain: ${CROSS_COMPILER_PREFIX}")