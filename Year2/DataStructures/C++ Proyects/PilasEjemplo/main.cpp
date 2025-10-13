#include <iostream>

using namespace std;

class Nodo
{
private:
    int valor;
    Nodo *siguiente; // Un nodo tiene un puntero a otro nodo.
    friend class Pila;
public:
    Nodo(int v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pNodo; // definimos un tipo de dato llamado pNodo, que es un puntero y es de tipo Nodo para no ir definiendo despues en los metodos.

class Pila
{
private:
    pNodo cima;
public:
    Pila() : cima(NULL) {} //Constructor de la Pila
    ~Pila();
    void apilar(int v);
    int desapilar();
};

//Destructor de la Pila
Pila::~Pila() // Lo ponemos de esta manera para que no sea tan sucio y poder definirlo mejor al hacerlo en 3 archivos.
{
    while(cima) desapilar();
}
//Meter elemento en la Pila
void Pila::apilar(int v)
{
    pNodo nuevo; //Var aux para manipular el nuevo nodo
//Se crea un nodo nuevo
    nuevo = new Nodo(v, cima);
//El comienzo de la pila es el nuevo nodo
    cima = nuevo;
}

//Sacar elemento de la Pila
int Pila::desapilar()
{
    pNodo nodo; //Var aux para manipular el nodo
    int v; //Var aux para el retorno del valor del nodo
    if(!cima) return 0; // Si no hay nodos en la pila se devuelve 0
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


int main()
{
    Pila pila; //Se instancia un objeto de la clase Pila.
    pila.apilar(20); //Se añade un nodo
    cout << "Apilar(20)" << endl;
         pila.apilar(10); //Se añade un nodo
    cout << "Apilar(10)" << endl;
//Se saca un nodo (10)
    cout << "Desapilar() = " << pila.desapilar() << endl;
    pila.apilar(40); //Se añade un nodo
    cout << "Apilar(40)" << endl;
    pila.apilar(30); //Se añade un nodo
    cout << "Apilar(30)" << endl;
//Se saca un nodo (30)
    cout << "Desapilar() = " << pila.desapilar() << endl;
//Se saca un nodo (40)
    cout << "Desapilar() = " << pila.desapilar() << endl;
    pila.apilar(90); //Se añade un nodo
    cout << "Apilar(90)" << endl;
//Se saca un nodo (90)
    cout << "Desapilar() = " << pila.desapilar() << endl;
//Se saca un nodo (20)
    cout << "Desapilar() = " << pila.desapilar() << endl;
    cout << "Desapilar() = " << pila.desapilar() << endl; // Desapilamos pila vacia.
    return 0;
}
