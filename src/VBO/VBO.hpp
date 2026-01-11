#pragma once

#include "../../glad/glad.h"
#include <vector>
#include "../resources/resources.hpp"

class VBO 
{
    public:
        VBO() = default;
        VBO(const std::vector<GLfloat>& vertices, const GLsizeiptr& size);
        ~VBO();
        
        [[ nodiscard ]] GLuint Get_ID() const noexcept { return _ID; };

        EmptyReturn Bind();
        EmptyReturn Unbind();
        EmptyReturn Delete();

    private:
        GLuint _ID;
};