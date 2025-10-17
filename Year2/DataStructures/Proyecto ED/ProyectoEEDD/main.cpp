#include <iostream>
#include <string.h>
#include <iomanip>
#include <ctime>
#include "editorial.h"

using namespace std;

int main(){
    srand(time(NULL));
    int op, amount;
    Cola QIniciado, QAlmacen, QImprenta, QListo;
    Pila c0,c1,c2,c3,c4,c5;
    int numLib;
    cout << "Simulacion: Editorial"<< endl << endl;             // Menu inicial del usuario.
    do{
        cout << "===== MENU =====" << endl;
        cout << "1) Generar N pedidos" << endl;
        cout << "2) Paso (una FASE)" << endl;
        cout << "3) Mostrar estado sistema" << endl;
        cout << "4) Ver contenido de una caja" << endl;
        cout << "0) Salir del programa" << endl;
        cout << "Opcion: "; cin >> op;
        switch(op){
        case 0:
            cout << "Saliendo..." << endl;                                  // Si el usuario inserta la opcion '0', el programa DEBERIA cerrarse. De ahi que tenga un 'return 0;' donde el switch por si acaso...
            return 0;
            break;
        case 1:
           cout << "Cantidad de pedidos a generar: ";
           cin >> amount;
           cout << "Generando "<<amount<<" pedidos..."<<endl;
           for(int i=0; i<amount; i++)                                      // Creamos amount pedidos de forma pseudoaleatoria y los vamos encolando en la cola QIniciado.
            {
                Pedido paux = genPedido();
                QIniciado.encolar(paux);
            }
            cout<< "QIniciados:"<<endl;                                 // Luego, mostramos lo que tiene dentro una vez generado los pedidos.
            cout<<"-----------------------------------------------------"<<endl;
            cout<<setw(4)<<"Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            printQueue(QIniciado);
            break;
        case 2:
            cout << "Funciona"<<endl;                                   // Funciona, ya esta, no tiene nada mas XD.
            break;
        case 3:
            //////////////////////////////////////////////// Se muestra la cola QIniciados
            cout<< "QIniciados:"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<setw(4)<<"Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            printQueue(QIniciado);
            //////////////////////////////////////////////// Se muestra la cola QAlmacen
            cout << "QAlmacen:"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<setw(4)<<"Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            printQueue(QAlmacen);
            //////////////////////////////////////////////// Se muestra la cola QImprenta
            cout << "QImprenta:"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<setw(4)<<"Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            printQueue(QImprenta);
            //////////////////////////////////////////////// Se muestra la cola QListo
            cout << "QListo:"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<setw(4)<<"Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            printQueue(QListo);
            //////////////////////////////////////////////// Fin mostrar colas.
            break;
        case 4:
            cout<<"Indique el numero de libreria: ";               // Esto es para ver los contenidos de una caja de una libreria. No implementado aun jiji. (Probar otro switch-case en main y en una funcion)
            try{
                cin >> numLib;
                cout << numLib;
            }
            catch(int numLib){
                cout << "Error, libreria no encontrada." << endl;           // En caso de que el usuario ponga una letra, daria error y volveria.... creo.... no se, a mi me entra en un maldito loop infinito sdgjkhfkgjahsdf T_T
            }
            break;
        default:
            cout << "Error, opcion no reconocida, intentelo de nuevo: " << endl;  // Si el usuario inserta un numero que no forme parte del switch, le manda un mensaje y lo vuelve a ejecutar. ADVERTENCIA: NO PROBAR CON LETRAS, NO QUIERES SABER LO QUE PASA ToT
            cout << endl;
        }
    }while(op!=0);
    return 0;
}
