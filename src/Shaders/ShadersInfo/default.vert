#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 Projection;

out vec2 fragTexCoord;

void main()
{
   gl_Position = Projection * vec4(aPos, 0, 1.0);

   fragTexCoord = aTexCoord;
}