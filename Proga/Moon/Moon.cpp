// Moon.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include <fstream>
using namespace std;
int year = 0, month = 0, day = 0;
// функция проверяет, является ли символ числом
bool isNumeric(char s);
// функция для проверки, входит число в интервал или нет
bool checkInterval(int number, int lower, int higher);
// функция для проверки даты, введенной пользователем
bool check(char* st, int mode);
// функция возвращает n символов начиная с указателя data
char* getSymbols(char* data, int n);
// функция для парсинга даты и некоторых проверок
bool isRightDateFormat(string s);
// функция ввода
string userInput();


int main()
{
	string s;
	char* time1 = new char[9];
	char* data;
	char* i;
	char* maxElTime;

	double elevation, azimut;
	double prevElevation;
	float maxElevation, maxAzimut;

	unsigned long long size = 0;
	cout << "Input date like DD.MM.YYYY" << endl;
	while (true)
	{
		year = 0, month = 0, day = 0;
		elevation = 0; azimut = 0;
		s = userInput();
		int start = clock();
		// считывание файла
		ifstream in("moon" + to_string(year) + ".dat", ios::binary);
		if (!in.is_open())
		{
			cout << "File does not exists" << endl;
			continue;
		}
		if (in.is_open())
		{
			in.seekg(0, ios::end);
			size = in.tellg();
			in.seekg(0, ios::beg);
			data = new char[size + 1];
			data[size] = '/0';
			in.read(data, size);
			// приводим дату в нужный формат
			string date = to_string(year) + ((month < 10) ? "0" : "") + to_string(month) + ((day < 10) ? "0" : "") + to_string(day);
			i = strstr(data, date.c_str());
			prevElevation = elevation;
			maxElevation = 0;
			maxElTime = new char[7];
			maxElTime[6] = '\0';
			while (i != NULL)
			{
				time1 = getSymbols(i + 9, 6);
				time1[6] = '\0';
				prevElevation = elevation;
				elevation = atof(getSymbols(i + 36, 7));
				if (maxElevation < elevation)
				{
					maxElevation = elevation;
					maxElTime = time1;
					maxAzimut = azimut;
				}
				azimut = atof(getSymbols(i + 45, 7));
				if (prevElevation < 0 && elevation >= 0)
					cout << "Rising time: " << time1[0] << time1[1] << ':' << time1[2] << time1[3] << ':' << time1[4] << time1[5] << " on azimut: " << azimut << endl;
				if (prevElevation > 0 && elevation <= 0)
					cout << "Setting time: " << time1[0] << time1[1] << ':' << time1[2] << time1[3] << ':' << time1[4] << time1[5] << " on azimut: " << azimut << endl;
				i++;
				i = strstr(i, date.c_str());
			}
			int end = clock();
			cout << "Max elevation: " << maxElevation << " on time: " << maxElTime[0] << maxElTime[1] << ':' << maxElTime[2] << maxElTime[3] << ':' << maxElTime[4] << maxElTime[5] << " on azimut " << maxAzimut << endl;
			cout << "time " << ((float)end - start) / CLOCKS_PER_SEC << endl;
		}
		in.close();
	}
}
//КОНЕЦ main

bool isNumeric(char s)
{
	if (s < '0' || s > '9')
		return false;
	return true;
}

bool checkInterval(int number, int lower, int higher)
{
	if (number < lower || number > higher)
		return true;
	return false;
}

bool check(char* st, int mode)
{
	if (!mode)
	{
		if (checkInterval(atoi(st), 1, 12))
			return true;
	}
	if (mode)
	{
		switch (month)
		{
		case 1:
			if (checkInterval(atoi(st), 1, 31))
				return true;
			break;
		case 2:
			if (checkInterval(atoi(st), 1, 28) || (atoi(st) == 29 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))))
				return true;
			break;
		case 3:
			if (checkInterval(atoi(st), 1, 31))
				return true;
			break;
		case 4:
			if (checkInterval(atoi(st), 1, 30))
				return true;
			break;
		case 5:
			if (checkInterval(atoi(st), 1, 31))
				return true;
			break;
		case 6:
			if (checkInterval(atoi(st), 1, 30))
				return true;
			break;
		case 7:
			if (checkInterval(atoi(st), 1, 31))
				return true;
			break;
		case 8:
			if (checkInterval(atoi(st), 1, 31))
				return true;
			break;
		case 9:
			if (checkInterval(atoi(st), 1, 30))
				return true;
			break;
		case 10:
			if (checkInterval(atoi(st), 1, 31))
				return true;
			break;
		case 11:
			if (checkInterval(atoi(st), 1, 30))
				return true;
			break;
		case 12:
			if (checkInterval(atoi(st), 1, 31))
				return true;
			break;
		}
	}
	return false;
}

string userInput()
{
	string out = "";
	do
	{
		cout << "Enter date: " << endl << flush;
		getline(cin, out);
	} while (!isRightDateFormat(out));
	return out;
}

bool isRightDateFormat(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (!isNumeric(s[i]))
		{
			if (s[i] != '.')
			{
				cout << "incorrect date ";
				return false;
			}
		}
	bool exit = false;
	char* ch = new char[5];
	ch[4] = '\0';
	if (s.size() != 10)
		return false;
	if (isNumeric(s[9]) && isNumeric(s[8]) && isNumeric(s[7]) && isNumeric(s[6]))
	{
		exit = true;
		if (isNumeric(s[4]) && isNumeric(s[3]))
			if (isNumeric(s[1]) && isNumeric(s[0]))
			{
				ch[0] = s[6];
				ch[1] = s[7];
				ch[2] = s[8];
				ch[3] = s[9];
				year = atoi(ch);
				ch[0] = s[3];
				ch[1] = s[4];
				ch[2] = '\0';
				if (check(ch, 0))
					exit = false;
				month = atoi(ch);
				ch[0] = s[0];
				ch[1] = s[1];
				day = atoi(ch);
				if (month == 2 && day == 29 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
					return true;
				if (check(ch, 1))
					exit = false;
			}
	}
	if (!exit)
		cout << "incorrect date " << endl;
	return exit;
}

char* getSymbols(char* data, int n)
{
	char* ret = new char[n];
	for (int i = 0; i < n; i++)
	{
		ret[i] = data[i];
	}
	return ret;
}


