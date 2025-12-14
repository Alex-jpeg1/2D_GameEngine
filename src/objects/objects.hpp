#pragma once
#include <GLFW/glfw3.h>

constexpr double PI = 3.14159;


enum class CollisionStates
{
    NoCollision,
    HeadCollision,
    BodyCollision,
    FeetCollision
};

namespace BasicObject
{
    class BasicObject
    {
        public:
            BasicObject(double _CenterX, double _CenterY);
            virtual void UpdateCenter(double _UpdateX, double _UpdateY);
        protected:
            double CenterX,CenterY;
    };
    //The basic object will check for collisions with every other object
    //The basic object will check for the relative position of the surrounding objects
    //The basic object will then compose the square and the circle hitboxes
}

namespace HitBox
{ 
class HalfCircle: public BasicObject::BasicObject
{
    public:
        HalfCircle(double _CenterX, double _CenterY, double _radius, int _NumberVertices);
        void render() const;
    private:
        const int NumberVertices;
        const double radius;
};
class Square: public BasicObject::BasicObject
{
    public: 
        Square(double _CenterX, double _CenterY, double _Height, double _Width);
        void render() const;
        //template<class CollisionObject>
        //CollisionStates CheckCollision(CollisionObject& Object) const;

    private:
        const double Height,Width;
};
};

namespace Player
{

    class Player
    {
        public:
            Player();
            //template<class ColisionObject>
            //CollisionStates CheckCollision(ColisionObject& Object) const;

            void UpdatePositions(GLFWwindow* window, double DeltaTime)
            {
                if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
                {
                    headPart.UpdateCenter(velocity * DeltaTime, 0);
                    bodyPart.UpdateCenter(velocity * DeltaTime, 0);
                    //Update the X position of the objects 
                }
            }
            void Render()
            {
                bodyPart.render();
                headPart.render();
            }
            //templated function to not rewrite every type of collision with every object 
        private:
            HitBox::HalfCircle headPart;
            HitBox::Square bodyPart;
            const double velocity = 0.1;  
        //The hitbox of a player will be created from 2 objects a Circle and a square
        //The head will interact with either a ceiling or other flying objects 
        //The body will interact with the ground, slopes or any other part
        //The game i intend to create will be pixelated so i do not need a circle as the body to create smoothness as the enviroment will be square
    };
}
