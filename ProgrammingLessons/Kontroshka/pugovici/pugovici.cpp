// pugovici.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int intSqrt(int num)
{
	int b = num;
	int x = 1;
	unsigned long x1 = (int)(0.5 * (x + (int)(b / x)));
	int x2 = 0;
	while (x2 != x1) {
		x2 = x;
		x = x1;
		x1 = (int)(0.5 * (x + (int)(b / x)));
		cout << "intSqrt call: " << num << endl;
	}
	return x1;
}

struct Point
{
	int x, y;
	double minDist = INT_MAX;
	Point* pair;
	double getDistance(Point p)
	{
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
	void setPair(Point* p)
	{
		pair = p;
	}
};

void printArr(Point* arr, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].x << ' ' << arr[i].y << endl;
	}
}

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	bool allPairs = false;
	int n = 0;
	in >> n;
	Point* first = new Point[n];
	Point* second = new Point[n];
	for (int i = 0; i < n; i++)
	{
		in >> first[i].x >> first[i].y;
		in >> second[i].x >> second[i].y;
	}
	printArr(first, n);
	printArr(second, n);
	while (!allPairs)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				double cur =  first[i].getDistance(second[j]);
				if (first[i].minDist > cur)
					first[i].minDist = cur;
			}
		}
	}
	return 0;
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
