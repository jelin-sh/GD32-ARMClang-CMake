#设置CMake最低支持版本
cmake_minimum_required(VERSION 3.17)

#引用ARMClang_Cortex-M4.cmake
include(ARMClang_Cortex-M4.cmake)

#关闭FPU
CMSIS_EnableFPU(FALSE)

#设置Sections脚本路径
CMSIS_SetSectionsScriptPath(${CMAKE_HOME_DIRECTORY}/FOC_GD32F303_Test.sct)

#配置交叉编译
CMSIS_CrossCompilingConfiguration()

#设置工程名
project(EmbeddedProject_Demo C CXX ASM)

#设置C标准版本
set(CMAKE_C_STANDARD 99)

#设置C++标准版本
set(CMAKE_CXX_STANDARD 11)

#添加全局宏定义
add_definitions(-DGD32F30X_HD -DUSE_STDPERIPH_DRIVER)

#添加头文件引用目录
include_directories(
        CMSIS
        System
        Platform/Inc
)

#添加源文件
file(GLOB_RECURSE SOURCES "Platform/Src/*.c" "System/*.*")

#添加生成可执行文件
add_executable(EmbeddedProject_Demo
        ${SOURCES}
        main.c
)


