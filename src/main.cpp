#include <iostream>
#include <fstream>
#include "Cliente.h"
#include "Producto.h"
#include "Venta.h"
using namespace std;
Cliente clientes[50];
Producto productos[50];
Venta ventas[50];
int nClientes = 0;
int nProductos = 0;
int nVentas = 0;

int buscarProductoPorID(int id){
    int i = 0;
    while(i < nProductos){
        if(productos[i].getId() == id)
            return i;
        i++;
    }
    return -1;
}

int buscarClientePorID(int id) {
    int i = 0;
    while (i < nClientes) {
        if (clientes[i].getId() == id)
            return i;
        i++;
    }
    return -1;
}

void ordenarProductos(){
    int i = 0;
    while(i < nProductos - 1){
        int j = 0;
        while(j < nProductos - i - 1){
            if(productos[j].getPrecio() > productos[j + 1].getPrecio()){
                Producto aux = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = aux;
            }
            j++;
        }
        i++;
    }
    cout<<"Productos ordenados por precio"<<endl;
}

void agregarProducto(){
    if(nProductos<50){
        int id, stk;
        float p;
        string n;
        cout<<"ID: ";
        cin>>id;
        cin.ignore();
        if(buscarProductoPorID(id) != -1){
            cout<<"ERROR: ID de producto ya registrado"<<endl;
        }else{
            cout<<"Nombre del producto: ";
            getline(cin, n);
            cout<<"Stock: ";
            cin>>stk;
            cout<<"Precio: ";
            cin>>p;
            productos[nProductos] = Producto(id, n, stk, p);
            if(productos[nProductos].getId() != 0){
                nProductos++;
                cout<<"Producto registrado correctamente"<<endl;
            }else{
                cout<<"Datos inválidos"<<endl;
            }
        }
    }else{
        cout<<"Límite de productos alcanzado"<<endl;
    }
}

void agregarCliente(){
    if(nClientes < 50){
        int id;
        string n, dni, t;
        cout<<"ID: ";
        cin>>id;
        cin.ignore();
        if(buscarClientePorID(id) != -1){
            cout<<"ERROR: ID de cliente ya registrado"<<endl;
        }else{
            cout<<"Nombre: ";
            getline(cin, n);
            cout<<"DNI: ";
            getline(cin, dni);
            cout<<"Tipo (normal/frecuente): ";
            getline(cin, t);
            clientes[nClientes] = Cliente(id, n, dni, t);
            if(clientes[nClientes].getId() != 0){
                nClientes++;
                cout<<"Cliente registrado correctamente"<<endl;
            }else{
                cout<<"Datos inválidos"<<endl;
            }
        }
    }else{
        cout<<"Límite de clientes alcanzado"<<endl;
    }
}

void listarClientes(){
    int i = 0;
    while(i < nClientes){
        clientes[i].mostrarDatos();
        cout<<"----------------"<<endl;
        i++;
    }
}

void listarProductos(){
    int i = 0;
    while(i < nProductos){
        productos[i].mostrarProducto();
        i++;
    }
}

void buscarProducto(){
    int id;
    cout<<"Ingrese ID del producto: ";
    cin>>id;
    int idx = buscarProductoPorID(id);
    if(idx == -1){
        cout<<"Producto no encontrado"<<endl;
    }else{
        productos[idx].mostrarProducto();
    }
}

void registrarVenta(){
    if (nVentas < 50 && nClientes > 0 && nProductos > 0){
        int idV, idC;
        cout<<"ID Venta: "; cin>>idV;
        cout<<"ID Cliente: "; cin>>idC;
        int idxC = -1;
        int i = 0;
        while(i < nClientes){
            if(clientes[i].getId() == idC){
            	idxC = i;
			}
            i++;
        }
        if(idxC != -1){
            ventas[nVentas].setVenta(idV, &clientes[idxC]);
            int num;
            cout<<"Cantidad de productos: ";
            cin>>num;
            int j = 0;
            while(j < num){
                int idP, cant;
                cout<<"ID Producto: "; cin>>idP;
                cout<<"Cantidad: "; cin>>cant;
                int idxP = buscarProductoPorID(idP);
                if(idxP != -1){
                    if(productos[idxP].vender(cant)){
                    	ventas[nVentas].agregarProducto(&productos[idxP], cant);
					}
                }
                j++;
            }
            ventas[nVentas].guardarReporte();
            nVentas++;
            cout<<"Venta registrada"<<endl;
        }
    }
}

int main() {
	int op;
	do{
		cout<<"----------Minimarket----------"<<endl;
		cout<<"1. Agregar cliente"<<endl;
		cout<<"2. Agregar producto"<<endl;
		cout<<"3. Listar clientes"<<endl;
		cout<<"4. Listar productos"<<endl;
		cout<<"5. Registrar venta"<<endl;
		cout<<"6. Ordenar productos por precio"<<endl;
		cout<<"7. Buscar producto"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<"Elija una opcion"<<endl;
		cin>>op;
		cin.ignore();
		switch(op){
			case 1:
				agregarCliente();
				break;
			case 2:
				agregarProducto();
				break;
			case 3:
				listarClientes();
				break;
			case 4:
				listarProductos();
				break;
			case 5:
				registrarVenta();
				break;
			case 6:
				ordenarProductos();
				break;
			case 7:
				buscarProducto();
				break;
			case 0:
				cout<<"Saliendo..."<<endl;
				break;
			default:
				cout<<"Opcion invalida"<<endl;
		}
	}while(op!=0);
	return 0;
}