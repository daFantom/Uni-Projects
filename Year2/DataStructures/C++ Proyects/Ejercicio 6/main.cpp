
#include <iostream>
#include <ctime>

using namespace std;

struct Hora
{
    int hh;
    int mm;
    int ss;
};

Hora hhAleat() // funcion que devuelve una variable de tipo "Hora".
{
    Hora haleat;
    haleat.hh=rand()%24;
    haleat.mm=rand()%60;
    haleat.ss=rand()%60;
    return haleat;
}
int main()
{
    int i = 0;
    Hora h; //={17,34,45}; como ejemplo.
    srand(time(NULL)); // para que salga aleatorio cada vez que se ejecuta el programa.
    for (i=0; i<5; i++)
    {
        h=hhAleat();
        cout << h.hh << ":"
             << h.mm << ":"
             << h.ss << endl;
        cout << endl << endl;
    }
}
