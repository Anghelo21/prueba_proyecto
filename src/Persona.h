#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <iostream>
using namespace std;

class Persona {
protected:
    int id;
    string nombre;
    string dni;
public:
    Persona();
    Persona(int , string , string );
    int getId();
    string getNombre();
    virtual void mostrarDatos();
};

#endif