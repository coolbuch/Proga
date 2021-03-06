// taskForTime.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
// ЗАДАЧА №3 Дважды три	
char* toThree(int num);
unsigned long long toDec(char* s);
int myPow(int num, int pow);


int main()
{
	unsigned long long n = 0;
	cin >> n;
	while (n <= 0 || n > 200)
		cin >> n;
	cout << endl << toDec(toThree(n)) << endl;
	

}


int myPow(int num, int pow)
{
	if (pow != 0)
	{
		int f = num;
		for (int i = 0; i < pow - 1; i++)
		{
			num *= f;
		}
		return num;
	}
	else
		return 1;
}
unsigned long long toDec(char* s)
{
	unsigned long long out = 0;
	int count = strlen(s);
	cout << s << endl;
	for (int i = count - 1; i>= 0; i--)
	{
		out += (s[i] - 48) * myPow(3, count - i - 1); 
	}
	return out;
}

char* toThree(int num)
{
	char* out = new char[10];
	for (int i = 0; i < 10; i++)
	{
		out[i] = 'a';
	}
	out[9] = '\0';
	int i = 8;
	while (num > 0)
	{
		out[i] = (num % 3) + 48;
		num /= 3;
		i--;
	}
	char* c = new char[30];
	int j = 0;
	i = 0;
	for (i = 0, j = 0; i < 10; i++)
	{
		if (out[i] != 'a')
		{
			c[j] = out[i];
			c[j + 1] = out[i];
			j += 2;
		}
	}
	c[j] = '\0';
	return c;
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
