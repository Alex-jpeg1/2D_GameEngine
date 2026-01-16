#pragma once
#include "Vector2D.hpp"
#include "../Textures/Textures.hpp"
#include "../Shaders/ShadersClass.hpp"

namespace Objects
{
    class Rectangle
    {
        public:
        Rectangle(const XValue& x, const YValue& y, const Height& height, const Width& width);

        Positions GetPositions();
        
        private:
        Positions GetNormalizedPositions(const Positions InitialValues);
        GLfloat Normalize(const GLfloat& Value,const WindowSize& WindowValue);

        Vector2DCustom::vect2d _LeftDownCorner; 
        Vector2DCustom::vect2d _RectangleSizes; //Width in place of x and height in place of y
    };

    class GameObject 
    {
        public:
        
        GameObject(const XValue& XPosition, const YValue& YPosition,const XValue& width, const YValue& height, GetShaderType::TileType TextureType);

        Positions TexturePositionsCalculations();

        private:

        enum class Corners
        {
            _LeftCornerDown,
            _RightCornerDown,
            _LeftCornerUp,
            _RightCornerUp,
        };

        [[ nodiscard ]] Positions GetPositionsTexture(Corners , TextureColumns ) noexcept;

        GLfloat GetPositionHeight();
        TextureColumns GetLine();
        Rectangle _HitBox;
        TextureType _TexType;
    };
    //A GameObject will be a rectangle and will have a texture
}
