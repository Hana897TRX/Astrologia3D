#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

//####################### - HOLA -
#include "Sphere.h"
#include "Planet.h"
#include "Moon.h"
#include "Disk.h"
#include "Cubemap.h"
#include "RGBpixmap.h"
#include "Asteroid.h"
#include "Lights.h"
#include "Reloj.h"
#include "Elliptica.h"
//#######################

					//    Separación	    Coordenas random
Planet planets[1];  //    con el sol	 sobre la circunferencia    
Asteroid* asteroids[10];
Lights* lightConfig;

float asteroidRing = 12;//					 X           Z
float posFinal[8][3] = {    {08.0,			0.0,		0.0},
							{11.0,			0.0,		0.0},
							{15.0,			0.0,		0.0},
							{19.0,			0.0,		0.0},
							{24.0,			0.0,		0.0},
							{31.0,			0.0,		0.0},
							{35.0,			0.0,		0.0},
							{39.0,			0.0,		0.0} };

static bool doAuto = false;
static bool seeOrbits = false;
Planet sun(0, 0.0, 5, 0.0, 0.0);

float angulo = 0;
float angulos[8];

float deltaT;
bool planetaActual = false;
int actual = 0;
int zoom = 1;

bool pressLeft, pressRight;
enum class ANIMATION { Init, InicialPos, Idle };
ANIMATION anim;
Reloj timer;
float t;

//################

Cubemap* map;

//###############

float eyex = 0, eyey = 35, pY = 0, pX = 0;
float lightEmission[4] = { 1.0, 1.0, 0.0, 1.0 };
float black[4] = { 0.0, 0.0, 0.0, 1.0 };

int estrellas = 1000;
float** estrellasPos;

float r = 0.45, R = 3.0, divisiones = 12.0, divisiones2 = divisiones * 3;

void Rotar() {
	for (int planeta = 0; planeta < 8; planeta++) {
		angulos[planeta] -= planets[planeta].GetYearInc() * deltaT;
		posFinal[planeta][1] = cos(angulos[planeta]) * posFinal[planeta][0];
		posFinal[planeta][2] = sin(angulos[planeta]) * posFinal[planeta][0];
	}
}

//Asignar coordenadas random dentro de sus orbitas
void reColocar() {
	for (int planeta = 0; planeta < 8; planeta++) {
		float angulo = 1 + rand() % 360;
		angulos[planeta] = angulo;
		posFinal[planeta][1] = cos(angulo) * posFinal[planeta][0];
		posFinal[planeta][2] = sin(angulo) * posFinal[planeta][0];
	}
}

void colocarEstrellas() {
	estrellasPos = new float* [estrellas];
	for (int i = 0; i < estrellas; i++) {
		estrellasPos[i] = new float[3];
		float randX = -114 + rand() % 228;
		float randY = -105 + rand() % 210;
		float randZ = -250 + rand() % 500;

		estrellasPos[i][0] = randX;
		estrellasPos[i][1] = randY;
		estrellasPos[i][2] = randZ;
	}
}

void dibujarEstrellas() {
	for (int i = 0; i < estrellas; i++) {
		glPushMatrix();

		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(
			estrellasPos[i][0],
			estrellasPos[i][1],
			estrellasPos[i][2]);
		glutSolidSphere(0.25, 10, 10);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}
}

void init(void)
{
	//################## LIGHTS #####################
	lightConfig = new Lights(0.0, 0.0, 0.0, 0.901, 0.513, 0.078);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	//##################### LOAD TEXTURES ###############################

	Moon::SetTexture((char*)"res/moon.bmp");
	sun.SetTexture((char*) "res/sun.bmp");

	planets[0] = Planet(0, 0, 0.6, 0.15f, 0.25f);
	planets[0].SetTexture((char*) "res/mercury.bmp");

	planets[1] = Planet(1, 0, 1.0, 0.13f, 0.23f);
	planets[1].SetTexture((char*) "res/venus.bmp");

	planets[2] = Planet(1, 0, 0.8, 0.11f, 0.21f);
	planets[2].SetTexture((char*) "res/earth.bmp");
	
	planets[3] = Planet(2, 0, 0.75, 0.09f, 0.19f);
	planets[3].SetTexture((char*) "res/mars.bmp");
	
	planets[4] = Planet(5, 0, 2.5, 0.07f, 0.17f);
	planets[4].SetTexture((char*) "res/jupiter.bmp");

	planets[5] = Planet(2, 1, 2.0, 0.05f, 0.15f);
	planets[5].SetTexture((char*) "res/saturn.bmp");

	planets[6] = Planet(2, 0, 1.2, 0.03f, 0.13f);
	planets[6].SetTexture((char*) "res/uranus.bmp");

	planets[7] = Planet(1, 0, 0.8, 0.02f, 0.11f);
	planets[7].SetTexture((char*) "res/neptune.bmp");

	cout << glGetString(GL_VERSION) << " |* This project was encoded over OpenGL 4.6.0 *| ";

	map = new Cubemap(400, (char*)"res/bot0.bmp", (char*)"res/bot1.bmp",
		(char*)"res/mid.bmp", (char*)"res/left.bmp",
		(char*)"res/right.bmp", (char*)"res/top.bmp");

	//######################## ANIMATION ########################
	timer = Reloj();
	anim = ANIMATION::Init;
	deltaT = 0.005;

	reColocar();

	//################## ASTEROIDS ##################
	Asteroid::SetTexture((char*)"res/asteroid.bmp");

	for (int i = 0; i < 10; i++) {
		float angulo = 1 + rand() % 360;
		asteroids[i] = new Asteroid(asteroidRing, cos(angulo) * asteroidRing, sin(angulo) * asteroidRing);
	}

	colocarEstrellas();
}

Elliptica elip[2];

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	map->Draw();
	dibujarEstrellas();
	glScaled(zoom, zoom, zoom);

	if (planetaActual) {
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glScaled(3, 3, 3);
		elip[0].Thingy(12, 3, 1.0, r, R, 0.8, 0.95, 0.8);
		elip[1].Thingy(12, 4, 0.75, r * 0.75, R * 0.75, 0.75, 0.9, 0.9);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}

	glRotated(eyex, 0.0, 1.0, 0.0);
	glRotated(eyey, 1.0, 0.0, 0.0);

	//universe.Draw();
	
	if (!planetaActual) {
		glPushMatrix();
			glMaterialfv(GL_FRONT, GL_EMISSION, lightEmission);
				sun.DrawPlanet(0, 0, 0);
			glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glPopMatrix();
	}

	switch (anim)
	{
	case ANIMATION::Init:
		timer.Iniciar_Conteo();
		if (timer.Conteo(3)) {
			anim = ANIMATION::InicialPos;
			t = 0.0;
		}
		break;

	case ANIMATION::InicialPos:
		float posInicial[8][3];
		if (t < 1.0) {
			t += (1.0 * deltaT);
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 3; j++) {
					posInicial[i][j] = 0.0 + posFinal[i][j] * t;
				}
				planets[i].DrawPlanet(posInicial[i][0], posInicial[i][1], posInicial[i][2]);
			}

		}
		else
			anim = ANIMATION::Idle;
		break;

	case ANIMATION::Idle:
		glPushMatrix();

		if (planetaActual)
		{
			glScaled(zoom, zoom, zoom);
			glTranslatef(-posFinal[actual][1], 0.0, -posFinal[actual][2]);
		}
		else {
			glTranslatef(0.0, 0.0, 0.0);
		}

		for (int i = 0; i < 8; i++)
			planets[i].DrawPlanet(posFinal[i][0], posFinal[i][1], posFinal[i][2]);
		for (int i = 0; i < 10; i++)
			asteroids[i]->Draw();

		if (doAuto)
			Rotar();

		glPopMatrix();

		break;
	}


	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 2160.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0.0, 35.0, 105.0, 0.0, -9.0, 0.0, 0.0, 1.0, 1.0);
	gluLookAt(0.0, 0.0, 105.0, 0.0, -9.0, 0.0, 0.0, 1.0, 1.0);
	//gluLookAt(0.0, 5.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a':
	case 'A':
		// Toggle automatic movement of planet
		if (doAuto)
			doAuto = false;
		else
			doAuto = true;
		planets->DoAuto(doAuto);
		break;
	case 'r':
	case 'R':
		// Change the planets position
		reColocar();
		glutPostRedisplay();
		break;
		// Manual control of day and year movement
	case 's':
	case 'S':
		// Toggle visibility of the orbits
		if (seeOrbits)
			seeOrbits = false;
		else
			seeOrbits = true;
		planets->SeeOrbits(seeOrbits);
		break;

	case 'Q':
	case 'q':
		if (zoom > 1)
			zoom -= 1;
		break;
	case 'e':
	case 'E':
		zoom += 1;
		break;

	case '1':
		actual = 0;
		zoom = 5;
		planetaActual = true;
		break;
	case '2':
		actual = 1;
		zoom = 5;
		planetaActual = true;
		break;
	case '3':
		actual = 2;
		zoom = 5;
		planetaActual = true;
		break;
	case '4':
		actual = 3;
		planetaActual = true;
		break;
	case '5':
		actual = 4;
		zoom = 5;
		planetaActual = true;
		break;
	case '6':
		actual = 5;
		zoom = 5;
		planetaActual = true;
		break;
	case '7':
		actual = 6;
		zoom = 5;
		planetaActual = true;
		break;
	case '8':
		actual = 7;
		zoom = 5;
		planetaActual = true;
		break;
	case '0':
		zoom = 1;
		planetaActual = false;
		break;
	}
}

void mouse(int btn, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		pressLeft = false;
		pressRight = false;

		// Make the year move faster
		if (btn == GLUT_LEFT_BUTTON)
			pressLeft = true;
			/*for (int i = 0; i < 8; i++)
				planets[i].ChangeInc(0.02);*/


		// Make the day move faster
		else if (btn == GLUT_RIGHT_BUTTON)
			pressRight = true;
			/*for (int i = 0; i < 8; i++)
				planets[i].ChangeInc(-0.02);*/


		glutPostRedisplay();
	}
}

void mouse_motion(int x, int y) {
	if (pressLeft) {
		if (y > pY)
			eyey += 1.0;
		else if (y < pY)
			eyey -= 1.0;
		glutPostRedisplay();
	}

	if (pressRight) {
		if (x > pX)
			eyex += 1.0;
		else if (x < pX)
			eyex -= 1.0;
		glutPostRedisplay();
	}

	pX = x;
	pY = y;
}

int main(int argc, char** argv)
{
	srand(time(NULL));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D Astrology");
	init();

	glutMotionFunc(mouse_motion);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);

	glutMainLoop();
	return 0;
}
