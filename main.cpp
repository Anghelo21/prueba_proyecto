#include <iostream>
using namespace std;

int main() {
	int op;
	do{
		cout<<"----------Minimarket-*---------"<<endl;
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
				//agregarCliente();
				break;
			case 2:
				//agregarProducto();
				break;
			case 3:
				//listarClientes();
				break;
			case 4:
				//listarProductos();
				break;
			case 5:
				//registrarVenta();
				break;
			case 6:
				//ordenarProductos();
				break;
			case 7:
				//buscarProducto();
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