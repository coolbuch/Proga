// fastPow.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cassert>
#include <vector>
#include "Matrix.h"
using namespace std;
int k = 0;


int fastPow(int n, int pow);
int summ(int m);
void init(unsigned long long** a, int n, int m);
void printMatrix(Matrix &mat);
void enterMatrix(unsigned long long** arr, int n, int m);
Matrix* fastPow(Matrix* mat, int pow);
void fibNum();
void mulMatrixes();

int main()
{
	bool mode = 0;
	cout << "Enter" << endl << "1 if you want to multification 2 matrixes" << endl
		<< "0 if you want to find N fibbonachi number" << endl;
	cin >> mode;
	if (mode)
	{
		mulMatrixes();
	}
	else
	{
		fibNum();
	}

}

void mulMatrixes()
{
	int n = 0, m = 0, n1 = 0, m1 = 0, pow = 0;
	unsigned long long ** arr = new unsigned long long*[n];
	unsigned long long ** arr2 = new unsigned long long*[n];

	cout << "Matrix 1. Enter n, m: ";
	cin >> n >> m;

	init(arr, n, m);
	enterMatrix(arr, n, m);
	Matrix matrix(arr, n, m);

	cout << "Matrix 2. Enter n, m: ";
	cin >> n >> m;
	init(arr2, n, m);
	enterMatrix(arr2, n, m);
	Matrix matrix2(arr2, n, m);

	cout << endl << "Answer : " << endl;
	printMatrix(*matrix.mul(matrix2));

	/*for (int i = 0; i < n; i++)
	{
		if (arr[i])
			delete[] arr[i];
	}
	delete[] arr;
	for (int i = 0; i < m; i++)
		if (arr2[i])
			delete[] arr2[i];
	delete[] arr2;*/
}

void fibNum()
{
	int pow = 0;
	cout << endl << "Pow : ";
	cin >> pow;

	//--------------Матрица для поиска чисел Фиббоначи--------------------
	unsigned long long ** fibData = new unsigned long long*[2];
	fibData[0] = new unsigned long long[2];
	fibData[1] = new unsigned long long[2];
	fibData[0][0] = 0;
	fibData[0][1] = 1;
	fibData[1][0] = 1;
	fibData[1][1] = 1;
	Matrix fibMatrix(fibData, 2, 2);
	//--------------Вектор для поиска чисел фиббоначи----------------------
	unsigned long long **vector = new unsigned long long*[2];
	vector[0] = new unsigned long long[1];
	vector[1] = new unsigned long long[1];
	vector[0][0] = 1;
	vector[1][0] = 1;
	Matrix vect(vector, 2, 1);
	// Вывод фибоначи
	printMatrix(*(*fastPow(&fibMatrix, pow)).mul(vect));
	for (int i = 0; i < 2; i++)
	{
		if (fibData[i])
			delete[] fibData[i];
		if (vector[i])
			delete[] vector[i];


	}
	delete[] fibData;
	delete[] vector;
}
void enterMatrix(unsigned long long** arr, int n, int m)
{
	cout << endl << "Enter matrix, " << n << '*' << m << endl;
	for (unsigned long long i = 0; i < n; i++)
	{
		for (unsigned long long j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void init(unsigned long long** a, int n, int m)
{

	for (unsigned long long i = 0; i < n; i++)
	{
		a[i] = new unsigned long long[m];
		for (unsigned long long j = 0; j < m; j++)
			a[i][j] = 0;
	}
}

void printMatrix(Matrix &mat)
{
	unsigned long long n = mat.n;
	unsigned long long m = mat.m;
	for (unsigned long long i = 0; i < n; i++)
	{
		for (unsigned long long j = 0; j < m; j++)
			cout << mat.data[i][j] << ' ';
		cout << endl;
	}
}

Matrix* fastPow(Matrix* mat, int pow)
{
	if (pow == 1)
		return mat;
	if (pow % 2 == 1)
		return mat->mul(*fastPow(mat, pow - 2));
	else
		return fastPow(mat->mul(*mat), pow / 2);
}

int fastPow(int n, int pow)
{
	if (pow == 0)
	{
		return 1;
	}
	if (pow == 1)
	{
		return n;
	}
	k++;
	if (pow % 2 == 1)
	{
		return n * fastPow(n, pow - 1);
	}
	else
	{
		return fastPow(n * n, pow / 2);
	}
}

int summ(int m)
{
	if (m < 10)
		return m;
	else
	{
		return summ(m / 10) + m % 10;
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
