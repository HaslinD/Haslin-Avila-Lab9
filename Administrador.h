#include "Usuario.h"
#include <string>

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

class Administrador : public Usuario {
	private:
		string cargo;
		int numSeguro;

	public:
		Administrador(string, int, string, string);

		string getCargo();
		void setCargo(string);

		int getSeguro();
		void setSeguro(int);
};
#endif