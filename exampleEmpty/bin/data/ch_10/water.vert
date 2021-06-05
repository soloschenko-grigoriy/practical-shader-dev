#version 410

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 tangent;
layout (location = 2) in vec3 nrm;
layout (location = 3) in vec2 uv;

uniform mat4 mvp;
uniform mat4 model;
uniform mat3 normalMatrix;
uniform float time;

out vec2 fragUV;
out vec2 fragUV2;
out vec3 fragWorldPosition;
out mat3 TBN;

void main() {
    float t = time * 0.05;
    float t2 = time * 0.02;

    fragUV = vec2(uv.x + t, uv.y) * 3.0;
    fragUV2 = vec2(uv.x + t2, uv.y - t2) * 2.0;

    vec3 T = normalize(normalMatrix * tangent.xyz); // tangent vector in world space
    vec3 B = normalize(normalMatrix * cross(tangent.xyz, nrm)); // bitangent vector in world space
    vec3 N = normalize(normalMatrix * nrm); // normal vector in world space
    TBN = mat3(T, B, N);

    fragWorldPosition = (model * vec4(pos, 1.0)).xyz;

    gl_Position = mvp * vec4(pos, 1.0);
}