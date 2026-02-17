#include "Mat4.hpp"

CustomMat4::Matrix::Matrix(int matrixSize)
:_Vertexes(matrixSize * matrixSize)
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
        _Vertexes[pozCurrent] = val;
        pozCurrent += matrixSize + 1; 
    }
}

EmptyReturn CustomMat4::Matrix::PopulateMatrix(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top,int matrixSize)
{
        _Vertexes[0] = 2.0f/(right - left);
        _Vertexes[12] = -1.0f;

        _Vertexes[5] = 2.0f/(top-bottom);
        _Vertexes[13] = -1.0f;

        _Vertexes[10] = 0;
        _Vertexes[14] = 0;

        _Vertexes[15] = 1;
}

std::vector<GLfloat> CustomMat4::Matrix::GetData()
{
    return _Vertexes;
}