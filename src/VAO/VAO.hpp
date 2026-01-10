#pragma once

#include "../../glad/glad.h"
#include "../resources/resources.hpp"
#include "../VBO/VBO.hpp"

class VAO
{
public:
    VAO();
    EmptyReturn LinkVBO(VBO& VBO, const GLuint& layout);
    
    EmptyReturn Bind();
    EmptyReturn Unbind();
    EmptyReturn Delete();

private:
    GLuint _ID;
};