#include "Usuario.h"
#include <string>

using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente : public Usuario {
	private:
		string tipoMembre;

	public:
		Cliente();
		Cliente(string, string, string);

		string getMembresia();
		void setMembresia(string);

		~Cliente();
};
#endif