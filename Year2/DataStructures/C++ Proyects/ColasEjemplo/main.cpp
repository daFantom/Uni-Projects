#include <iostream>

using namespace std;


class Nodo
{
private:
    int valor;
    Nodo *siguiente;
    friend class Cola;
public:
    Nodo(int v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pnodo;

class Cola
{
public:
    Cola() : frente(NULL), final(NULL) {}
    ~Cola();
    void encolar(int v);
    int desencolar();
private:
    pnodo frente, final;
};

//Destructor
Cola::~Cola()
{
    while(frente) desencolar();
}


//Añadir elemento en la cola
void Cola::encolar(int v)
{
    pnodo nuevo;
    nuevo = new Nodo(v); // Se crea un nodo nuevo
// Si cola no vacía, se añade el nuevo a continuación de ultimo
    if(final) final->siguiente = nuevo;
//El último elemento de la cola es el nuevo nodo
    final= nuevo;
// Si frente es NULL, la cola está vacía y el nuevo nodo pasa a ser el primero
    if(!frente) frente = nuevo;
}

//Leer elemento de la cola
int Cola::desencolar()
{
    pnodo nodo; //Var aux para manipular nodo
    int v; //Var aux para retorno del valor
// Nodo apunta al primer elemento de la pila
    nodo = frente;
    if(!nodo) return 0; // Si no hay nodos en la pila se devuelve 0
//Se asigna a frente la dirección del segundo nodo
    frente = nodo->siguiente;
//Se guarda el valor de retorno
    v = nodo->valor;
    delete nodo; // Se borra el nodo
// Si cola vacía, ultimo debe ser NULL también
    if(!frente) final = NULL;
    return v;
}


int main()
{
    Cola cola;
    cola.encolar(20);
    cout << "Encolar(20)" << endl;
    cola.encolar(10);
    cout << "Encolar(10)" << endl;
    cout << "Desencolar: " << cola.desencolar() << endl;
    cola.encolar(40);
    cout << "Encolar(40) " << endl;
    cola.encolar(30);
    cout << "Encolar(30) " << endl;
    cout << "Desencolar: " << cola.desencolar() << endl;
    cout << "Desencolar: " << cola.desencolar() << endl;
    cola.encolar(90);
    cout << "Encolar(90) " << endl;
    cout << "Desencolar: " << cola.desencolar() << endl;
    cout << "Desencolar: " << cola.desencolar() << endl;
    cout << "Desencolar: " << cola.desencolar() << endl; // Desencolamos una cola vacia.
    return 0;
}
