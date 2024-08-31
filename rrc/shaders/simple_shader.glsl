#type vertex
#version 330 core
layout(location = 0) in vec2 a_pos;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(a_pos, 0.0f, 1.0f);
}

#type fragment
#version 330 core
out vec4 out_color;

void main()
{
    out_color = vec4(0.0f, 0.0f, 1.0f, 1.0f);
}