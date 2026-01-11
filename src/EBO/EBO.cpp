#include "EBO.hpp"

EBO::EBO(const std::vector<GLuint>& indices, const GLsizeiptr& size)
{
    glGenBuffers(1, &_ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &indices[0], GL_DYNAMIC_DRAW);
}

EmptyReturn EBO::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ID);
}

EmptyReturn EBO::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

EmptyReturn EBO::Delete()
{
    glDeleteBuffers(1, &_ID);
}
EBO::~EBO()
{
    Delete();
}