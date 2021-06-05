#pragma once

#include "ofMain.h"

class MyClass
{

public:
	void set(int _i, float _f)
	{
		i = _i;
		f = _f;
	};

	int i;
	float f;
};

struct CameraData
{
	glm::vec3 position;
	float rotation;
	float fov;
};

struct DirectionalLight
{
	glm::vec3 direction;
	glm::vec3 color;
	float intensity;
};

class ofApp : public ofBaseApp
{
	// ofMesh quad;
	// ofShader shader;
	// ofImage parrot;
	// ofImage checker;
	// float brightness;

	CameraData cam;

	// ofMesh charMesh;
	// ofMesh bgMesh;
	// ofMesh cloudMesh;
	// ofMesh sunMesh;

	// ofShader charShader;
	// ofShader cloudShader;
	// ofShader bgShader;
	// ofShader spritesheetShader;

	// ofImage alienImg;
	// ofImage bgImg;
	// ofImage cloudImg;
	// ofImage sunImg;

	// bool walkRight;
	// bool walkLeft;
	// glm::vec3 charPos;

	ofMesh shieldMesh;
	ofShader uvShader;
	ofShader specularShader;

	ofImage shieldDiffuseTex;
	ofImage shieldSpecTex;

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};
