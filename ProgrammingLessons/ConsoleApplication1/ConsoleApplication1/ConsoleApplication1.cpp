// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "Move time, rest time: ";
	int duration, restTime, start = 7 * 60, end = 19 * 60;
	
	cin >> duration;
	cin >> restTime;
	int usedTime = start;
	cout << "  A " << "      " << " B" << endl;
	while (start + 2 * duration + restTime < end)
	{
		cout << setw(2) << setfill('0') << start / 60 << ':' << setw(2) << setfill('0') << start % 60<< " -> ";
		cout << setw(2) << setfill('0') << (start + duration) / 60 << ':' << setw(2) << setfill('0') << (start + duration) % 60 << endl;

		start += duration + restTime;

		cout << setw(2) << setfill('0') << start / 60 << ':' << setw(2) << setfill('0') << start % 60 << " <- ";
		cout << setw(2) << setfill('0') << (start + duration) / 60 << ':' << setw(2) << setfill('0') << (start + duration) % 60 << endl;
		start += duration + restTime;
	}
	
	return 0;
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
