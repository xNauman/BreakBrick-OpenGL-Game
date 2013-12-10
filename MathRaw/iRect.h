/*
 * Rect.h
 *
 *  Created on: Mar 18, 2010
 *      Author: Admin
 */

#ifndef IRECT_H_
#define IRECT_H_
#include "iPoint.h"

#include <GL/glut.h>
#include <iostream>
using namespace std;


class IRect {
	private:
	//P1: is for initial positioning.
	//P2: is for the width and the height information.
	IPoint p1;
	IPoint p2;
	bool withBorder;
	GLfloat mColor[3];
public:
	IRect();
	virtual ~IRect();
	IRect(IPoint,IPoint);

	bool HitTest(IPoint);
	bool HitTest(IRect);
	int HitTestEx(IRect);//to check which part (left right middle) the passed point is hit
	int HitTestEx(IPoint);//to check which part (left right middle) the passed point is hit

	bool Render(void);
	IPoint getP1(){return p1;}
	IPoint getP2(){return p2;}

	void setP1(IPoint _P1){p1 = _P1;}
	void setP2(IPoint _P2){p2 = _P2;}

	void setP1(int _x,int _y){this->p1.setX(_x);this->p1.setY(_y);};
	void setP2(int _x,int _y){this->p2.setX(_x);this->p2.setY(_y);};

	void setColor(GLfloat,GLfloat,GLfloat);
	void setColor(GLfloat pColor[3]);

	void setWithBorder(bool);

};
/********************************************/
/**
 * Impelementation of template
 */
/*******************************************/


#endif /* RECT_H_ */
