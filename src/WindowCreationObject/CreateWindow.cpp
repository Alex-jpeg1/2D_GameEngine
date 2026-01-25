#include "CreateWindow.hpp"
#include <GLFW/glfw3.h>

WindowObject::WindowObject()
    :
    WindowObject(CUSTOM_DefaultHeight, CUSTOM_DefaultWidth)
    {}
WindowObject::WindowObject(const WindowHeight& windowHeight, const WindowWidth& windowWidth)
    :
    _WindowHeight{windowHeight},
    _WindowWidth{windowWidth},
    _window{glfwCreateWindow(_WindowWidth, _WindowHeight, "Game", NULL, NULL)}
{
    if(_window == NULL)
    {
        ErrorMsg = WC_Messages::WC_Fail;
    }
}

EmptyReturn WindowObject::DefaultHints()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

