#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

//#####################
#include "Cubemap.h"
#include "RGBpixmap.h"
//#####################

Cubemap::Cubemap(float _size, char* bot0, char* bot1, char* mid, char* left, char* right, char* top) {
	size = _size;
	glGenTextures(6, corex);

	text[0].readBMPFile(bot0);
	text[0].SetTexture(corex[0]);

	text[1].readBMPFile(bot1);
	text[1].SetTexture(corex[1]);

	text[2].readBMPFile(mid);
	text[2].SetTexture(corex[2]);

	text[3].readBMPFile(left);
	text[3].SetTexture(corex[3]);

	text[4].readBMPFile(right);
	text[4].SetTexture(corex[4]);

	text[5].readBMPFile(top);
	text[5].SetTexture(corex[5]);
}

void Cubemap::Draw() {
	//glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
		glTranslated(-200.0, -150.0, -250.0);

		//glBindTexture(GL_TEXTURE_2D, corex[0]);
		glBegin(GL_QUADS);
			//glTexCoord2f(0, 0);
				glVertex3f(0, 0, 0);
			//glTexCoord2f(0, 1);
				glVertex3f(size, 0, 0);
			//glTexCoord2f(1, 1);
				glVertex3f(size, 0, size);
			//glTexCoord2f(1, 0);
				glVertex3f(0, 0, size);
		glEnd();

		//glBindTexture(GL_TEXTURE_2D, corex[4]);
		glBegin(GL_QUADS);
			//glTexCoord2f(0, 0);
				glVertex3f(0, 0, 0);
			//glTexCoord2f(0, 1);
				glVertex3f(0, 0, size);
			//glTexCoord2f(1, 1);
				glVertex3f(0, size, size);
			//glTexCoord2f(1, 0);
				glVertex3f(0, size, 0);
		glEnd();


		//glBindTexture(GL_TEXTURE_2D, corex[2]);
		glBegin(GL_QUADS);
			//glTexCoord2f(0, 0);
				glVertex3f(size, 0, 0);
			//glTexCoord2f(0, 1);
				glVertex3f(0, 0, 0);
			//glTexCoord2f(1, 1);
				glVertex3f(0, size, 0);
			//glTexCoord2f(1, 0);
				glVertex3f(size, size, 0);
		glEnd();

		//glBindTexture(GL_TEXTURE_2D, corex[3]);
		glBegin(GL_QUADS);
			//glTexCoord2f(0, 0);
				glVertex3f(size, 0, 0);
			//glTexCoord2f(0, 1);
				glVertex3f(size, 0, size);
			//glTexCoord2f(1, 1);
				glVertex3f(size, size, size);
			//glTexCoord2f(1, 0);
				glVertex3f(size, size, 0);
		glEnd();

		//glBindTexture(GL_TEXTURE_2D, corex[1]);
		glBegin(GL_QUADS);
			//glTexCoord2f(0, 0);
				glVertex3f(size, 0, size);
			//glTexCoord2f(0, 1);
				glVertex3f(0, 0, size);
			//glTexCoord2f(1, 1);
				glVertex3f(0, size, size);
			//glTexCoord2f(1, 0);
				glVertex3f(size, size, size);
		glEnd();

		//glBindTexture(GL_TEXTURE_2D, corex[5]);
		glBegin(GL_QUADS);
			//glTexCoord2f(0, 0);
				glVertex3f(0, size, 0);
			//glTexCoord2f(0, 1);
				glVertex3f(size, size, 0);
			//glTexCoord2f(1, 1);
				glVertex3f(size, size, size);
			//glTexCoord2f(1, 0);
				glVertex3f(0, size, size);
		glEnd();

		//glBindTexture(GL_TEXTURE_2D, 0);
		glEnable(GL_LIGHTING);
	glPopMatrix();
	//glDisable(GL_TEXTURE_2D);
}
