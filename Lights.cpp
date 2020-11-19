#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

//#################
#include "Lights.h"
//#################

Lights::Lights(float sunLx, float sunLy, float sunLz, float r, float g, float b) {
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_LIGHTING);

	colorLight[0] = r;
	colorLight[1] = g;
	colorLight[2] = b;
	colorLight[3] = 0.0;

	lightAndSphere[0] = sunLx;
	lightAndSphere[1] = sunLy;
	lightAndSphere[2] = sunLz;
	lightAndSphere[3] = 1.0;

	GlobalLight();
	SunLight();
}

void Lights::SetSunLight(float r, float g, float b) {
	colorLight[0] = r;
	colorLight[1] = g;
	colorLight[2] = b;
}

void Lights::GlobalLight() {
	GLfloat myPos[] = { 0.0, 3.0, 0.0, 1.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, myPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

	glEnable(GL_LIGHT0);
}

void Lights::SunLight() {
	float shiniess = 51.2;
	glLightfv(GL_LIGHT1, GL_POSITION, lightAndSphere);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, colorLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, colorLight);
	glLightfv(GL_LIGHT1, GL_SHININESS, &shiniess);

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 2.0);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 3.0);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 2.0);

	glEnable(GL_LIGHT1);
}