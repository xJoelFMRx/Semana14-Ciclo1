#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void GenerarValores(int* Mensaje, int N)
{
	for (int i = 0; i < N; i++)
	{
		Mensaje[i] = RandInt(0, 9);
	}
}

void MostrarValores(int* Mensaje, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << Mensaje[i] << ' ';
	}
	cout << endl;
}

bool ExisteCapicua4(int* Mensaje, int N)
{
	return (Mensaje[N - 1] == Mensaje[N - 4] && Mensaje[N - 2] == Mensaje[N - 3]);
}

//Para hacerlo mas corto el codigo y halla mas probabilidad podria ponerle que busque si exista un capicua de 3, pero el problema no lo pide
//bool ExisteCapicua3(int* Mensaje, int N)
//{
//	return (Mensaje[N - 1] == Mensaje[N - 3]);
//}

int main()
{
	srand(time(nullptr));
	int cont = 0;
	do
	{
		int N = RandInt(10, 15);
		int* Mensaje = new int[N];

		GenerarValores(Mensaje, N);
		MostrarValores(Mensaje, N);
		if (ExisteCapicua4(Mensaje, N))/*/|| ExisteCapicua3(Mensaje, N)/)*/
		{
			cout << "Se encontro un capicua....\n\n";
			cont++;
		}
		if (cont == 5)
		{
			cout << "CONTACTO!!";
		}
		delete[] Mensaje;
	} while (cont != 5);

	system("pause>0");
	return 0;
}
