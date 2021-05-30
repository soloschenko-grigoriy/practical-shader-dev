#version 410

uniform vec3 meshColor;
uniform vec3 cameraPosition;

in vec3 fragNorm;
in vec3 fragWorldPosition;

out vec4 outColor;

void main(){
    vec3 normal = normalize(fragNorm);
    vec3 toCam = normalize(cameraPosition - fragWorldPosition);
    float rimAmount = 1.0 - max(0.0, dot(normal, toCam));

    rimAmount = pow(rimAmount, 2);

    vec3 rimLightColor = vec3(1, 1, 1);

    outColor = vec4(rimLightColor * rimAmount, 1.0);
}
