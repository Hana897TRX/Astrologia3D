#include "Reloj.h"

Reloj::Reloj() {
	timeI = time(0);
	timeF = time(0);
	asignar = false;
}

void Reloj::Iniciar_Conteo() {
	if (!asignar) {
		timeI = time(0);
		asignar = true;
	}
}

bool Reloj::Conteo(int _segundos) {
	timeF = time(0);
	int s = timeF - timeI;
	if (s >= _segundos) {
		asignar = false;
		return true;
	}
	return false;
}