#include <iostream>
#include <string.h>
#include "editorial.h"
#include <iomanip>
using namespace std;

int main(){
    int op, amount;
    Cola QIniciado, QAlmacen, QImprenta, QListo;
    Pila cajas;
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
            cout<< "QIniciados:"<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<setw(4)<<"Lib"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
            cout<<"-------------------------------------------"<<endl;
            while (!esVacia(qaux)){
                Pedido p = qaux.desencolar();
                cout<<setw(4)<<p.id_editorial<<"|"<<setw(8)<<p.cod_libro<<"|"<<setw(12)<<p.materia<<"|"<<setw(4)<<p.cantidad<<"|"<<setw(10)<<p.estado<<"|"<<endl;
            }
            break;
        case 2:
            cout << "Funciona"<<endl;
            break;
        case 3:
            Cola qaux;
            qaux = QIniciado;
            cout<< "QIniciados:"<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<setw(4)<<"Lib"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
            cout<<"-------------------------------------------"<<endl;
            while (!esVacia(qaux)){
                Pedido p = qaux.desencolar();
                cout<<setw(4)<<p.id_editorial<<"|"<<setw(8)<<p.cod_libro<<"|"<<setw(12)<<p.materia<<"|"<<setw(4)<<p.cantidad<<"|"<<setw(10)<<p.estado<<"|"<<endl;
            }
            qaux = QAlmacen;;
            cout << "QAlmacen:"<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<setw(4)<<"Lib"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
            cout<<"-------------------------------------------"<<endl;
            while (!esVacia(qaux)){
                Pedido p = qaux.desencolar();
                cout<<setw(4)<<p.id_editorial<<"|"<<setw(8)<<p.cod_libro<<"|"<<setw(12)<<p.materia<<"|"<<setw(4)<<p.cantidad<<"|"<<setw(10)<<p.estado<<"|"<<endl;
            }
            qaux = QImprenta;
            cout << "QImprenta:"<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<setw(4)<<"Lib"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
            cout<<"-------------------------------------------"<<endl;
            while (!esVacia(qaux)){
                Pedido p = qaux.desencolar();
                cout<<setw(4)<<p.id_editorial<<"|"<<setw(8)<<p.cod_libro<<"|"<<setw(12)<<p.materia<<"|"<<setw(4)<<p.cantidad<<"|"<<setw(10)<<p.estado<<"|"<<endl;
            }
            qaux = QListo;
            cout << "QListo:"<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<setw(4)<<"Lib"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
            cout<<"-------------------------------------------"<<endl;
            while (!esVacia(qaux)){
                Pedido p = qaux.desencolar();
                cout<<setw(4)<<p.id_editorial<<"|"<<setw(8)<<p.cod_libro<<"|"<<setw(12)<<p.materia<<"|"<<setw(4)<<p.cantidad<<"|"<<setw(10)<<p.estado<<"|"<<endl;
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
