#include "Vehiculo.h"
#include <sstream>
#include <string>

using namespace std;

Vehiculo :: Vehiculo() {

}

Vehiculo :: Vehiculo(string placa, string marca, string modelo, string anio, double precio) {
	this -> placa = placa;
	this -> marca = marca;
	this -> modelo = modelo;
	this -> anio = anio;
	this -> precio = precio;
}

string Vehiculo :: getPlaca(){
	return placa;
}

void Vehiculo :: setPlaca(string placa){
	this -> placa = placa;
}

string Vehiculo :: getMarca(){
	return marca;
}

void Vehiculo :: setMarca(string marca){
	this -> marca = marca;
}

string Vehiculo :: getModelo(){
	return modelo;
}

void Vehiculo :: setModelo(string modelo){
	this -> modelo = modelo;
}

string Vehiculo :: getAnio(){
	return anio;
}

void Vehiculo :: setAnio(string anio){
	this -> anio = anio;
}

double Vehiculo :: getPrecio(){
	return precio;
}

void Vehiculo :: setPrecio(double precio){
	this -> precio = precio;
}

/*int* Vehiculo :: aleatPlaca1(){
	int random;
    int* placa1v;
    for (int i = 0; i < 4; ++i)
    {
    	placa1v = new int[4];
    }
    for(int i = 0; i < 4; ++i){
        random = rand() % 9 + 0;
        placa1v[i] = random;
    }
    return placa1v;
}
	
char* Vehiculo :: aleatPlacaA(){
	int random;
	char* placaAd;
	for (int i = 0; i < 3; ++i)
	{
		placaAd = new char[3];
	}
	for (int i = 0; i < 3; ++i)
    {
    	random = rand() % 26 + 0;
    	placaAd[i] = random; 
    }
    return placaAd;
}*/

/*string Vehiculo :: tostring(){
	stringstream alpha;
	stringstream beta;
	for (int i = 0; i < 3; ++i)
	{
		beta << placaA[i];
	}
	beta << "-";
	for (int i = 0; i < 4; ++i)
	{
		alpha << placa1[i];		
	}
	return beta.str() + alpha.str();
}*/