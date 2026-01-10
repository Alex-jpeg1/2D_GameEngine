#pragma once
#include "Vector2D.hpp"

namespace Objects
{
    class Rectangle
    {
        public:
        Rectangle(const XValue& x, const YValue& y, const Height& height, const Width& width, const ShaderType& ShaderTypeValue);

        Positions GetPositions();
        private:

        Positions GetNormalizedPositions(const Positions InitialValues);
        GLfloat Normalize(const GLfloat& Value,const WindowSize& WindowValue);
        const ShaderType _ShaderType; 
        Vector2DCustom::vect2d _LeftDownCorner; 
        Vector2DCustom::vect2d _RectangleSizes; //Width in place of x and height in place of y
    };
}
