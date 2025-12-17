#include<iostream>
#include "Producto.h"
using namespace std;

Producto::Producto(){
	id = 0;
	nombre = " ";
	stock = 0;
	precio = 0.0;
}

Producto::Producto(int i, string n, int s, float p){
	id = i;
	nombre = n;
	stock = s;
	precio = p;
}

int Producto::getId(){
	return id;
}

string Producto::getNombre(){
	return nombre;
}

int Producto::getStock(){
	return stock;
}

float Producto::getPrecio(){
	return precio;
}

bool Producto::vender(int c){
	if(c<=stock){
		stock -= c;
		return true;
	}else{
		return false;
	}
}

void Producto::mostrarProducto(){
	cout<<" ID: "<<id<<" Nombre: "<<nombre<<" Stock: "<<stock<<" Precio: "<<precio<<endl;
	if(stock>0&&stock<=5){
		cout<<"ADVERTENCIA: STOCK CRITICO"<<endl;
	}
	cout<<"------------------"<<endl;
}