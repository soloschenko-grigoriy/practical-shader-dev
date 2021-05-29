#version 410

uniform sampler2D parrotTex;
uniform sampler2D checkerTex;
uniform float brightness;
uniform vec4 multiply;
uniform vec4 add;


in vec2 fragUV; 
out vec4 outColor;

void main(){
    vec4 parrot = texture(parrotTex, fragUV);
    vec4 checker = texture(checkerTex, fragUV);

    outColor = mix(checker, parrot, checker.r) * brightness;
}