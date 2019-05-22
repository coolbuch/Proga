// MatrixTransponir.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;
int main(void)
{
	setlocale(LC_ALL, "Russian");
	const int MAX_SIZE = 20;
	int m, n;
	double matrix[MAX_SIZE][MAX_SIZE];
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "Файл in.txt не существует" << endl;
		return -1;
	}
	in >> m >> n;
	if (in.fail() || m<1 || m>MAX_SIZE ||
		n<1 || n>MAX_SIZE)
	{
		cout << "Некорректные размерности" << endl;
		return -2;
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			in >> matrix[i][j];
	if (in.fail())
	{
		cout << "Не удалось прочитать матрицу" << endl;
		return -3;
	}
	ofstream out("out.txt");
	if (!out.is_open())
	{
		cout << "Не удалось создать файл out.txt" << endl;
		return -4;
	}
	out << m << '\t' << n;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
			out << matrix[i][j] << " ";
		out << endl;
	}
	cout << "Выполнено" << endl;
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
