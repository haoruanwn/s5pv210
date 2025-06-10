# /home/hao/tools/toolchains/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-
# CMake toolchain file for arm-linux-gnueabihf

# Target system
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Cross compiler paths
set(CROSS_COMPILER_PREFIX /home/hao/tools/toolchains/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-)


set(CMAKE_C_COMPILER ${CROSS_COMPILER_PREFIX}gcc)
set(CMAKE_ASM_COMPILER ${CROSS_COMPILER_PREFIX}gcc)  # Use gcc for assembly as well
set(CMAKE_OBJCOPY ${CROSS_COMPILER_PREFIX}objcopy)
set(CMAKE_OBJDUMP ${CROSS_COMPILER_PREFIX}objdump)

# Set the sysroot if necessary (often needed for includes and libraries)
# Example: set(CMAKE_SYSROOT /home/hao/luckfox-pico/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/arm-rockchip830-linux-uclibcgnueabihf/sysroot)
# If your toolchain handles sysroot implicitly, you might not need this.
# Adjust the path above if your sysroot is located elsewhere within the toolchain directory.

# Configure find commands
# set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# --- Compiler Flags (Project-Wide) ---
add_compile_options(
    -nostdlib # 裸机程序，不使用标准库
    # -O3 -g0
    # C Specific
    # $<$<COMPILE_LANGUAGE:C>:-std=c99>
    # C++ Specific
    # $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>

    # Common Warnings
    # -Wall -Wshadow -Wundef -Wmissing-prototypes -Wno-discarded-qualifiers -Wextra
    # -Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith -fno-strict-aliasing
    # -Wno-error=cpp -Wuninitialized -Wmaybe-uninitialized -Wno-unused-parameter
    # -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess
    # -Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default
    # -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers
    # -Wno-error=pedantic -Wno-sign-compare -Wno-error=missing-prototypes
    # -Wdouble-promotion -Wclobbered -Wdeprecated -Wempty-body -Wtype-limits
    # -Wshift-negative-value -Wstack-usage=2048 -Wno-unused-value
)