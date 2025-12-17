#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <iostream>
using namespace std;

class Producto {
private:
    int id;
    string nombre;
    int stock;
    float precio;
public:
    Producto();
    Producto(int i, string n, int s, float p);
    int getId();
    string getNombre();
    int getStock();
    float getPrecio();
    bool vender(int);
    void mostrarProducto();
};

#endif