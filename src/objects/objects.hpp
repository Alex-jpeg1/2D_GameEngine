#pragma once
#include "Vector2D.hpp"
#include "../VAO/VAO.hpp"
#include "../VBO/VBO.hpp"
#include "../EBO/EBO.hpp"

namespace Objects
{
    class Rectangle
    {
        public:
        Rectangle(const XValue& x, const YValue& y, const Height& height, const Width& width, const ShaderType& ShaderTypeValue);

        Positions GetPositions();
        private:

        const ShaderType _ShaderType; 
        Vector2DCustom::vect2d _LeftDownCorner; 
        Vector2DCustom::vect2d _RectangleSizes; //Width in place of x and height in place of y
    };
}
