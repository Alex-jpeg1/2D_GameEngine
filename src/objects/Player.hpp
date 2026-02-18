#pragma once

#include "objects.hpp"
#include "../Gravity/Gravity.hpp"
//TO DO: Implement a unique vbo for the player 
class Player:public Objects::GameObject
{
    public:
        Player(const XValue& , const YValue& , const XValue& , const YValue& , GetShaderType::TileType);
        
    private:
        Alex::GravityComponent _Gravity;
};

//A player will have to have Gravity applied to him