#pragma once
#include <time.h>

class Reloj {
private:
	time_t timeI, timeF;
	bool asignar;
public:
	Reloj();
	void Iniciar_Conteo();
	bool Conteo(int);
	float Aumentar_PorSegundo();
};