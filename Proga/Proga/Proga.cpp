// Proga.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Matrix
{
	int ** data = new int *[200];
	Matrix()
	{
		for (int i = 0; i < 200; i++)
			data[i] = new int[200];
	}
	void add(int** in)
	{
		data = in;
	}

	int** getData()
	{
		return data;
	}

	char* toString()
	{
		char* out = new char[200*201];
		int i = 0;
		for (i; i < 200; i++)
		{
			for (int j = 0; j < 200; j++)
			{
				out[i] = data[i][j];
			};
			out[i] = '\n';
		}
		out[i] = '\0';
		return out;
	}
};
void readFile(string fileName, int** arr);



int main()
{
	Matrix* in = new Matrix();
	readFile("in.txt", in->getData());
	cout << in->toString();
}



void readFile(string fileName, int** arr)
{
	ifstream f(fileName);
	if (f.is_open())
	{
		for (int i = 0; i < 200; i++)
		{
			for (int j = 0; j < 200; j++)
			{
				f >> arr[i][j];
			}
		}
	}
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
