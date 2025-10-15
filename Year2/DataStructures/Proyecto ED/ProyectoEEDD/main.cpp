#include <iostream>
#include <string.h>
#include "editorial.h"
#include <iomanip>
using namespace std;

int main(){
    int op, amount;
    Cola QIniciado;
    int numLib;
    cout << "Simulacion: Editorial"<< endl << endl;
    do{
        cout << "===== MENU =====" << endl;
        cout << "1) Generar N pedidos" << endl;
        cout << "2) Paso (una FASE)" << endl;
        cout << "3) Mostrar estado sistema" << endl;
        cout << "4) Paso completo" << endl;
        cout << "5) Ver contenido de una caja" << endl;
        cout << "Opcion: "; cin >> op;
        switch(op){
        case 0:
            cout << "Saliendo..." << endl;
            break;
        case 1:
           cout << "Cantidad de pedidos a generar: ";
           cin >> amount;
           cout << "Generando "<<amount<<" pedidos..."<<endl;
           for(int i=0; i<amount; i++)
            {
                Pedido p = genPedido();
                QIniciado.encolar(p);
            }
            Cola qaux = QIniciado;
           cout << "QIniciado:" << endl;
           cout<<"---------------------------------------------------"<<endl;
           cout<< left<< setw(10)<< "Lib"<<setw(10)<< "Id"<<setw(10)<< "Codigo"<<setw(10)<< "Materia"<<setw(10)<< "U"<<setw(10)<< "Estado"<<endl;
           cout<<"---------------------------------------------------"<<endl;
            while(!esVacia(qaux))
            {
                Pedido p = QIniciado.desencolar();
                cout<< p.id_editorial<<"|"<<setw(10)<<p.id_pedido<<"|"<<setw(10)<<p.cod_libro<<"|"<<setw(10)<<p.materia<<"|"<<setw(10)<<p.cantidad<<"|"<<setw(10)<<p.estado<<"|"<<setw(10)<<endl;

            }

            break;
        case 2:
            cout << "Funciona" << endl;
            break;
        case 3:
            while (!esVacia(QIniciado)){
                Pedido aux = QIniciado.desencolar();
                cout << "Desencolando: " <<aux.id_pedido<< endl;
            }
            break;
        case 4:

            cout << "Funciona" << endl;
            break;
        case 5:
            cout<<"Indique el numero de libreria: "<<endl;
            cin >> numLib;



        default:
            cout << "Error, opcion no reconocida, intentelo de nuevo." <<endl;
        }
    }while(op!=0);
    return 0;

}
