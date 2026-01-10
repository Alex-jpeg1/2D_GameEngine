#include "objects.hpp"
#include <GLFW/glfw3.h>
#include <cstddef>

Objects::Rectangle::Rectangle(const XValue& xVal, const YValue& yVal, const Height& height, const Width& width, const ShaderType& ShaderTypeValue)
    :_ShaderType{ShaderTypeValue},
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