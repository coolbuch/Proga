#ifndef _GEOMETRY_H
#define _GEOMETRY_H

//Provides basic geometry things
struct Geometry
{
	//Returns the distance between two points
	static double getDistance(double xa, double ya, double xb, double yb);
	//Returns the square of triangle, declared with 3 points
	static double getTriangleArea(double xa, double ya, double xb, double yb, double xc, double yc);
};

#endif // !_GEOMETRY_H
