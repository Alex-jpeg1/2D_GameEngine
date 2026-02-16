#pragma once

#include "../GameEngine_all.hpp"
#include "../WindowCreationObject/CreateWindow.hpp"

class ShaderSupport
{
    
};

class Factory
{
    public:
    Factory();

    Factory(const Factory&) = delete;
    void operator=(const Factory&) = delete;
    //we do not want the GameObject to be copied

    Factory(Factory&&) = delete; 
    Factory operator=(Factory&&) = delete;
    //The GameObject can be moved but it will require custom implementation based on the purpose

    //TO-DO implement Main Game loop
    EmptyReturn MainGameLoop();

    private:

    WindowObject _window;
    int _projectionID;
    //A game object will run on a single window
    //The user does not need to have direct acces to this window
};

