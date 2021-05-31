#version 410

layout (location = 0) in vec3 pos;
layout (location = 2) in vec3 nrm;

uniform mat4 mvp;
uniform mat4 model;
uniform mat3 normalMatrix;

out vec3 fragNorm;
out vec3 fragWorldPosition;

void main () {
    gl_Position = mvp * vec4(pos, 1.0);
    fragNorm = (normalMatrix * nrm).xyz;
    fragWorldPosition = (model * vec4(pos, 1.0)).xyz;
}


// float angleBetween(vec3 a, vec3 b){
//     float d = dot(a, b);
//     float len = length(a) * length(b);

//     float cosAngle = d / len;
//     float angle = acos(cosAngle);

//     return angle;
// }