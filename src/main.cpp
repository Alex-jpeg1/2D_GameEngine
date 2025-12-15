#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <thread>
#include "objects/objects.hpp"
#include<vector>
#include<iostream>

constexpr std::chrono::duration<double> TargetFrameRate = std::chrono::duration<double>(1.0/100.0);


int contor = 0;
//These will be the main components for hitboxes
class Game{
    public:
        Game()
        {
            Surrounding::Ground obj(0.0, -0.9, 0.2, 0.5, 0);
            Ground.emplace_back(obj);
        }
        void Update()
        {
            Player::Player player;
            glfwInit();
            GLFWwindow* window = glfwCreateWindow(1000, 900, "OpenGL Tutorial", NULL, NULL);
            glfwMakeContextCurrent(window);
            glewInit();
            static auto LastTime = std::chrono::high_resolution_clock::now();
            while (!glfwWindowShouldClose(window)) 
            {
                auto CurrentTime = std::chrono::high_resolution_clock::now();
                glClear(GL_COLOR_BUFFER_BIT);
                for(auto& ground:Ground)
                {
                    player.CheckCollision(ground);
                    ground.render();
                }
                player.Render();
                std::chrono::duration<double> RawDeltaTime = CurrentTime-LastTime;
                double DeltaTime = RawDeltaTime.count(); 
                player.UpdatePositions(window,DeltaTime);

                glfwSwapBuffers(window);
                glfwPollEvents();
            
                auto EndTime = std::chrono::high_resolution_clock::now();
                auto DurationTime = EndTime - CurrentTime;
                LastTime = CurrentTime;
                if(TargetFrameRate > DurationTime)
                {
                    auto SleepTime = TargetFrameRate - DurationTime;
                
                    std::this_thread::sleep_for(SleepTime);
                }
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
    std::cout<<contor;
    return 0;
}
//The Update Function will play in the main thread to draw in there
//TO DO implement a second thread to load in the data of the current scene

