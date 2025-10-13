#include <iostream>
#include <ctime>

using namespace std;

struct bornDate{
    int d;
    int m;
    int y;
};

struct student{
    string name;
    string surname;
    bornDate dob;
    string nif;
    int num;
    string carplate;
    string degree;

};

int main()
{
    bornDate bd1 = {0,0,0};
    student st1 = {" "," ",bd1,"0",000000000,"0000000", " "};

    cout <<"Introduzca su dia de nacimiento [01-31]: ";
    cin >> bd1.d;
    cout<<endl;
    cout <<"Introduzca su mes de nacimiento [01-12]: ";
    cin >> bd1.m;
    cout<<endl;
    cout <<"Introduzca su anio de nacimiento [1950-2025]: ";
    cin >> bd1.y;
    cout<<endl;
    cout <<"Introduzca su nombre: ";
    cin >> st1.name;
    cout<<endl;
    cout <<"Introduzca su apellido principal: ";
    cin >> st1.surname;
    cout<<endl;
    cout <<"Introduzca su NIF [000000000]: ";
    cin >> st1.nif;
    cout<<endl;
    cout <<"Introduzca su numero de telefono principal [000000000]: ";
    cin >> st1.num;
    cout<<endl;
    cout <<"Introduzca su matricula [AAA-0000]: ";
    cin >> st1.carplate;
    cout<<endl;
    cout <<"Introduzca el grado que cursa: ";
    cin >> st1.degree;
    cout<<endl;
    st1.dob = bd1;
    cout << endl << endl;
    cout << "===== Datos Personales =====" << endl;
    cout << endl;
    cout << "Nombre: "<< st1.name << endl;
    cout << "Apellidos: " << st1.surname << endl;
    cout << "Fecha de nacimiento: "<<st1.dob.d<<"/"<<st1.dob.m <<"/"<<st1.dob.y << endl;
    cout << "NIF: "<< st1.nif << endl;
    cout << "Numero de telefono: "<<st1.num << endl;
    cout << "Matricula: "<<st1.carplate << endl;
    cout << "Grado actual que cursa: "<<st1.degree << endl;
    return 0;
}
