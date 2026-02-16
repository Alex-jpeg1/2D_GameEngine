#pragma once

#include"../GameEngine_all.hpp"
namespace CustomMat4
{
    class Matrix
    {
        public:
            
            Matrix(int = 4);
            
            Matrix(GLfloat, GLfloat, GLfloat, GLfloat );
            
            Matrix(GLfloat, int = 4);
        private:
            EmptyReturn init(int, GLfloat = 1.0f);
            EmptyReturn PopulateMatrix(GLfloat, GLfloat, GLfloat, GLfloat, int = 4);

            std::vector<GLfloat> Vertexes;
    };
}