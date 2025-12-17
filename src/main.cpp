#include <iostream>
#include <fstream>
#include "Cliente.h"
#include "Producto.h"
#include "Venta.h"
using namespace std;
Cliente clientes[20];
Producto productos[10];
Venta ventas[10];
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

void agregarCliente(){
    if(nClientes < 20){
        int id;
        string nombre, dni, tipo;
        cout<<"ID: "; cin>>id; cin.ignore();
        cout<<"Nombre: "; getline(cin, nombre);
        cout<<"DNI: "; getline(cin, dni);
        cout<<"Tipo (normal/frecuente): "; getline(cin, tipo);
        clientes[nClientes] = Cliente(id, nombre, dni, tipo);
        if(clientes[nClientes].getId() != 0) {
            nClientes++;
            cout<<"Cliente agregado"<<endl;
        }else{
            cout<<"Datos invalidos"<<endl;
        }
    }
}

void agregarProducto() {
    if(nProductos < 10){
        int id, stock;
        float precio;
        string nombre;
        cout<<"ID: "; cin>>id; cin.ignore();
        cout<<"Nombre: "; getline(cin, nombre);
        cout<<"Stock: "; cin>>stock;
        cout<<"Precio: "; cin>>precio;
        productos[nProductos] = Producto(id, nombre, stock, precio);
        if(productos[nProductos].getId() != 0){
            nProductos++;
            cout<<"Producto agregado"<<endl;
        }
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
    if (nVentas < 10 && nClientes > 0 && nProductos > 0){
        int idVenta, idCliente;
        cout<<"ID Venta: "; cin>>idVenta;
        cout<<"ID Cliente: "; cin>>idCliente;
        int idxCliente = -1;
        int i = 0;
        while(i < nClientes){
            if(clientes[i].getId() == idCliente){
            	idxCliente = i;
			}
            i++;
        }
        if(idxCliente != -1){
            ventas[nVentas].setVenta(idVenta, &clientes[idxCliente]);
            int num;
            cout<<"Cantidad de productos: ";
            cin>>num;
            int j = 0;
            while(j < num){
                int idProd, cant;
                cout<<"ID Producto: "; cin>>idProd;
                cout<<"Cantidad: "; cin>>cant;
                int idxProd = buscarProductoPorID(idProd);
                if(idxProd != -1){
                    if(productos[idxProd].vender(cant)){
                    	ventas[nVentas].agregarProducto(&productos[idxProd], cant);
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