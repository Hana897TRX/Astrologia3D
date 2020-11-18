#pragma once

//#############################
#include "RGBpixmap.h"
//############################

class Cubemap
{
private:
	RGBpixmap text[6];
	GLuint corex[6];
	float size = 150;

public:
	Cubemap(float _size, char* bot0, char* bot1, char* mid, char* left, char* right, char* top);

	void Draw();
};

