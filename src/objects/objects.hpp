#pragma once
#include <GLFW/glfw3.h>
#include <csetjmp>
#include <type_traits>
#include <math.h>
#include <cmath> 
#include "../resources/resources.hpp"

constexpr double OFFSET = 0.0001;

constexpr long double PI = 3.14159;
extern long double contor;


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
            BasicObject(long double _CenterX, long double _CenterY, long double _Height, long double _Width);
            virtual void UpdateCenter(long double _UpdateX, long double _UpdateY);
            virtual void OverWriteCenter(long double _UpdateX, long double _UpdateY);
            virtual long double ReturnPositionY() const ;
            virtual long double ReturnHeight() const ;
            virtual long double ReturnTop() const ;
            virtual long double ReturnPositionX() const ;
            virtual long double ReturnWidth() const ;
            virtual long double ReturnLeft() const ;
            virtual long double ReturnRight() const ;
            virtual long double ReturnBottom() const;
        
        protected:
            long double CenterX,CenterY;
            long double Height,Width;

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
        HalfCircle(long double _CenterX, long double _CenterY, long double _radius, int _NumberVertices);
        void render() const;        

        //template <class CollisionObject>
        //CollisionStates CheckCollision(CollisionObject& object);

    private:
        const int NumberVertices;
};
class Square: public BasicObject::BasicObject
{
    public: 
        Square();
        Square(long double _CenterX, long double _CenterY, long double _Height, long double _Width);
        void render() const;

        //template<class CollisionObject>
        //CollisionStates CheckCollision(CollisionObject& Object);

    protected:
};
};

namespace Surrounding
{
    class Ground: public HitBox::Square
    {
        public:
            Ground(long double _CenterX, long double _CenterY, long double _Height, long double _Width, int _Position);
            long double ReturnTop() const;
            long double ReturnLeft() const;
            long double ReturnRight() const; 

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

    class Character
    {
        public:
            template<class ColisionObject> 
            void CheckCollisionYDown(ColisionObject& Object)
            {
                if constexpr (std::is_same_v<ColisionObject, Surrounding::Ground>)
                {
                    if(bodyPart.ReturnLeft() < Object.ReturnRight() && bodyPart.ReturnRight() > Object.ReturnLeft())
                    {
                        if(abs(bodyPart.ReturnBottom() - Object.ReturnTop()) < OFFSET || bodyPart.ReturnBottom() < Object.ReturnTop())
                        {
                            isGrounded = true;
                            bodyPart.OverWriteCenter(bodyPart.ReturnPositionX(), Object.ReturnTop() + bodyPart.ReturnHeight() / 2 + OFFSET );
                            headPart.OverWriteCenter(headPart.ReturnPositionX(), Object.ReturnTop() + bodyPart.ReturnHeight() + OFFSET);
                        }
                    }
                }
            }
            template<typename CollisionObject>
            CollisionStates CheckCollisionXRight(CollisionObject& Object)
            {
                if constexpr (std::is_same_v<CollisionObject, Surrounding::Ground>)
                {
                    if(bodyPart.ReturnBottom() < Object.ReturnTop() && bodyPart.ReturnTop() > Object.ReturnBottom)
                    {
                        if(abs(bodyPart.ReturnRight() - Object.ReturnLeft()) < OFFSET || bodyPart.ReturnRight() < Object.ReturnTop())
                        {
                            bodyPart.OverWriteCenter(Object.ReturnLeft() - bodyPart.ReturnWidth() / 2 - OFFSET, bodyPart.ReturnPositionY());
                            headPart.OverWriteCenter(Object.ReturnLeft() - bodyPart.ReturnWidth() / 2 - OFFSET, headPart.ReturnPositionY());
                        }
                    }
                }
            }

            virtual EmptyReturn UpdatePositions(DeltaTimeType DeltaTime) = 0;
            Character();
            virtual EmptyReturn Render() = 0;
        protected:
            HitBox::HalfCircle headPart;
            HitBox::Square bodyPart;
            
            bool isInJump = false;
            WalkingSpeed velocity = 0.3;
            GravityModifier FallingSpeed = -1.8;

            Grounded isGrounded=false;
    };
    class Player:public Character
    {
        public:

            //Player();
            virtual EmptyReturn UpdatePositions(DeltaTimeType DelaTime);
            virtual EmptyReturn Render();
            virtual EmptyReturn CheckMaxHeight();
            EmptyReturn UpdateHeightToTouch();
            EmptyReturn UpdateJump();

            Grounded OnGround();
        private:
            
            Distance CalculateDistance(const long double& First, const long double& Second);
            FeetPosition CalculateFeet();

            MaxJump maxHeightJump = 0.4;
            MaxHeight MaximumHeightToTouch = 0; 
            WalkingValue dx = 0;
            GravityApllication dy = 0;

            const GravityModifier FallingSpeedModifier = 1;
        //The hitbox of a player will be created from 2 objects a Circle and a square
        //The head will interact with either a ceiling or other flying objects 
        //The body will interact with the ground, slopes or any other part
        //The game i intend to create will be pixelated so i do not need a circle as the body to create smoothness as the enviroment will be square
    };
}