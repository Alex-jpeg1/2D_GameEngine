#pragma once

#include "Mat4.hpp"
#include "../Shaders/ShadersClass.hpp"
namespace UMatrix
{
    class MatrixesUtils
    {
        public:
            MatrixesUtils() = default;
            MatrixesUtils(Shader&);
            virtual ~MatrixesUtils() = default;

            MatrixesUtils(const MatrixesUtils&) = default;
            MatrixesUtils& operator=(const MatrixesUtils&) = default;

            MatrixesUtils(MatrixesUtils&&) = default;
            MatrixesUtils& operator=(MatrixesUtils&&) = default;

            [[nodiscard]] std::vector<GLfloat> GetMatrix() noexcept { return _matrix.GetData();}

            virtual int UploadMatrix();
            
            virtual EmptyReturn ModifyMatrix() = 0;
            
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
                EmptyReturn ModifyMatrix() override {};
            private:
        };
    }
}