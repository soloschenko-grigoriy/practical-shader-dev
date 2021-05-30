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

    ofDisableArbTex();
    ofEnableDepthTest();

    torusMesh.load("ch_7/torus.ply");
    uvShader.load("ch_8/mesh.vert", "ch_8/normal_vis.frag");
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

    cam.position = vec3(0, 0, 1);
    cam.fov = radians(100.0f);
    float aspect = 1024.0f / 768.0f;

    mat4 model = rotate(1.0f, vec3(1, 1, 1)) * scale(vec3(0.5, 0.5, 0.5));
    mat4 view = inverse(translate(cam.position));
    mat4 proj = perspective(cam.fov, aspect, 0.01f, 10.0f);
    mat4 mvp = proj * view * model;
    mat3 normalMatrix = (transpose(inverse(mat3(model))));

    uvShader.begin();
    uvShader.setUniformMatrix4f("mvp", mvp);
    uvShader.setUniformMatrix3f("normalMatrix", normalMatrix);
    torusMesh.draw();
    uvShader.end();
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