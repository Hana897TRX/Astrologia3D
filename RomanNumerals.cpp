#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>
#include <iostream>

//#####################
#include "RomanNumerals.h"
//#####################

RomanNumerals::RomanNumerals()
{

}

void RomanNumerals::One(float scaled, float tx, float ty, float tz)
{
	glColor3f(0.5, 0.8, 0.3);
	glPushMatrix();
		glTranslated(tx, ty, tz);
		glScaled(0.25, 1.0, 0.25);
		glScaled(scaled, scaled, scaled);
		glutSolidCube(1.0);
	glPopMatrix();
}

void RomanNumerals::Two(float scaled, float tx, float ty, float tz)
{
	glColor3f(0.5, 0.8, 0.3);
	glPushMatrix();
		glTranslated(tx, ty, tz);
		glScaled(0.25, 1.0, 0.25);
		glScaled(scaled, scaled, scaled);
		glutSolidCube(1.0);

		glTranslated(2, 0.0, 0.0);
		glutSolidCube(1.0);
	glPopMatrix();
}

void RomanNumerals::Three(float scaled, float tx, float ty, float tz)
{
	glColor3f(0.5, 0.8, 0.3);
	glPushMatrix();
		glTranslated(tx, ty, tz);
		glScaled(0.25, 1.0, 0.25);
		glScaled(scaled, scaled, scaled);
		glutSolidCube(1.0);

		glTranslated(2, 0.0, 0.0);
		glutSolidCube(1.0);

		glTranslated(2, 0.0, 0.0);
		glutSolidCube(1.0);
	glPopMatrix();
}

void RomanNumerals::Four(float scaled, float tx, float ty, float tz)
{
	glPushMatrix();
		glTranslated(tx, ty, tz);

		glPushMatrix();
			glRotated(35, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glTranslated(0.11, 0.0, 0.0);

		glPushMatrix();
			glRotated(-35, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glScaled(0.25, 1.0, 0.25);
		glScaled(scaled, scaled, scaled);
		glTranslated(-4, 0.0, 0.0);
		glutSolidCube(1.0);
	glPopMatrix();
}

void RomanNumerals::Five(float scaled, float tx, float ty, float tz)
{
	glPushMatrix();
		glTranslated(tx, ty, tz);

		glPushMatrix();
			glRotated(35, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glTranslated(0.11, 0.0, 0.0);

		glPushMatrix();
			glRotated(-35, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();
}

void RomanNumerals::Six(float scaled, float tx, float ty, float tz)
{
	glPushMatrix();
		glTranslated(tx, ty, tz);

		glPushMatrix();
			glRotated(35, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glTranslated(0.11, 0.0, 0.0);

		glPushMatrix();
			glRotated(-35, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glScaled(0.25, 1.0, 0.25);
		glScaled(scaled, scaled, scaled);
		glTranslated(3, 0.0, 0.0);
		glutSolidCube(1.0);
	glPopMatrix();
}

void RomanNumerals::Seven(float scaled, float tx, float ty, float tz)
{
	glPushMatrix();
		glTranslated(tx, ty, tz);

		glPushMatrix();
			glRotated(35, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glTranslated(0.11, 0.0, 0.0);

		glPushMatrix();
			glRotated(-35, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glTranslated(3, 0.0, 0.0);
			glutSolidCube(1.0);
		glPopMatrix();

		glScaled(0.25, 1.0, 0.25);
		glScaled(scaled, scaled, scaled);
		glTranslated(5, 0.0, 0.0);
		glutSolidCube(1.0);
	glPopMatrix();
}

void RomanNumerals::Eight(float scaled, float tx, float ty, float tz)
{
	glPushMatrix();
		glTranslated(tx, ty, tz);

		glPushMatrix();
			glRotated(35, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glTranslated(0.11, 0.0, 0.0);

		glPushMatrix();
			glRotated(-35, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glTranslated(3, 0.0, 0.0);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glTranslated(5, 0.0, 0.0);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glTranslated(7, 0.0, 0.0);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();
}

void RomanNumerals::Nine(float scaled, float tx, float ty, float tz)
{
	glPushMatrix();
		glTranslated(tx, ty, tz);

		glPushMatrix();
			glRotated(45, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glRotated(-45, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glTranslated(-3, 0.0, 0.0);
			glutSolidCube(1.0);
		glPopMatrix();

	glPopMatrix();
}

void RomanNumerals::Ten(float scaled, float tx, float ty, float tz)
{
	glPushMatrix();
		glTranslated(tx, ty, tz);

		glPushMatrix();
			glRotated(45, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glRotated(-45, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();
}

void RomanNumerals::Eleven(float scaled, float tx, float ty, float tz)
{
	glPushMatrix();
		glTranslated(tx, ty, tz);

		glPushMatrix();
			glRotated(45, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glRotated(-45, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glTranslated(3, 0.0, 0.0);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();
}

void RomanNumerals::Twelve(float scaled, float tx, float ty, float tz)
{
	glPushMatrix();
		glTranslated(tx, ty, tz);

		glPushMatrix();
			glRotated(45, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glRotated(-45, 0.0, 0.0, 1.0);
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glTranslated(3, 0.0, 0.0);
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glScaled(0.25, 1.0, 0.25);
			glScaled(scaled, scaled, scaled);
			glTranslated(5, 0.0, 0.0);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();
}
