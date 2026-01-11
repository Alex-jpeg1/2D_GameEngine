#pragma once
#include<vector>
#include "../../glad/glad.h"

using Distance = float;
using FeetPosition = float;
using MaxJump = float;
using MaxHeight = float;
using CenterYPosition = float;
using CenterXPosition = float;

using YSpeed = float;
using XSpeed = float;


using DeltaTimeType = float;
using GravityModifier = float;
using WalkingSpeed = float;
using WalkingValue = float;
using GravityApllication = float;


using Grounded = bool;
using EmptyReturn = void;

using XValue = GLfloat;
using YValue = GLfloat;

using Height = GLfloat;
using Width = GLfloat;
using Size = float;

using WindowHeight = int;
using WindowWidth = int;
using Error = int;

using WindowSize = int;

using TextureType = int;
using Positions = std::vector<GLfloat>;

using TextureNumber = int;
using TextureColumns = int;

constexpr WindowHeight CUSTOM_DefaultHeight = 800;
constexpr WindowWidth CUSTOM_DefaultWidth = 800;

constexpr TextureNumber MaximumTextures = 1;
constexpr TextureColumns MaximumTextureColumn = 4;

constexpr int NumberCorners = 4;
//Default macros for the center width height and radius 
