#ifndef VENTA_H
#define VENTA_H
#include<iostream>
#include<fstream>
#include "Cliente.h"
#include "Producto.h"

using namespace std;

class Venta{
	private:
		int idVenta;
		Cliente *cliente;
		Producto *productos[10];
		int cantidades[10];
		int nProductos;
	public:
		Venta();
		void setVenta(int, Cliente*);
		void agregarProducto(Producto*, int);
		void guardarReporte();	
};

#endif