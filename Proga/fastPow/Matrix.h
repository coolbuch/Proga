#pragma once
#ifndef _MATRIX
#define _MATRIX
struct Matrix
{
	unsigned long long ** data;
	unsigned long long ** newData;
	int n = 0, m = 0;

public: Matrix(int n1, int m1);
public:Matrix(unsigned long long** matrix, int n1, int m1);
public:Matrix();
Matrix* mul(Matrix &other);
~Matrix();

};

#endif // !_MATRIX
