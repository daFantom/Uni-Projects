#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
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

//METODO PARA SABER SI COLA VACIA (gracias Javier <3)
bool Cola::esVacia()
{
    if (!frente) return true;
    else return false;
}
// METODO PARA SABER LA LONGITUD DE UNA COLA (gracias javier x2)

int Cola::getLength(){
    pNodo point_aux;
    int len = 0;
     point_aux = frente;
     while(point_aux!=NULL){
        len++;
        point_aux = point_aux->siguiente;
     }
     return len;
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
bool Pila::esVacia(){
    if(!cima){
        return true;
    }
    else{
        return false;
    }
}
int Pila::getLength(){
    pNodo point_aux;
    int len = 0;
     point_aux = cima;
     while(point_aux!=NULL){
        len++;
        point_aux = point_aux->siguiente;
     }
     return len;
}
string Pila::getTopCode(){
    if (!cima){
        return "(vacio)";
    }
    else{
        return cima->valor.id_pedido;
    }
}
// FUNCIONES Y PROCEDIMIENTOS

// GENERAR PEDIDOS ALEATORIOS.
Pedido genPedido(){
    char abecedario[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; // Todo el abecedario para elegir una letra de forma aleatoria.
    int numaleat1,numaleat2,unidades;
    char letraAleat;
    letraAleat = abecedario[rand()%(sizeof(abecedario)/sizeof(abecedario[0]))]; // Se recoge una letra del Array 'abecedario' de manera randomizada.
    unidades = rand()%20 + 1;
    numaleat1=rand()%999; // Se coge un numero de entre 0 y 998 de forma pseudoaleatoria.
    numaleat2=rand()%99; // Se coge un numero de entre 0 y 98 de forma pseualeatoria.
    string materias[6] ={"Matematicas","Fisica","Tecnologia","Musica","Historia", "Lengua"};
    string id_pedido = "P"+to_string(rand()%99999); // el rand() representa la parte numerica del codigo.
    string cod_libro = to_string(numaleat1)+letraAleat+to_string(numaleat2);
    string materia = materias[rand()%(sizeof(materias)/sizeof(materias[0]))]; // Dividimos la longitud del array (en bytes) con la longitud del primer elemenento para que nos devuelva la cantidad de elementos del array.
    Pedido ped = {(rand()%6),id_pedido,cod_libro,materia,unidades,"Iniciado"}; // Cuando se crea un pedido, siempre empieza en iniciado :D
    return ped;
}
// funcion de los huevos que rompe el codigo y no funciona tal y como lo damos en clase ni como queremos OJALA SE MUERA CODEBLOCKS JDHFJHKSGAFLJ;SLKDJFKOWTHRUPIJ
void printQueue(Cola &c){
    Pedido p_aux; // Variable auxiliar Pedido para poder mostrar sus elementos por pantalla
    cout<<"-----------------------------------------------------"<<endl;
    cout<<setw(4)<<"Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    if(c.esVacia()){
        cout<<"(vacio)"<<endl; // Si la cola esta vacia de antes, lo mostramos por medio de este cout.
    }
    else{
            for(int i = 0; i<c.getLength();i++){
                p_aux = c.desencolar(); // Si no esta vacia, pues vamos desencolando y mostrando los atributos de cada pedido hasta que se vacie.
                cout<<setw(4)<<p_aux.id_editorial<<"|"<<setw(10)<<p_aux.id_pedido<<"|"<<setw(8)<<p_aux.cod_libro<<"|"<<setw(12)<<p_aux.materia<<"|"<<setw(4)<<p_aux.cantidad<<"|"<<setw(10)<<p_aux.estado<<"|"<<endl;
                c.encolar(p_aux);
            }
        }
    cout << endl;
}

void printPile(Pila &p, int libcode){
    Pila aux_pile;                              // Creamos una pila auxiliar que esta vacia.
    Pedido p_aux;                            // La misma funcion que la variable del procedimiento anterior.
    cout <<"==="<<" Caja de la libreria codigo "<<libcode<<" (de ultimo elemento a primero) "<<"==="<< endl;
    cout<< endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<setw(4)<<"Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    if(p.esVacia()){
        cout<<"(vacia)"<<endl;        // Si la pila esta vacia de antes, mostramos este mensaje y no imprimimos nada mas.
    }
    else{
        for(int i = 0;i<p.getLength();i++){
                p_aux = p.desapilar();  // Si no esta vacia,  vamos desapilando hasta que se quede vacia.
                cout<<setw(4)<<p_aux.id_editorial<<"|"<<setw(10)<<p_aux.id_pedido<<"|"<<setw(8)<<p_aux.cod_libro<<"|"<<setw(12)<<p_aux.materia<<"|"<<setw(4)<<p_aux.cantidad<<"|"<<setw(10)<<p_aux.estado<<"|"<<endl;
                aux_pile.apilar(p_aux);
        }
    }
    for(int j = 0; j<aux_pile.getLength();j++){
            p_aux = aux_pile.desapilar();
            p.apilar(p_aux);
    }
    cout<<endl;
}


