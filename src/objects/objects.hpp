#include "Vector2D.hpp"

namespace Objects
{
    class Rectangle
    {
        public:
        Rectangle();
        Rectangle(const XValue& x, const YValue& y, const Height& height, const Width& width);
        EmptyReturn Render();

        private:

        Vector2DCustom::vect2d _LeftUpperCorner; 
        Vector2DCustom::vect2d _RectangleSizes; //Width in place of x and height in place of y
    };
}