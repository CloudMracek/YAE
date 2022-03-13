#version 460 core
in vec2 TexCoords;
out vec4 color;

layout (binding = 0) uniform sampler2D text;
layout (location = 6) uniform vec3 textColor;

uniform vec3 textColor;

void main()
{    
	color = vec4(textColor, 1.0) * texture(text, TexCoords).r;
}  