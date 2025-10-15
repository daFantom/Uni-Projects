#ifndef EDITORIAL_H_INCLUDED
#define EDITORIAL_H_INCLUDED

// CONSTANTES
#define MAX_TITULOS 10
#define N_PEDIDOS_PASO 12
#define TAM_LOTE 10
#define LIBRERIAS 6
#define CAP_CAJA 5
// FIN CONSTANTES

string estado[5] = {"Iniciado","Almacen","Imprenta","Listo","Caja"};
struct Pedido{
    int id_editorial;
    string id_pedido;
    string cod_libro;
    string materia
    int cantidad;
    string estado;
};
struct pedido_stock{
    string cod_libro;esk
    int unidades;
};
//pedido_stock stock[MAX_TITULOS]

// CLASE NODO

class Nodo
{
private:
    pedido valor;
    Nodo *siguiente;
    friend class Pila;
    friend class Cola;
public:
    Nodo(pedido v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pNodo;

// LA CLASE COLA
class Cola
{
public:
    Cola() : frente(NULL), final(NULL) {}
    ~Cola();
    void encolar(Pedido v);
    Pedido desencolar();
private:
    pNodo frente, final;
};

// LA CLASE PILA
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



#endif // EDITORIAL_H_INCLUDED
