Main: Main.o Vehiculo.o Usuario.o Administrador.o Cliente.o
	g++ Main.o Vehiculo.o Usuario.o Administrador.o Cliente.o -o Main

Main.o: Vehiculo.h Administrador.h Cliente.h Main.cpp
	g++ -c Main.cpp

Vehiculo.o: Vehiculo.h Vehiculo.cpp
	g++ -c Vehiculo.cpp

Usuario.o: Usuario.h Usuario.cpp
	g++ -c Usuario.cpp

Administrador.o: Usuario.h Administrador.h Administrador.cpp
	g++ -c Administrador.cpp

Cliente.o: Usuario.h Cliente.h Cliente.cpp
	g++ -c Cliente.cpp

clean:
	rm -f *.o main
