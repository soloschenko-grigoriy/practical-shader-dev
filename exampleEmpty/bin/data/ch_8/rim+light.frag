#version 410

uniform vec3 lightDir;
uniform vec3 lightColor;
uniform vec3 meshColor;
uniform vec3 cameraPosition;

in vec3 fragNorm;
in vec3 fragWorldPosition;

out vec4 outColor;

void main(){
    vec3 normal = normalize(fragNorm);
    vec3 toCam = normalize(cameraPosition - fragWorldPosition);

    vec3 rimColor = vec3(0, 1, 1);
    float rimAmt = 1.0 - max(0.0, dot(normal, toCam));
    rimAmt = pow(rimAmt, 2);

    float lightAmount = max(0.0, dot(normal, lightDir));
    vec3 fragLight = lightColor * lightAmount;

    outColor = vec4((meshColor * fragLight) + (rimAmt * rimColor), 1.0);
}