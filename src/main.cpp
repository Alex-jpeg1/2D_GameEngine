#include <iostream>
#include "../glad/glad.h"
#include "resources/resources.hpp"
#include <GLFW/glfw3.h>
#include <cstddef>
#include <iostream>

EmptyReturn UpdateHints()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

enum class WC_Messages
{
    WC_Succesfull,
    WC_Fail
};

WC_Messages CreateWindow(GLFWwindow ** window, const WindowHeight& windowHeight = CUSTOM_DefaultHeight, const WindowWidth& windowWidth = CUSTOM_DefaultWidth)
{
    *window = glfwCreateWindow(CUSTOM_DefaultWidth, CUSTOM_DefaultHeight, "Game", NULL, NULL);

    if(*window == NULL)
    {
        return WC_Messages::WC_Fail;
    }

    return WC_Messages::WC_Succesfull;
}

EmptyReturn CreateContext(GLFWwindow** window)
{

    glfwMakeContextCurrent(*window);
    gladLoadGL();
    glViewport(0,0,CUSTOM_DefaultWidth,CUSTOM_DefaultHeight);
}

EmptyReturn Update()
{
    glfwInit();

    UpdateHints();

    GLFWwindow * window;
    
    switch(CreateWindow(&window))
    {
        case WC_Messages::WC_Fail:
        {
            glfwTerminate();
            std::cerr << "Window creation failure";
            std::exit( static_cast< Error > ( WC_Messages::WC_Fail ) );
        }
        case WC_Messages::WC_Succesfull:
        {
            ;//it just continues
        }
    }
    CreateContext(&window);

    glClearColor(0.07f ,0.13f ,0.17f , 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}

int main()
{
    Update();
    return 0;
}