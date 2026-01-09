#include "objects.hpp"

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

    return {LeftCornerX, LeftCornerY, RightCornerX, RightCornerY};
}

