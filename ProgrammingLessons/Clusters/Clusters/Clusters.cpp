// Clusters.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std;
const double START = 5, END = 100, counter = 100;
const double X1 = -5, X2 = 5, Y1 = -5, Y2 = 5;

int main()
{	
	ofstream outX("X.txt"), outX1("outX.txt");
	ofstream outY("Y.txt");
	ofstream otkl1("otklonenie1.txt"), otkl2("otklonenie2.txt"), otkl("otklonenia.txt");
	ofstream outks("Ks.txt"), outbs("Bs.txt");
	double k, b;
	double arrX[100], arrY[100], BS[1000], KS[1000];
	k = (Y2 - Y1) / (X2 - X1);
	b = Y1 - k * X1;
	outks << X1 << '\t' << Y1 << endl;
	outks << X2 << '\t' << Y2 << endl;
	outX1 << k << '\t' << b << endl;
	//outX1 << X2 << '\t' << Y2 << endl;
	double deltaX = (X2 - X1) / 100,
		deltaY = (Y2 - Y1) / 100,
		tmpX = deltaX,
		summX = 0,
		summY = 0,
		summXY = 0,
		summXX = 0,
		summBS = 0,
		summKS = 0,
		ks = 0,
		bs = 0,
		summBB = 0,
		summKK = 0;
	int n = 0;
	srand(time(0));
	for (int j = 0; j < counter; j++)
	{
		ks = 0; bs = 0; 
		summX = 0;
		summY = 0; summXX = 0;
		summXY = 0;
		deltaX = 0;
		for (int i = 0; i < END; i++)
		{
			double noize = (((double)rand() / (double)RAND_MAX) - 0.5) * 3;

			arrX[i] = X1 + deltaX;
			deltaX += tmpX;
			arrY[i] = arrX[i] * k + b + noize;
			summX += arrX[i];
			summY += arrY[i];
			summXY += arrX[i] * arrY[i];
			summXX += arrX[i] * arrX[i];
			//
		}
		ks = (END * summXY - summY * summX) / (END * summXX - summX * summX);
		//bs = ((summY * summXX) - (summXY * summX)) / (END * summXX - summX * summX);
		bs = (1 / END) * (summY - ks * summX );
		//cout << "ks = " << ks << " bs = " << bs << endl;
		summBS += bs;
		summKS += ks;
		summBB += bs * bs;
		summKK += ks * ks;
	}
	for (int i = 0; i < END; i++)
	{
		//outX1 << arrX[i] << '\t' << arrY[i] << endl;
		//cout << arrX[i] << ";" << arrY[i] << ";" << endl;  //Точки шумов
	}
	double summaK = sqrt((summKK / counter) - (summKS / counter) * (summKS / counter)),
		summaB = sqrt((summBB / counter) - (summBS / counter) * (summBS / counter));
	// y = 1.85226 * x - 1.33622;
	//cout << ks << ' ' << bs << endl;
	outX << summKS / counter << '\t' << summBS / counter <<  endl;
	cout << summBS / counter << endl;
	cout << summaK << ' ' << summaB << endl;
	deltaX = (X2 - X1) / 100;
	//outX1 << X1 << '\t' << ((summKS / counter) + summaK) * X1 + (summBS/counter + summaB) << endl;
	//outX1 << X2 << '\t' << ((summKS / counter) + summaK) * X2 + (summBS/counter + summaB) << endl;
	//outX1 << X1 << '\t' << ((summKS / counter) - summaK) * X1 + (summBS / counter - summaB) << endl;
	//outX1 << X2 << '\t' << ((summKS / counter) - summaK) * X2 + (summBS / counter - summaB) << endl;
	double y = 0, x = 0;
	int co = 0;
	for (double i = k - summaK; i < k + summaK; i += summaK / 10)
	{
		for (double j = b - summaB; j < b + summaB; j += summaB / 10)
		{
			outX1 << i << '\t' << j << endl;
			
			co++;
		}
	}
	cout << co;
	//FILE *gp = _popen("gnuplot -persist", "w");
	//fprintf(gp, "set terminal png\n");
	//fprintf(gp, "set output \"graph.png\"");
	//fprintf(gp, "plot sin(x)\n");
	//_pclose(gp);
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
