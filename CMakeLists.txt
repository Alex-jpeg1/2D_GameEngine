find_package(PkgConfig REQUIRED)

pkg_check_modules(GLEW_DEPS REQUIRED glew)

pkg_check_modules(GLFW_DEPS REQUIRED glfw3)

add_executable(MyApp src/main.cpp src/objects/objects.cpp src/objects/enviroment.cpp src/objects/player.cpp)

target_link_libraries(MyApp PUBLIC
    ${GLEW_DEPS_LDFLAGS} 
    ${GLEW_DEPS_LIBS}

    ${GLFW_DEPS_LDFLAGS}
    ${GLFW_DEPS_LIBS}
    
    ${OpenGL_LIBRARIES}
    ${X11_LIBRARIES}
)