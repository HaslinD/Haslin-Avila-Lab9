#include "Cliente.h"

using namespace std;

Cliente :: Cliente() {

}

Cliente :: Cliente (string tipoMembre, string user, string password) : Usuario(user, password){
	this -> tipoMembre = tipoMembre;
}

string Cliente :: getMembresia(){
	return tipoMembre;
}

void Cliente :: setMembresia(string tipoMembre){
	this -> tipoMembre = tipoMembre;
}

Cliente :: ~Cliente() {
}