// Stars.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// задача со звездами
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

struct pt
{
	int x, y, id;
};

inline bool cmp_x(const pt & a, const pt & b)
{
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

inline bool cmp_y(const pt & a, const pt & b)
{
	return a.y < b.y;
}

const int MAXN = 10;
pt a[MAXN];
static pt t[MAXN];
double mindist;
int ansa, ansb;

inline void upd_uns(const pt & a, const pt & b)
{
	double dist = sqrt((a.x - b.x)* (a.x - b.x) + (a.y - b.y)*(a.y - b.y) + .0);
	if (dist < mindist)
		mindist = dist, ansa = a.id, ansb = b.id;
}

void rec(int l, int r)
{
	if (r - l <= 3)
	{
		for (int i = l; i <= r; ++i)
		{
			for (int j = i + 1; j <= r; ++j)
				upd_uns(a[i], a[j]);
		}
		sort(a + l, a + r + 1, &cmp_y);
	}
	int m = (l + r) >> 1;
	int midx = a[m].x;
	rec(l, m), rec(m + 1, r);
	
	merge(a+l, a + m + 1, a + m + 1, a+r+1, t, &cmp_y);
	copy(t, t + r - l + 1, a + l);

	int tsz = 0;
	for (int i = l; i <= r; ++i)
	{
		if (abs(a[i].x - midx) < mindist)
		{
			for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
				upd_uns(a[i], t[j]);
			t[tsz++] = a[i];
		}
	}
}

int main()
{
	srand(time(0));
	for (int i = 0; i < MAXN; i++)
	{
		a[i].x = (rand() % 10) * 10;
		a[i].y = (rand() % 10) * 10;
		a[i].id = i;
	}
	sort(a, a + MAXN, &cmp_x);
	cout << "Sort array: " << endl;
	for (int i = 0; i < MAXN; i++)
	{
		cout << "a[" << i << "].x=" << a[i].x << " a[" << i << "].y=" << a[i].y << endl;
	}
	mindist = 1e20;
	rec(0, MAXN - 1);
	cout << "mindist = " << mindist << endl;
	cout << "a=" << ansa << " b=" << ansb << endl;
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
