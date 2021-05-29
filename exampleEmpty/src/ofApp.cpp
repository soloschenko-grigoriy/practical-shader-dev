#include "ofApp.h"

void buildMesh(ofMesh &mesh, float w, float h, glm::vec3 pos)
{
    float verts[] = {-w + pos.x,
                     -h + pos.y,
                     pos.z,
                     -w + pos.x,
                     h + pos.y,
                     pos.z,
                     w + pos.x,
                     h + pos.y,
                     pos.z,
                     w + pos.x,
                     -h + pos.y,
                     pos.z};

    float uvs[] = {0,
                   0,
                   0,
                   1,
                   1,
                   1,
                   1,
                   0};

    for (int i = 0; i < 4; ++i)
    {
        int idx = i * 3;
        int uvIdx = i * 2;

        mesh.addVertex(glm::vec3(verts[idx], verts[idx + 1], verts[idx + 2]));
        mesh.addTexCoord(glm::vec2(uvs[uvIdx], uvs[uvIdx + 1]));
    }

    ofIndexType indicies[6] = {0, 1, 2, 2, 3, 0};
    mesh.addIndices(indicies, 6);
}

//--------------------------------------------------------------
void ofApp::setup()
{
    // quad.addVertex(glm::vec3(-1, -1, 0));
    // quad.addVertex(glm::vec3(-1, 1, 0));
    // quad.addVertex(glm::vec3(1, 1, 0));
    // quad.addVertex(glm::vec3(1, -1, 0));

    // quad.addColor(ofDefaultColorType(1, 0, 0, 1));
    // quad.addColor(ofDefaultColorType(0, 1, 0, 1));
    // quad.addColor(ofDefaultColorType(0, 0, 1, 1));
    // quad.addColor(ofDefaultColorType(1, 1, 1, 1));

    // quad.addTexCoord(glm::vec2(0, 0));
    // quad.addTexCoord(glm::vec2(0, 1));
    // quad.addTexCoord(glm::vec2(1, 1));
    // quad.addTexCoord(glm::vec2(1, 0));

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

    ofDisableArbTex();
    ofEnableDepthTest();

    buildMesh(charMesh, 0.1, 0.2, glm::vec3(0.0, -0.2, 0.0));
    buildMesh(bgMesh, 1.0, 1.0, glm::vec3(0.0, 0.0, 0.5));
    buildMesh(sunMesh, 1., 1., glm::vec3(0., 0., 0.4));
    buildMesh(cloudMesh, .2, .1, glm::vec3(-0.4, 0, 0.0));

    alienImg.load("ch_4/walk_sheet.png");
    bgImg.load("ch_4/forest.png");
    cloudImg.load("ch_4/cloud.png");
    sunImg.load("ch_4/sun.png");

    bgShader.load("ch_4/passthrough.vert", "ch_4/alphaTest.frag");
    cloudShader.load("ch_4/passthrough.vert", "ch_4/cloud.frag");
    spritesheetShader.load("ch_4/spritesheet.vert", "ch_4/alphaTest.frag");
}

//--------------------------------------------------------------
void ofApp::update()
{
    float distance = 0.4 * ofGetLastFrameTime();

    if (walkRight)
    {
        charPos += glm::vec3(distance, 0, 0);
    }
    else if (walkLeft)
    {
        charPos -= glm::vec3(distance, 0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    // shader.begin();
    // shader.setUniformTexture("parrotTex", parrot, 0);
    // shader.setUniformTexture("checkerTex", checker, 1);
    // shader.setUniform1f("time", ofGetElapsedTimef());
    // shader.setUniform1f("brightness", brightness);
    // shader.setUniform4f("multiply", glm::vec4(1., 1., 1., 1.));
    // shader.setUniform4f("add", glm::vec4(0.25, .25, .25, 1.));
    // quad.draw();
    // shader.end();

    static float frame = 0.0;
    frame = (frame > 10) ? 0.0 : frame += 0.2;
    glm::vec2 spriteSize = glm::vec2(0.28, 0.19);
    glm::vec2 spriteFrame = glm::vec2((int)frame % 3, (int)frame / 3);

    ofDisableBlendMode();
    ofEnableDepthTest();

    spritesheetShader.begin();
    spritesheetShader.setUniformTexture("tex", alienImg, 0);
    spritesheetShader.setUniform2f("size", spriteSize);
    spritesheetShader.setUniform2f("offset", spriteFrame);
    spritesheetShader.setUniform3f("translation", charPos);
    charMesh.draw();
    spritesheetShader.end();

    bgShader.begin();
    bgShader.setUniformTexture("tex", bgImg, 0);
    bgMesh.draw();
    bgShader.end();

    ofDisableDepthTest();
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);

    cloudShader.begin();
    cloudShader.setUniformTexture("tex", cloudImg, 0);
    cloudMesh.draw();
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    cloudShader.setUniformTexture("tex", sunImg, 0);
    sunMesh.draw();
    cloudShader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == ofKey::OF_KEY_RIGHT)
    {
        walkRight = true;
    }
    else if (key == ofKey::OF_KEY_LEFT)
    {
        walkLeft = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if (key == ofKey::OF_KEY_RIGHT)
    {
        walkRight = false;
    }
    else if (key == ofKey::OF_KEY_LEFT)
    {
        walkLeft = false;
    }
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