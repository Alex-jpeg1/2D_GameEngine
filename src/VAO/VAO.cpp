#include "VAO.hpp"

//Creates the Id for the VAO
VAO::VAO()
{
    glGenVertexArrays(1, &_ID);
}

EmptyReturn VAO::LinkVBO(VBO& VBO, const GLuint& layout)
{
    VBO.Bind();

    glVertexAttribPointer(layout, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)(0));
    glEnableVertexAttribArray(layout);

    VBO.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(_ID);
}

// Unbinds the VAO
void VAO::Unbind()
{
	glBindVertexArray(0);
}

// Deletes the VAO
void VAO::Delete()
{
	glDeleteVertexArrays(1, &_ID);
}