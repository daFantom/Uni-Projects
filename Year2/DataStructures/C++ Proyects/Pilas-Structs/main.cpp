#include <iostream>

using namespace std;

struct Alumno
{
    string Nombre;
    int edad;
};

class Nodo
{
private:
    Alumno valor;
    Nodo *siguiente;
    friend class Pila;
public:
    Nodo(Alumno v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pNodo;

class Pila
{
private:
    pNodo cima;
public:
    Pila() : cima(NULL) {} //Constructor de la Pila
    ~Pila();
    void apilar(Alumno v);
    Alumno desapilar();
};

//Destructor de la Pila
Pila::~Pila()
{
    while(cima) desapilar();
}
//Meter elemento en la Pila
void Pila::apilar(Alumno v)
{
    pNodo nuevo; //Var aux para manipular el nuevo nodo
//Se crea un nodo nuevo
    nuevo = new Nodo(v, cima);
//El comienzo de la pila es el nuevo nodo
    cima = nuevo;
}

//Sacar elemento de la Pila
Alumno Pila::desapilar()
{
    pNodo nodo; //Var aux para manipular el nodo
    Alumno v; //Var aux para el retorno del valor del nodo
    Alumno nadie = {"",0};
    if(!cima) return nadie; // Si no hay nodos en la pila se devuelve un alumno vacio
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
    Alumno a1 = {"Francisco",20};
    Alumno a2 = {"Fernando",45};
    Alumno a3 = {"Emanuel",18};
    Alumno a_aux;
    pila.apilar(a1);
    cout << "Apilar a: "<< a1.Nombre << " con edad: " << a1.edad << endl;
    pila.apilar(a2);
    cout << "Apilar a: "<< a2.Nombre << " con edad: " << a2.edad << endl;
    pila.apilar(a3);
    cout << "Apilar a: "<< a3.Nombre << " con edad: " << a3.edad << endl;
    a_aux = pila.desapilar();
    cout << "Desapilando a: " << a_aux.Nombre << " con edad: " << a_aux.edad << endl;
    a_aux = pila.desapilar();
    cout << "Desapilando a: " << a_aux.Nombre << " con edad: " << a_aux.edad << endl;
    a_aux = pila.desapilar();
    cout << "Desapilando a: " << a_aux.Nombre << " con edad: " << a_aux.edad << endl;

    return 0;
}
