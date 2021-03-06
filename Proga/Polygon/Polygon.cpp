// Polygon.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cassert>
struct Point
{
	int x = 0, y = 0;
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	Point() {
		x = 0; y = 0;
	}
};

struct Segment {
	Point p1, p2;
	int vectorX = 0, vectorY = 0;
	Segment(Point po1, Point po2)
	{
		p1 = po1;
		p2 = po2;
		vectorX = p2.x - p1.x;
		vectorY = p2.y - p1.y;
	}
};
using namespace std;
//return 0 when segment or its continuence exists this Point; 1 when Point is above Segment; -1 below.
int getPointOrientation(Point p, Segment s);
bool segmentsIntersection(Segment s1, Segment s2);
int vectorMul(Segment s1, Segment s2);
int scalarMul(Segment s1, Segment s2);
int main()
{
	int x = 0, y = 0;
	cout << "Enter points of segment; Point 1 x, y: ";
	cin >> x >> y;
	Point p1(x, y);
	cout << endl << "Point 2 x,y: ";
	cin >> x >> y;
	Point p2(x, y);
	Segment segment(p1, p2);
	cout << endl << "Enter point coords; x,y: ";
	cin >> x >> y;
	Point point(x, y);
	cout << endl << getPointOrientation(point, segment);
}

//return 0 when segment or its continuence exists this Point; 1 when Point is above Segment; -1 below.
int getPointOrientation(Point p, Segment s)
{
	int k = vectorMul(s, Segment(s.p1, p));
	if (k > 0)
		return 1;
	else 
		if (k == 0)
			return 0;
		else 
			if (k < 0)
				return -1;
}
// реализовать векторное произведение, скалярное. Если векторное произведение > 0, то точка лежит ниже(или выше)
// 
bool segmentsIntersection(Segment s1, Segment s2)
{
	return 0;
}


int vectorMul(Segment s1, Segment s2)
{
	return (s1.vectorX  * s2.vectorY - s1.vectorY * s2.vectorX);
}

int scalarMul(Segment s1, Segment s2)
{
	return 0;
}
