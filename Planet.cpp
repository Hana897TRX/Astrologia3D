#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>
#include <iostream>

//#######################
#include "Planet.h"
#include "Moon.h"
#include "Disk.h"
//#######################

Planet::Planet() {
	moonCount = 0;
	diskCount = 0;
	size = 1;

	year = 0.0;
	day = 0.0;

	yearInc = 0.05f;
	dayInc = 0.25f;

	moons = NULL;
	disks = NULL;
}

Planet::Planet(int _moons, int _disks, float _size, float _yearInc, float _dayInc) {
	moonCount = _moons;
	diskCount = _disks;
	size = _size;

	yearInc = _yearInc;
	dayInc = _dayInc;

	year = 0.0;
	day = 0.0;

	planetS = new Sphere(_size);
	moons = new Moon[_moons];
	disks = new Disk[_disks];

	for (int i = 0; i < moonCount; i++) {
		float space = size + 5;
		float tempX = space, tempY = 0.0f, tempZ = 0.0f;

		moons[i].Space(space);

		float random;

		switch (i)
		{
		case 0:
			random = rand() % 72;
			break;
		case 1:
			random = 220 + rand() % 72;
			break;
		case 2:
			random = 76 + rand() % 72;
			break;
		case 3:
			random = 292 + rand() % 72;
			break;
		case 4:
			random = 148 + rand() % 72;
			break;

		default:
			random = 0.0f;
			break;
		}

		tempX = cos(random) * space;
		tempZ = sin(random) * space;
		moons[i].InitialPos(tempX, tempY, tempZ);
	}
}

void Planet::SetTexture(char* fname) {
	planetS->SetTexture(fname);
}

void Planet::DrawPlanet(float space, float x, float z) {

	glPushMatrix();
	if (seeOrbits) {
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glutWireTorus(space, 0.0, 40, 1);
		glEnable(GL_LIGHTING);
	}
	//Rotate on the sun
	glTranslated(x, 0.0, z);

	for (int i = 0; i < moonCount; i++) {
		glPushMatrix();
		glTranslated(0.0, 0.0, 0.0);
		glScaled(0.5, 0.5, 0.5);
		moons[i].DrawMoon();
		glPopMatrix();
	}

	//Rotate on itself
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);

	if (seeOrbits)
		Axes();
	planetS->HaSolidSphere();

	for (int i = 0; i < diskCount; i++) {
		glColor3f(0.6, 0.6, 0.6);
		disks[i].Space(size + 1 + i);
		disks[i].DrawDisk();
	}

	glPopMatrix();

	moons->DoAuto(doAuto);
	moons->SeeOrbits(seeOrbits);

	if (doAuto) {
		day = (GLfloat)(((GLint)(day * 100.f + dayInc * 100.f)) % 36000) / 100.0f;
	}
}

void Planet::ChangeInc(float _inc) {
	yearInc += _inc;
	dayInc += _inc;
	for (int i = 0; i < moonCount; i++) {
		moons[i].ChangeInc(_inc);
	}
}

void Planet::Axes() {
	glBegin(GL_LINES);
	glVertex3f(-size * 2, 0.0, 0.0);
	glVertex3f(size * 2, 0.0, 0.0);
	glEnd();
}

void Planet::DoAuto(bool _doAuto) {
	doAuto = _doAuto;
}
bool Planet::doAuto = false;

void Planet::SeeOrbits(bool _seeOrbits) {
	seeOrbits = _seeOrbits;
}
bool Planet::seeOrbits = false;

float Planet::GetYearInc() {
	return yearInc;
}
////////////////////////////////////////////////////////////////////////////////////////////