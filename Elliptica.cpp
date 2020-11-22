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

float scaled = 0.85;

ZodiacalSign* zodiac;

Elliptica::Elliptica() {
	zodiac = new ZodiacalSign();
}

void Elliptica::Thingy(int divisiones, int divisiones2, float scale, float r, float R, float cr, float cg, float cb, bool sign, float _angle) {
	int divInt = divisiones * divisiones2;
	float wholeCircleAng = 2 * PI;
	float anglePerDiv = wholeCircleAng / divisiones;
	float anglePerDiv2 = wholeCircleAng / divInt;
	// Draw torus'
	glPushMatrix();
		glColor3f(cr, cg, cb);

		glPushMatrix();
			glTranslated(0.0, 0.0, -0.6);
			glRotated(_angle, 0.0, 0.0, 1.0);
			glutSolidTorus(r, R, 100, 100);
		glPopMatrix();

		//Divisions
		glColor3f(0.0, 0.0, 0.0);
		glTranslated(0.45, 0.0, 0.0);
		
		glPushMatrix();
			glScaled(scaled, scaled, scaled);
			glRotated(_angle, 0.0, 0.0, 1.0);

			for (int x = 0; x < divisiones; x++) {
				//Ascendant Color line
				if (x == 0)
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
				zodiac->Aries(0.15, 20 + (R - 0.2) * cos(6 * anglePerDiv2),  5 + (R - 0.2) * sin(anglePerDiv2), 0);
				zodiac->Tauro(0.15, 13 + (R - 0.2) * cos(6 * anglePerDiv2), 14 + (R - 0.2) * sin(anglePerDiv2), 0);
				zodiac->Geminis(0.15, 6 + (R - 0.2) * cos(6 * anglePerDiv2), 20 + (R - 0.2) * sin(anglePerDiv2), 0);
			}

		glPopMatrix();

	glPopMatrix();
}
