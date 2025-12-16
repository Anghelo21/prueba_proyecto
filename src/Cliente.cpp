#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(){
	tipo = " ";
}

Cliente::Cliente(int i, string n, string d, string t):Persona(i, n, d){
	tipo = t;
}

string Cliente::getTipoCliente(){
	return tipo;
}

float Cliente::obtenerDescuento(){
	if(tipo=="F"){
		return 0.2;
	}else{
		return 0.0;
	}
}

void Cliente::mostrarCliente(){
	Persona::mostrarPersona();
	cout<<"Tipo de cliente: "<<tipo<<endl;
}