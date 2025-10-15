#include <ctime>
#include <iostream>
#include "editorial.h"
// ====================== METODOS COLA ======================

//Destructor Cola
Cola::~Cola(){
    while(frente) desencolar();
};

//A�adir elemento en la cola
void Cola::encolar(Pedido v)
{
    pNodo nuevo;
    nuevo = new Nodo(v); // Se crea un nodo nuevo
// Si cola no vac�a, se a�ade el nuevo a continuaci�n de ultimo
    if(final) final->siguiente = nuevo;
//El �ltimo elemento de la cola es el nuevo nodo
    final= nuevo;
// Si frente es NULL, la cola est� vac�a y el nuevo nodo pasa a ser el primero
    if(!frente) frente = nuevo;
}

//Leer elemento de la cola
Pedido Cola::desencolar()
{
    pNodo nodo; //Var aux para manipular nodo
    Pedido v; //Var aux para retorno del valor
// Nodo apunta al primer elemento de la pila
    nodo = frente;
    Pedido ped_vacio = {0,"","","",0,""};
    if(!nodo) return ped_vacio; // Si no hay nodos en la pila se devuelve 0
//Se asigna a frente la direcci�n del segundo nodo
    frente = nodo->siguiente;
//Se guarda el valor de retorno
    v = nodo->valor;
    delete nodo; // Se borra el nodo
// Si cola vac�a, ultimo debe ser NULL tambi�n
    if(!frente) final = NULL;
    return v;
}


// ====================== METODOS PILA ======================

//Destructor de la Pila
Pila::destrucPila()
{
    while(cima) desapilar();
}
//Meter elemento en la Pila
void Pila::apilar(Pedido v)
{
    pNodo nuevo; //Var aux para manipular el nuevo nodo
//Se crea un nodo nuevo
    nuevo = new Nodo(v, cima);
//El comienzo de la pila es el nuevo nodo
    cima = nuevo;
};

//Sacar elemento de la Pila
Pedido Pila::desapilar()
{
    pNodo nodo; //Var aux para manipular el nodo
    Pedido v; //Var aux para el retorno del valor del nodo
    Pedido ped_vacio = {0,"","","",0,""};
    if(!cima) return ped_vacio; // Si no hay nodos en la pila se devuelve un alumno vacio
// Nodo apunta al primer elemento de la pila
    nodo = cima;
//Se asigna a pila toda la pila menos el primer elemento
    cima= nodo->siguiente;
//Se guarda el retorno del valor del nodo
    v = nodo->valor;
//Se borra el nodo
    delete nodo;
    return v;
}

// GENERAR PEDIDOS ALEATORIOS.
Pedido genPedido(void){
    srand(time(NULL));
    int amount = rand()%20 + 1;
    char abecedario[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; // Todo el abecedario para elegir una letra de forma aleatoria.
    int numaleat1,numaleat2;
    char letraAleat;
    letraAleat = abecedario[rand()%(sizeof(abecedario)/sizeof(abecedario[0]))]; // Se recoge una letra del Array 'abecedario' de manera randomizada.
    numaleat1=rand()%999; // Se coge un numero de entre 0 y 998 de forma aleatoria.
    numaleat2=rand()%99; // Se coge un numero de entre 0 y 98 de forma aleatoria.
    string materias[6] ={"Matematicas","Fisica","Tecnologia","Musica","Historia", "Lengua"};
    string id_pedido = "P"+to_string(rand()%99999); // el rand() representa la parte numerica del codigo.
    string cod_libro = to_string(numaleat1)+letraAleat+to_string(numaleat2);
    string materia = materias[rand()%(sizeof(materias)/sizeof(materias[0]))]; // Dividimos la longitud del array (en bytes) con la longitud del primer elemenento para que nos devuelva la cantidad de elementos del array.
    int amount;
    Pedido p = {rand()%6,id_pedido,cod_libro,materia,amount,"Iniciado"}; // Cuando se crea un pedido, siempre empieza en iniciado :D
    return p;
}

//FUNCION PARA SABER SI COLA VACIA
bool esVacia(Cola c){
    if (c.frente == NULL){
        return true;
    }
    else{
         return false;
    }

}
//FUNCION PARA PINTAR PEDIDOS INICIALIZADOS
void pintarPedidosIni(Cola cola){

}


