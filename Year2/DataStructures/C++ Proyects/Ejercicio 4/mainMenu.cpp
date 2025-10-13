#include <iostream>

void menuPizza(void){
    int op;
    do{
        std::cout << "Simulacion: pedidos a una pizzeria." << std::endl;
        std::cin >> op;
        std::cout << "=== MENU ===" << std::endl;
        std::cout << "1) Generar N pedidos" << std::endl;
        std::cout << "2) Paso (una FASE)" << std::endl;
        std::cout << "3) Mostrar estado sistema" << std::endl;
        std::cout << "4) Ver caja de reparto de una moto" << std::endl;
        std::cout << "0) Salir" << std::endl;
        std::cout << "Opcion: "; std::cin >> op;
        switch(op){
        case 1:
            std::cout << "Funciona" << std::endl;
            break;
        case 2:
            std::cout << "Funciona" << std::endl;
            break;
        case 3:
            std::cout << "Funciona" << std::endl;
            break;
        case 4:
            std::cout << "Funciona" << std::endl;
            break;
        default:
            menuPizza();
        }
    }while(op!=0);
}

int main()
{
    return 0;
}
