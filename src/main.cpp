#include "GameLoopObject/GameObject.hpp"

int main()
{
    glfwInit();
    {   
        GameObject MainObject;
        MainObject.MainGameLoop();
    }
    glfwTerminate();
    return 0;
}