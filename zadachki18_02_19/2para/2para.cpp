// 2para.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

unsigned long long intSqrt(unsigned long long num);
bool isPrime(unsigned long long num);
unsigned long long toInt(char* s);


int main()
{
	unsigned long long curPos = 0;
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "File does not exist";
		return -1;
	}

	char* s = new char[5];
	char c = ' ';
	for (int i = curPos; i < curPos + 10; i++)
	{
		c = in.get();
		s[i] = c;
	}
	curPos++; 
	in.seekg(curPos);
	while (!isPrime(toInt(s)) && !in.eof())
	{
		for (int i = 0; i < 10; i++)
		{
			c = in.get();
			if (c != '\n')
				s[i] = c;
			else i--;

		}
		curPos++;
		in.seekg(curPos);
		cout  <<toInt(s) << ' ' << isPrime(toInt(s)) << endl;
	}	
}


unsigned long long intSqrt(unsigned long long num)
{
	unsigned long long b = num;
	unsigned long long x = 1;
	unsigned long long x1 = (int)(0.5 * (x + (int)(b / x)));
	unsigned long long x2 = 0;
	while (x2 != x1) {
		x2 = x;
		x = x1;
		x1 = (unsigned long long)(0.5 * (x + (unsigned long long)(b / x)));
		//cout << "intSqrt call: " << num << endl;
	}
	return x1;
}

bool isPrime(unsigned long long num)
{
	unsigned long long divider = 1;
	while (divider <= intSqrt(num))
	{
		//cout << "isPrime call: " << num << endl;
		divider++;
		if (num % divider == 0)
		{

			return false;
		}
	}
	return true;
}

unsigned long long toInt(char* s)
{
	//int ans = 0;
	if (s[0] - 48 != 0)
		return (s[0] - 48) * (unsigned long long)1e9 + (s[1] - 48) * (unsigned long long) 1e8 + (s[2] - 48) * (unsigned long long) 1e7 + (s[3] - 48) * 1e6 + (s[4] - 48) * 1e5 + (s[5] - 48) * 1e4 + (s[6] - 48) * 1e3 + (s[7] - 48) * 1e2 + (s[8] - 48) * 1e1 + (s[9] - 48);
	else return 4;
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
