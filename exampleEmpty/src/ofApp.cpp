#include "ofApp.h"
using namespace glm;

// void buildMesh(ofMesh &mesh, float w, float h, vec3 pos)
// {
//     float verts[] = {-w + pos.x,
//                      -h + pos.y,
//                      pos.z,
//                      -w + pos.x,
//                      h + pos.y,
//                      pos.z,
//                      w + pos.x,
//                      h + pos.y,
//                      pos.z,
//                      w + pos.x,
//                      -h + pos.y,
//                      pos.z};

//     float uvs[] = {0,
//                    0,
//                    0,
//                    1,
//                    1,
//                    1,
//                    1,
//                    0};

//     for (int i = 0; i < 4; ++i)
//     {
//         int idx = i * 3;
//         int uvIdx = i * 2;

//         mesh.addVertex(vec3(verts[idx], verts[idx + 1], verts[idx + 2]));
//         mesh.addTexCoord(vec2(uvs[uvIdx], uvs[uvIdx + 1]));
//     }

//     ofIndexType indicies[6] = {0, 1, 2, 2, 3, 0};
//     mesh.addIndices(indicies, 6);
// }

// mat4 buildMatrix(vec3 t, float r, vec3 s)
// {
//     mat4 translation = translate(t);
//     mat4 rotation = rotate(r, vec3(0.0, 0.0, 1.0));
//     mat4 scaler = scale(s);

//     return translation * rotation * scaler;
// }

// mat4 buildViewMatrix(CameraData cam)
// {
//     return inverse(buildMatrix(cam.position, cam.rotation, vec3(1, 1, 1)));
// }

vec3 getLightDirection(DirectionalLight &l)
{
    return normalize(l.direction * -1.0f);
}

vec3 getLightColor(DirectionalLight &l)
{
    return l.color * l.intensity;
}
void calcTangents(ofMesh &mesh)
{
    using namespace glm;
    std::vector<vec4> tangents;
    tangents.resize(mesh.getNumVertices());

    uint indexCount = mesh.getNumIndices();

    const vec3 *vertices = mesh.getVerticesPointer();
    const vec2 *uvs = mesh.getTexCoordsPointer();
    const uint *indices = mesh.getIndexPointer();

    for (uint i = 0; i < indexCount - 2; i += 3)
    {
        const vec3 &v0 = vertices[indices[i]];
        const vec3 &v1 = vertices[indices[i + 1]];
        const vec3 &v2 = vertices[indices[i + 2]];
        const vec2 &uv0 = uvs[indices[i]];
        const vec2 &uv1 = uvs[indices[i + 1]];
        const vec2 &uv2 = uvs[indices[i + 2]];

        vec3 edge1 = v1 - v0;
        vec3 edge2 = v2 - v0;
        vec2 dUV1 = uv1 - uv0;
        vec2 dUV2 = uv2 - uv0;

        float f = 1.0f / (dUV1.x * dUV2.y - dUV2.x * dUV1.y);

        vec4 tan;
        tan.x = f * (dUV2.y * edge1.x - dUV1.y * edge2.x);
        tan.y = f * (dUV2.y * edge1.y - dUV1.y * edge2.y);
        tan.z = f * (dUV2.y * edge1.z - dUV1.y * edge2.z);
        tan.w = 0;
        tan = normalize(tan);

        tangents[indices[i]] += (tan);
        tangents[indices[i + 1]] += (tan);
        tangents[indices[i + 2]] += (tan);
    }

    int numColors = mesh.getNumColors();

    for (int i = 0; i < tangents.size(); ++i)
    {
        vec3 t = normalize(tangents[i]);
        if (i >= numColors)
        {
            mesh.addColor(ofFloatColor(t.x, t.y, t.z, 0.0));
        }
        else
        {
            mesh.setColor(i, ofFloatColor(t.x, t.y, t.z, 0.0));
        }
    }
}

//--------------------------------------------------------------
void ofApp::setup()
{
    // quad.addVertex(vec3(-1, -1, 0));
    // quad.addVertex(vec3(-1, 1, 0));
    // quad.addVertex(vec3(1, 1, 0));
    // quad.addVertex(vec3(1, -1, 0));

    // quad.addColor(ofDefaultColorType(1, 0, 0, 1));
    // quad.addColor(ofDefaultColorType(0, 1, 0, 1));
    // quad.addColor(ofDefaultColorType(0, 0, 1, 1));
    // quad.addColor(ofDefaultColorType(1, 1, 1, 1));

    // quad.addTexCoord(vec2(0, 0));
    // quad.addTexCoord(vec2(0, 1));
    // quad.addTexCoord(vec2(1, 1));
    // quad.addTexCoord(vec2(1, 0));

    // ofIndexType indices[6] = {0, 1, 2, 2, 3, 0};
    // quad.addIndices(indices, 6);

    // shader.load("scrolling_uv.vert", "texture.frag");

    // ofDisableArbTex();
    // ofDisableAlphaBlending();

    // checker.load("checker.jpg");
    // parrot.load("parrot.png");

    // parrot.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);
    // // checker.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    // brightness = 0.5;

    // cam.position = vec3(0, 0, 0);

    // ofDisableArbTex();
    // ofEnableDepthTest();

    // buildMesh(charMesh, 0.1, 0.2, vec3(0.0, -0.2, 0.0));
    // buildMesh(bgMesh, 1.0, 1.0, vec3(0.0, 0.0, -0.5));
    // buildMesh(sunMesh, 1., 1., vec3(0., 0., -0.4));
    // buildMesh(cloudMesh, .25, .15, vec3(0., 0., 0.));

    // alienImg.load("ch_4/walk_sheet.png");
    // bgImg.load("ch_4/forest.png");
    // cloudImg.load("ch_4/cloud.png");
    // sunImg.load("ch_4/sun.png");

    // bgShader.load("ch_6/passthrough.vert", "ch_4/alphaTest.frag");
    // cloudShader.load("ch_6/passthrough.vert", "ch_4/cloud.frag");
    // spritesheetShader.load("ch_6/spritesheet.vert", "ch_4/alphaTest.frag");

    // ofDisableArbTex();
    // ofEnableDepthTest();
    // // ofSetBackgroundColor(ofColor::black);

    // shieldMesh.load("ch_9/shield.ply");
    // planeMesh.load("ch_10/plane.ply");
    // specularShader.load("ch_10/mesh.vert", "ch_10/specular.frag");

    // shieldDiffuseTex.load("ch_9/shield_diffuse.png");
    // shieldSpecTex.load("ch_9/shield_spec.png");
    // shieldNormTex.load("ch_10/shield_normal.png");
    // waterNormTex.load("ch_10/water_nrm.png");
    // waterNormTex.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    ofDisableArbTex();
    ofEnableDepthTest();

    planeMesh.load("ch_10/plane.ply");
    calcTangents(planeMesh);

    shieldMesh.load("ch_9/shield.ply");
    calcTangents(shieldMesh);

    blinnPhong.load("ch_10/mesh.vert", "ch_11/shied.frag");
    waterShader.load("ch_10/water.vert", "ch_11/water.frag");

    diffuseTex.load("ch_9/shield_diffuse.png");
    specTex.load("ch_9/shield_spec.png");
    nrmTex.load("ch_10/shield_normal.png");
    waterNrm.load("ch_10/water_nrm.png");
    waterNrm.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    cubeMesh.load("ch_11/cube.ply");
    cubemapShader.load("ch_11/cubemap.vert", "ch_11/cubemap.frag");
    skyboxShader.load("ch_11/skybox.vert", "ch_11/skybox.frag");
    cubemap.load("ch_11/cube2_front.jpg", "ch_11/cube2_back.jpg",
                 "ch_11/cube2_right.jpg", "ch_11/cube2_left.jpg",
                 "ch_11/cube2_top.jpg", "ch_11/cube2_bottom.jpg");

    cam.position = glm::vec3(0, 0.75f, 1.0);
    cam.fov = glm::radians(90.0f);
}

//--------------------------------------------------------------
void ofApp::update()
{
    // float distance = 0.4 * ofGetLastFrameTime();

    // if (walkRight)
    // {
    //     charPos += vec3(distance, 0, 0);
    // }
    // else if (walkLeft)
    // {
    //     charPos -= vec3(distance, 0, 0);
    // }
}

void ofApp::drawWater(DirectionalLight &dirLight, glm::mat4 &proj, glm::mat4 &view)
{
    using namespace glm;

    static float t = 0.0f;
    t += ofGetLastFrameTime();

    vec3 right = vec3(1, 0, 0);
    mat4 rotation = rotate(radians(-90.0f), right);
    mat4 model = rotation * scale(vec3(5.0, 4.0, 4.0));

    mat4 mvp = proj * view * model;
    mat3 normalMatrix = mat3(transpose(inverse(model)));

    ofShader &shd = waterShader;
    shd.begin();
    shd.setUniformMatrix4f("mvp", mvp);
    shd.setUniformMatrix4f("model", model);
    shd.setUniformMatrix3f("normalMatrix", normalMatrix);
    shd.setUniform3f("meshSpecCol", glm::vec3(1, 1, 1));
    shd.setUniformTexture("normTex", waterNrm, 0);
    shd.setUniformTexture("envMap", cubemap.getTexture(), 1);
    shd.setUniform1f("time", t);

    shd.setUniform3f("ambientCol", glm::vec3(0.1, 0.1, 0.1));
    shd.setUniform3f("lightDir", getLightDirection(dirLight));
    shd.setUniform3f("lightColor", getLightColor(dirLight));
    shd.setUniform3f("cameraPosition", cam.position);
    planeMesh.draw();
    shd.end();
}

void ofApp::drawShield(DirectionalLight &dirLight, glm::mat4 &proj, glm::mat4 &view)
{
    using namespace glm;

    mat4 model = translate(vec3(0.0, 0.75, 0.0f));
    mat4 mvp = proj * view * model;
    mat3 normalMatrix = mat3(transpose(inverse(model)));

    ofShader &shd = blinnPhong;

    shd.begin();
    shd.setUniformMatrix4f("mvp", mvp);
    shd.setUniformMatrix4f("model", model);
    shd.setUniformMatrix3f("normalMatrix", normalMatrix);
    shd.setUniform3f("meshSpecCol", glm::vec3(1, 1, 1));
    shd.setUniformTexture("diffuseTex", diffuseTex, 0);
    ;
    shd.setUniformTexture("specTex", specTex, 1);
    shd.setUniformTexture("normTex", nrmTex, 2);
    shd.setUniformTexture("envMap", cubemap.getTexture(), 3);
    shd.setUniform3f("ambientCol", glm::vec3(0.1, 0.1, 0.1));
    shd.setUniform3f("lightDir", getLightDirection(dirLight));
    shd.setUniform3f("lightColor", getLightColor(dirLight));
    shd.setUniform3f("cameraPosition", cam.position);
    shieldMesh.draw();
    shd.end();
}

void ofApp::drawCube(glm::mat4 &proj, glm::mat4 &view)
{
    using namespace glm;

    static float rotAngle = 0.0;
    rotAngle += 0.2f;

    mat4 r = rotate(radians(rotAngle), vec3(0, 1, 0));
    mat4 s = scale(vec3(0.4, 0.4, 0.4));
    mat4 model = translate(vec3(0.0, 0.75, 0.0f)) * r * s;
    mat4 mvp = proj * view * model;

    ofShader &shd = cubemapShader;

    shd.begin();
    shd.setUniformMatrix4f("mvp", mvp);
    shd.setUniformTexture("cubemap", cubemap.getTexture(), 0);
    shd.setUniform3f("cameraPos", cam.position);
    cubeMesh.draw();
    shd.end();
}

void ofApp::drawSkybox(mat4 &proj, mat4 &view)
{
    mat4 model = translate(cam.position);
    mat4 mvp = proj * view * model;

    ofShader &shd = skyboxShader;
    glDepthFunc(GL_LEQUAL);

    shd.begin();
    shd.setUniformMatrix4f("mvp", mvp);
    shd.setUniformTexture("cubemap", cubemap.getTexture(), 0);
    shd.setUniform3f("cameraPos", cam.position);
    cubeMesh.draw();
    shd.end();
    glDepthFunc(GL_LESS);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    // mat4 identity = mat4();
    // mat4 view = buildViewMatrix(cam);
    // mat4 proj = ortho(-1.33f, 1.33f, -1.0f, 1.0f, 0.0f, 10.0f);

    // shader.begin();
    // shader.setUniformTexture("parrotTex", parrot, 0);
    // shader.setUniformTexture("checkerTex", checker, 1);
    // shader.setUniform1f("time", ofGetElapsedTimef());
    // shader.setUniform1f("brightness", brightness);
    // shader.setUniform4f("multiply", vec4(1., 1., 1., 1.));
    // shader.setUniform4f("add", vec4(0.25, .25, .25, 1.));
    // quad.draw();
    // shader.end();

    // static float frame = 0.0;
    // frame = (frame > 10) ? 0.0 : frame += 0.2;
    // vec2 spriteSize = vec2(0.28, 0.19);
    // vec2 spriteFrame = vec2((int)frame % 3, (int)frame / 3);

    // ofDisableBlendMode();
    // ofEnableDepthTest();

    // spritesheetShader.begin();
    // spritesheetShader.setUniformMatrix4f("view", view);
    // spritesheetShader.setUniformTexture("tex", alienImg, 0);
    // spritesheetShader.setUniform2f("size", spriteSize);
    // spritesheetShader.setUniform2f("offset", spriteFrame);
    // spritesheetShader.setUniformMatrix4f("model", translate(charPos));
    // spritesheetShader.setUniformMatrix4f("proj", proj);
    // charMesh.draw();
    // spritesheetShader.end();

    // bgShader.begin();
    // bgShader.setUniformMatrix4f("view", view);
    // bgShader.setUniformTexture("tex", bgImg, 0);
    // bgShader.setUniformMatrix4f("model", identity);
    // bgShader.setUniformMatrix4f("proj", proj);
    // bgMesh.draw();
    // bgShader.end();

    // ofDisableDepthTest();
    // ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);

    // static float rotation = 0.0f;
    // rotation += 0.1f * ofGetLastFrameTime();

    // // construct the transform for our un-rotated cloud
    // mat4 translationA = translate(vec3(-0.55, 0, 0));
    // mat4 scaleA = scale(vec3(1.5, 1, 1));
    // mat4 transformA = translationA * scaleA;

    // // apply a rotation to that
    // mat4 ourRotation = rotate(rotation, vec3(0.0, 0.0, 1.0));
    // mat4 newMatrix = translationA * ourRotation * inverse(translationA);
    // mat4 finalMatrix = newMatrix * transformA;

    // // mat4 transformA = buildMatrix(vec3(-0.55, 0, 0), rotation, vec3(1.5, 1, 1));
    // mat4 transformB = buildMatrix(vec3(0.4, 0.2, 0), 1.0f, vec3(1, 1, 1));

    // cloudShader.begin();
    // cloudShader.setUniformMatrix4f("view", view);
    // cloudShader.setUniformTexture("tex", cloudImg, 0);
    // cloudShader.setUniformMatrix4f("model", finalMatrix);
    // cloudShader.setUniformMatrix4f("proj", proj);
    // cloudMesh.draw();

    // cloudShader.setUniformMatrix4f("model", transformB);
    // cloudMesh.draw();

    // ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    // cloudShader.setUniformTexture("tex", sunImg, 0);
    // cloudShader.setUniformMatrix4f("model", identity);

    // sunMesh.draw();
    // cloudShader.end();

    // DirectionalLight dirLight;
    // dirLight.direction = normalize(vec3(1, -1, -0.8));
    // dirLight.color = vec3(1, 1, 1);
    // dirLight.intensity = 1.0f;

    // cam.position = vec3(0, 0.85f, 1.0f);
    // cam.fov = radians(90.0f);
    // float cAngle = radians(-45.0f);
    // vec3 right = vec3(1, 0, 0);

    // float aspect = 1024.0f / 768.0f;

    // static float rotAngle = 0.0f;
    // rotAngle += 0.01f;
    // vec3 up = vec3(0, 1, 0);
    // mat4 rotation = rotate(radians(-45.0f), right) * rotate(rotAngle, up);
    // mat4 model = rotation * scale(vec3(1.5, 1.5, 1.5));
    // mat4 view = inverse(translate(cam.position) * rotate(cAngle, right));
    // mat4 proj = perspective(cam.fov, aspect, 0.01f, 10.0f);
    // mat4 mvp = proj * view * model;
    // mat3 normalMatrix = (transpose(inverse(mat3(model))));

    // specularShader.begin();
    // specularShader.setUniformMatrix4f("mvp", mvp);
    // specularShader.setUniformMatrix3f("normalMatrix", normalMatrix);
    // specularShader.setUniform3f("meshColor", vec3(1, 1, 0));
    // specularShader.setUniform3f("lightDir", getLightDirection(dirLight));
    // specularShader.setUniform3f("lightColor", getLightColor(dirLight));
    // specularShader.setUniform3f("cameraPosition", cam.position);
    // specularShader.setUniform3f("meshSpecCol", vec3(1, 1, 1));
    // specularShader.setUniformMatrix4f("model", model);
    // specularShader.setUniform3f("ambientCol", glm::vec3(0.0, 0., 0.));
    // // specularShader.setUniformTexture("diffuseTex", shieldDiffuseTex, 0);
    // // specularShader.setUniformTexture("specTex", shieldSpecTex, 1);
    // specularShader.setUniformTexture("normTex", waterNormTex, 2);
    // planeMesh.draw();
    // specularShader.end();

    //
    // drawWater(waterLight, proj, view);

    DirectionalLight dirLight;
    dirLight.direction = glm::normalize(glm::vec3(0.5, -1, -1));
    dirLight.color = glm::vec3(1, 1, 1);
    dirLight.intensity = 1.0f;

    DirectionalLight waterLight;
    waterLight.direction = glm::normalize(glm::vec3(0.5, -1, 1));
    waterLight.color = glm::vec3(1, 1, 1);
    waterLight.intensity = 1.0f;

    mat4 proj = perspective(cam.fov, 1024.0f / 768.0f, 0.01f, 10.0f);

    cam.position = glm::vec3(0, 0.75f, 1.0);

    mat4 rotation = mat4();
    mat4 view = inverse(translate(cam.position) * rotation);

    // drawCube(proj, view);
    drawSkybox(proj, view);
    drawShield(dirLight, proj, view);
    drawWater(waterLight, proj, view);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    // if (key == ofKey::OF_KEY_RIGHT)
    // {
    //     walkRight = true;
    // }
    // else if (key == ofKey::OF_KEY_LEFT)
    // {
    //     walkLeft = true;
    // }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    // if (key == ofKey::OF_KEY_RIGHT)
    // {
    //     walkRight = false;
    // }
    // else if (key == ofKey::OF_KEY_LEFT)
    // {
    //     walkLeft = false;
    // }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}