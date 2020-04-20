CMAKE_MINIMUM_REQUIRED(VERSION 3.13)
PROJECT(packman)
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(packman ${DIR_SRCS})

find_library(OPEN_GL OpenGL)
find_library(COCOA Cocoa)
find_library(CORE_VIDEO CoreVideo)
find_library(IOKIT IOKit)
find_library(CARBON Carbon)
find_package(glm REQUIRED)

link_libraries(GLEW)
link_libraries(glfw3)
link_libraries(SOIL)

TARGET_LINK_LIBRARIES( packman GLEW )
TARGET_LINK_LIBRARIES( packman SOIL )
TARGET_LINK_LIBRARIES( packman glfw3 )
TARGET_LINK_LIBRARIES( packman ${OPEN_GL})
TARGET_LINK_LIBRARIES( packman ${COCOA})
TARGET_LINK_LIBRARIES( packman ${CORE_VIDEO})
TARGET_LINK_LIBRARIES( packman ${IOKIT})
TARGET_LINK_LIBRARIES( packman ${CARBON})
TARGET_LINK_LIBRARIES( packman glm)

set_property(TARGET packman PROPERTY CXX_STANDARD 14) 
set_property(TARGET packman PROPERTY CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++0x -stdlib=libc++")
set(CMAKE_CXX_COMPILER      "clang++" )         # 显示指定使用的C++编译器

set(CMAKE_CXX_FLAGS   "-std=c++11")             # c++11
set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告
