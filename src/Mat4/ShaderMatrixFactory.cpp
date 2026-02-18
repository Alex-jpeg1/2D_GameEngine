#include "ShaderMatrixFactory.hpp"
#include "Mat4.hpp"

UMatrix::MatrixesUtils::MatrixesUtils(Shader& bindedShader)
    :_bindedShader{bindedShader}
{}
int UMatrix::MatrixesUtils::UploadMatrix()
{
    int projectionID = _bindedShader.UploadProjectionMatrix("Projection"); 
    glUniformMatrix4fv(projectionID, 1, GL_FALSE, _matrix.GetData().data());

    return projectionID;
}

UMatrix::FOrtoghonalMatrix::OrtoghonalMatrixFactory::OrtoghonalMatrixFactory(Shader& bindedShader, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top)
    :MatrixesUtils(bindedShader)
{
    _matrix = CustomMat4::Matrix(left, right, bottom, top);
}

UMatrix::UTransformationMatrix::TransformationMatrixUtils::TransformationMatrixUtils(Shader& bindedShader)
    :MatrixesUtils{bindedShader}
{
    _matrix = CustomMat4::Matrix(4);
}
EmptyReturn UMatrix::UTransformationMatrix::TransformationMatrixUtils::ModifyMatrix(Direction dir, GLfloat val)
{
    switch (dir) 
    {
        case Direction::left:

        case Direction::right:

        case Direction::down:

        default:
        {
            throw MatrixError::UnknownValue;
        }
    }
}