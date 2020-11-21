#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

//##################
#include "ZodiacalSign.h"
//##################

ZodiacalSign::ZodiacalSign() {

}

void ZodiacalSign::Aries(float scaled, float tx, float ty, float tz) {
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glScaled(scaled, scaled, scaled);
	glTranslated(tx, ty, tz);
	glColor3f(0.760, 0.039, 0.098);
	//LEFT
	glTranslated(-2.5, 0.0, 0.0);
	glPushMatrix();
	glRotated(15, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.025, 0.4, 0.0);
	glPushMatrix();
	glRotated(-10, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.135, 0.4, 0.0);
	glPushMatrix();
	glRotated(-35, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.3, 0.2, 0.0);
	glPushMatrix();
	glRotated(-85, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.3, -0.10, 0.0);
	glPushMatrix();
	glRotated(45, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.25, -0.35, 0.0);
	glPushMatrix();
	glRotated(20, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.175, -1.35, 0.0);
	glPushMatrix();
	glRotated(5, 0.0, 0.0, 1.0);
	glScaled(0.25, 2.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//RIGHT

					 //x //y //z
	glTranslated(0.2, 0.0, 0.0);
	glPushMatrix();
	glRotated(-5, 0.0, 0.0, 1.0);
	glScaled(0.25, 2.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.16, 1.35, 0.0);
	glPushMatrix();
	glRotated(-20, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.2, 0.30, 0.0);
	glPushMatrix();
	glRotated(-50, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.325, 0.14, 0.0);
	glPushMatrix();
	glRotated(95, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.26, -0.15, 0.0);
	glPushMatrix();
	glRotated(35, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.15, -0.4, 0.0);
	glPushMatrix();
	glRotated(8, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.025, -0.35, 0.0);
	glPushMatrix();
	glRotated(-15, 0.0, 0.0, 1.0);
	glScaled(0.25, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void ZodiacalSign::Tauro(float scaled, float tx, float ty, float tz) {
	//Center
	glPushMatrix();
	glScaled(scaled, scaled, scaled);
	glTranslated(tx, ty, tz);
	glPushMatrix();
	glTranslated(0.0, -0.3, 0.2);
	glScaled(1.0, 1.0, 1.0);
	glutSolidTorus(0.2, 0.6, 60, 60);
	glPopMatrix();


	//Right

	glPushMatrix();
	glTranslated(0.0, 0.36, -0.35);

	glPushMatrix();
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.30, 0.0, 0.0);

	glPushMatrix();
	glRotated(30, 0.0, 0.0, 1.0);
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.2, 0.23, 0.0);

	glPushMatrix();
	glRotated(70, 0.0, 0.0, 1.0);
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.06, 0.25, 0.0);

	glPushMatrix();
	glRotated(85, 0.0, 0.0, 1.0);
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.10, 0.30, 0.0);

	glPushMatrix();
	glRotated(55, 0.0, 0.0, 1.0);
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.25, 0.2, 0.0);

	glPushMatrix();
	glRotated(20, 0.0, 0.0, 1.0);
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();

	//LEFT
	glPushMatrix();
	glTranslated(0.0, 0.36, -0.35);

	glPushMatrix();
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.30, 0.0, 0.0);

	glPushMatrix();
	glRotated(-30, 0.0, 0.0, 1.0);
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.2, 0.23, 0.0);

	glPushMatrix();
	glRotated(-70, 0.0, 0.0, 1.0);
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.06, 0.25, 0.0);

	glPushMatrix();
	glRotated(-85, 0.0, 0.0, 1.0);
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.10, 0.30, 0.0);

	glPushMatrix();
	glRotated(-55, 0.0, 0.0, 1.0);
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.25, 0.2, 0.0);

	glPushMatrix();
	glRotated(-20, 0.0, 0.0, 1.0);
	glScaled(0.4, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void ZodiacalSign::Geminis(float scaled, float tx, float ty, float tz) {
	glPushMatrix();
	glScaled(scaled, scaled, scaled);
	glTranslated(tx, ty, tz);

	glTranslated(0.0, 1.25, 0.0);
	//CENTER - TOP
	glPushMatrix();
	glScaled(1.0, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//GENERAL CENTER
	glPushMatrix();
	glTranslated(0.0, -1.0, 0.0);
	//LEFT
	glPushMatrix();
	glTranslated(-0.4, 0.0, 0.0);
	glScaled(0.2, 1.9, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	//RIGHT
	glPushMatrix();
	glTranslated(0.4, 0.0, 0.0);
	glScaled(0.2, 1.9, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	//RIGHT - TOP
	glPushMatrix();
	glTranslated(0.7, 0.1, 0.0);

	glPushMatrix();
	glRotated(20, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.35, 0.25, 0.0);

	glPushMatrix();
	glRotated(50, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	//LEFT - TOP
	glPushMatrix();
	glTranslated(-0.7, 0.1, 0.0);

	glPushMatrix();
	glRotated(-20, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.35, 0.25, 0.0);

	glPushMatrix();
	glRotated(-50, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glTranslated(0.0, -2.0, 0.0);

	//CENTER - BOTTOM
	glPushMatrix();
	glScaled(1.0, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//LEFT - BOTTOM
	glPushMatrix();
	glTranslated(-0.7, -0.1, 0.0);

	glPushMatrix();
	glRotated(20, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.35, -0.25, 0.0);

	glPushMatrix();
	glRotated(50, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	//RIGHT - BOTTOM
	glPushMatrix();
	glTranslated(0.7, -0.1, 0.0);

	glPushMatrix();
	glRotated(-20, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.35, -0.25, 0.0);

	glPushMatrix();
	glRotated(-50, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void ZodiacalSign::Cancer(void) {
	glPushMatrix();
	//Torus
	glPushMatrix();
	glTranslated(-1.0, 1.5, 0.0);
	glPushMatrix();
	glTranslated(0.1, -0.05, 0.5);
	glScaled(0.2, 0.2, 0.1);
	glutSolidTorus(0.5, 2.125, 45, 45);
	glPopMatrix();

	glTranslated(0.0, 0.4, 0.0);
	glPushMatrix();
	glRotated(-75, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.35, 0.1, 0.0);
	glPushMatrix();
	glRotated(-80, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.45, 0.05, 0.0);
	glPushMatrix();
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.45, -0.01, 0.0);
	glPushMatrix();
	glRotated(85, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.45, -0.07, 0.0);
	glPushMatrix();
	glRotated(75, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.40, -0.15, 0.0);
	glPushMatrix();
	glRotated(60, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(180, 1.0, 0.0, 0.0);
	glRotated(180, 0.0, 1.0, 0.0);
	glTranslated(-0.8, -0.8, 0.0);
	glPushMatrix();
	glTranslated(0.1, -0.05, -0.5);
	glScaled(0.2, 0.2, 0.1);
	glutSolidTorus(0.5, 2.125, 45, 45);
	glPopMatrix();

	glTranslated(0.0, 0.4, 0.0);
	glPushMatrix();
	glRotated(-75, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.35, 0.1, 0.0);
	glPushMatrix();
	glRotated(-80, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.45, 0.05, 0.0);
	glPushMatrix();
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.45, -0.01, 0.0);
	glPushMatrix();
	glRotated(85, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.45, -0.07, 0.0);
	glPushMatrix();
	glRotated(75, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.40, -0.15, 0.0);
	glPushMatrix();
	glRotated(60, 0.0, 0.0, 1.0);
	glScaled(0.15, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void ZodiacalSign::Leo(void) {
	glPushMatrix();
	glPushMatrix();
	glTranslated(0.1, 0.0, 0.5);
	glScaled(0.2, 0.2, 0.1);
	glutSolidTorus(0.25, 2.125, 45, 45);
	glPopMatrix();

	glTranslated(0.4, 0.50, 0.0);
	glPushMatrix();
	glRotated(20, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.75, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.125, 0.4, 0.0);
	glPushMatrix();
	glRotated(0, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.0, 0.125, 0.0);
	glPushMatrix();
	glRotated(-15, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.05, 0.125, 0.0);
	glPushMatrix();
	glRotated(-25, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.05, 0.1, 0.0);
	glPushMatrix();
	glRotated(-45, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.05, 0.05, 0.0);
	glPushMatrix();
	glRotated(-55, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.1, 0.05, 0.0);
	glPushMatrix();
	glRotated(-75, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.1, 0.0, 0.0);
	glPushMatrix();
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.1, 0.0, 0.0);
	glPushMatrix();
	glRotated(75, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.1, -0.05, 0.0);
	glPushMatrix();
	glRotated(65, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.05, -0.05, 0.0);
	glPushMatrix();
	glRotated(45, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.1, -0.1, 0.0);
	glPushMatrix();
	glRotated(25, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.05, -0.15, 0.0);
	glPushMatrix();
	glRotated(5, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.0, -0.15, 0.0);
	glPushMatrix();
	glRotated(-5, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.1, -0.65, 0.0);
	glPushMatrix();
	glRotated(-10, 0.0, 0.0, 1.0);
	glScaled(0.125, 1.25, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.05, -0.65, 0.0);
	glPushMatrix();
	glRotated(25, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.05, -0.1, 0.0);
	glPushMatrix();
	glRotated(65, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();


	glTranslated(0.1, -0.0, 0.0);
	glPushMatrix();
	glRotated(85, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.15, 0.05, 0.0);
	glPushMatrix();
	glRotated(-45, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.05, 0.1, 0.0);
	glPushMatrix();
	glRotated(-15, 0.0, 0.0, 1.0);
	glScaled(0.125, 0.2, 0.125);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();
}

void ZodiacalSign::Acuario(void) {
	//Top
	glPushMatrix();
	glTranslated(-1.5, 1.0, 0.0);
	glPushMatrix();
	glRotated(45, 0.0, 0.0, 1.0);
	glScaled(1.5, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.8, 0.06, 0.0);
	glPushMatrix();
	glRotated(-45, 0.0, 0.0, 1.0);
	glScaled(1.3, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.75, 0.0, 0.0);
	glPushMatrix();
	glRotated(45, 0.0, 0.0, 1.0);
	glScaled(1.3, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.75, 0.0, 0.0);
	glPushMatrix();
	glRotated(-45, 0.0, 0.0, 1.0);
	glScaled(1.3, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.75, 0.0, 0.0);
	glPushMatrix();
	glRotated(45, 0.0, 0.0, 1.0);
	glScaled(1.3, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.85, -0.1, 0.0);
	glPushMatrix();
	glRotated(-45, 0.0, 0.0, 1.0);
	glScaled(1.5, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	//Bottom
	glPushMatrix();
	glTranslated(-1.5, 0.0, 0.0);
	glPushMatrix();
	glRotated(45, 0.0, 0.0, 1.0);
	glScaled(1.5, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.8, 0.06, 0.0);
	glPushMatrix();
	glRotated(-45, 0.0, 0.0, 1.0);
	glScaled(1.3, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.75, 0.0, 0.0);
	glPushMatrix();
	glRotated(45, 0.0, 0.0, 1.0);
	glScaled(1.3, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.75, 0.0, 0.0);
	glPushMatrix();
	glRotated(-45, 0.0, 0.0, 1.0);
	glScaled(1.3, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.75, 0.0, 0.0);
	glPushMatrix();
	glRotated(45, 0.0, 0.0, 1.0);
	glScaled(1.3, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.85, -0.1, 0.0);
	glPushMatrix();
	glRotated(-45, 0.0, 0.0, 1.0);
	glScaled(1.5, 0.25, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();
}

void ZodiacalSign::Sagitario(void) {
	glPushMatrix();

	glPushMatrix();
	glTranslated(-1.0, -1.0, 0.0);
	glRotated(45, 0.0, 0.0, 1.0);
	glScaled(0.4, 2.5, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.8, -0.8, 0.0);
	glRotated(-45, 0.0, 0.0, 1.0);
	glScaled(0.4, 6.0, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.35, 1.5, 0.0);
	glPushMatrix();
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.4, 2.5, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(1.1, -1.1, 0.0);
	glPushMatrix();
	glScaled(0.4, 2.5, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();
}

void ZodiacalSign::Piscis(void) {
	glPushMatrix();
	glTranslated(0.0, 1.25, 0.0);
	//CENTER - TOP
	glPushMatrix();
	glScaled(1.0, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//RIGHT - TOP
	glPushMatrix();
	glTranslated(0.7, 0.1, 0.0);

	glPushMatrix();
	glRotated(20, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.35, 0.25, 0.0);

	glPushMatrix();
	glRotated(50, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	//LEFT - TOP
	glPushMatrix();
	glTranslated(-0.7, 0.1, 0.0);

	glPushMatrix();
	glRotated(-20, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.35, 0.25, 0.0);

	glPushMatrix();
	glRotated(-50, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glTranslated(0.0, -2.0, 0.0);
	////CENTER - BOTTOM
	glPushMatrix();
	glScaled(1.0, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//LEFT - BOTTOM
	glPushMatrix();
	glTranslated(-0.7, -0.1, 0.0);

	glPushMatrix();
	glRotated(20, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(-0.35, -0.25, 0.0);
	glPushMatrix();
	glRotated(50, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	//RIGHT - BOTTOM
	glPushMatrix();
	glTranslated(0.7, -0.1, 0.0);

	glPushMatrix();
	glRotated(-20, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslated(0.35, -0.25, 0.0);
	glPushMatrix();
	glRotated(-50, 0.0, 0.0, 1.0);
	glScaled(0.5, 0.2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}
