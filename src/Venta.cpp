#include "Venta.h"
using namespace std;
Venta::Venta(){
	idVenta = 0;
	cliente = NULL;
	nProductos = 0;
}

void Venta::setVenta(int idV, Cliente* c){
	if(idV>0&&c!=NULL){
		idVenta = idV;
		cliente = c;	
	}
}

void Venta::agregarProducto(Producto* p, int cant){
	if(nProductos<50&&cant>0&&p!=NULL){
		productos[nProductos] = p;
		cantidades[nProductos] = cant;
		nProductos++;
	}
}

void Venta::guardarReporte(){
	if (cliente!=NULL&&nProductos>0) {
        ofstream archivo("reporte_ventas.txt", ios::app);
        if (archivo.is_open()) {
            archivo<<"Venta ID: "<<idVenta<<endl;
            archivo<<"Cliente: "<<cliente->getNombre()<<endl;
            float total = 0;
            int i = 0;
            while (i<nProductos) {
                float sub = productos[i]->getPrecio() * cantidades[i];
                archivo <<productos[i]->getNombre()
                    	<<" x "<< cantidades[i]
                        <<" = "<<sub<<endl;
                total+=sub;
                i++;
            }
            total -= total * cliente->obtenerDescuento();
            archivo<<"TOTAL: "<<total<<endl;
            archivo<<"------------------------"<<endl;
            archivo.close();
        }
    }
}
