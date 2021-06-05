#version 410

uniform vec3 lightDir;
uniform vec3 lightColor;
uniform vec3 cameraPosition;
uniform vec3 ambientCol;
// uniform sampler2D diffuseTex;
// uniform sampler2D specTex;
uniform sampler2D normTex;

in vec2 fragUV;
in vec2 fragUV2;
in vec3 fragWorldPosition;
in mat3 TBN;

out vec4 outColor;

void main () {
    vec3 normalDir = texture(normTex, fragUV).rgb;
    normalDir = normalize(normalDir * 2.0 - 1.0);
    
    vec3 normalDir2 = texture(normTex, fragUV2).rgb;
    normalDir2 = normalize(normalDir2 * 2.0 - 1.0);

    normalDir = normalize(TBN * (normalDir + normalDir2));

    vec3 toCam = normalize(cameraPosition - fragWorldPosition);

    vec3 halfVec = normalize(toCam + lightDir);
    float specAmount = max(0.0, dot(halfVec, normalDir));
    float specBrightness = pow(specAmount, 512.0);

    float diffuseAmount = max(0.0, dot(normalDir, lightDir));
    float diffuseBrightness = pow(diffuseAmount, 2);

    vec3 meshColor = vec3(0.3, 0.3, 0.4);

    vec3 diffuse = meshColor * diffuseBrightness * lightColor;
    vec3 specular = specBrightness * lightColor;
    vec3 ambient = meshColor * ambientCol;

    outColor = vec4(diffuse + specular + ambient, 1.0);
}