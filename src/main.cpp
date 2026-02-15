#include "GameLoopObject/GameObject.hpp"

int main()
{
    glfwInit();
    {   
        Factory Game;
        Game.MainGameLoop();
    }
    glfwTerminate();
    return 0;
}