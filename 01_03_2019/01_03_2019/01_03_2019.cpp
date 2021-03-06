// 01_03_2019.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
// Дан 1 байт ( 1 символ ) сгенерить его двоичное представление
void print(char* c);
char* toBinary(char c);
void encode(char* input, char* out1, char* out2);
int getbit(char a, int i);
int setbit(char a, int i);


int main()
{	
	char c = '0';
	char* arr = new char[8];
	char* c1 = new char[8], *c2 = new char[8];
	arr = toBinary(c);
	print(arr);
	encode(arr, c1, c2);

}

void print(char* c)
{
	char binary[8] = { 1,2,4,8,16,32,64,128 };
	for (int i = 0; i < 8; i++)
	{
		cout << (int)c[i];
	}
}

char* toBinary(char c)
{
	char binary[8] = { 1,2,4,8,16,32,64,128 };
	char *out = new char[8];
	for (int i = 7; i >= 0; i--)
	{
		out[i] = (c&binary[i]) / binary[i];

	}
	return out;
}

int getbit(char a, int i)
{
	return a & (1 << i) ? 1 : 0;
}

int setbit(char a, int i)
{
	return 0;
}

void encode(char* input, char* out1, char* out2)
{
	cout << endl << getbit(input[3], 8);
}


