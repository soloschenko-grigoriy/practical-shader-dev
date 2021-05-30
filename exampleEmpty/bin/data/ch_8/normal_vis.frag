#version 410

uniform vec3 lightDir;
uniform vec3 lightCol;

in vec3 fragNrm;

out vec4 outColor;

void main(){
    vec3 normal = normalize(fragNrm);
    outColor = vec4(normal, 1.0);
}