#include "pch.h"
#include <iostream>
#include <fstream>
#include <locale.h>
#include <string.h>

using namespace std;

const int STR_LENGTH = 80;

bool readLine(ifstream& in, char* buffer)
{
	buffer[0] = 0;
	in.getline(buffer, STR_LENGTH + 1, '\n');
	if (in.fail())
	{
		if (buffer[0] > 0)
			cout << "Слишком длинная строка во входном файле." << endl;
		return false;
	}
	return true;
}

void centerLine(char* buffer)
{
	int len = strlen(buffer);
	int shift = (STR_LENGTH - len) / 2;
	if (shift == 0)
		return;
	for (int i = len; i >= 0; i--)
		buffer[i + shift] = buffer[i];
	for (int i = 0; i < shift; i++)
		buffer[i] = ' ';
}

void rightLine(char* buffer)
{
	int len = strlen(buffer);

	int shift = STR_LENGTH;
	if (len == shift)
		return;

	buffer[shift--] = 0;
	for (int i = len; i >= 0; i--)
		buffer[shift--] = buffer[i];

	for (int i = 0; i <= shift; i++)
		buffer[i] = ' ';
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "Файл in.txt не существует" << endl;
		return -1;
	}
	ofstream out("out.txt");
	if (!out.is_open())
	{
		cout << "Невозможно создать выходной файл out.txt" << endl;
		return -2;
	}
	char buffer[STR_LENGTH + 1];
	int variant = 1;
	while (readLine(in, buffer))
	{
		switch (variant)
		{
		case 1:
			out << buffer << endl;
			variant++;
			break;
		case 2:
			centerLine(buffer);
			out << buffer << endl;
			variant++;
			break;
		case 3:
			rightLine(buffer);
			out << buffer << endl;
			variant = 1;
			break;
		}
	}
	return 0;
}
