#pragma once
#ifndef _MATRIX
#define _MATRIX
struct Matrix
{
	int ** data;
	int ** newData;
	int n = 0, m = 0;

public: Matrix(int n1, int m1);
public:Matrix(int** matrix, int n1, int m1);
public:Matrix();
Matrix* mul(Matrix &other);
~Matrix();

};

#endif // !_MATRIX
