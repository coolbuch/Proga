// Moon.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

struct Date {
	int year, month, day;
	Date()
	{
		year = 0;
		month = 1;
		day = 1;
	}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}

	void setDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};

void enterDate(Date d)
{
	char* buf = new char[20];
	char *res = new char[5];
	int date[3];
	cout << "Enter date like YYYY.MM.DD";
	cin.getline(buf, 10);
	int j = 0, counter = 0;
	for (int i = 0; i < 3; i++)
	{
		while (buf[j] != '.')
		{
			res[counter] = buf[j];
			j++;
			counter++;
		}
		date[i % 3] = atoi(res);
	}
	d.setDate(date[0], date[1], date[2]);
}

int main()
{
	Date* userDate = new Date();
	enterDate(*userDate);
	cout << userDate->year << '.' << userDate->month << '.' <<userDate->day;
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
