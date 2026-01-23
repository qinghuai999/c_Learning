cmake_minimum_required(VERSION 3.26)
project(c_Learning C)

set(CMAKE_C_STANDARD 17)

# ---- 让 CMake/CLion 知道 macOS SDK 在哪（解决 stdio.h 找不到）----
if(APPLE)
    execute_process(
            COMMAND xcrun --show-sdk-path
            OUTPUT_VARIABLE MACOSX_SDK_PATH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(CMAKE_OSX_SYSROOT "${MACOSX_SDK_PATH}")
endif()

# ---- 收集源码 ----
file(GLOB SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/*.c"
        "${PROJECT_SOURCE_DIR}/src/core_study/*.c"
        "${PROJECT_SOURCE_DIR}/src/utils/*.c"
)

# ---- 主程序可执行文件 ----
add_executable(c_Learning
        main.c          # 根目录下的 main.c
        ${SRC_FILES}
        src/core_study/week2.c
        src/core_study/week2/Week2Test2.c
        src/core_study/week2/Week2Test3.c
        src/core_study/week2/Week2Test5.c
        src/core_study/week2/Largest.c
        src/core_study/week2/Memory.c
        src/core_study/week2/Dynamic.c
)

# 头文件目录
target_include_directories(c_Learning PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
)

# 编译警告
target_compile_options(c_Learning PRIVATE -Wall -Wextra -Werror)

# ---- （可选）单元测试可执行文件 ----
file(GLOB TEST_FILES "${PROJECT_SOURCE_DIR}/test/*.c")

if(TEST_FILES)
    add_executable(run_tests ${TEST_FILES} ${SRC_FILES}
            src/core_study/week2/Largest.c)
    target_include_directories(run_tests PRIVATE "${PROJECT_SOURCE_DIR}/include")
    target_compile_options(run_tests PRIVATE -Wall -Wextra -Werror)
endif()