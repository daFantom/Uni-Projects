#include <ctime>
#include <iostream>
// ====================== METODOS COLA ======================

//Destructor
Cola::~Cola()
{
    while(frente) desencolar();
}


//Añadir elemento en la cola
void Cola::encolar(Pedido v)
{
    pNodo nuevo;
    nuevo = new Nodo(v); // Se crea un nodo nuevo
// Si cola no vacía, se añade el nuevo a continuación de ultimo
    if(final) final->siguiente = nuevo;
//El último elemento de la cola es el nuevo nodo
    final= nuevo;
// Si frente es NULL, la cola está vacía y el nuevo nodo pasa a ser el primero
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
//Se asigna a frente la dirección del segundo nodo
    frente = nodo->siguiente;
//Se guarda el valor de retorno
    v = nodo->valor;
    delete nodo; // Se borra el nodo
// Si cola vacía, ultimo debe ser NULL también
    if(!frente) final = NULL;
    return v;
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
}

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
string calcularCodigoAleat(void){
    srand(time(NULL));
    char abecedario[6] = {'A','B','C','D','E','F'}; // Poner todo el abecedario
    int numaleat1,numaleat2, indexAleat;
    char letraAleat;
    indexAleat = rand()%sizeof(abecedario);
    letraAleat = abecedario[indexAleat];
    numaleat=rand()%999;
    numaleat2=rand()%99;
    string codigo = to_string(numaleat1)+letraAleat+to_string(numaleat2);
    return codigo;
}
pedido genPedido(void){
    srand(time(NULL));
    string materias[6] ={"Matematicas","Fisica","Tecnologia","Musica","Historia", "Lengua"};
    string id_pedido = "P"+to_string(rand()%99999); // el rand representa la parte numerica del codigo.
    string cod_libro = calcularCodigoAleat();
    string materia = materias[rand()%(sizeof(materias)/sizeof(materias[0]))]; // Dividimos la longitud del array (en bytes) con la longitud del primer elemenento para que nos devuelva la cantidad de elementos del array.
    int amount;
    cout << "Inserta la cantidad de libros que quiere pedir: "; // no se si esto hay que pedirlo o no, pero lo pido porque puedo y me da la gana hasta que se diga lo contrario.
    cin >> amount;
    Pedido p = {rand()%6,id_pedido,cod_libro,materia,amount,"Iniciado"}; // Cuando se crea un pedido, siempre empieza en iniciado :D
    return p;
}

//FUNCION PARA METER LOS PEDIDOS SOLICITADOS EN UNA LISTA.
void listaPedidos(int pedidos){

}

