#include "pch.h"
#include "iostream"
#define ANCHO_CONSOLA 80
#define ALTO_CONSOLA 40
const int CantSatelites = 4;

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void Ventana()
{
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

void IngresarPosicionSatelites(int* PosXS, int* PosYS, int* dXS, int* dYS)
{
    cout << "Ingrese las Posiciones X de cada uno de los satelites: ";
    for (int i = 0; i < CantSatelites; i++)
    {
        do
        {
            cin >> PosXS[i];
        } while (PosXS[i] < 0 || PosXS[i] > ANCHO_CONSOLA);
    }
    cout << "Ingrese las Posiciones Y de cada uno de los satelites: ";
    for (int i = 0; i < CantSatelites; i++)
    {
        do
        {
            cin >> PosYS[i];
        } while (PosYS[i] < 0 || PosYS[i] > ALTO_CONSOLA);
    }
    cout << "Ingrese el desplazamiento en X de los satelites: ";
    for (int i = 0; i < CantSatelites; i++)
    {
        do
        {
            cin >> dXS[i];
        } while (dXS[i] < -1 || dXS[i] > 1);
    }
    cout << "Ingrese el desplazamiento en Y de los satelites: ";
    for (int i = 0; i < CantSatelites; i++)
    {
        do
        {
            cin >> dYS[i];
        } while (dYS[i] < -1 || dYS[i] > 1);
    }
}

void BorrarSatelites(int* PosXS, int* PosYS)
{
    for (int i = 0; i < CantSatelites; i++)
    {
        Console::SetCursorPosition(PosXS[i], PosYS[i]); cout << " ";
    }
}

void DibujarSatelites(char* FormaS, int* ColorS, int* PosXS, int* PosYS)
{
    for (int i = 0; i < CantSatelites; i++)
    {
        Console::ForegroundColor = ConsoleColor(ColorS[i]);
        Console::SetCursorPosition(PosXS[i], PosYS[i]); cout << FormaS[i];
        Console::ResetColor();
    }
}

void MoverSatelites(int* PosXS, int* PosYS, int* dXS, int* dYS)
{
    for (int i = 0; i < CantSatelites; i++)
    {
        if (PosXS[i] >= 0 && PosXS[i] < ANCHO_CONSOLA / 2)
        {
            if (PosXS[i] + dXS[i] < 0 || PosXS[i] + dXS[i] >= ANCHO_CONSOLA / 2)
            {
                dXS[i] *= -1;
            }
        }
        if (PosXS[i] > ANCHO_CONSOLA / 2 && PosXS[i] <= ANCHO_CONSOLA)
        {
            if (PosXS[i] + dXS[i] <= ANCHO_CONSOLA / 2 || PosXS[i] + dXS[i] > ANCHO_CONSOLA - 1)
            {
                dXS[i] *= -1;
            }
        }
        if (PosYS[i] + dYS[i] < 0 || PosYS[i] + dYS[i] >= ALTO_CONSOLA)
        {
            dYS[i] *= -1;
        }
        PosXS[i] += dXS[i];
        PosYS[i] += dYS[i];
    }
}

void Simulacion(char* FormaS, int* ColorS, int* PosXS, int* PosYS, int* dXS, int* dYS)
{
    BorrarSatelites(PosXS, PosYS);
    MoverSatelites(PosXS, PosYS, dXS, dYS);
    DibujarSatelites(FormaS, ColorS, PosXS, PosYS);
    _sleep(20);
}

int main()
{
    srand(time(nullptr));
    int* PosXS = new int[CantSatelites];
    int* PosYS = new int[CantSatelites];
    int* dXS = new int[CantSatelites];
    int* dYS = new int[CantSatelites];
    char* FormaS = new char[CantSatelites];
    int* ColorS = new int[CantSatelites];

    Ventana();

    for (int i = 0; i < CantSatelites; i++)
    {
        FormaS[i] = RandInt(33, 47);
        ColorS[i] = RandInt(1, 15);
    }
    IngresarPosicionSatelites(PosXS, PosYS, dXS, dYS);
    system("cls");

    while (true)
    {
        Simulacion(FormaS, ColorS, PosXS, PosYS, dXS, dYS);
    }

    delete[] PosXS;
    delete[] PosYS;
    delete[] dXS;
    delete[] dYS;
    delete[] FormaS;
    delete[] ColorS;

    system("pause>0");
    return 0;
}