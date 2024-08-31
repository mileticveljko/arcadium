#type vertex
#version 330 core
layout(location = 0) in vec2 a_pos;
layout(location = 1) in vec2 a_tex_coord;

out vec2 v_tex_coord;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(a_pos, 0.0f, 1.0f);
    v_tex_coord = a_tex_coord;
}

#type fragment
#version 330 core
out vec4 out_color;

in vec2 v_tex_coord;
uniform sampler2D u_tex;

void main()
{
    out_color = texture(u_tex, v_tex_coord);
}