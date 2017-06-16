#include <string>

using namespace std;

#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
	private:
		string user;
		string password;

	public:
		Usuario();
		Usuario(string, string);

		string getUser();
		void setUser(string);

		string getPassword();
		void setPassword(string);

		virtual ~Usuario();
};
#endif