// 15.04.19_para.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// ЗАДАЧА "Очень важные гости"

#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

struct Place
{
	int x, y;
};

double getDistance(int n1, int m2);
void print(int** arr, int n, int m);
bool contains(char reagent);

int main()
{	
	ifstream in("in.txt");
	char** input = new char*[20];
	for (int i = 0; i < 20; i++)
	{
		input[i] = new char[10];
		input[i][9] = '\0';
	}
	char reagents[20];
	int i = 0;
	//in >> 
	while (!in.eof())
	{
		in >> input[i];
		i++;
		cout << input[i] << endl;
	}

	/*int t = 0, n = 0, m = 0, current = 0;;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		n = 0; m = 0;
		cin >> n >>  m;
		current = n * m;
		int ** arr = new int*[n];
		for (int i = 0; i < n; i++)
			arr[i] = new int[m];
		for (int i = 0; i < n; i++)
		{
			for (int j = n - i - 1; j < m; j++)
			{
				//cout << "aaa";
				arr[i][j] = current;
				current--;
				
			}
		}
		print(arr, n, m);
		delete[] *arr;
		delete[] arr;
		cout << endl;
	}*/
}

bool contains(char reagent, char* reagents)
{
	for (int i = 0; i < sizeof(reagents); i++)
	{
		if (reagents[i] == reagent)
			return true;
	}
	return false;
}

void print(int** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}

double getDistance(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
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
