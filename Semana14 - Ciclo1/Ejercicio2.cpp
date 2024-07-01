#include "pch.h"
#include "iostream"
#define N 8

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void GenerarVector(int* Byte)
{
    for (int i = 0; i < N; i++)
    {
        Byte[i] = RandInt(0, 1);
    }
}

void MostrarVector(int* Byte)
{
    for (int i = 0; i < N; i++)
    {
        cout << Byte[i] << ' ';
    }
    cout << endl << endl;
}

void PrendeApagaBits(int* Byte)
{
    for (int i = 0; i < N; i++)
    {
        Byte[i] = abs(Byte[i] - 1);
    }
}

void IntercambiarBits(int* Byte)
{
    for (int i = 0; i < N; i += 2)
    {
        swap(Byte[i], Byte[i + 1]);
    }
}

int ConvertirToDecimal(int* Byte)
{
    int aBaseDec = 0;
    for (int i = 0; i < N; i++)
    {
        aBaseDec += Byte[i] * pow(2, 7 - i);
    }
    return aBaseDec;
}

int main()
{
    srand(time(nullptr));
    int* Byte = new int[N];

    GenerarVector(Byte);
    MostrarVector(Byte);

    PrendeApagaBits(Byte);
    MostrarVector(Byte);

    IntercambiarBits(Byte);
    MostrarVector(Byte);

    MostrarVector(Byte);
    cout << "La conversion del arreglo de bits a base decimal es: " << ConvertirToDecimal(Byte);

    delete[] Byte;

    system("pause>0");
    return 0;
}