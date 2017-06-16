#include "Administrador.h"

using namespace std;

Administrador :: Administrador() {
	
}

Administrador :: Administrador (string cargo, int numSeguro, string user, string password) : Usuario(user, password){
	this -> cargo = cargo;
	this -> numSeguro = numSeguro;
}

string Administrador :: getCargo(){
	return cargo;
}

void Administrador :: setCargo(string cargo){
	this -> cargo = cargo;
}

int Administrador :: getSeguro(){
	return numSeguro;
}

void Administrador :: setSeguro(int numSeguro){
	this -> numSeguro = numSeguro;
}

Administrador :: ~Administrador(){
}