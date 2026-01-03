#include <iostream>
#include "../glad/glad.h"
#include "resources/resources.hpp"
#include <GLFW/glfw3.h>
#include <cstddef>
#include <iostream>
#include "VAO/VAO.hpp"
#include "VBO/VBO.hpp"
#include "EBO/EBO.hpp"
#include <math.h>
#include <vector>
#include "Shaders/ShadersClass.hpp"

std::vector<GLfloat> vertices =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
};

// Indices for vertices order
std::vector<GLuint> indices =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};

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

    Shader shaderProgram("Shaders/ShadersInfo/default.vert", "Shaders/ShadersInfo/default.frag");

    CreateContext(&window);

    VAO _VAO;
    _VAO.Bind();
    VBO _VBO(vertices, vertices.size() * sizeof(GLfloat));
    EBO _EBO(indices, indices.size() * sizeof(GLuint));

    _VAO.LinkVBO(_VBO, 0);

    _VAO.Unbind();
    _VBO.Unbind();
    _EBO.Unbind();

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f ,0.13f ,0.17f , 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();

        _VAO.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        
        glfwSwapBuffers(window);

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