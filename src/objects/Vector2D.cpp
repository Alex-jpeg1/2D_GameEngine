#include "objects.hpp"
#include "../resources/resources.hpp"

Vector2D::vect2d::vect2d():
    Xposition{static_cast<XPosition>(0)},
    Yposition{static_cast<YPosition>(0)}
{}
Vector2D::vect2d::vect2d(XPosition _Xposition, YPosition _Yposition):
    Xposition{_Xposition},
    Yposition{_Yposition}
    {}