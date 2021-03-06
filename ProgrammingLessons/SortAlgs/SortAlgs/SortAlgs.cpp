// SortAlgs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <time.h>
#include <stdio.h>
using namespace std;
ifstream in("in.txt");
ofstream out("inputArray.txt");

void printArray(int arr[], int size, bool b) // b = true - нумерация
{
	for (int i = 0; i < size; i++)
	{
		if (b)
			cout << i << ". ";
		cout << arr[i] << endl;
	}
}

void InsertionSort(int *arr, int size)
{
	int buf;
	int i, j;
	for (i = 1; i < size; i++)
	{
		buf = arr[i];
		for (j = i - 1; j >= 0 && buf < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = buf;
	}
	
}

void heapSort(int *arr, int size)
{
	int buf;
	for (int i = size; i > 1; i--)
	{
		bool flag = false;
		int sh = 0;
		for (int j = 0; j < i / 2;)
		{
			int largest = j, left = 2 * j + 1, right = 2 * j + 2;
			if (arr[left] > arr[largest])
			{
				buf = arr[left];
				arr[left] = arr[largest];
				arr[largest] = buf;
				flag = true;
			}
			if (right < i)
			{
				if (arr[right] > arr[largest])
				{
					buf = arr[right];
					arr[right] = arr[largest];
					arr[largest] = buf;
					flag = true;
				}
			}
			if (flag && j > 0)
			{
				j = (j - 1) / 2;
				sh++;
				flag = false;
			}
			else
			{
				j = j + 1 + sh;
				sh = 0;
			}
		}
		buf = arr[i - 1];
		arr[i - 1] = arr[0];
		arr[0] = buf;
	}
}

void fastSort(int *arr, int first, int last)
{
	int i = first, j = last;
	int buf, comp;
	comp = arr[(first + last) / 2];
	do
	{
		while (arr[i] < comp && i < last)
			i++;
		while (arr[j] > comp && j > first)
			j--;
		if (i <= j)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
			i++; j--;
		}
	} while (i <= j);
	if (first < j)
		fastSort(arr, first, j);
	if (i < last)
		fastSort(arr, i, last);
}

void blockSort(int *arr, int n)
{
	int **b = new int*[n];
	int *k = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		b[i] = new int[n];
		k[i] = 0;
		
		cout << "kek" << endl;
	}

	for (int i = 0; i < n; i++)
	{
		int x = arr[i] / 10;
		b[x][k[x]++] = arr[i];
		printArray(b[i], n, true);
		//cout << "kek1" << endl;
	}

	for (int i = 0; i < n; i++)
	{
		heapSort(b[i], k[i] - 1);
		//fastSort(b[i], 0, k[i] - 1);
		//cout << "kek2" << endl;
	}
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k[i]; j++)
		{
			arr[index] = b[i][j];
			index++;
		}
		//cout << "kek3" << endl;
	}
}

void mergeSort(int arr[], int size)
{
	int i, j, lbi, rbi, mi, lb, mb, rb;
	for (i = 1; i < size; i *= 2)
	{
		for (j = 0; j < size - i; j += 2 * i)
		{
			lbi = 0;
			rbi = 0;
			lb = j;
			mb = j + i;
			rb = j + 2 * i;
			rb = (rb < size) ? rb : size;
			int* SortedBlock = new int[rb - lb];
			while (lb + lbi < mb && mb + rbi < rb)
			{
				if (arr[lb + lbi] < arr[mb + rbi])
				{
					SortedBlock[lbi + rbi] = arr[lb + lbi];
					lbi++;
				}
				else
				{
					SortedBlock[lbi + rbi] = arr[mb + rbi];
					rbi++;
				}
			}
			while (lb + lbi < mb)
			{
				SortedBlock[lbi + rbi] = arr[lb + lbi];
				lbi++;
			}
			while (mb + rbi < rb)
			{
				SortedBlock[lbi + rbi] = arr[mb + rbi];
				rbi++;
			}
			for (mi = 0; mi < lbi + rbi; mi++)
				arr[lb + mi] = SortedBlock[mi];
			delete SortedBlock;

		}
	}
}

void generateFile(int n)
{
	
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		out << rand() % 10 << endl;
	}
	//system("pause");
}

void rewriteArr(int n, int *arr)
{
	for (int i = 0; i < n; i++)
	{
		in >> arr[i];
		//cout << arr[i];
		if (i % 10000 == 0) cout << i << ' ';
	}
	cout << endl;
}

int main()
{
	
	int task = 0;
	int n = 30;
	clock_t start, stop;
	generateFile(n);
	system("pause");
	//cout << "Enter task number: ";
	//cin >> task;
	int* arr = new int[n];
	int* copyArr = new int[n];
	//if (task == 1)
	//{
	start = clock();
	rewriteArr(n, arr);
	
	copyArr = arr;
	stop = clock();
	//cout << "Input time: " << (stop - start) / CLK_TCK << endl;
	// Вставки
	/*start = clock();
	InsertionSort(arr, n);
	stop = clock();
	
	cout << "Insertion sort time(10^5 random elements) = " << (stop - start) / CLK_TCK << endl;
	delete[] arr;
	arr = nullptr;
	//HEAP
	arr = new int[n];
	rewriteArr(n, arr);*/
	/*start = clock();
	heapSort(arr, n);
	stop = clock();
	cout << "Heap sort time(10^5 random elements) = " << (stop - start) / CLK_TCK << endl;
	delete arr;
	arr = nullptr;
	//Быстрая
	arr = new int[n];
	rewriteArr(n, arr);*/
	/*start = clock();
	fastSort(arr, 0, n - 1);
	stop = clock();
	cout << "Quick sort time(10^5 random elements) = " << (stop - start) / CLK_TCK << endl;
	delete arr;
	arr = nullptr;*/
	// Блочная
	//arr = new int[n];
	//rewriteArr(n, arr);
	start = clock();
	blockSort(arr, n);
	stop = clock();
	cout << "Bucket sort time(10^5 random elements) = " << (stop - start) / CLK_TCK << endl;
	/*delete arr;
	arr = nullptr;
	// Слияние
	arr = new int[n];
	rewriteArr(n, arr);
	start = clock();
	mergeSort(copyArr, n);
	stop = clock();
	cout << "Merge sort time(10^5 random elements) = " << (stop - start) / CLK_TCK << endl;
	*/
	return 0;
	//}
	//if (task == 2)
	//{
	//	int n = 0;
	//	cin >> n;
	//	int* arr = new int[n];
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << ' ';
	//}
	//return 0;
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
