#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

#define PI 3.1416

//##########################
#include "Elliptica.h"
#include "ZodiacalSign.h"
//##########################
							// Aries - Tauro - Geminis - Cancer -  Leo -  Virgo - Libra -	Escorpio -	Sagitario - Capricornio - Acuario - Piscis
int ascendant[12][12] = {	{	10,		11,		12,			1,		2,		3,		4,			5,			6,			7,			8,			9		},
							{	11,		12,		1,			2,		3,		4,		5,			6,			7,			8,			9,			10		},
							{	12,		1,		2,			3,		4,		5,		6,			7,			8,			9,			10,			11		},
							{	1,		2,		3,			4,		5,		6,		7,			8,			9,			10,			11,			12		},
							{	2,		3,		4,			5,		6,		7,		8,			9,			10,			11,			12,			1		},
							{	3,		4,		5,			6,		7,		8,		9,			10,			11,			12,			1,			2		},
							{	4,		5,		6,			7,		8,		9,		10,			11,			12,			1,			2,			3		},
							{	5,		6,		7,			8,		9,		10,		11,			12,			1,			2,			3,			4		},
							{	6,		7,		8,			9,		10,		11,		12,			1,			2,			3,			4,			5,		},
							{	7,		8,		9,			10,		11,		12,		1,			2,			3,			4,			5,			6,		},
							{	8,		9,		10,			11,		12,		1,		2,			3,			4,			5,			6,			7,		},
							{	9,		10,		11,			12,		1,		2,		3,			4,			5,			6,			7,			8,		} };


float scaled = 0.85;

ZodiacalSign* zodiac;

Elliptica::Elliptica(float _solarAngle, int _hour, int _minutes) {
	zodiac = new ZodiacalSign();
	solarAngle = _solarAngle;
	hour = _hour;
	minutes = _minutes;

	solarPosition = (int)(_solarAngle / 30);

	zodiacSign = ascendant[solarPosition][_hour / 2];
}

void Elliptica::Thingy(int divisiones, int divisiones2, float offset, float scale, float r, float R, float cr, float cg, float cb, bool sign, float _angle) {
	int divInt = divisiones * divisiones2;
	float wholeCircleAng = 2 * PI;
	float anglePerDiv = wholeCircleAng / divisiones;
	float anglePerDiv2 = wholeCircleAng / divInt;

	// Draw torus
	glPushMatrix();
		//glColor3f(cr, cg, cb);
		glColor3f(0.7, 0.4, 0.8);

		glPushMatrix();
			if (sign) {
				glTranslated(0.0, 0.0, -offset);
				glRotated(-_angle, 0.0, 0.0, 1.0);
			}
			else {
				glTranslated(0.38, 0.0, -offset);
				glRotated(-30 * zodiacSign, 0.0, 0.0, 1.0);
			}
			glColor3f(cr, cg, cb);
			glutSolidTorus(r, R, 100, 100);
		glPopMatrix();

		//Divisions
		glColor3f(0.0, 0.0, 0.0);
		glTranslated(0.54, 0.0, 0.1);
		
		glPushMatrix();
			glRotated(-_angle, 0.0, 0.0, 1.0);
			glScaled(scaled, scaled, scaled);
			for (int x = 0; x < divisiones; x++) {

				//Ascendant Color line
				if (x == zodiacSign - 1)
					glColor3f(1.0, 0.0, 0.0);
				else
					glColor3f(0.0, 0.0, 0.0);

				glBegin(GL_LINES);
					glVertex2f((R - r) * cos(x * anglePerDiv), (R - r) * sin(x * anglePerDiv));
					glVertex2f((R + 1.0) * cos(x * anglePerDiv), (R + 1.0) * sin(x * anglePerDiv));
				glEnd();
			}

			for (int x = 0; x < divInt; x++) {
				glBegin(GL_LINES);
					glVertex2f((R - r) * cos(x * anglePerDiv2), (R - r) * sin(x * anglePerDiv2));
					glVertex2f((R - 0.2) * cos(x * anglePerDiv2), (R - 0.2) * sin(x * anglePerDiv2));
				glEnd();
			}

			if (sign) {
				glTranslated(0.0, 0.0, 0.1);
					zodiac->Aries(0.15, 22 * cos(15 * PI / 180), 22 * sin(15 * PI / 180), 0);
					zodiac->Tauro(0.15, 20 * cos(45 * PI / 180), 20 * sin(45 * PI / 180), 0);
					zodiac->Geminis(0.15, 20 * cos(75 * PI / 180), 20 * sin(75 * PI / 180), 0);
					zodiac->Cancer(0.15, 19 * cos(105 * PI / 180), 19 * sin(105 * PI / 180), 0);
					zodiac->Leo(0.20, 15 * cos(135 * PI / 180), 15 * sin(135 * PI / 180), 0);
					zodiac->Sagitario(0.12, 25 * cos(245 * PI / 180), 25 * sin(245 * PI / 180), 0);
					glColor3f(0.7, 0.4, 0.8);
			}

		glPopMatrix();

	glPopMatrix();
}
