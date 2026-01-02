#include "../resources/resources.hpp"


namespace Vector2DCustom
{
    class vect2d
    {   
    public:
    
        vect2d();
        vect2d(const XValue& Xval, const YValue& Yval);

        [[ nodiscard ]] XValue GetXVal() const { return _X; }
        [[ nodiscard ]] YValue GetYVal() const { return _Y; }

        EmptyReturn UpdateX(const Size& val);
        EmptyReturn UpdateY(const Size& val);

    private:
        XValue _X;
        YValue _Y;
    };
}