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

void Administrador :: setCargo(){
	this -> cargo = cargo;
}

string Administrador :: getSeguro(){
	return numSeguro;
}

void Administrador :: setSeguro(){
	this -> numSeguro = numSeguro;
}

Administrador :: ~Administrador(){
}