#include "Barco.h"


#include <iostream>
#include "SFML/Graphics.hpp"

double Barco::getVelocidad() {
	return velocidad;
}
void Barco::setVelocidad(double p_velocidad) {
	velocidad = p_velocidad;
}

double Barco::getDistancia() {
	return distancia;
}
void Barco::setDistancia(double p_distancia) {

	distancia = p_distancia;
}

bool Barco::getNitro() {
	return nitro;

}
void Barco::setNitro(bool p_nitro) {
	nitro = p_nitro;
}

string  Barco::getName() {
	return nombre;
}

void Barco::setName(string p_name) {
	nombre = p_name;

}

void Barco::getParameters() {
	cout << nombre << "\nVelocidad: " << velocidad << " km/h\nDistancia: " << distancia << " m\nNitro: " << nitro << "\n\n";

}


void Barco::calcDsitancia() {
	distancia += velocidad * 100;

}
void  Barco::calcVelocidad() {
	velocidad = velocidad + rand() % 7;


}
void  Barco::reiniciarValores() {
	distancia = 0;
	nitro = true;
	velocidad = 0;


}

string Barco::getNitroStr() {
	if (nitro)
	{
		return "si";
	}
	else {
		return "no";
	}


}


Barco::Barco() {
	velocidad = 0;
	distancia = 0;
	nitro = true;
}

Barco::Barco(string p_nombre) {

	nombre = p_nombre;
	velocidad = 0;
	distancia = 0;
	nitro = true;


}