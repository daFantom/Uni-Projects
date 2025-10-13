#include <iostream>
using namespace std;

    struct Alumno{
        string name;
        int age;
    };

class Nodo
{
private:
    Alumno valor;
    Nodo *siguiente;
    friend class Pila;
    friend class Cola;
public:
    Nodo(Alumno v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pNodo;

// LA CLASE COLA Y SUS METDOS.
class Cola
{
public:
    Cola() : frente(NULL), final(NULL) {}
    ~Cola();
    void encolar(Alumno v);
    Alumno desencolar();
private:
    pNodo frente, final;
};

//Destructor
Cola::~Cola()
{
    while(frente) desencolar();
}


//Añadir elemento en la cola
void Cola::encolar(Alumno v)
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
Alumno Cola::desencolar()
{
    pNodo nodo; //Var aux para manipular nodo
    Alumno v; //Var aux para retorno del valor
// Nodo apunta al primer elemento de la pila
    nodo = frente;
    Alumno a_vacio = {"",0};
    if(!nodo) return a_vacio; // Si no hay nodos en la pila se devuelve 0
//Se asigna a frente la dirección del segundo nodo
    frente = nodo->siguiente;
//Se guarda el valor de retorno
    v = nodo->valor;
    delete nodo; // Se borra el nodo
// Si cola vacía, ultimo debe ser NULL también
    if(!frente) final = NULL;
    return v;
}

// LA CLASE PILA Y SUS METODOS
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
    Alumno a1,a2,a3, a_aux;
    Pila p1;
    Cola c1;
    a1 = {"Francisco Diaz",20};
    a2 = {"Fernando Lorcas",45};
    a3 = {"Emanuel Baciu",18};
    cout<< "===== PILA ====" <<endl<<endl;

    cout<<"\t===== Apilado ====" << endl;
    cout << "\t\tApilando: "<< a1.name <<" - "<<a1.age<<endl;
    p1.apilar(a1);
    cout << "\t\tApilando: "<< a2.name <<" - "<<a2.age<<endl;
    p1.apilar(a2);
    cout << "\t\tApilando: "<< a3.name <<" - "<<a3.age<<endl;
    p1.apilar(a3);

    cout<<"\t===== Desapilado ====" << endl;
    a_aux = p1.desapilar();
    while(a_aux.name!=""&&a_aux.age!=0){
        cout << "\t\tDesapilando: "<< a_aux.name <<" - "<<a_aux.age<<endl;
        a_aux = p1.desapilar();
    }
    cout<<endl;

    cout<< "===== COLA ====" <<endl<<endl;
    cout<<"\t===== Encolado ====" << endl;
    cout << "\t\tEncolando: "<< a1.name <<" - "<<a1.age<<endl;
    c1.encolar(a1);
    cout << "\t\tEncolado: "<< a2.name <<" - "<<a2.age<<endl;
    c1.encolar(a2);
    cout << "\t\tEncolado: "<< a3.name <<" - "<<a3.age<<endl;
    c1.encolar(a3);

    cout<<"\t===== Desencolado ====" << endl;
    a_aux = c1.desencolar();
    while(a_aux.name!=""&&a_aux.age!=0){
        cout << "\t\tDesapilando: "<< a_aux.name <<" - "<<a_aux.age<<endl;
        a_aux = c1.desencolar();
    }
    return 0;
}
