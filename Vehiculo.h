#include <string>

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

	public:
		Vehiculo();
		Vehiculo(string, string, string, string, double);

		string getṔlaca();
		void setPlaca(string);

		string getMarca();
		void setMarca(string);

		string getModelo();
		void setModelo(string);

		string getAnio();
		void setAnio(string);

		double getPrecio();
		void setPrecio(double);
};
#endif