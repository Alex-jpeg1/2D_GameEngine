cmake_minimum_required(VERSION 3.10)
project(MyOpenGLGame)

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

target_compile_features(MyApp PRIVATE cxx_std_17)