#include "Mat4.hpp"

CustomMat4::Matrix::Matrix(int matrixSize)
:Vertexes(matrixSize * matrixSize)
{}

CustomMat4::Matrix::Matrix(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top)
:Matrix{4}
{
    PopulateMatrix(left, right, bottom, top);
}

CustomMat4::Matrix::Matrix(GLfloat Value, int matrixSize)
:Matrix{matrixSize}
{
    init(matrixSize, Value);
}

EmptyReturn CustomMat4::Matrix::init(int matrixSize, GLfloat val)
{
    int pozCurrent = 0;

    for(int i = 0;i < matrixSize; i++)
    {
        Vertexes[pozCurrent] = val;
        pozCurrent += matrixSize + 1; 
    }
}

EmptyReturn CustomMat4::Matrix::PopulateMatrix(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top,int matrixSize)
{
        Vertexes[0] = 1.0f/(right - left);
        Vertexes[12] = -1.0f;

        Vertexes[5] = 1.0f/(top-bottom);
        Vertexes[13] = -1.0f;

        Vertexes[10] = 0;
        Vertexes[14] = 0;

        Vertexes[15] = 1;
}