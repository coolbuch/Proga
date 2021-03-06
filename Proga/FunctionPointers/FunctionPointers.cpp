// FunctionPointers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int mul(int n1, int n2) { return n1 * n2; }
int sub(int n1, int n2) { return n1 - n2; }
int divn(int n1, int n2) 
{ if (!n2) return 0; 
	else return n1 / n2; 
};
int add(int n1, int n2) { return n1 + n2; };
int fastPow(int n1, int pow) 
{
	if (pow == 0)
	{
		return 1;
	}
	if (pow == 1)
	{
		return n1;
	}
	if (pow % 2 == 1)
	{
		return fastPow(n1, pow - 1) * n1;
	}
	else
	{
		return fastPow(n1 * n1, pow / 2);
	}
};
int bals(int n1, int n2) {
	if (n2 != 0)
		return n1 % n2; 
	else return 0;
};
int calculate(int n1, int n2, int(*func)(int, int)) { return func(n1, n2); };
void removeSpaces(char* buf)
{
	int size = sizeof(buf) / sizeof(buf[0]);
	for (int i = 0; i < sizeof(buf) / sizeof(buf[0]); i++)
	{
		if (buf[i] == ' ')
			for (int j = i; j < size - i; j++)
			{
				for (int k = j; j < size - i; k++)
				{
					char tmp = buf[k];
					buf[k] = buf[j];
					buf[j] = tmp;
				}
			}
	}
}

bool checkStr(char ch)
{
	if (ch == '-') return true;
	return false;
}

int main()
{
	int(*functions[])(int, int) = { mul, sub, divn, add, fastPow, bals };
	char signs[] = { '*', '-', '/', '+', '^', '%' };
	char sign = '\0';
	char* buf = new char[200], *buf2 = new char[10];
	for (int i = 0; i < 10; i++)
		buf2[i] = ' ';
	char check[2];
	bool exit = true,  wrong  = false;
	cout << "You can use these operators: +, -, *, /, ^, %" << endl;
	cout << "Enter an expression like <Number> <sign> <Number>" << endl << flush;
	int num1, num2;
	do
	{
		char *endprt;
		cin.getline(buf, 200, '\n');
		int j = 0;
		while (buf[j] == ' ')
		{
			j++;
		}
		check[0] = buf[j];
		check[1] = '\0';
		if (!strcmp("q", &check[0]))
			exit = false;
		num1 = strtod(buf, &endprt);
		while (*endprt == ' ')
			endprt++;
		sign = *endprt++;
		cout << endl << '\'' << sign << '\'' << ' ' << endprt << endl;

		num2 = strtod(buf2, &buf2);
		if (wrong)
		{
			if (exit) 
				cout << "Incorrect input " << endl;
			wrong = false;
			continue;
		}
		int i;
		cout << num1 << ' ' << sign << ' ' << num2 << ' ';
		for (i = 0; i < 6; i++)
		{
			if (sign == signs[i])
			{
				if (sign == '^'&& num2 < 0)
				{
					cout << "wrong power" << endl;
					break;
				}
				if ((sign == '/' || sign == '%') && num2 == 0)
				{
					cout<< ' ' << "division by zero " << endl;
				}
				else
					cout << "=" << calculate(num1, num2, functions[i]) << endl;
				break;
			}
			if (i == 5 && exit)
				cout << "Wrong sign " << endl;
		}
	} while (exit);
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
