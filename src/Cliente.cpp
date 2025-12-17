#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(){
	tipo = "N";
}

Cliente::Cliente(int i, string n, string d, string t):Persona(i, n, d){
	if(t=="F"||t=="f"){
		tipo = "F";
	}else{
		tipo = "N";
	}
}

float Cliente::obtenerDescuento(){
	if(tipo=="F"){
		return 0.2;
	}else{
		return 0.0;
	}
}

void Cliente::mostrarDatos(){
	Persona::mostrarDatos();
	cout<<"Tipo de cliente: "<<tipo<<endl;
}