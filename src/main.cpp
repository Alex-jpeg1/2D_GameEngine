#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <iomanip>
#include <thread>
#include <vector>
#include <iostream>
#include "KeyEvents/KeyEvents.hpp"

constexpr std::chrono::duration<double> TargetFrameRate = std::chrono::duration<double>(1.0/100.0);
std::queue<KeyEvent> UnhandledInputs;

long double contor = 0; //debug tool
//These will be the main components for hitboxes

Player::Player player; //global to call it from the call_back

void call_back(GLFWwindow* window, int key, int scancode, int action, int mods)
{

    UnhandledInputs.emplace(KeyEvent(key,scancode,action,mods));
}

class Game{
    public:
        Game()
        {
            Surrounding::Ground obj(0.0, -0.9, 0.2, 0.5, 0);
            Surrounding::Ground obj1(0.6, -0.7, 0.2, 0.5, 1);
            Ground.emplace_back(obj);
            //Ground.emplace_back(obj1);
        }
        void Update()
        {
            glfwInit();
            GLFWwindow* window = glfwCreateWindow(1000, 900, "OpenGL Tutorial", NULL, NULL);
            glfwMakeContextCurrent(window);
            
            glfwSetKeyCallback(window, call_back);
            glewInit();
            static auto LastTime = std::chrono::high_resolution_clock::now();

            while (!glfwWindowShouldClose(window)) 
            {
                auto CurrentTime = std::chrono::high_resolution_clock::now();
                glClear(GL_COLOR_BUFFER_BIT);

                for(auto& ground:Ground)
                {

                    player.CheckCollisionY(ground);
                    ground.render();
                }
                player.Render();
                std::chrono::duration<double> RawDeltaTime = CurrentTime-LastTime;
                double DeltaTime = RawDeltaTime.count(); 
                player.UpdatePositions(DeltaTime);
                glfwSwapBuffers(window);
                glfwPollEvents();
            
                auto EndTime = std::chrono::high_resolution_clock::now();
                auto DurationTime = EndTime - CurrentTime;
                if(TargetFrameRate > DurationTime)
                {
                    auto SleepTime = TargetFrameRate - DurationTime;
                    
                    std::this_thread::sleep_for(SleepTime);
                }

                LastTime = CurrentTime;
            }
            //The main loop
            glfwDestroyWindow(window);
            glfwTerminate();
        }
        void ResourceFetch()
        {

        }
    private:
        std::vector<Surrounding::Ground> Ground;
};
int main() 
{
    Game game;
    std::thread t1(&Game::Game::ResourceFetch, &game); 
    game.Update();
    t1.join();
    std::cout<<std::fixed<<std::setprecision(100)<<contor;
    return 0;
}
//The Update Function will play in the main thread to draw in there
//TO DO implement a second thread to load in the data of the current scene