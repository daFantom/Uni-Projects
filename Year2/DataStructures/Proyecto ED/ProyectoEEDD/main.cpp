#include <iostream>
#include <string.h>
#include "editorial.h"
using namespace std;

int main(){
    int op, amount;
    Cola QIniciado;
    cout << "Simulacion: Editorial"<< endl << endl;
    do{
        cout << "===== MENU =====" << endl;
        cout << "1) Generar N pedidos" << endl;
        cout << "2) Paso (una FASE)" << endl;
        cout << "3) Mostrar estado sistema" << endl;
        cout << "4) Ver caja de reparto de una moto" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: "; cin >> op;
        switch(op){
        case 0:
            cout << "Saliendo..." << endl;
            break;
        case 1:
           cout << "Cantida de pedidos a generar: ";
           cin >> amount;
           cout << "Generando "<<amount<<" pedidos..."<<endl;
           for(int i=0; i<amount;i++){
            Pedido p = genPedido();
            QIniciado.encolar(p);
           }
           Cola qaux = QIniciado;
           cout << "QIniciado:" << endl;
           cout<<"------------------------"<<endl;
           cout<<

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
        default:
            cout << "Error, opcion no reconocida, intentelo de nuevo." <<endl;
        }
    }while(op!=0);
    return 0;

}
