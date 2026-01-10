cmake_minimum_required(VERSION 3.10)
project(MyOpenGLGame)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)

add_executable(MyApp 
    src/main.cpp 
    src/objects/objects.cpp 
    src/objects/enviroment.cpp 
    src/objects/Player.cpp 
    src/KeyEvents/KeyEvents.cpp 
    src/objects/Vector2D.cpp 
    src/Shaders/ShadersClass.cpp
    src/EBO/EBO.cpp
    src/VAO/VAO.cpp
    src/VBO/VBO.cpp
    gladsrc/glad.c
    src/Textures/Textures.cpp
    src/extern/stb_image.h
    src/resources/resources.cpp
)

target_include_directories(MyApp PRIVATE 
    src 
    gladsrc/include
    ${GLFW_INCLUDE_DIRS}
)

target_link_libraries(MyApp PRIVATE
    ${GLFW_LIBRARIES}
    ${OpenGL_LIBRARIES}
    ${X11_LIBRARIES}
    Xrandr Xi Xinerama Xcursor 
    dl                        
)
