#version 410

uniform vec3 lightDir;
uniform vec3 lightColor;
uniform vec3 cameraPosition;
uniform vec3 ambientCol;
uniform sampler2D diffuseTex;
uniform sampler2D specTex;
uniform sampler2D normTex;
uniform samplerCube envMap;

in vec2 fragUV;
in vec3 fragWorldPosition;
in mat3 TBN;

out vec4 outColor;

void main () {
    vec3 normalDir = texture(normTex, fragUV).rgb;
    normalDir = normalize(normalDir * 2.0 - 1.0);
    normalDir = normalize(TBN * normalDir);

    vec3 toCam = normalize(cameraPosition - fragWorldPosition);

    vec3 envSample = texture(envMap, reflect(-toCam, normalDir)).xyz;
    vec3 sceneLight = mix(lightColor, envSample + lightColor * 0.5, 0.5);

    vec3 halfVec = normalize(toCam + lightDir);
    float specAmount = max(0.0, dot(halfVec, normalDir));
    float specBrightness = pow(specAmount, 2.0);

    float diffuseAmount = max(0.0, dot(normalDir, lightDir));
    float diffuseBrightness = pow(diffuseAmount, 2);

    vec3 meshColor = texture(diffuseTex, fragUV).xyz;
    float meshSpecCol = texture(specTex, fragUV).x;

    vec3 diffuse = meshColor * diffuseBrightness * sceneLight;
    vec3 specular = meshSpecCol * specBrightness * sceneLight;
    vec3 ambient = meshColor * ambientCol;

    outColor = vec4(diffuse + specular + ambient, 1.0);
}