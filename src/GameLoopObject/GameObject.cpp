#include "GameObject.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "../Mat4/ShaderMatrixFactory.hpp"
#include "../objects/Player.hpp"
Factory::Factory():
    _window{}
{}
std::vector<GLuint> indices =
{
	0, 1, 2, 
	2, 1, 3,
    4, 5, 6,
    6,5,7
};

std::ostream& operator<<(std::ostream& os, std::vector<GLfloat> valori)
{
    for(auto x:valori)
    {
        os<<x<<" ";
    }
    return os;
}

EmptyReturn Factory::MainGameLoop()
{
    Shader shaderProgram("../src/Shaders/ShadersInfo/default.vert", "../src/Shaders/ShadersInfo/default.frag");


    Player TestRectangle(100,100,100,100,static_cast<GetShaderType::TileType>(0));
    Player TestRectangle1(400,400,100,100,static_cast<GetShaderType::TileType>(0));
    Texture NewTexture("../src/Textures/Images/johnPork.jpg");

    UMatrix::FOrtoghonalMatrix::OrtoghonalMatrixFactory mat4(shaderProgram,0,800,0,800);

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
        
    while(!_window.WindowShouldClose())
    {
        glClearColor(0.0f ,0.8f ,0.8f , 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();
        mat4.UploadMatrix();
        NewTexture.Load();
        _VAO.Bind();
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

        _window.BufferSwap();
        glfwPollEvents();
    }
    shaderProgram.Delete();
}
