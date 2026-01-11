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
#include "objects/objects.hpp"
#include "Textures//Textures.hpp"

std::vector<GLuint> indices =
{
	0, 1, 2, 
	2, 1, 3,
    4, 5, 6,
    6,5,7
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
    
    Shader shaderProgram("../src/Shaders/ShadersInfo/default.vert", "../src/Shaders/ShadersInfo/default.frag");


    Objects::GameObject TestRectangle(100,100,100,100,static_cast<GetShaderType::TileType>(0));
    Objects::GameObject TestRectangle1(200,200,100,100,static_cast<GetShaderType::TileType>(0));    
    Texture NewTexture("../src/Textures/Images/johnPork.jpg");
    VAO _VAO;
    _VAO.Bind();
    std::vector<GLfloat> vertices = TestRectangle.TexturePositionsCalculations(); 
    std::vector<GLfloat> vertices1 = TestRectangle1.TexturePositionsCalculations();

    vertices.insert(vertices.end(), vertices1.begin(), vertices1.end());

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
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
	shaderProgram.Delete();
    glfwDestroyWindow(window);
    //glfwTerminate();
}

int main()
{
    glfwInit();
    Update();
    glfwTerminate();
    return 0;
}