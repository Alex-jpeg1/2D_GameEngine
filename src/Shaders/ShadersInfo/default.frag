#version 330 core

in vec2 fragTexCoord;

out vec4 FragColor;

uniform sampler2D material; 


void main()
{
   FragColor =texture(material, fragTexCoord);
}