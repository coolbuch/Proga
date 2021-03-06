// Kontroshka.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int stringlen(char* buf)
{
	int i = 0;
	while (*(buf + i++));
	return i - 1;
}

void mstrcpy(char* c1, char* c2)
{
	int i = 0;
	while (*(c1 + i))
	{
		*(c2 + i) = *(c1 + i);
		i++;
	}
}

void mstrcat(char* c1, char* c2)
{
	int i = 0, len = stringlen(c1);
	while (*(c2 + i))
	{
		*(c1 + i + len) = *(c2 + i);
		i++;
	}
}

int mstrcmp(char* c1, char* c2)
{
	int i = 0;

	while (*(c1 + i) || *(c2 + i))
	{
		//cout << *(c1 + i) << ' ' << *(c2 + i) << endl;
		if (*(c1 + i) > *(c2 + i)) 
			return 1;
		else if (*(c1 + i) < *(c2 + i)) 
			return -1;
		i++;
	}

	if (stringlen(c1) > stringlen(c2))
		return 1;
	else if (stringlen(c1) < stringlen(c2))
		return -1;

	return 0;
}

char* left(char* c, int n)
{
	int i = 0;
	char* out = new char[n];
	while (*(c + i) && i < n)
	{
		*(out + i) = *(c + i);
		i++;
	}
	*(out + i) = '\0';
	return out;
}

char* right(char* c, int n)
{
	int i = 0;
	char* out = new char[n];
	while (*(c + i))
	{
		*(out + n - i) = *(c + stringlen(c) - i);
		i++;
	}
	return out;
}

char* mid(char* c, int first, int n)
{
	int i = 0;
	char* out = new char[n];
	while (*(c + i) && i < n)
	{
		*(out + i) = *(c + first + i);
		i++;
	}
	*(out + i) = '\0';
	return out;
}

int instr(char* c1, char* c2, int n)
{
	int i = n, j = 0, find = 0;
	while (*(c1 + i))
	{
		int k = 0;
		j = i;
		while (*(c1 + j) && *(c2 + k) && j < i + stringlen(c2))
		{
			if (*(c1 + j) == *(c2 + k))
				k++;
			j++;
			if (k == stringlen(c2))
				return i;
		}
		i++;
	}
	return -1;
}

int rinstr(char* c1, char* c2, int n)
{
	int i = n, j = 0;
	while (*(c1 + i) && i > -1)
	{
		int k = 0;
		j = i;
		while (*(c1 + j) && *(c2 + k) && j < i + stringlen(c2))
		{
			if (*(c1 + j) == *(c2 + k))
				k++;
			j++;
			if (k == stringlen(c2)) return i;
		}
		i--;
	}
	return -1;
}

int main()
{
	char st[20] = {'a','b','c','c'};
	char st2[10]; char st3[4] = {'a'};
	//char* c = &st[10];
	//cout << c;
	//cout << stringlen(st) << endl;
	//mstrcpy(st, st2);
	//cout << "st2 ";
	//for (int i = 0; i < 9; i++)
	///{
	//	cout << *(st2 + i);
	//}
	//cout << endl;
	//mstrcat(st, st3);
	//cout << "st ";
	for (int i = 0; i < 20; i++)
	{
		cout << *(st + i);
	}
	
	cout << endl << rinstr(st, st3,strlen(st) - 1) << endl;
	//char* s = left(st, 2);
	//cout << stringlen(s) << endl;
	//for (int i = 0; *(s + i) != 0; i++)
	//{
	//	cout << *(s + i);
	//}	
	//s = right(st, 5);
	//cout << endl;
	//for (int i = 0; *(s + i) != 0; i++)
	//{
	//	cout << *(s + i);
	//}
	//s = mid(st, 5, 2);
	//cout << endl;
	////for (int i = 0; *(s + i) != 0; i++)
	
	//	cout << *(s + i);
	//}
	//char s2[2] = { '3' };
	//cout << endl << instr(st, s2, 0);
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
