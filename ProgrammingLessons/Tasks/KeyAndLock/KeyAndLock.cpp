// KeyAndLock.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

int** rotate(int** a, int n)
{
	int** out = new int*[n];
	for (int i = 0; i < n; i++)
		out[i] = new int[n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			out[j][n - 1 - i] = a[i][j];
		}
	}
	return out;
}

void flipX(int** a, int n, int m)
{
	if (m % 2 != 0) m = m / 2 + 1;
	int** out = new int*[n];
	for (int i = 0; i < n; i++)
		out[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			swap(a[i][j], a[i][m - j + 1]);
		}
	}
}

void flipY(int** a, int n, int m)
{
	if (n % 2 != 0) n = n / 2 + 1;
	int** out = new int*[n];
	for (int i = 0; i < n; i++)
		out[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			swap(a[i][j], a[n - i + 1][j]);
		}
	}
}

bool check(int* a1, int* a2, int size)
{
	bool b = false;
	for (int i = 0; i < size; i++)
	{
		if (a1[i] ^ a2[i] == 0)
			return false;
	}
	return true;
}


int* openLock(int** lock, int** key, int n1, int m1, int n2, int m2)
{
	int* output = new int[2];
	int* helpArr = new int[m2 * n2], *tmpkey = new int[m2 * n2];
	int counter = 0;
	
	
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			tmpkey[counter] = key[i][j];
			//cout << tmpkey[counter] << ' ';
			helpArr[counter] = 9;
			counter++;
		}
	}
	counter = 0;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			if (lock[i][j] == tmpkey[0])
				for (int q = i; q < n2 + i && q < n1; q++)
				{
					for (int k = j; k < m2 + j && k < m1; k++)
					{
						helpArr[counter] = lock[q][k];
						//cout << helpArr[counter] << ' ';
						counter++;
					}

				}
			for (int g = 0; g < m2 * n2; g++)
				cout << helpArr[g] << ' ';
			cout << endl;

			if (check(helpArr, tmpkey, m2 * n2))
			{
				cout << i << ' ' << j;
				output[0] = i;
				output[1] = j;
				return output;
			}
			counter = 0;
		}
	}
	output[0] = -1;
	return output;
}



int main()
{
	ifstream k("key.txt"), l("lock.txt");
	int n1 = 0, m1 = 0, n2 = 0, m2 = 0;
	int* ans = new int[2];
	bool b = true;
	k >> n2 >> m2;
	l >> n1 >> m1;
	int** key = new int*[n2];
	int** lock = new int*[n1];
	for (int i = 0; i < n2; i++)
		key[i] = new int[m2];
	for (int i = 0; i < n1; i++)
		lock[i] = new int[m1];
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m1; j++)
			l >> lock[i][j];
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			k >> key[i][j];
		}
	}
	 ans = openLock(lock, key, n1, m1, n2, m2);
	 if (ans[0] != -1)
	 {
		 cout << endl << "Coordinates: " << ans[0] << ' ' << ans[1];
		 return 0;
	 }
	 for (int i = 0; i < 4; i++)
	 {
		 rotate(lock, n1);
		 ans = openLock(lock, key, n1, m1, n2, m2);
		 if (ans[0] != -1)
		 {
			 cout << "Coordinates: " << ans[0] << ' ' << ans[1];
			 return -1;
		 }
		flipX(lock, n1, m1);
		ans = openLock(lock, key, n1, m1, n2, m2);
		if (ans[0] != -1)
		{
			cout << "Coordinates: " << ans[0] << ' ' << ans[1];
			return -1;
		}
		flipX(lock, n1, m1);
		flipY(lock, n1, m1);
		ans = openLock(lock, key, n1, m1, n2, m2);
		if (ans[0] != -1)
		{
			cout << "Coordinates: " << ans[0] << ' ' << ans[1];
			return -1;
		}
		flipY(lock, n1, m1);
	 }
	 
	 flipX(lock, n1, m1);
	 ans = openLock(lock, key, n1, m1, n2, m2);
	 if (ans[0] != -1)
	 {
		 cout << "Coordinates: " << ans[0] << ' ' << ans[1];
		 return 0;
	 }
	 flipX(lock, n1, m1);
	 flipY(lock, n1, m1);
	 if (ans[0] != -1)
	 {
		 cout << "Coordinates: " << ans[0] << ' ' << ans[1];
		 return 0;
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
