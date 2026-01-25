#pragma once

#include "../../glad/glad.h"
#include "../resources/resources.hpp"
#include <GLFW/glfw3.h>
#include <cstddef>
#include <iostream>
#include "../VAO/VAO.hpp"
#include "../VBO/VBO.hpp"
#include "../EBO/EBO.hpp"
#include <math.h>
#include <vector>
#include "../Shaders/ShadersClass.hpp"
#include "../objects/objects.hpp"
#include "../Textures//Textures.hpp"
#include <initializer_list>
enum class WC_Messages
{
    WC_Succesfull,
    WC_Fail
};



class WindowObject
{
    private:
    
    struct WindowHint
    {
        int target;
        int Value;
    };

    public:
    WindowObject();
    WindowObject(const WindowHeight&, const WindowWidth& windowWidth);

    EmptyReturn DefaultHints();
    EmptyReturn SetHints(std::initializer_list<WindowHint>);
    ~WindowObject();

    WC_Messages GetCreationMessage() {return _ErrorMsg;};

    bool WindowShouldClose() { return glfwWindowShouldClose(_window); }

    EmptyReturn BufferSwap() { glfwSwapBuffers(_window); }
    private:

    EmptyReturn CreateContext();

    const WindowHeight _WindowHeight;
    const WindowWidth _WindowWidth;
    GLFWwindow* _window;
    WC_Messages _ErrorMsg;
};