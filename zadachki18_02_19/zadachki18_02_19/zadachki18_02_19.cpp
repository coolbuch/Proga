// zadachki18_02_19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;



int main()
{
	string s = "";
	int* numbers = new int[20];
	getline(cin ,s);
	int simbol = 10, sum = 0, wrongNum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] - 48 >= 0 && s[i] - 48 < 10 || s[i] - 88 == 0 || s[i] - 120 == 0)
		{
			//cout << s[i] << ' ' << s[i] - 48 << endl;
			
			if (s[i] - 88 != 0 && s[i] - 120 != 0)
			{
				sum += simbol * (s[i] - 48);
				numbers[simbol - 1] = s[i] - 48;
			}
			else
			{
				sum += simbol * 10;
				numbers[simbol - 1] = 10;
			}
			simbol--;
			
		}
	}
	

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
