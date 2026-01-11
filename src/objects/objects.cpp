#include "objects.hpp"
#include <GLFW/glfw3.h>
#include <cstddef>

Objects::Rectangle::Rectangle(const XValue& xVal, const YValue& yVal, const Height& height, const Width& width)
    :
     _LeftDownCorner( xVal, yVal),
     _RectangleSizes(width, height)
     {}

Positions Objects::Rectangle::GetPositions()
{
    XValue LeftCornerX = 0, RightCornerX = 0;
    YValue LeftCornerY = 0, RightCornerY = 0;

    LeftCornerX = _LeftDownCorner.GetXVal();
    LeftCornerY = _LeftDownCorner.GetYVal();

    RightCornerX = LeftCornerX + _RectangleSizes.GetWidth();
    RightCornerY = LeftCornerY + _RectangleSizes.GetHeight();

    return GetNormalizedPositions({LeftCornerX,
                                                  LeftCornerY, 
                                                  RightCornerX,
                                                  LeftCornerY, 
                                                  LeftCornerX, 
                                                  RightCornerY, 
                                                  RightCornerX, 
                                                  RightCornerY});
}

GLfloat Objects::Rectangle::Normalize(const GLfloat& Value, const WindowSize& WindowValue)
{
    GLfloat FinalValue = Value - static_cast<GLfloat>(WindowValue/2.0);
    
    FinalValue /= static_cast<GLfloat>(WindowValue/2.0);

    return FinalValue;
}

Positions Objects::Rectangle::GetNormalizedPositions(const Positions InitialValues)
{
    Positions FinalValue;
    for(std::size_t i=0; i < InitialValues.size(); i++)
    {
        GLfloat Val = InitialValues[i];
        if(i % 2 == 0)
        {
            FinalValue.emplace_back(Normalize(Val, CUSTOM_DefaultWidth));
        }
        else 
        {
            FinalValue.emplace_back(Normalize(Val, CUSTOM_DefaultHeight));
        }
    }
    return FinalValue;
}

Objects::GameObject::GameObject(const XValue& XPosition, const YValue& YPosition, const XValue& width, const YValue& height, GetShaderType::TileType TexType):
    _HitBox(XPosition, YPosition,width, height),
    _TexType(static_cast<TextureType>(TexType))
{}

Positions Objects::GameObject::TexturePositionsCalculations()
{
    Positions InitialPositions = _HitBox.GetPositions();
    TextureColumns Line = GetLine();

    Positions result;
    for(std::size_t i = 0; i < NumberCorners; i++)
    {
        Positions CurrentCorner = GetPositionsTexture(static_cast<Corners>(i), Line);
        result.emplace_back(InitialPositions[2*i]);
        result.emplace_back(InitialPositions[2*i+1]);

        result.insert(result.end(), CurrentCorner.begin(), CurrentCorner.end());
    }
    return result;
}

TextureColumns Objects::GameObject::GetLine()
{
    return _TexType/MaximumTextureColumn;
}

[[ nodiscard ]] Positions Objects::GameObject::GetPositionsTexture(Corners corner, TextureColumns line) noexcept
{
    switch (corner) 
    {
        case Corners::_LeftCornerDown:
        {
            return{0,1}; 
        }
        case Corners::_LeftCornerUp:
        {
            return{0,0};
        }
        case Corners::_RightCornerDown:
        {
            return{1,1};
        }
        case Corners::_RightCornerUp:
        {
            return{1,0};
        }
    }
    return {};
}

GLfloat Objects::GameObject::GetPositionHeight()
{
    return 0;
}