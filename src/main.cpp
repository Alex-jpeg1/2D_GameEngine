#include "GameLoopObject/GameObject.hpp"

int main()
{
    glfwInit();
    {   
        Factory MainObject;
        MainObject.MainGameLoop();
    }
    glfwTerminate();
    return 0;
}