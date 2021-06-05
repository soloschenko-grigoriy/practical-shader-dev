#version 410

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 tangent;
layout (location = 2) in vec3 nrm;
layout (location = 3) in vec2 uv;

uniform mat4 mvp;
uniform mat4 model;
uniform mat3 normalMatrix;

out vec2 fragUV;
out vec3 fragWorldPosition;
out mat3 TBN;

void main () {
    vec3 T = normalize(normalMatrix * tangent.xyz); // tangent vector in world space
    vec3 B = normalize(normalMatrix * cross(tangent.xyz, nrm)); // bitangent vector in world space
    vec3 N = normalize(normalMatrix * nrm); // normal vector in world space
    TBN = mat3(T, B, N);

    fragUV = vec2(uv.x, 1.0 - uv.y);
    fragWorldPosition = (model * vec4(pos, 1.0)).xyz;

    gl_Position = mvp * vec4(pos, 1.0);
}