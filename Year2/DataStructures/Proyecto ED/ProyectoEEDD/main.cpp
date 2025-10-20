#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "editorial.h"

using namespace std;

int main(){
    /*ATENCION: NO TOQUES EL CODIGO, NO LO ENTENDEMOS, PERO FUNCIONA.
        SI LO ENTIENDES, NO FUNCIONA
        SI NO LO ENTIENDES, FUNCIONA
        ASIQUE MEJOR DEJARLO TAL Y COMO ESTA
            besos,
            manu
    */
    srand(time(NULL));
    int opcion, amount,numLib;
    Cola QIniciado, QAlmacen, QImprenta, QListo;
    Pila c0,c1,c2,c3,c4,c5;
    Cola caux = QIniciado;//variable del case 2
    Pedido paux;//variable del case 2
    pedido_stock stock[MAX_TITULOS] = {}; // Inicializacion del STOCK (no sirve para nada por ahora)
    cout << "Simulacion: Editorial"<< endl << endl;             // Menu inicial del usuario.
    do{
        cout << "===== MENU =====" << endl;
        cout << "1) Generar N pedidos" << endl;
        cout << "2) Paso (una FASE)" << endl;
        cout << "3) Mostrar estado sistema" << endl;
        cout << "4) Ver contenido de una caja" << endl;
        cout << "0) Salir del programa" << endl;
        cout << "Opcion: "; cin >> opcion;
        cout << endl;
        switch(opcion){
            case 0:
                cout << "Saliendo..." << endl;                                  // Si el usuario inserta la opcion '0', el programa DEBERIA cerrarse. De ahi que tenga un 'return 0;' donde el switch por si acaso...
                return 0;
                break;
            case 1:
               cout << "Cantidad de pedidos a generar: ";
               cin >> amount;
               cout << endl;
               cout << "Generando "<<amount<<" pedidos..."<<endl;
               cout << endl;
               for(int i=0; i<amount; i++)                                      // Creamos amount pedidos de forma pseudoaleatoria y los vamos encolando en la cola QIniciado.
                {
                    Pedido paux = genPedido();
                    QIniciado.encolar(paux);
                    c0.apilar(paux);                                                    // Prueba para ver si funcionan las funciones que imprimen las pilas, en caso de no usarlo, comentarlo con CTRL+SHIFT+C tras haberlo elegido con el raton.
                }
                cout<< "QIniciados:"<<endl;                                 // Luego, mostramos lo que tiene dentro una vez generado los pedidos.
                printQueue(QIniciado);
                break;
            case 2:
                cout << "Funciona"<<endl;                                   // Funciona, ya esta, no tiene nada mas XD.
                //Funcion de prueba a ver si funciona el metodo de la pt opcion 2
                while(!caux.esVacia()){//Lo que se pretende es comprobar si funciona el cambio de estado imprimiendo la cola de almacen que es el siguiente paso
                    paux = caux.desencolar();
                    cambiarEstado(paux,QAlmacen,c0);
                }
                printQueue(QAlmacen);
                break;
            case 3:
                //////////////////////////////////////////////// Se muestra la cola QIniciados
                cout<< "QIniciados:"<<endl;
                printQueue(QIniciado);
                //////////////////////////////////////////////// Se muestra la cola QAlmacen
                cout << "QAlmacen:"<<endl;
                printQueue(QAlmacen);
                //////////////////////////////////////////////// Se muestra la cola QImprenta
                cout << "QImprenta:"<<endl;
                printQueue(QImprenta);
                //////////////////////////////////////////////// Se muestra la cola QListo
                cout << "QListo:"<<endl;
                printQueue(QListo);
                //////////////////////////////////////////////// Fin mostrar colas.
                cout<<"=== CAJAS ===" << endl;
                cout << "Libreria 0 --> "<< "tam = " <<c0.getLength() <<", codigo cima --> " << c0.getTopCode() << endl;
                cout << "Libreria 1 --> "<< "tam = " <<c1.getLength() <<", codigo cima --> " << c1.getTopCode() << endl;
                cout << "Libreria 2 --> "<< "tam = " <<c2.getLength() <<", codigo cima --> " << c2.getTopCode() << endl;
                cout << "Libreria 3 --> "<< "tam = " <<c3.getLength() <<", codigo cima --> " << c3.getTopCode() << endl;
                cout << "Libreria 4 --> "<< "tam = " <<c4.getLength() <<", codigo cima --> " << c4.getTopCode() << endl;
                cout << "Libreria 5 --> "<< "tam = " <<c5.getLength() <<", codigo cima --> " << c5.getTopCode() << endl;
                cout<< endl;
;                break;
            case 4:
                cout<<"Indique el numero de libreria: ";               // Esto es para ver los contenidos de una caja de una libreria. No implementado aun jiji. (Probar otro switch-case en main y en una funcion)
                cin >> numLib;
                cout << endl;
                switch(numLib){
                    case 0:
                        printPile(c0,numLib);
                        break;
                    case 1:
                        printPile(c1,numLib);
                        break;
                    case 2:
                        printPile(c2,numLib);
                        break;
                    case 3:
                        printPile(c3,numLib);
                        break;
                    case 4:
                        printPile(c4,numLib);
                        break;
                    case 5:
                        printPile(c5,numLib);
                        break;
                    }
        }
    }while(opcion!=0);
    return 0;
}
