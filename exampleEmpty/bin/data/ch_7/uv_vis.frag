#version 410

in vec2 fragUV;
out vec4 outColor;

void main() {
    outColor = vec4(fragUV, 0.0, 1.0);
}