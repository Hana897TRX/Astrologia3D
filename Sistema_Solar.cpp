#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>

//#######################
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

using namespace std;

					//    Separación	    Coordenas random
				    //    con el sol	 sobre la circunferencia    
//Asteroid* asteroids[10];

float asteroidRing = 12;//					 X           Z

//float planetAngle[8] = { 332, 330, 353, 23, 35, 43, 318, 305 };
float planetAngle[8] = { 211, 216, 186, 158, 71, 60, 317, 303 };
//float planetAngle[8] = { 228, 201, 208, 182, 212, 321, 29, 163 };
//float planetAngle[8] = { 213, 157, 198, 186, 271, 80, 198, 243 };	

float anglePerDay[8] = {	4.0909090909090909090909090909091, //	MERCURY
														  1.6, //	VENUS
						   0.98562628336755646817248459958932, //	SUN
						   0.52401746724890829694323144104803, //	MART
						   0.09126169290440337668263746292494, //	JUPITER
						   0.03341106045313750739567744405388, //	SATURNO
						   0.01173364623056614843062481666178, //	URANO
						   0.00597349262647003920104536120963};//	NEPTUNO

float posFinal[8][3] = {	{08.0,		0.0,	0.0},		//	Mercury
							{11.0,		0.0,	0.0},		//	Venus
							{15.0,		0.0,	0.0},		//	Sun
							{19.0,		0.0,	0.0},		//	Mart
							{24.0,		0.0,	0.0},		//	Jupiner
							{31.0,		0.0,	0.0},		//	Saturno
							{35.0,		0.0,	0.0},		//	Urano
							{39.0,		0.0,	0.0} };		//	Neptuno

float eyex = 0, eyey = 35, pY = 0, pX = 0;
float lightEmission[4] = { 1.0, 1.0, 0.0, 1.0 };
float black[4] = { 0.0, 0.0, 0.0, 1.0 };
float angulo = 0;
float angulos[8];
float deltaT;
float r = 0.45, R = 3.0, divisiones = 12.0, divisiones2 = divisiones * 3;
float** estrellasPos;
float t;

static bool doAuto = false;
static bool seeOrbits = true;
bool planetaActual = false;
bool pressLeft, pressRight;

int actual = 0;
int zoom = 1;
int estrellas = 250;

enum class ANIMATION { Init, InicialPos, Idle };

//################ Objects and Pointers

Planet planets[1];
Cubemap* map;
Elliptica* elip[2];
ANIMATION anim;
Reloj timer;
Planet sun(1, 0.0, 2.5, 0.0, 0.0);
Lights* lightConfig;

//############### DEFAULT DATE

//int year = 2000, month = 3, day = 13;
int year = 2000, month = 9, day = 29;
int hour = 12, minutes = 30;
//int year = 1972, month = 10, day = 11;

//###############

void Rotar() {

}

void Fog() {
	GLfloat density = 0.0030;
	//GLfloat fogColor[4] = { 0.541, 0.023, 0.556, 1.0 };
	GLfloat fogColor[4] = { 0.01, 0.01, 0.01, 1.0 };
	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, density);
	glFogf(GL_FOG_START, 1.5);
	glFogf(GL_FOG_END, 3.0);
}

//Asignar coordenadas random dentro de sus orbitas

void reColocar() {
	for (int planeta = 0; planeta < 8; planeta++) {
		posFinal[planeta][1] =	cos(planetAngle[planeta] * M_PI / 180) * posFinal[planeta][0];
		posFinal[planeta][2] = -sin(planetAngle[planeta] * M_PI / 180) * posFinal[planeta][0];
	}
}

void setDate(int _year, int _month, int _day, int _hours, int _minutes) {
	hour = _hours;
	minutes = _minutes;

	int finalYear, finalMonth, finalDay;

	finalYear = _year - year;
	finalMonth = _month - month;
	finalDay = _day - day;

	int periodo = _month / 4;

	float totalDays = finalYear * 365.25 + finalMonth * 30.5 + finalDay;

	switch (periodo) {
	case 0:
		planetAngle[0] = std::fmod((planetAngle[0] + anglePerDay[0]), 360);
		break;
	case 1:
		planetAngle[0] = std::fmod((planetAngle[0] + anglePerDay[0] * (totalDays - (finalYear + 1) * 63)), 360);
		break;
	case 2:
		planetAngle[0] = std::fmod((planetAngle[0] + anglePerDay[0] * (totalDays - (finalYear + 2) * 63)), 360);
		break;
	}

	//planetAngle[0] = std::fmod((planetAngle[0] + anglePerDay[0] * (totalDays - (finalYear + 2) * 63)), 360);

	//if (totalDays < 0)
	//	//planetAngle[0] *= -1;
	//	planetAngle[0] = 360 + planetAngle[0] * -1;

	for (int x = 1; x < 8; x++) {
		planetAngle[x] = std::fmod((planetAngle[x] + anglePerDay[x] * totalDays), 360);
		
		//if (totalDays < 0)
		//	//planetAngle[x] *= -1;
		//	planetAngle[x] = 360 + planetAngle[x] * -1;
	}

	reColocar();
}

void GetDate() {
	int datex[5];

	std::string date = "", segment = "", hourMinutes = "";
	std::cout << "Get your date with the following format <Y-M-D>: 2000-12-26\n>>";
	std::cin >> date;
	std::cout << "\nNow please, write your hour and minutes of birthday with the following format <hr, min>: 0-42\n>>";
	std::cin >> hourMinutes;
	date += "-" + hourMinutes;

	std::string delimiter = "-";
	std::vector<std::string> seglist;
	size_t pos = 0;
	std::string token;

	int i = 0;

	while ((pos = date.find(delimiter)) != std::string::npos) {
		token = date.substr(0, pos);
		date.erase(0, pos + delimiter.length());
		datex[i] = atoi(token.c_str());
		i++;
	}

	datex[4] = atoi(date.c_str());
	
	std::cout << "Your date is: Year<" << datex[0] << "> Month <" << datex[1] << "> Day <" << datex[2] << "> Hour <" << datex[3] << "> Minutes <" << datex[4] << ">\n";
	setDate(datex[0], datex[1], datex[2], datex[3], datex[4]);
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
	GetDate();
	//################## LIGHTS #####################
	lightConfig = new Lights(0.0, 0.0, 0.0, 0.901, 0.513, 0.078);

	glClearColor(0.1, 0.1, 0.1, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	//##################### LOAD TEXTURES ###############################

	Moon::SetTexture((char*)"res/moon.bmp");
	sun.SetTexture((char*) "res/earth.bmp");

	planets[0] = Planet(0, 0, 0.6, 0.15f, 0.25f);
	planets[0].SetTexture((char*) "res/mercury.bmp");

	planets[1] = Planet(1, 0, 0.8, 0.13f, 0.23f);
	planets[1].SetTexture((char*) "res/venus.bmp");

	planets[2] = Planet(0, 0, 0.9, 0.11f, 0.21f);
	planets[2].SetTexture((char*) "res/sun.bmp");
	
	planets[3] = Planet(0, 0, 0.75, 0.09f, 0.19f);
	planets[3].SetTexture((char*) "res/mars.bmp");
	
	planets[4] = Planet(5, 0, 1.0, 0.07f, 0.17f);
	planets[4].SetTexture((char*) "res/jupiter.bmp");

	planets[5] = Planet(2, 1, 1.0, 0.05f, 0.15f);
	planets[5].SetTexture((char*) "res/saturn.bmp");

	planets[6] = Planet(2, 0, 0.8, 0.03f, 0.13f);
	planets[6].SetTexture((char*) "res/uranus.bmp");

	planets[7] = Planet(1, 0, 0.6, 0.02f, 0.11f);
	planets[7].SetTexture((char*) "res/neptune.bmp");

	cout << glGetString(GL_VERSION) << " |* This project was encoded over OpenGL 4.6.0 *| ";

	map = new Cubemap(400,	(char*)"res/bot0.bmp",	(char*)"res/bot1.bmp",
							(char*)"res/mid.bmp",	(char*)"res/left.bmp",
							(char*)"res/right.bmp", (char*)"res/top.bmp");

	//######################## ANIMATION ########################

	timer = Reloj();
	anim = ANIMATION::Init;
	deltaT = 0.005;

	reColocar();
	//setDate(2000, 11, 9, 0, 42);
	//setDate(2000, 9, 29);
	//setDate(2000, 4, 26);
	//setDate(2002, 6, 4, 13, 5);
	//setDate(1999, 11, 3, 9, 5);
	//setDate(1999, 12, 18, 7, 0);
	//setDate(1934, 10, 22);

	elip[0] = new Elliptica(planetAngle[2], hour, minutes);
	elip[1] = new Elliptica(planetAngle[2], hour, minutes);

	planets->SeeOrbits(seeOrbits);

	//################## ASTEROIDS ##################
	/*Asteroid::SetTexture((char*)"res/asteroid.bmp");

	for (int i = 0; i < 10; i++) {
		float angulo = 1 + rand() % 360;
		asteroids[i] = new Asteroid(asteroidRing, cos(angulo) * asteroidRing, sin(angulo) * asteroidRing);
	}*/

	Fog();

	colocarEstrellas();
}

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
			glTranslated(-30.0, 0.0, -2);
			glScaled(10, 10, 10);
			elip[1]->Thingy(12, 4,  0.30, 1.5, r * 0.65, R * 0.65, 1.0, 1.0, 1.9, false, planetAngle[actual]);
			elip[0]->Thingy(12, 3,	0.40, 1.0,		 r,			R, 0.8, 0.95, 0.8, true, planetAngle[actual]);
			glEnable(GL_LIGHTING);
		glPopMatrix();
	}

	glRotated(eyex, 0.0, 1.0, 0.0);
	glRotated(eyey, 1.0, 0.0, 0.0);
	
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
			planets[actual].DrawPlanet(posFinal[actual][0], posFinal[actual][1], posFinal[actual][2]);
		}
		else {
			glTranslatef(0.0, 0.0, 0.0);
			for (int i = 0; i < 8; i++)
				planets[i].DrawPlanet(posFinal[i][0], posFinal[i][1], posFinal[i][2]);
		}		

		/*for (int i = 0; i < 10; i++)
			asteroids[i]->Draw();*/

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
	gluLookAt(0.0, 0, 80.0, 0.0, -2.0, 0.0, 0.0, 1.0, 1.0);
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
		zoom = 2;
		planetaActual = true;
		seeOrbits = false;
		planets->SeeOrbits(seeOrbits);
		break;
	case '2':
		actual = 1;
		zoom = 2;
		planetaActual = true;
		seeOrbits = false;
		planets->SeeOrbits(seeOrbits);
		break;
	case '3':
		actual = 2;
		zoom = 2;
		planetaActual = true;
		seeOrbits = false;
		planets->SeeOrbits(seeOrbits);
		break;
	case '4':
		actual = 3;
		planetaActual = true;
		seeOrbits = false;
		planets->SeeOrbits(seeOrbits);
		break;
	case '5':
		actual = 4;
		zoom = 2;
		planetaActual = true;
		seeOrbits = false;
		planets->SeeOrbits(seeOrbits);
		break;
	case '6':
		actual = 5;
		zoom = 2;
		planetaActual = true;
		seeOrbits = false;
		planets->SeeOrbits(seeOrbits);
		break;
	case '7':
		actual = 6;
		zoom = 2;
		planetaActual = true;
		seeOrbits = false;
		planets->SeeOrbits(seeOrbits);
		break;
	case '8':
		actual = 7;
		zoom = 2;
		planetaActual = true;
		seeOrbits = false;
		planets->SeeOrbits(seeOrbits);
		break;
	case '0':
		zoom = 1;
		planetaActual = false;
		seeOrbits = true;
		planets->SeeOrbits(seeOrbits);
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
