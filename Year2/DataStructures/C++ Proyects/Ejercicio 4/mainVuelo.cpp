#include <iostream>
#include <ctime>

using namespace std;
string calcularVuelo(void)
{
    int numaleat;
    numaleat=rand()%9999;
    string empres[]= {"IBE", "ACA","RYR","MSR","UAL","AEA","KLM"};
    int i = rand()%6;
    return empres[i]+ to_string(numaleat);
}

int main()
{
    int i = 0;
    srand(time(NULL));
    for (i=1; i<10; i++)
    {
        cout << "Secuencia aleatoria: " << i << endl;
        cout << calcularVuelo();
        cout << endl << endl;
    }
    return 0;
}
