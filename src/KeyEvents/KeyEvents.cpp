#include "KeyEvents.hpp"
#include <GLFW/glfw3.h>



KeyEvent::KeyEvent(const int& _key, const int& _scancode, const int& _action, const int& _mods, const TimePoint& _inputTime):key(_key),
                                                                                                                             scancode(_scancode),
                                                                                                                             action(_action),
                                                                                                                             mods(_mods),
                                                                                                                             inputTime(_inputTime){}
                                                                                           
void HandleInput(Player::Player& player)
{
    while(!UnhandledInputs.empty())
    {
        KeyEvent current = UnhandledInputs.front();
        UnhandledInputs.pop();
        int key = current.key;
        int action = current.action;
        switch (key) 
        {
            case GLFW_KEY_W:
            {
                if(action == GLFW_PRESS || action == GLFW_REPEAT)
                {
                       player.UpdateJump();
                }
            }
        }
    }
}