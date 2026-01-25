#include "WindowCreationObject/CreateWindow.hpp"



std::vector<GLuint> indices =
{
	0, 1, 2, 
	2, 1, 3,
    4, 5, 6,
    6,5,7
};


EmptyReturn Update()
{
    WindowObject window;

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

    while(!window.WindowShouldClose())
    {
        glClearColor(0.0f ,0.8f ,0.8f , 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();

        _VAO.Bind();
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

        window.BufferSwap();
        glfwPollEvents();
    }
	shaderProgram.Delete();
    //glfwTerminate();
}

int main()
{
    glfwInit();
    {   
    Update();
    }
    glfwTerminate();
    return 0;
}