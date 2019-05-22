#include "pch.h"
#include "Matrix.h"
#include <cassert>
	Matrix::Matrix(int n1, int m1)
	{
		//init(n, m);
		n = n1;
		m = m1;
		data = new int*[n];
		newData = new int*[n];

		for (int i = 0; i < n; i++)
		{
			data[i] = new int[m];
			newData[i] = new int[m];
			for (int j = 0; j < m; j++)
			{
				data[i][j] = 0;
				newData[i][j] = 0;
			}
		}
	}

	Matrix::Matrix(int** matrix, int n1, int m1)
	{
		n = n1;
		m = m1;
		data = new int*[n];
		newData = new int*[n];

		for (int i = 0; i < n; i++)
		{
			data[i] = new int[m];
			newData[i] = new int[m];
			for (int j = 0; j < m; j++)
			{
				data[i][j] = 0;
				newData[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				data[i][j] = matrix[i][j];
		}
	}

	Matrix::Matrix()
	{
		for (int i = 0; i < n; i++)
		{
			data[i] = new int[m];
			if (!newData[i])
				newData[i] = new int[m];
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
		newData = new int*[this->m];
		for (int i = 0; i < n; i++)
			newData[i] = new int[other.n];

		for (int i = 0; i < this->n; i++)
		{
			for (int j = 0; j < other.m; j++)
			{
				newData[i][j] = 0;
				for (int k = 0; k < this->m; k++)
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
		for (int i = 0; i < n; i++)
		{
			if (data[i])
				delete[] data[i];
			if (newData[i])
				delete[] newData[i];
		}
	}
