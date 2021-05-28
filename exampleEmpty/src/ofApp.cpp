#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    quad.addVertex(glm::vec3(-1, -1, 0));
    quad.addVertex(glm::vec3(-1, 1, 0));
    quad.addVertex(glm::vec3(1, 1, 0));
    quad.addVertex(glm::vec3(1, -1, 0));

    quad.addColor(ofDefaultColorType(1, 0, 0, 1));
    quad.addColor(ofDefaultColorType(0, 1, 0, 1));
    quad.addColor(ofDefaultColorType(0, 0, 1, 1));
    quad.addColor(ofDefaultColorType(1, 1, 1, 1));

    quad.addTexCoord(glm::vec2(0, 0));
    quad.addTexCoord(glm::vec2(0, 1));
    quad.addTexCoord(glm::vec2(1, 1));
    quad.addTexCoord(glm::vec2(1, 0));

    ofIndexType indices[6] = {0, 1, 2, 2, 3, 0};
    quad.addIndices(indices, 6);

    shader.load("scrolling_uv.vert", "texture.frag");

    ofDisableArbTex();
    ofDisableAlphaBlending();

    
    checker.load("checker.jpg");
    parrot.load("parrot.png");

    parrot.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);
    // checker.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

    brightness = 0.5;
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
    shader.begin();
    shader.setUniformTexture("parrotTex", parrot, 0);
    shader.setUniformTexture("checkerTex", checker, 1);
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform1f("brightness", brightness);
    shader.setUniform4f("multiply", glm::vec4(1., 1., 1., 1.));
    shader.setUniform4f("add", glm::vec4(0.25, .25, .25, 1.));
    quad.draw();
    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
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