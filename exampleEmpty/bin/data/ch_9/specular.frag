#version 410

uniform vec3 lightDir;
uniform vec3 lightColor;
uniform vec3 cameraPosition;
// uniform vec3 meshColor;
// uniform vec3 meshSpecCol;
uniform vec3 ambientCol;
uniform sampler2D diffuseTex;
uniform sampler2D specTex;

in vec2 fragUV;
in vec3 fragNorm;
in vec3 fragWorldPosition;

out vec4 outColor;

void main () {
    vec3 normalDir = normalize(fragNorm);
    vec3 refl = normalize(reflect(-lightDir, normalDir));
    vec3 toCam = normalize(cameraPosition - fragWorldPosition);

    // float specAmount = max(0.0, dot(refl, toCam));
    // float specBrightness = pow(specAmount, 16.0);

    // blinn-phong
    vec3 halfVec = normalize(toCam + lightDir);
    float specAmount = max(0.0, dot(halfVec, normalDir));
    float specBrightness = pow(specAmount, 2.0);

    float diffuseAmount = max(0.0, dot(normalDir, lightDir));
    float diffuseBrightness = pow(diffuseAmount, 2);

    vec3 meshColor = texture(diffuseTex, fragUV).xyz;
    float meshSpecCol = texture(specTex, fragUV).x;

    vec3 diffuse = meshColor * diffuseBrightness * lightColor;
    vec3 specular = meshSpecCol * specBrightness * lightColor;
    vec3 ambient = meshColor * ambientCol;

    outColor = vec4(diffuse + specular + ambient, 1.0);
}