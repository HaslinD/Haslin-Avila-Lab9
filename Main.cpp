#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>

#include "Administrador.h"
#include "Cliente.h"
#include "Vehiculo.h"

int menu();
int menu2();
int menu3();
int menu4();
string RandomPlaca();

vector<Administrador*> CargarAdmin(vector<Administrador*>);
vector<Cliente*> CargarClien(vector<Cliente*>);
vector<Vehiculo*> CargarCarr(vector<Vehiculo*>);

int main(){
	string user, password;
	vector<Vehiculo*> carro;
	vector<Administrador*> admin;
	vector<Cliente*> clien;
	ofstream textAdm, textCli, textCar;
	srand(time(NULL));
	textAdm.open("Administrador.txt", ios::app);
	textCli.open("Cliente.txt", ios::app);
	textCar.open("Vehiculo.txt", ios::app);
	
	admin = CargarAdmin(admin);
	clien = CargarClien(clien);
	carro = CargarCarr(carro);

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	bool salir = false;
	while (!salir){
        switch(menu()){
           	case 1:{
	        	bool salir2 = false;
				while (!salir2){
			        switch(menu2()){
			           	case 1:{
			           		string cargo;
			           		int numSeguro;

				        	cout << "Crear Administrador" << endl;
				        	cout << "Ingrese Nombre de Usuario Admin: " << endl;
				        	cin >> user;
				        	cout << "Ingrese la contraseña del admin: " << endl;
				        	cin >> password;
				        	cout << "Ingrese el Cargo: " << endl;
				        	cin >> cargo;
				        	cout << "Ingrese el numero de Seguro: " << endl;
				        	cin >> numSeguro;

				        	admin.push_back(new Administrador(cargo, numSeguro, user, password));
				        	textAdm << user << password << cargo << numSeguro << endl; 
				        	cout << "Se ha Guardado " << endl;
			               	break;}

				       	case 2:{
				       		int mem;
				       		string membre;
				            cout << "Crear Cliente" << endl;
				        	cout << "Ingrese Nombre de Usuario Admin: " << endl;
				        	cin >> user;
				        	cout << "Ingrese la contraseña del admin: " << endl;
				        	cin >> password;
				        	cout << "Seleccione tipo de membresia: " << endl;
				        	cout << "[1] Normal" << endl;
				        	cout << "[2] Gold" << endl;
				        	cout << "[3] Platinum" << endl;
				        	cin >> mem;
				        	if (mem == 1) {
				        		membre = "Normal";
				        	} else if (mem == 2) {
				        		membre = "Gold";
				        	} else if (mem == 3) {
				        		membre = "Platinum";
				        	}

				        	clien.push_back(new Cliente(membre, user, password));
				        	textCli << user << password << membre << endl;
				        	cout << "Se ha Guardado " << endl;
				           	break;}

				       	case 3:
				           	salir2 = true;
				           	break;
				    }
				}
               	break;}

	       	case 2:{
	       		string Nusuario;
	       		string contrasenia;
	            cout << "--| Log In |--" << endl;
	            cout << "Ingrese el Nombre de Usuario" << endl;
	            cin >> Nusuario;
	            cout << "Ingrese la Contraseña" << endl;
	            cin >> contrasenia;
	            for (int i = 0; i < admin.size(); ++i)
	            {
	            	if (admin.at(i) -> getUser() == Nusuario && admin.at(i) -> getPassword() == contrasenia)
	            	{
	            		
            			bool salir3 = false;
						while (!salir3){
					        switch(menu3()){
					           	case 1:{
					           		string placa, marca, modelo, anio;
					           		double precio;
						        	cout << "Crear Vehiculo" << endl;
						        	placa = RandomPlaca();
						        	cout << "Ingrese la Marca del Vehiculo" << endl;
						        	cin >> marca;
						        	cout << "Ingrese el Modelo del Vehiculo" << endl;
						        	cin >> modelo;
						        	cout << "Ingrese el año del Vehiculo" << endl;
						        	cin >> anio;
						        	cout << "Ingrese la renta del Vehiculo" << endl;
						        	cin >> precio;

						        	carro.push_back(new Vehiculo(placa, marca, modelo, anio, precio));
						        	textCar << placa << marca << modelo << anio << precio << endl;
						        	cout << "Se ha Guardado" << endl;
					               	break;}

						       	case 2:{
						       		int num;
						       		string placa1, marca1, modelo1, anio1; 
						       		double precio1;
						            cout << "Modificar Vehiculo" << endl;
						            for(int i = 0; i < carro.size(); i++){
						            	cout << "<---[" << i << "]--->" << endl;
										cout << "Placa: " << carro[i] -> getPlaca() << endl;
										cout << "Marca: " << carro[i] -> getMarca() << endl;
										cout << "Modelo: " << carro[i] -> getModelo() << endl;
										cout << "Año: " << carro[i] -> getAnio() << endl;
										cout << "Precio Renta: " << carro[i] -> getPrecio() << endl;
										cout << "<------------------->" << endl;
									}
									while (num > 0 || num < carro.size()) {
										cout << "Ingrese el Vehiculo que desea Modificar" << endl;
										cin >> num;
									}
									cout << "Crear Vehiculo" << endl;
						        	placa1 = RandomPlaca();
						        	cout << "Ingrese la Marca del Vehiculo" << endl;
						        	cin >> marca1;
						        	cout << "Ingrese el Modelo del Vehiculo" << endl;
						        	cin >> modelo1;
						        	cout << "Ingrese el año del Vehiculo" << endl;
						        	cin >> anio1;
						        	cout << "Ingrese la renta del Vehiculo" << endl;
						        	cin >> precio1;
									carro.at(num) -> setPlaca(placa1);
									carro.at(num) -> setMarca(marca1);
									carro.at(num) -> setModelo(modelo1);
									carro.at(num) -> setAnio(anio1);
									carro.at(num) -> setPrecio(precio1);
						           	break;}

					           	case 3:{
					           		int numbers =  0;
							       	cout << "Ingrese la posicion que quiere eliminar: " << endl;
									for(int i = 0; i < carro.size(); i++){
										cout << "<---[" << i << "]--->" << endl;
										cout << "Placa: " << carro[i] -> getPlaca() << endl;
										cout << "Marca: " << carro[i] -> getMarca() << endl;
										cout << "Modelo: " << carro[i] -> getModelo() << endl;
										cout << "Año: " << carro[i] -> getAnio() << endl;
										cout << "Precio Renta: " << carro[i] -> getPrecio() << endl;
										cout << "<------------------->" << endl;
									}
									cin >> numbers;
									carro.erase(carro.begin() + numbers);
									cout << "Obra ha eliminada" << endl;
					           		break;}

					           	case 4:{
					           		cout << "Lista de Carros" << endl;
					           		for(int i = 0; i < carro.size(); i++){
					           			cout << "<---[" << i << "]--->" << endl;
										cout << "Placa: " << carro[i] -> getPlaca() << endl;
										cout << "Marca: " << carro[i] -> getMarca() << endl;
										cout << "Modelo: " << carro[i] -> getModelo() << endl;
										cout << "Año: " << carro[i] -> getAnio() << endl;
										cout << "Precio Renta: " << carro[i] -> getPrecio() << endl;
										cout << "<------------------->" << endl;
									}

					           		break;}

						       	case 5:
						           	salir3 = true;
						           	break;
						    }
	            		}
	            	} else {
	            		for (int i = 0; i < clien.size(); ++i)
			            {
			            	if (clien.at(i) -> getUser() == Nusuario && clien.at(i) -> getPassword() == contrasenia)
			            	{
			            		
		            			bool salir4 = false;
								while (!salir4){
							        switch(menu4()){
							           	case 1:{
											
							               	break;}

								       	case 2:{
								                
								           	break;}

								       	case 3:
								           	salir4 = true;
								           	break;
								    }
								}
			            	}
			            }
	            	}
	            }
	           	break;}

	       	case 3:
	           	salir = true;
	           	break;
	    }
	}
    return 0;
}

int menu(){
    int opcion;
    bool valido = true;
    do{
        cout << "-----MENU------" << endl
             << "1.- Crear Usuarios" << endl
             << "2.- LogIn"<< endl
             << "3.- Salir" << endl; 

        cout << " Ingrese una opción: ";
        cin >> opcion;

        if (opcion > 0 && opcion < 4)
            valido = true;
        else {
            cout << "La opcion seleccionada es Nula, intente de nuevo ......." << endl;
        }
        cout << "----------------------" << endl;
                
    }while(!valido);
    return opcion;
}

int menu2(){
    int opcion;
    bool valido = true;
    do{
        cout << "------SUB-MENU------" << endl
             << "1.- Administrador" << endl
             << "2.- Cliente"<< endl
             << "3.- Salir" << endl; 

        cout << " Ingrese una opción: ";
        cin >> opcion;

        if (opcion > 0 && opcion < 4)
            valido = true;
        else {
            cout << "La opcion seleccionada es Nula, intente de nuevo ......." << endl;
        }
        cout << "----------------------" << endl;
                
    }while(!valido);
    return opcion;
}

int menu3(){
    int opcion;
    bool valido = true;
    do{
        cout << "------SUB-MENU------" << endl
             << "1.- Agregar" << endl
             << "2.- Modificar"<< endl
             << "3.- Eliminar" << endl
             << "4.- Listar" << endl
             << "5.- Salir" << endl; 

        cout << " Ingrese una opción: ";
        cin >> opcion;

        if (opcion > 0 && opcion < 6)
            valido = true;
        else {
            cout << "La opcion seleccionada es Nula, intente de nuevo ......." << endl;
        }
        cout << "----------------------" << endl;
                
    }while(!valido);
    return opcion;
}

int menu4(){
    int opcion;
    bool valido = true;
    do{
        cout << "-----SUB-MENU------" << endl
             << "1.- Alquilar" << endl
             << "2.- Imprimir Factura"<< endl
             << "3.- Salir" << endl; 

        cout << " Ingrese una opción: ";
        cin >> opcion;

        if (opcion > 0 && opcion < 4)
            valido = true;
        else {
            cout << "La opcion seleccionada es Nula, intente de nuevo ......." << endl;
        }
        cout << "----------------------" << endl;
                
    }while(!valido);
    return opcion;
}

string RandomPlaca(){
	int random;
	stringstream random2;
	string random3;
	for(int i = 0; i < 3; i++){
		random = rand() % 27 + 1;
		if(random == 1){
			random2 << "A";
		} else if(random == 2){
            random2 << "B";
        } else if(random == 3){
        	random2 << "C";
        } else if(random == 4){
            random2 << "D";
        } else if(random == 5){
            random2 << "E";
        } else if(random == 6){
            random2 << "F";
        } else if(random == 7){
            random2 << "G";
        } else if(random == 8){
            random2 << "H";
        } else if(random == 9){
            random2 << "I";
        } else if(random == 10){
            random2 << "J";
        } else if(random == 11){
            random2 << "K";                        
        } else if(random == 12){
            random2 << "L";
        } else if(random == 13){
            random2 << "M";
        } else if(random == 15){
            random2 << "N";
        } else if(random == 16){
            random2 << "O";
        } else if(random == 17){
            random2 << "P";
        } else if(random == 18){
            random2 << "Q";
        } else if(random == 19){
            random2 << "R";
        } else if(random == 20){
            random2 << "S";
        } else if(random == 21){
            random2 << "T";
        } else if(random == 22){
            random2 << "U";
        } else if(random == 23){
            random2 << "V";
        } else if(random == 24){
            random2 << "W";
        } else if(random == 25){
            random2 << "X";
        } else if(random == 26){
            random2 << "Y";
        } else if (random == 27){
        	random2 << "Z";
        }
        random2 << "-";
        for (int i = 0; i < 4; ++i)
        {
        	random = rand() % 9 + 0;
        	random2 << random;
        }
	}
	random3 = random2.str();
	return random3;
}

vector<Administrador*> CargarAdmin(vector<Administrador*> admins){
	ifstream archivo("Administrador.txt");

	while(!archivo.eof()){
		string user, password, cargo;
		int numSeguro;
		//---------------------------->
		archivo >> user;
		archivo >> password;
		archivo >> cargo;
		archivo >> numSeguro;
		//---------------------------->
		Administrador* adds = new Administrador(cargo, numSeguro, user, password);
		admins.push_back(adds);
	}
	return admins;
}

vector<Cliente*> CargarClien(vector<Cliente*> cliens){
	ifstream archivo("Cliente.txt");

	while(!archivo.eof()){
		string user, password, membresia;
		//---------------------------->
		archivo >> user;
		archivo >> password;
		archivo >> membresia;
		//---------------------------->
		Cliente* adds = new Cliente(membresia, user, password);
		cliens.push_back(adds);
	}
	return cliens;
}

vector<Vehiculo*> CargarCarr(vector<Vehiculo*> carr){
	ifstream archivo("Vehiculo.txt");

	while(!archivo.eof()){
		string placa, marca, modelo, anio;
		double precio;
		//---------------------------->
		archivo >> placa;
		archivo >> marca;
		archivo >> modelo;
		archivo >> anio;
		archivo >> precio;
		//---------------------------->
		Vehiculo* adds = new Vehiculo(placa, marca, modelo, anio, precio);
		carr.push_back(adds);
	}
	return carr;
}