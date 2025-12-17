#include<iostream>
#include "Persona.h"
using namespace std;

Persona::Persona(){
	id = 0;
	nombre = "";
	dni = "";
}

Persona::Persona(int i, string n, string d){
	id = i;
	nombre = n;
	dni = d;
	
}

int Persona::getId(){
	return id;
}

string Persona::getNombre(){
	return nombre;
}

void Persona::mostrarDatos(){
	cout<<"ID: "<<id<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"DNI: "<<dni<<endl;
}