#include "Vector2D.hpp"

Vector2DCustom::vect2d::vect2d():
                _X{ static_cast<XValue>(0) },
                _Y{ static_cast<YValue>(0) }
                {}
Vector2DCustom::vect2d::vect2d(const XValue& X, const YValue& Y):
                _X{X},
                _Y{Y}
                {}

EmptyReturn Vector2DCustom::vect2d::UpdateX(const Size& val)
{
    _X += val;
}
EmptyReturn Vector2DCustom::vect2d::UpdateY(const Size& val)
{
    _Y += val;
}