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
    friend class Cola;
public:
    Nodo(Alumno e, Nodo *sig = NULL)
    {
        valor = e;
        siguiente = sig;
    }
};
typedef Nodo *pnodo;

class Cola
{
public:
    Cola() : frente(NULL), final(NULL) {}
    ~Cola();
    void encolar(Alumno v);
    Alumno desencolar();
private:
    pnodo frente, final;
};

//Destructor
Cola::~Cola()
{
    while(frente) desencolar();
}


//Añadir elemento en la cola
void Cola::encolar(Alumno v)
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
Alumno Cola::desencolar()
{
    pnodo nodo; //Var aux para manipular nodo
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
    return e;
}
int main(void){
    Cola cola;
    Alumno a1,a2,a3, a_aux;
    a1 = {"Emanuel Baciu",18};
    a2 = {"Pablo Fernandez",20};
    a3 = {"Gerardo Diego",87};
    cout << "Encolando a: "<< a1.name << " con edad de: " << a1.age << " anios"<< endl;
    cola. encolar(a1);
    cout << "Encolando a: "<< a2.name << " con edad de: " << a2.age << " anios" << endl;
    cola.encolar(a2);
    cout << "Encolando a: "<< a3.name << " con edad de: " << a3.age <<" anios"<<endl;
    cola.encolar(a3);
    a_aux = cola.desencolar();
    while (a_aux.name!=""&&a_aux.age!=0){
        cout << "Desencolando a: " << a_aux.name <<" de edad: " << a_aux.age << " anios" << endl;
        a_aux = cola.desencolar();
    }
    return 0;
}
