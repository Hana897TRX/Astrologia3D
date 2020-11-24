#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

#define PI 3.1416

//##########################
#include "Elliptica.h"
#include "ZodiacalSign.h"
#include "RomanNumerals.h"
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
RomanNumerals* roman;

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
				glTranslated(0.25, 0.0, -offset);
				glRotated(-30 * zodiacSign, 0.0, 0.0, 1.0);
			}
			glColor3f(cr, cg, cb);
			glutSolidTorus(r, R, 100, 100);
		glPopMatrix();

		//Divisions
		glColor3f(0.0, 0.0, 0.0);
		glTranslated(0.54, 0.0, 0.1);
		
		glPushMatrix();
			if(sign)
				glRotated(-_angle, 0.0, 0.0, 1.0);
			else {
				glRotated(30 * (zodiacSign - 1), 0.0, 0.0, 1.0);
				glRotated(-_angle, 0.0, 0.0, 1.0);
			}

			glScaled(scaled, scaled, scaled);
			for (int x = 0; x < divisiones; x++) {

				//Ascendant Color line
				if (sign) {
					if (x == zodiacSign - 1)
						glColor3f(1.0, 0.0, 0.0);
					else
						glColor3f(0.0, 0.0, 0.0);
				}
				else {
					if (x == 0)
						glColor3f(1.0, 0.0, 0.0);
					else
						glColor3f(0.0, 0.0, 0.0);
				}

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
				zodiac->Aries(		0.15,		22 * cos(15  * PI / 180),	22 * sin(15  * PI / 180),	0);
				zodiac->Tauro(		0.15,		20 * cos(45  * PI / 180),	20 * sin(45  * PI / 180),	0);
				zodiac->Geminis(	0.15,		20 * cos(75  * PI / 180),	20 * sin(75  * PI / 180),	0);
				zodiac->Cancer(		0.15,		19 * cos(105 * PI / 180),	19 * sin(105 * PI / 180),	0);
				zodiac->Leo(		0.20,		15 * cos(135 * PI / 180),	15 * sin(135 * PI / 180),	0);
				zodiac->Virgo(		0.10,		32 * cos(165 * PI / 180),	32 * sin(165 * PI / 180),	0);
				zodiac->Libra(		0.20,		15 * cos(193 * PI / 180),	15 * sin(193 * PI / 180),	0);
				zodiac->Escorpio(	0.15,		20 * cos(222 * PI / 180),	20 * sin(222 * PI / 180),	0);
				zodiac->Sagitario(	0.10,		30 * cos(255 * PI / 180),	30 * sin(255 * PI / 180),	0);
				zodiac->Capricornio(0.10,		30 * cos(290 * PI / 180),	30 * sin(290 * PI / 180),	0);
				zodiac->Acuario(	0.10,		30 * cos(315 * PI / 180),	30 * sin(315 * PI / 180),	0);
				zodiac->Piscis(		0.10,		30 * cos(345 * PI / 180),	30 * sin(345 * PI / 180),	0);
				glColor3f(0.7, 0.4, 0.8);
			}
			else {
				roman->One(		0.25,	 2.05 * cos(18  * PI / 180),	2.05 * sin(18  * PI / 180),  0);
				roman->Two(		0.25,	 2.05 * cos(45  * PI / 180),	2.05 * sin(45  * PI / 180),  0);
				roman->Three(	0.25,	 2.05 * cos(78  * PI / 180),	2.05 * sin(78  * PI / 180),  0);
				roman->Four(	0.25,	 2.05 * cos(105 * PI / 180),	2.05 * sin(105 * PI / 180),  0);
				roman->Five(	0.25,	 2.05 * cos(135 * PI / 180),	2.05 * sin(135 * PI / 180),  0);
				roman->Six(		0.25,	 2.2  * cos(165 * PI / 180),	2.2  * sin(165 * PI / 180),  0);
				roman->Seven(	0.25,	 2.3  * cos(195 * PI / 180),	2.3  * sin(195 * PI / 180),  0);
				roman->Eight(	0.25,	 2.3  * cos(220 * PI / 180),	2.3  * sin(220 * PI / 180),  0);
				roman->Nine(	0.25,	 2.05 * cos(258 * PI / 180),	2.05 * sin(258 * PI / 180),  0);
				roman->Ten(		0.25,	 2.05 * cos(285 * PI / 180),	2.05 * sin(285 * PI / 180),  0);
				roman->Eleven(	0.25,	 2.05 * cos(315 * PI / 180),	2.05 * sin(315 * PI / 180),  0);
				roman->Twelve(	0.25,	 1.95 * cos(343 * PI / 180),	1.95 * sin(343 * PI / 180),  0);
			}

		glPopMatrix();

	glPopMatrix();
}
