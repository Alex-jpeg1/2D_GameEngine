#include "KeyEvents.hpp"
#include <GLFW/glfw3.h>



KeyEvent::KeyEvent(const int& _key, const int& _scancode, const int& _action, const int& _mods, const TimePoint& _inputTime):key(_key),
                                                                                                                             scancode(_scancode),
                                                                                                                             action(_action),
                                                                                                                             mods(_mods),
                                                                                                                             inputTime(_inputTime){}

bool ValidateInput(const TimePoint& myTimePoint,const TimePoint& MaximumTimePoint)
{
    return myTimePoint < MaximumTimePoint;
}
//This validates the number of inputs at a given time to not block the main thread in case of multiple inputs
EmptyReturn HandleInput(Player::Player& player, const TimePoint& MaximumTimePoint)
{
    while(!UnhandledInputs.empty() && ValidateInput(UnhandledInputs.front().inputTime, MaximumTimePoint))
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
            case GLFW_KEY_D:
            {
                if(action == GLFW_PRESS || action == GLFW_REPEAT)
                {
                    
                }
            }
        }
    }
}