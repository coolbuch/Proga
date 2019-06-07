#include "pch.h"
#include "Matrix.h"
#include <cassert>
	Matrix::Matrix(int n1, int m1)
	{
		//init(n, m);
		n = n1;
		m = m1;
		data = new unsigned long long*[n];
		newData = new unsigned long long*[n];

		for (int i = 0; i < n; i++)
		{
			data[i] = new unsigned long long[m];
			newData[i] = new unsigned long long[m];
			for (int j = 0; j < m; j++)
			{
				data[i][j] = 0;
				newData[i][j] = 0;
			}
		}
	}

	Matrix::Matrix(unsigned long long** matrix, int n1, int m1)
	{
		n = n1;
		m = m1;
		data = new unsigned long long*[n];
		newData = new unsigned long long*[n];

		for (unsigned long long i = 0; i < n; i++)
		{
			data[i] = new unsigned long long[m];
			newData[i] = new unsigned long long[m];
			for (unsigned long long j = 0; j < m; j++)
			{
				data[i][j] = 0;
				newData[i][j] = 0;
			}
		}
		for (unsigned long long i = 0; i < n; i++)
		{
			for (unsigned long long j = 0; j < m; j++)
				data[i][j] = matrix[i][j];
		}
	}

	Matrix::Matrix()
	{
		for (unsigned long long i = 0; i < n; i++)
		{
			data[i] = new unsigned long long[m];
			if (!newData[i])
				newData[i] = new unsigned long long[m];
			for (int j = 0; j < m; j++)
			{
				data[i][j] = 0;
				newData[i][j] = 0;
			}
		}
	}
	Matrix* Matrix::mul(Matrix &other)
	{
		assert(this->m == other.n);
		newData = new unsigned long long*[this->m];
		for (unsigned long long i = 0; i < n; i++)
			newData[i] = new unsigned long long[other.n];

		for (unsigned long long i = 0; i < this->n; i++)
		{
			for (unsigned long long j = 0; j < other.m; j++)
			{
				newData[i][j] = 0;
				for (unsigned long long k = 0; k < this->m; k++)
				{
					newData[i][j] += data[i][k] * other.data[k][j];
				}
			}
		}
		this->m = other.m;
		return new Matrix(newData, this->n, this->m);
	}


	Matrix::~Matrix()
	{
		for (unsigned long long i = 0; i < n; i++)
		{
			if (data[i])
				delete[] data[i];
			if (newData[i])
				delete[] newData[i];
		}
	}
