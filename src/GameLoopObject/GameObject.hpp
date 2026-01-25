#pragma once

#include "../GameEngine_all.hpp"
#include "../WindowCreationObject/CreateWindow.hpp"

class GameObject
{
    public:
    GameObject();

    GameObject(const GameObject&) = delete;
    void operator=(const GameObject&) = delete;
    //we do not want the GameObject to be copied

    //TO-DO implement move operator and move constructor
    GameObject(GameObject&&); 
    GameObject operator=(GameObject&&);
    //The GameObject can be moved but it will require custom implementation based on the purpose

    //TO-DO implement Main Game loop
    EmptyReturn MainGameLoop();


    private:

    WindowObject _window;
    //A game object will run on a single window
    //The user does not need to have direct acces to this window
};