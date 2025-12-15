#pragma once
#include <GLFW/glfw3.h>
#include <csetjmp>
#include <type_traits>

constexpr double PI = 3.14159;

extern int contor;

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
            BasicObject();
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
        HalfCircle();
        HalfCircle(double _CenterX, double _CenterY, double _radius, int _NumberVertices);
        void render() const;
        //template <class CollisionObject>
        //CollisionStates CheckCollision(CollisionObject& object);

    private:
        const int NumberVertices;
        const double radius;
};
class Square: public BasicObject::BasicObject
{
    public: 
        Square();
        Square(double _CenterX, double _CenterY, double _Height, double _Width);
        void render() const;
        double ReturnPositionY() const ;
        double ReturnHeight() const ;
        double ReturnTop() const ;
        double ReturnPositionX() const ;
        double ReturnWidth() const ;
        double ReturnLeft() const ;
        double ReturnRight() const ;

        //template<class CollisionObject>
        //CollisionStates CheckCollision(CollisionObject& Object);

    protected:
        double Height,Width;
};
};

namespace Surrounding
{
    class Ground: public HitBox::Square
    {
        public:
            Ground(double _CenterX, double _CenterY, double _Height, double _Width, int _Position);
            double ReturnTop() const;
            double ReturnBottom() const;
            double ReturnLeft() const;
            double ReturnRight() const; 

            void Recenter();

            //This function is needed to redraw the surrounding terrain relative to the seated position of the player to not have evergrowing terrain
        private:
            int Position;
    };
    //The ground will have a square hitbox 
    //The ground will be positioned on the lowest part of the whole game
    //The ground will also be composed of some hills like structure
    //The ground will have a specific identifier to be able to assign a sprite to it 
}

namespace Player
{

    class Player
    {
        public:
            Player();
            template<class ColisionObject> void CheckCollision(ColisionObject& Object)
            {
                if constexpr (std::is_same_v<ColisionObject, Surrounding::Ground>)
                {
                    if(bodyPart.ReturnLeft() < Object.ReturnRight() && bodyPart.ReturnRight() > Object.ReturnLeft())
                    {
                        if(CalculateFeet() < Object.ReturnTop())
                        {
                            headPart.UpdateCenter(0, Object.ReturnTop() - CalculateFeet());
                            bodyPart.UpdateCenter(0, Object.ReturnTop() - CalculateFeet());
                            isGrounded = true;
                        }
                    }
                    else  
                    {
                        isGrounded = false;
                    }
                }
            }
            //Templated function to not rewrite every type of collision with every object 
            //This function will call the specific object Collision  
            void UpdatePositions(GLFWwindow* window, double DeltaTime)
            {
                if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
                {
                    headPart.UpdateCenter(velocity * DeltaTime, 0);
                    bodyPart.UpdateCenter(velocity * DeltaTime, 0);
                    //Update the X position of the objects 
                }
                if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && isGrounded)
                {
                    FallingSpeed = 2;
                    isGrounded = false;
                    MaximumHeightTouched = bodyPart.ReturnPositionY() + maxHeightJump;
                    isInJump = true;
                }
                if(!isGrounded)
                {
                    bodyPart.UpdateCenter(0, FallingSpeed * DeltaTime);
                    headPart.UpdateCenter(0, FallingSpeed * DeltaTime);

                    if(isInJump && bodyPart.ReturnPositionY() >= MaximumHeightTouched)
                    {
                        headPart.UpdateCenter(0, MaximumHeightTouched-bodyPart.ReturnPositionY());
                        bodyPart.UpdateCenter(0, MaximumHeightTouched-bodyPart.ReturnPositionY());
                        FallingSpeed = -2;
                        isInJump = false;
                    }
                }
            }

            void Render()
            {
                bodyPart.render();
                headPart.render();
            }
        private:
            double CalculateFeet();
            HitBox::HalfCircle headPart;
            HitBox::Square bodyPart;
            const double velocity = 0.1;  
            double FallingSpeed = -2;
            bool isGrounded=false;
            double maxHeightJump = 0.2;
            double MaximumHeightTouched = 0; 
            double isInJump = false;
        //The hitbox of a player will be created from 2 objects a Circle and a square
        //The head will interact with either a ceiling or other flying objects 
        //The body will interact with the ground, slopes or any other part
        //The game i intend to create will be pixelated so i do not need a circle as the body to create smoothness as the enviroment will be square
    };
}