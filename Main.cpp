#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>

#include "Administrador.h"
#include "Cliente.h"
#include "Vehiculo.h"

int menu();
int menu2();
int menu3();
string RandomPlaca();

int main(){
	string user, password;
	vector<Vehiculo*> carro;
	vector<Administrador*> admin;
	vector<Cliente*> clien;
	ofstream textAdm, textCli, textCar;
	textAdm.open("Administrador.txt", ios::app);
	textCli.open("Cliente.txt", ios::app);
	textCar.open("Vehiculo.txt", ios::app);
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
				        	textAdm << "User: " << user << "Password: " << password << "Cargo: " << cargo << "#Seguro" << numSeguro << endl; 
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

				        	clien.push_back(new Cliente(user, password, membre));
				        	textCli << "User: " << user << "Password: " << password << "Tipo de Membresia: " << membre << endl;
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
	            		if (dynamic_cast<Administrador*>(admin.at(i)))
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
							        	textCar << "Placa: " << placa << "Marca: " << marca << "Modelo: " << modelo << "Año: " << anio << "Precio Renta: " << precio << endl;
							        	cout << "Se ha Guardado" << endl;
						               	break;}

							       	case 2:{
							            cout << "Modificar Vehiculo" << endl;

							           	break;}

						           	case 3:{
						           		int numbers =  0;
								       	cout << "Ingrese la posicion que quiere eliminar: " << endl;
										for(int i = 0; i < carro.size(); i++){
											cout << "Placa: " << carro[i] -> getPlaca() << endl;
											cout << "Marca: " << carro[i] -> getMarca() << endl;
											cout << "Modelo: " << carro[i] -> getModelo() << endl;
											cout << "Año: " << carro[i] -> getAnio() << endl;
											cout << "Precio Renta: " << carro[i] -> getPrecio() << endl;
										}
										cin >> numbers;
										carro.erase(carro.begin() + numbers);
										cout << "Obra ha eliminada" << endl;
						           		break;}

						           	case 4:{
						           		cout << "Lista de Carros" << endl
						           		for(int i = 0; i < carro.size(); i++){
											cout << "Placa: " << carro[i] -> getPlaca() << endl;
											cout << "Marca: " << carro[i] -> getMarca() << endl;
											cout << "Modelo: " << carro[i] -> getModelo() << endl;
											cout << "Año: " << carro[i] -> getAnio() << endl;
											cout << "Precio Renta: " << carro[i] -> getPrecio() << endl;
										}
						           		break;}

							       	case 5:
							           	salir3 = true;
							           	break;
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