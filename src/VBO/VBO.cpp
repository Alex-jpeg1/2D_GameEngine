#include "VBO.hpp"

VBO::VBO(const std::vector<GLfloat>& vertices, const GLsizeiptr& size)
{

    glGenBuffers(1, &_ID);
    glBindBuffer(GL_ARRAY_BUFFER, _ID);
    glBufferData(GL_ARRAY_BUFFER, size, &vertices[0], GL_DYNAMIC_DRAW);

}

EmptyReturn VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, _ID);
}

EmptyReturn VBO::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

EmptyReturn VBO::Delete()
{
    glDeleteBuffers(1, &_ID);
}