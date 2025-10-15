#include <iostream>

using namespace std;

int main(){
    int op, amount;
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
           cout << amount << endl;
            break;
        case 2:
            cout << "Funciona" << endl;
            break;
        case 3:
            cout << "Funciona" << endl;
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
