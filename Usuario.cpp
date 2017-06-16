#include "Usuario.h"

using namespace std;

Usuario :: Usuario() {
}

Usuario :: Usuario (string user, string password) {
	this -> user = user;
	this -> password = password;
}

string Usuario :: getUser(){
	return user;
}

void Usuario :: setUser(string user){
	this -> user = user;
}

string Usuario :: getPassword(){
	return password;
}

void Usuario :: setPassword(string password){
	this -> password = password;
}

Usuario :: ~Usuario() {
}