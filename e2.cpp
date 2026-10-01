#include <iostream>
using namespace std;

struct Ponto {
    int x;
    int y;
};

template <typename T>
void trocar(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1, b = 2;
    Ponto p1 = {1, 2};
    Ponto p2 = {2, 1};
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "p1: " << p1.x << " " << p1.y << endl;
    cout << "p2: " << p2.x << " " << p2.y << endl;

    trocar(a, b);
    trocar(p1, p2);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "p1: " << p1.x << " " << p1.y << endl;
    cout << "p2: " << p2.x << " " << p2.y << endl;
}