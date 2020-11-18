#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

#define PI 3.1416

//##########################
#include "Elliptica.h"
//##########################

void Elliptica::Thingy(int divisiones, int divisiones2, float scale, float r, float R, float cr, float cg, float cb) {
	int divInt = divisiones * divisiones2;
	float wholeCircleAng = 2 * PI;
	float anglePerDiv = wholeCircleAng / divisiones;
	float anglePerDiv2 = wholeCircleAng / divInt;
	// Draw torus'
	glPushMatrix();
		glColor3f(cr, cg, cb);
		//glScaled(20.0, 20.0, 20.0);
		//glRotated(30.0, 0.0, 1.0, 0.0);
		//glRotated(-5.0, 0.0, 0.0, 1.0);
		//glRotated(-5.0, 1.0, 0.0, 0.0);
		//glTranslated(0.0, -0.5, 0.0);
		glutSolidTorus(r, R, 100, 100);

		//Divisions
		glColor3f(0.0, 0.0, 0.0);
		for (int x = 0; x < divisiones; x++) {
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

	glPopMatrix();
}
