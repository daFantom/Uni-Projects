#include <ctime>
#include <iostream>
#include <iomanip>
#include "editorial.h"

// ====================== METODOS COLA ======================

//Destructor Cola
Cola::~Cola(){
    while(frente) desencolar();
};

//Agregar elemento en la cola
void Cola::encolar(Pedido v)
{
    pNodo nuevo;
    nuevo = new Nodo(v); // Se crea un nodo nuevo
// Si la cola no es vacia, se agrega el nuevo a continuacion de ultimo
    if(final) final->siguiente = nuevo;
//El ultimo elemento de la cola es el nuevo nodo
    final= nuevo;
// Si frente es NULL, la cola esta vacia y el nuevo nodo pasa a ser el primero
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
//Se asigna a frente la direccion del segundo nodo
    frente = nodo->siguiente;
//Se guarda el valor de retorno
    v = nodo->valor;
    delete nodo; // Se borra el nodo
// Si cola vacia, ultimo debe ser NULL tambien
    if(!frente) final = NULL;
    return v;
}

//FUNCION PARA SABER SI COLA VACIA (gracias Javier <3)

bool Cola::esVacia()
{
    if (!frente) return true;
    else return false;
}


// ====================== METODOS PILA ======================

//Destructor de la Pila
Pila::~Pila()
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
    Pedido ped = {(rand()%6),id_pedido,cod_libro,materia,amount,"Iniciado"}; // Cuando se crea un pedido, siempre empieza en iniciado :D
    return ped;
}
// funcion de los huevos que rompe el codigo y no funciona tal y como lo damos en clase ni como queremos OJALA SE MUERA CODEBLOCKS JDHFJHKSGAFLJ;SLKDJFKOWTHRUPIJ
void printQueue(Cola &c){
    Cola qaux = c; // Creamos una cola auxiliar que contiene la direccion de memoria de la cola introducida.
    Pedido p_aux; // Variable auxiliar Pedido para poder mostrar sus elementos por pantalla
    if(qaux.esVacia()){
        cout<<"(vacio)"<<endl; // Si la cola esta vacia de antes, lo mostramos por medio de este cout.
    }
    else{
        while(!qaux.esVacia()){
                p_aux = qaux.desencolar(); // Si no esta vacia, pues vamos desencolando y mostrando los atributos de cada pedido hasta que se vacie.
                cout<<setw(4)<<p_aux.id_editorial<<"|"<<setw(10)<<p_aux.id_pedido<<"|"<<setw(8)<<p_aux.cod_libro<<"|"<<setw(12)<<p_aux.materia<<"|"<<setw(4)<<p_aux.cantidad<<"|"<<setw(10)<<p_aux.estado<<"|"<<endl;
        }
    }
}
