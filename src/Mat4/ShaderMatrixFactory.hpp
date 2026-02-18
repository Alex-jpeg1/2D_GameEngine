#pragma once

#include "Mat4.hpp"
#include "../Shaders/ShadersClass.hpp"
enum class Direction
{
    left,
    right, 
    down
};
enum class MatrixError
{
    UnknownValue
};
namespace UMatrix
{
    class MatrixesUtils
    {
        public:
            //MatrixesUtils();
            MatrixesUtils(Shader&);
            virtual ~MatrixesUtils() = default;

            MatrixesUtils(const MatrixesUtils&) = default;
            MatrixesUtils& operator=(const MatrixesUtils&) = default;

            MatrixesUtils(MatrixesUtils&&) = default;
            MatrixesUtils& operator=(MatrixesUtils&&) = default;

            [[nodiscard]] std::vector<GLfloat> GetMatrix() noexcept { return _matrix.GetData();}

            virtual int UploadMatrix();
            
            virtual EmptyReturn ModifyMatrix(Direction, GLfloat) = 0;
            
        protected:
            CustomMat4::Matrix _matrix;
            Shader& _bindedShader;
        
    };
    namespace FOrtoghonalMatrix
    {
        class OrtoghonalMatrixFactory: public MatrixesUtils
        {
            public:
                OrtoghonalMatrixFactory(Shader&, GLfloat, GLfloat, GLfloat, GLfloat);
                EmptyReturn ModifyMatrix(Direction, GLfloat) override {};
            private:
        };
    }
    namespace UTransformationMatrix
    {
        class TransformationMatrixUtils: public MatrixesUtils 
        {
            public:
                TransformationMatrixUtils(Shader&);
                EmptyReturn ModifyMatrix(Direction, GLfloat) override;
            private:
        };
    }
}