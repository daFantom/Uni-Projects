#include <iostream>

void menuPizza(void){

    std::cout << "Simulacion: pedidos a una pizzeria." <<
        std::endl <<
        "=== MENU ===\n" <<
        "1) Generar N pedidos\n" <<
        "2) Paso (una FASE)\n" <<
        "3) Mostrar estado sistema\n" <<
        "4) Ver caja de reparto de una moto\n" <<
        "0) Salir\n" <<
        std::endl <<
        "Opcion: ";

}

int main(){
    int op;
    int q;
    do{
        menuPizza();
        std::cin >> op;
        switch(op){
        case 0:
            std::cout << "Apaganado programa..." << std::endl;
            return 0;
        case 1:
            std::cout << "Introduzca una cantidad: ";
            std::cin >> q;
            std::cout << "Se han generado " << q << " pedidos!" << std::endl;
            break;

        case 2:
            std::cout << "Se ha ejecutado la fase." << std::endl;
            break;

        case 3:
            std::cout << "Estado del sistema: repiola" << std::endl;
            break;

        case 4:
            std::cout << "Aqui se mostrarian los contenidos de una\n"
                "caja de reparto, pero estamos pobres :(" << std::endl;
                break;

        default:
            std::cout << "Error: No se encuentra la opcion, por favor introduzca de nuevo." << std::endl;

        }
    }while(op!=0);

    return 0;
}
