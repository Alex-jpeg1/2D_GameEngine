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

enum class WC_Messages
{
    WC_Succesfull,
    WC_Fail
};

class WindowObject
{
    public:
    WindowObject();
    WindowObject(const WindowHeight&, const WindowWidth& windowWidth);

    EmptyReturn DefaultHints();

    ~WindowObject();

    WC_Messages GetCreationMessage() {return ErrorMsg;};
    
    private:

    const WindowHeight _WindowHeight;
    const WindowWidth _WindowWidth;
    GLFWwindow* _window;
    WC_Messages ErrorMsg;
};