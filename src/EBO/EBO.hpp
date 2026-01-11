#pragma once

#include "../../glad/glad.h"
#include <vector>
#include "../resources/resources.hpp"

class EBO
{
public:
    EBO() = default;
    EBO(const std::vector<GLuint>& indices,const GLsizeiptr& size);
    ~EBO();
    [[ nodiscard ]] GLuint Get_ID() const {return _ID; }
    
    EmptyReturn Bind();
    EmptyReturn Unbind();
    EmptyReturn Delete();

private:
    GLuint _ID;
};