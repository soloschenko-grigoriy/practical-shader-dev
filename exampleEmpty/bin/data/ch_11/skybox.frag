#version 410

uniform samplerCube cubemap;

in vec3 fragPos;
out vec4 outCol;

void main(){
    outCol = texture(cubemap, fragPos);
}