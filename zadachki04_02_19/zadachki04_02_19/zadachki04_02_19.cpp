
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;	
int main()
{
	int n = 0;
	cin >> n;
    int num = 0;
	string st = "", out = "";
	int i = 0;
	if (n / 1000 != 0)
	{
		for (i = 0; i < n / 1000; i++)
			st += "M";
		n -= 1000 * i;
	}
	if (n / 500 != 0 && n % 1000 < 899)
	{
		for (i = 0; i < n / 500; i++)
			st += "D";
		n -= 500 * i;
	} 
	else if (n % 1000 > 899)
	{
		st += "CM";
		n -= 900;
	}
	if (n / 100 != 0 && n % 500 < 399)
	{
		for (i = 0; i < n / 100; i++)
			st += "C";
		n -= 100 * i;
	}
	else if (n % 500 > 399)
	{
		st += "CD";
		n -= 400;
	}
	if (n / 50 != 0 && n % 100 < 89)
	{
		for (i = 0; i < n / 50; i++)
			st += "L";
		n -= i * 50;
	}
	else if (n % 100 > 89)
	{
		st += "XC";
		n -= 90;
	}
	if (n / 10 != 0 && n % 50 < 39)
	{
		for (i = 0; i < n / 10; i++)
			st += "X";
		n -= i * 10;
	}
	else if (n % 50 > 39)
	{
		st += "XL";
		n -= 40;
	}
	cout << n << endl;
	if (n / 5 != 0 && n % 10 < 7)
	{
		for (i = 0; i < n / 5; i++)
			st += "V";
		n -= i * 5;
	}
	else if (n % 10 > 8)
	{
		st += "IX";
		n -= 9;
	}
	//cout << n << endl;
	if (n % 5 > 3)
	{
		st += "IV";
		n -= 4;
	}
	cout << st << ' ' << n;;
}


