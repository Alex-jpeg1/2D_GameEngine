#include "CreateWindow.hpp"
#include <GLFW/glfw3.h>
#include <initializer_list>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
WindowObject::WindowObject()
    :
    WindowObject(CUSTOM_DefaultHeight, CUSTOM_DefaultWidth)
    {}
WindowObject::WindowObject(const WindowHeight& windowHeight, const WindowWidth& windowWidth)
    :
    _WindowHeight{windowHeight},
    _WindowWidth{windowWidth},
    _ErrorMsg{WC_Messages::WC_Succesfull}
{

    DefaultHints();
    _window = glfwCreateWindow(_WindowWidth, _WindowHeight, "Game", NULL, NULL);
    
    if(_window == NULL)
    {
        _ErrorMsg = WC_Messages::WC_Fail;
    }

    if(_ErrorMsg == WC_Messages::WC_Succesfull)
    {
        CreateContext();
    }
}

WindowObject::~WindowObject()
{
    glfwDestroyWindow(_window);
}

EmptyReturn WindowObject::DefaultHints()
{
    SetHints({
            {GLFW_CONTEXT_VERSION_MAJOR,3},
            {GLFW_CONTEXT_VERSION_MINOR, 3},
            {GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE}
            });
}

EmptyReturn WindowObject::SetHints(std::initializer_list<WindowHint> WindowHints)
{
    for(const WindowHint& Hint: WindowHints)
    {
        glfwWindowHint(Hint.target, Hint.Value);
    }
}
EmptyReturn WindowObject::CreateContext()
{

    glfwMakeContextCurrent(_window);
    gladLoadGL();
    glViewport(0,0,_WindowWidth,_WindowHeight);
}