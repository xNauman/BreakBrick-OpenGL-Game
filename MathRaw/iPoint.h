/*
 * Point.h
 *
 *  Created on: Mar 18, 2010
 *      Author: Admin
 */

#ifndef IPOINT_H_
#define IPOINT_H_
#include <iostream>
using  std::cout;



class IPoint {
public:
	IPoint();
	IPoint(int,int);
	virtual ~IPoint();

private:
	int x;
	int y;

public:
	int getX();
	int getY();

	void setX(int pX);
	void setY(int pY);

	void setXY(int,int);
	void PrintToConsole();

};

#endif /* POINT_H_ */
