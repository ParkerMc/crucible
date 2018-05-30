#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 direction;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    direction = aPos;  
	
	mat4 newView = mat4(mat3(view));

    gl_Position =  projection * newView * vec4(direction, 1.0);
}