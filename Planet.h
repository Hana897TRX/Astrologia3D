#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>
#include <iostream>

//###################
#include "Moon.h"
#include "Disk.h"
#include "Sphere.h"
//###################
///////////////////////////// PLANET CLASS /////////////////////////////////////////////////
class Planet {
private:
	float year;
	float day;
	float yearInc;
	float dayInc;

	float size;
	int moonCount;
	int diskCount;

	static bool doAuto;
	static bool seeOrbits;

	Sphere* planetS;
	Moon* moons;
	Disk* disks;

public:
	Planet();
	Planet(int, int, float, float, float);
	void DrawPlanet(float, float, float);
	void ChangeInc(float);
	float GetYearInc();
	void SetTexture(char*);
	void Axes();
	static void DoAuto(bool);
	static void SeeOrbits(bool);
};