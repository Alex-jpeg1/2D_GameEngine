#include <iostream>
#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include <chrono>
#include <cstddef>


void UpdateHints()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Update()
{
    glfwInit();

    UpdateHints();
    GLFWwindow* window = glfwCreateWindow(800, 800, "Game", NULL, NULL); 

    if(window == NULL)
    {
        std::cout << "Error creating the window";
        glfwTerminate();

        return;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();

    glViewport(0,0,800,800);

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