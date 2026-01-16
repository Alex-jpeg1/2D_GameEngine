#pragma once

#include "objects.hpp"
#include "../Gravity/Gravity.hpp"

class Player:public Objects::GameObject
{
    public:

    private:
    Alex::GravityComponent _Gravity;
};

//A player will have to have Gravity applied to him