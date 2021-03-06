// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <cassert>
using namespace std;

void mySort(int* arr, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		for (int j = 0; j < end; j++)
			if (arr[i] >= arr[j]) swap(arr[j], arr[i]);
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
void printArray(int arr[], int size, bool b) // b = true - нумерация
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (b)
			cout << i << ". ";
		cout << arr[i] << endl;
	}
}
void printMatrix(int* arr, int n, int m, bool b)
{
	cout << endl;
	if (b)
	{
		cout << "   ";
		for (int i = 0; i < m; i++) cout << i << " ";
		cout << endl;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (b)
			cout << i << ". ";
		for (int j = 0; j < m; j++)
		{
			
			cout << arr[i * n + j]  << " ";
		}
		cout << endl;
	}
}
void findSame(int arr[], int size)
{
	int buf = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] == buf)
			arr[i - 1] = 0;
		else buf = arr[i];
	}
}
int* findSame2(int* arr, int size)
{
	int* out = new int[size];
	int buf = arr[0], outCount = 1;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] == buf)
		{
			out[outCount++] = arr[i - 1];
			arr[i - 1] = 0;
			
		}
		else buf = arr[i];
	}
	out[0] = outCount;
	return out;
}
int intSqrt(int num)
{
	int b = num;
	int x = 1;
	unsigned long x1 = (int)(0.5 * (x + (int)(b / x)));
	int x2 = 0;
	while (x2 != x1) {
		x2 = x;
		x = x1;
		x1 = (int)(0.5 * (x + (int)(b / x)));
		//cout << "intSqrt call: " << num << endl;
	}
	return x1;
}
bool isPrime(int num)
{
	int divider = 1;
	while (divider <= intSqrt(num))
	{
		//cout << "isPrime call: " << num << endl;
		divider++;
		if (num % divider == 0)
		{
			
			return false;
		}
	}
	return true;
}

void checkErrors(int* arr, int size)
{
	int* r = new int[6], errNum = 0, buf = 0, corrected = 0;
	for (int i = 0; i < size; i++)
	{

		if (arr[i] == 0)
		{
			i += 2;
			continue;
		}

		buf = arr[i];		
		if (!isPrime(arr[i]) || (arr[i] > 2e5))
		{

			for (int j = 0; j < 6; j++)
			{
				r[j] = buf % 10;
				buf /= 10;

			}
			
			for (int j = 0; j < 6; j++)
			{
				r[j] = (9 + r[j]) % 10;
				int number = r[0] + r[1] * 1e1 + r[2] * 1e2 + r[3] * 1e3 + r[4] * 1e4 + r[5] * 1e5;
				if ((number > 1e5 && number < 2e5 && isPrime(number)))
				{ // 101197 - 100 число
					corrected = r[0] + r[1] * 1e1 + r[2] * 1e2 + r[3] * 1e3 + r[4] * 1e4 + r[5] * 1e5;
					errNum++;
				}
				r[j]++;
				r[j] %= 10;

			}

			if (errNum <= 1)
				arr[i] = corrected;
			else
			{
				arr[i] = r[0] + r[1] * 1e1 + r[2] * 1e2 + r[3] * 1e3 + r[4] * 1e4 + r[5] * 1e5;
				arr[i] = -arr[i];
			}
		}
		errNum = 0;
	}
	
}

void generateFile(int n, string filename /*Witout .format*/, int div)
{
	// Генерирует файл с  массивом из n случайных элементов. 
	// filename - имя файла без формата, div - диапазон полученных чисел
	filename += ".txt";
	ofstream out(filename);
	out << n << endl;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		out << rand() % div << endl;
	}
	out.close();
	//system("pause");
}
void generateFileMatrix(int n, int m, string filename, int div, bool b)
{
	// Генерирует файл с матрицой из n*m случайных элементов. 
	// filename - имя файла без формата, div - диапазон полученных чисел
	// b - заполнение диагонали. True - да, false - заполнение нулями
	filename += ".txt";
	ofstream out(filename);
	out << n << "\t" << m << endl;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!b && i == j) out << 0 << ' ';
			if (i != j)out << rand() % div << ' ';
		}
		out << endl;
	}
	out.close();
}
void simpleNumbers()
{
	const int n = 1100, primesCount = 100;
	// Ввод входного массива и массива простых чисел
	int arr[n];
	int primesArr[primesCount];
	ifstream in("1.txt");
	ifstream in1("input3.dat");
	ofstream out("output.txt");
	for (int i = 0; i < n; i++)
	{
		if (i < primesCount)
		{
			in >> primesArr[i];
			arr[i + 1000] = primesArr[i];
		}
		in1 >> arr[i];
	}
	mergeSort(arr, n);
	//printArray(arr, n, true);
	findSame(arr, n);
	//printArray(arr, n, true);
	checkErrors(arr, n);
	findSame(arr, n);
	mergeSort(arr, n);
	//checkErrors(arr, n);
	//findSame(arr, n);
	//printArray(arr, n, true);
	
	int* r = new int[6];
	int buf = 0, corrected = 0, errNum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			out << -arr[i] << '*' << endl;
			arr[i] = -arr[i];
		}
		else if (arr[i] > 0)
			out << arr[i] << endl;
	}
	//for (int i = 0; i < n; i++) cout << arr[i] << ' ' << isPrime(arr[i]) << endl;
}

void arrayTask()
{
	ifstream in("inputArray.txt");
	
	int n = 0;
	cout << "Enter n : ";
	in >> n;
	cout << n << endl;
	int* arr = new int[n];
	int unic = 0;
	for (int i = 0; i < n; i++)
	{ 
		in >> arr[i];
		for (int j = 0; j < i; j++)
			if (arr[i] == arr[j] && arr[i] != 0) arr[i] = 0;
		
		if (arr[i] != 0)
		{
			arr[unic] = arr[i];
			unic++;
		}
	}
	mergeSort(arr, unic);
	printArray(arr, unic, true);
	
	
}

void arrayTask2()
{
	ifstream in("inputMatrix.txt");
	const int MAX_SIZE = 20;
	int n = 0, m = 0, counter = 0, diff = 0;
	int arr[MAX_SIZE][MAX_SIZE];
	in >> n; in >> m;
	if (n <= 0 || n > MAX_SIZE || m <= 0 || m > MAX_SIZE)
	{
		cout << endl << "Error, overflow matrix size";
		abort();
	}
	// Инициализация вспомогательных массивов
	int** winsArr = new int*[n], **diffArr = new int*[n]; 
	for (int i = 0; i < n; i++)
	{
		winsArr[i] = new int[2];
		diffArr[i] = new int[2];
	}
	for (int i = 0; i < n; i++)
	{
		
		winsArr[1][i] = 0;
		winsArr[0][i] = i + 1;
		diffArr[0][i] = i + 1;
		diffArr[1][i] = 0;
	}
	// Ввод данных
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << "aaaaaaa" << endl;
			in >> arr[i][j];
			//cout << arr[i * n + j] << ' ';
		}
		//cout << endl;
	}
	in.close();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	//Заполнение вспомогательных массивов (Количество побед каждой команды
	// и разница между забитыми и пропущенными голами).
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i != j)
			{
				diffArr[1][i] += arr[i][j] - arr[j][i];
				if (arr[i][j] > arr[j][i])
					winsArr[1][i] ++;
				else if (arr[i][j] < arr[j][i])
					winsArr[1][i] --;
				//if (arr[i][j] == 0)
				//	arr[i][j] = -1;
			}
		}
	}
	//Сортировка, расстановка команд по местам
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (winsArr[1][i] == winsArr[1][j])
			{
				//cout << winsArr[0][i] - 1 << ' ';
				if (diffArr[1][winsArr[0][i] - 1] > diffArr[1][winsArr[0][j] - 1])
				{
					swap(winsArr[1][i], winsArr[1][j]);
					swap(winsArr[0][i], winsArr[0][j]);
				}
			}
			else if (winsArr[1][i] > winsArr[1][j])
				{
					swap(winsArr[1][i], winsArr[1][j]);
					swap(winsArr[0][i], winsArr[0][j]);
				}
			//if (diffArr[1][i] > diffArr[1][j])
			//{
			//	swap(diffArr[1][i], diffArr[1][j]);
			//	swap(diffArr[0][i], diffArr[0][j]);
			//}
			
		}
	}
	cout << endl;
	// Подведение итогов
	for (int i = 0; i < n; i++)
	{
		cout << winsArr[0][i] << ". " << winsArr[1][i] << endl;
		int index = winsArr[0][i] - 1;
		arr[index][index] = i+ 1;
	}
	
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << diffArr[0][i] << ". " << diffArr[1][i] << endl;
	}

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	in.close();
	//Задание 3, сортировка по местам
	/*int num = arr[0][0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i-1][i-1] < arr[i][i])
			for (int j = 0; j < n; j++)
			{
				swap(arr[i][j], arr[i - 1][j]);
			}
		num = arr[i][i];
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	//printArray(diffArr, n, true);*/
}

void arrayTask4()
{
	ifstream in("");
	int cCounter = 0, dCounter = 0, m = 0, n = 0;
	int* A = new int[m], *B = new int[n], *C = new int[m+n], *D = new int[m+n], *tmp = new int[m + n];
	//generateFile(10, "in1", 10);
	//generateFile(10, "in2", 15);
	in.open("in1.txt");
	in >> m;
	for (int i = 0; i < m; i++)
	{
		in >> A[i];
	}
	in.close();
	in.open("in2.txt");
	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> B[i];
	}
	//in.close();
	mySort(A, 0, m);
	mySort(B, 0, n);
	tmp = findSame2(A, m);
	//printArray(tmp, m, 1);
	for (int i = 1; i < tmp[0]; i++)
		D[dCounter++] = tmp[i];
	//printArray(D, dCounter, 1);
	//cout << endl;
	tmp = findSame2(B, n);
	for (int i = 1; i < tmp[0]; i++)
		D[dCounter++] = tmp[i];
	printArray(D, dCounter, 1);
	delete[] tmp;
	cout << endl;
	mySort(A, 0, m);
	mySort(B, 0, n);
	printArray(A, m, true);
	printArray(B, n, true);
}

int main()
{
	//simpleNumbers();
	//generateFile(60, "inputArray", 10);
	generateFileMatrix(5, 5, "inputMatrix", 10, false);
	//arrayTask();
	arrayTask2();
	//arrayTask4();

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
