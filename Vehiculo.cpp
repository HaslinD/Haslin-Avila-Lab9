#include "Vehiculo.h"

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

void Vehiculo :: setPrecio(string precio){
	this -> precio = precio;
}