#pragma once
#include "../MathRaw/IPoint.h"
#include "../MathRaw/IRect.h"
#include <GL/GLUT.H>

class CBrick: public IRect
{
public:
	CBrick(void);
	~CBrick(void);
    CBrick(int pHeigth,int pWidth);
	CBrick(int pHeigth,int pWidth,IPoint pPos);

	void setHeight(int pHeight);
	void setWidth(int pWidth);

	int getWidth(void);
		int getHeigth(void);

	IPoint getPosition(void);
	void setPosition(IPoint);

	//new functions.
	void renderMe(void);
private:
	IPoint mPosition;
	int width;
	int height;
};
