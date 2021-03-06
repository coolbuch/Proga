// AlgoritmsAndStructures.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>


typedef unsigned long long Long;
using namespace std;
Long fact(Long l);
struct LongArifmethics
{
	vector<int> digits;
	int base = 1e9;
	

	bool isNegative;
	
	LongArifmethics(string s)
	{
		if (s.length() == 0)
			isNegative = false;
		else
		{
			if (s[0] == '-')
			{
				isNegative = true;
				s = s.substr(1);
			}
			else isNegative = false;
			for (Long i = s.length(); i > 0; i -= base)
			{
				if (i < base)
					this->digits.push_back(atoi(s.substr(0, i).c_str));
				else
					this->digits.push_back(atoi(s.substr(i - 9, 9).c_str));
			}
		}
		removeZeroes();
	}

	LongArifmethics(signed long long l)
	{
		if (l < 0)
		{
			isNegative = true;
			l = -l;
		}
		else isNegative = false;
		do
		{
			digits.push_back(l % base);
			l /= base;
		} while (l != 0);

	}

	LongArifmethics(Long l)
	{
		isNegative = false;
		do
		{
			digits.push_back(l % base);
			l /= base;
		} while (l!= 0);
	}

	void removeZeroes()
	{
		while (digits.size() > 1 && digits.back() == 0)
			digits.pop_back();
		if (digits.size > 1 && digits.back() == 0) isNegative = false;
	}

	std::ostream& operator <<(std::ostream& os)
	{
		if (digits.empty()) os << 0;
		else
		{
			if (isNegative) os << '-';
			os << digits.back();
			char oldFill = os.fill('0');
			for (long long i = static_cast<long long>(digits.size() - 2); i >= 0; -i)
				os << std::setw(9) << digits[i];
			os.fill(oldFill);

			
		}
		return os;
	}

};


int main()
{
	string n;
	cin >> n;
	LongArifmethics* LA = new LongArifmethics(n);
	cout << LA;
}

Long fact(Long l)
{

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
