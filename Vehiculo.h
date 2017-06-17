#include <string>
#include <stdlib.h>

using namespace std;

#ifndef VEHICULO_H
#define VEHICULO_H

class Vehiculo {
	private:
		string placa;
		string marca;
		string modelo;
		string anio;
		double precio;

		bool alquilado;

	public:
		Vehiculo();
		Vehiculo(string, string, string, string, double);

		string getPlaca();
		void setPlaca(string);

		string getMarca();
		void setMarca(string);

		string getModelo();
		void setModelo(string);

		string getAnio();
		void setAnio(string);

		double getPrecio();
		void setPrecio(double);

		bool getAlquilado();
		void setAlquilado(bool);
};
#endif