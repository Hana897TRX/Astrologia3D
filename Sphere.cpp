#include <Windows.h>
#include <GL/gl.h>
#include <string.h>
#include <glut.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <stdio.h>

//##################
#include "Sphere.h"
#include "mRGB.h"
//##################

using namespace std;

Sphere::Sphere() {
	radius = 1;
	glGenTextures(1, &name);
}

Sphere::Sphere(float _r) {
	radius = _r;
	glGenTextures(1, &name);
}

void Sphere::SetTexture(char* fname) {
	texture = 1;
	myText[0].readBMPFile(fname);
	myText[0].SetTexture(name);
}

void Sphere::SetTexture(GLuint *name) {
	texture = 2;
	paramName = name;
}

void Sphere::SetSpeedAndTranslation(float _speed, float t0, float t1, float t2) {
	speed = _speed;
	translate[0] = t0;
	translate[1] = t1;
	translate[2] = t2;
}

void Sphere::LogicSphere() {
	for (int i = 0; i < slices + 1; i++) {
		float lon = Map(i, 0, slices, - PI, 0);

		for (int j = 0; j < stacks + 1; j++) {
			float lat = Map(j, 0, stacks, -2 * PI, 0);
			float x = radius * sin(lon) * cos(lat);
			float y = radius * sin(lon) * sin(lat);
			float z = radius * cos(lon);

			points[i][j][0] = x;
			points[i][j][1] = y;
			points[i][j][2] = z;
		}
	}
	//LogicNormals();
	finishCalc = true;
}

void Sphere::DoRotation() {
	glRotated(-75, 0.5, 0.0, 0.45);
	year += speed / 360;
	if (year >= 360)
		year -= 360;
	glRotated(year, 0.0, 1.0, 0.0);
}

void Sphere::HaSolidSphere() {
	if (!finishCalc) {
		LogicSphere();
	}
	else {
		glPushMatrix();
			DoRotation();
			glTranslated(translate[0], translate[1], translate[2]);

			if (texture == 1) {
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, name);
			}
			else if (texture == 2) {
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, *paramName);
			}

			glBegin(GL_TRIANGLES);
			for (int i = 0; i < slices; i++)
				for (int j = 0; j < stacks; j++) {

						glColor3f(1.0, 1.0, 1.0);

					glTexCoord2f((float)i / (float)slices, (float)j / (float)stacks);
						glNormal3fv(points[i][j]);
						glVertex3fv(points[i][j]);

					glTexCoord2f((float)(i + 1) / (float)slices, (float)j / (float)stacks);
						glNormal3fv(points[i + 1][j]);
						glVertex3fv(points[i + 1][j]);

					glTexCoord2f((float)(i + 1) / (float)slices, (float)(j + 1) / (float)stacks);
						glNormal3fv(points[i + 1][j + 1]);
						glVertex3fv(points[i + 1][j + 1]);
					
						glColor3f(0.5, 0.5, 0.5);

					glTexCoord2f((float)(i + 1) / (float)slices, (float)(j + 1) / (float)stacks);
						glNormal3fv(points[i + 1][j + 1]);
						glVertex3fv(points[i + 1][j + 1]);

					glTexCoord2f((float)(i) / (float)slices, (float)(j + 1) / (float)stacks);
						glNormal3fv(points[i][j + 1]);
						glVertex3fv(points[i][j + 1]);

					glTexCoord2f((float)(i) / (float)slices, (float)(j) / (float)stacks);
						glNormal3fv(points[i][j]);
						glVertex3fv(points[i][j]);
				}
			glEnd();
			glBindTexture(GL_TEXTURE_2D, 0);
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
}

void Sphere::HaWireSphere(float _pointSize) {
	if (!finishCalc) {
		LogicSphere();
	}
	else {
		glPushMatrix();
		for(int i = 0; i < slices; i ++)
			for (int j = 0; j < stacks; j++) {
				glPointSize(_pointSize);
				glBegin(GL_POINTS);
					glColor3f(1.0, 1.0, 1.0);
					glVertex3fv(points[i][j]);
				glEnd();
			}
		glPopMatrix();
	}
}
