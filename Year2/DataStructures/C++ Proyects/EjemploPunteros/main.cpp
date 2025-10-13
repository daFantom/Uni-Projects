#include <iostream>

using namespace std;

int main()
{
    int x,y,*p,*q;

    p = &x;
    cout << p <<" "<< x << endl;

    *p = 5;
    cout << p <<" "<< x << endl;

    q = &y;
    *q = 23;
    cout << q <" "<< y << endl;

    cout << *p <<" "<< *q << endl;

    q=p;
    cout << p <<" "<< q << endl;
    cout << *p <<" "<< *q << endl;
    return 0;
}
