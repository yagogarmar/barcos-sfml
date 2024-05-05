#pragma once

#include <iostream>


using namespace std;


class Barco {

public:
	Barco();
	Barco(string p_nombre);


	double getVelocidad();
	void setVelocidad(double p_velocidad);

	double getDistancia();
	void setDistancia(double p_distancia);

	bool getNitro();
	void setNitro(bool p_nitro);

	string getName();
	void setName(string p_name);

	void getParameters();

	void calcDsitancia();

	void calcVelocidad();

	void reiniciarValores();

	string getNitroStr();

private:
	int velocidad;
	int distancia;
	bool nitro;
	string nombre;
	int x;
	int y;


};

