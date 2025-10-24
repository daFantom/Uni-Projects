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
    Pedido paux; // Variable de Pedido auxiliar para las pruebas en la opcion 2.
    pedido_stock stock[MAX_TITULOS] = {}; // Inicializacion del STOCK, un array vacio que tendra una precarga de pedidos.
    for  ( int i = 0; i < MAX_TITULOS; i++){
        pedido_stock pstock = genStock(); // Precarga de los MAX_TITULOS pedidos. (En este caso MAX_TITULOS = 10)
        stock[i] = pstock; // Se pone en la posicion i (0, 1, 2, ..., 9) un struct de tipo pedido_stock
    }
        // mostrar stock [COMPROBACIONES CON LAS COLAS Y TAL, SE PUEDE QUITAR SI ESTAMOS SEGUROS (no lo estoy -manus)]
    for(int i=0;i<MAX_TITULOS;i++){
        cout << stock[i].codigo_libro<<"|"<< stock[i].materia<<"|"<< stock[i].unidades<< endl;
    }
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
                    int premio = rand()%10;              // Se utiliza un valor del 0 al 9 por cada iteracion del bucle para elegir un elemento del stock y crear un pedido con sus datos. Me gustaria que sonase lo del PREMIOOO  de las ferias pero uno no puede conseguir todo lo que quiere :(
                    Pedido ped_aux = genPedido(stock[premio].codigo_libro, stock[premio].materia);   // Se genera un pedido utilizando los datos de un pedido precargado stock y se encola en la cola QIniciados.
                    QIniciado.encolar(ped_aux);
                }
                cout<< "QIniciados:"<<endl;        // Luego, mostramos lo que tiene dentro una vez generado los pedidos.
                printQueue(QIniciado);
                break;
            case 2:
                cout << "Funciona"<<endl;
                /* vvvvvvv AQUI IRIA TODO LO DEL ESQUEMITA ESTE DE LOS HUEVOS DEL QUE ME PASE LA ULTIMA CLASE HACIENDO WAAAAAAAA vvvvvvv
                    24/10/25 19:48 Manu > El primer paso de QIniciado a QAlmacen funciona, lo malo es que si se utiliza un "if" en la parte del almacen, se ejecuta despues y es como si hiciese varios pasos, en cambio, si se utiliza "else if" solo se ejecuta
                    si QIniciada esta vacia. Propuesta de solucion --> Hacerlo todo en un procedimiento que se basa en paux.estado y llamarlo 5 veces, por ejemplo, si el nombre del procedimiento es pasoColas(Cola &c) seria:
                            pasoColas(QIniciado)
                            pasoColas(QAlmacen)
                            pasoColas(QImprenta)
                            pasoColas(QListo)
                    de tal manera que se ejecuta uno una vez de forma independiente y no habria que basarse en los condicionales aqui en el main, sino en el procedimiento. [buah me encanta cuando se me ocurren cosas mientras escribo pero no cuando pienso que huevos tengo]
                */
                if (!QIniciado.esVacia()){ // Comprueba si esta vacia incialmente.
                    for(int i = 0; i < N_PEDIDOS_PASO; i++){
                        if(QIniciado.esVacia()){
                            break; // Si la lista QIniciados esta vacia, se pasa a ver la siguiente cola [?]
                        }
                        else{
                            paux = QIniciado.desencolar(); // Si no esta vacia, desencolamos, cambiamos el estado del pedido a "Almacen" y lo encolamos en QAlmacen.
                            paux.estado = "Almacen";
                            QAlmacen.encolar(paux);
                        }
                    }
                }
                if(!QAlmacen.esVacia()){
                    for(int i=0; i< N_PEDIDOS_PASO; i++){
                        if(QAlmacen.esVacia()){
                            break;
                        }
                        else{
                            paux = QAlmacen.desencolar();
                            pedido_stock aux = findInStock(paux, stock);
                            if( (aux.codigo_libro != " ") && (paux.cantidad > aux.unidades) ){
                                    aux.unidades-=paux.cantidad;
                                    paux.estado = "Listo";
                                    QListo.encolar(paux);
                            }
                            else{
                                aux.unidades+=TAM_LOTE;
                                paux.estado = "Imprenta";
                                QImprenta.encolar(paux);
                            }
                        }
                    }
                }
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
