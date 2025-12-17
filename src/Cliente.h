#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"
#include <string>
#include <iostream>
using namespace std;

class Cliente : public Persona {
private:
    string tipo;
public:
    Cliente();
    Cliente(int , string , string , string);
    float obtenerDescuento();
    void mostrarDatos();
};

#endif