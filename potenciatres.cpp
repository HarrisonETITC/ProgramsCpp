#include <iostream>
using namespace std;

long pot[16];

void init()
{
    pot[0] = 1;
    for (int i = 1; i < 16; i++)
        pot[i] = 3 * pot[i - 1];
}

int buscar(int n)
{
    int i = 0;
    int resultado = -1;
    while (pot[i] < n)
    {
        i++;
    }
    if (pot[i] == n)
        return i;
    return -1;
}
int main()
{
    init();
    int n;
    cin >> n;
    cout << buscar(n) << "\n";

    return 0;
}