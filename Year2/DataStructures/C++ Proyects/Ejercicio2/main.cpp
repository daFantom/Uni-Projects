#include <iostream>
#include <ctime>
using namespace std;
int calcularSecuenciaAleatoria(void)
{
    int numaleat;
    numaleat=rand()%9999;
    return numaleat;
}
 int calcularSecuenciaAleatoria() //prototipo de la funcion.
int main()
{
    srand(time(NULL));
    for (int i=1; i<10; i++)
    {
        cout << "Secuencia aleatoria: " << i << endl;
        cout << calcularSecuenciaAleatoria();
        cout << endl << endl;
    }
    return 0;
}
