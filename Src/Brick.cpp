
#include "Brick.h"

CBrick::CBrick(void)
{
}

CBrick::~CBrick(void)
{
}

CBrick::CBrick(int pHeigth,int pWidth)
{
	IRect();
	this->height = pHeigth;
	this->width = pWidth;
}


CBrick::CBrick(int pHeigth,int pWidth, IPoint pPos)
{
	IRect();
	this->height = pHeigth;
	this->width = pWidth;

	this->mPosition = pPos;


this->setP1(pPos.getX(),pPos.getY());
this->setP2(pPos.getX()+this->width,pPos.getY()+this->height);
	//this->setP1(pPos.getX(),pPos.getY());
	//this->setP2( ,);
}

IPoint CBrick::getPosition()
{
	return this->mPosition;
}

void CBrick::setPosition(IPoint pPos)
{
	this->mPosition = pPos;
}

void CBrick::setHeight(int pHeight)
{
	this->height = pHeight;
}

void CBrick::setWidth(int pWidth)
{
	this->width = pWidth;
}

int CBrick::getWidth()
{
	return width;
}

int CBrick::getHeigth()
{
	return height;
}

void CBrick::renderMe(){
glPushMatrix();

	glBegin(GL_LINE_LOOP);
	glVertex2i( getPosition().getX(), getPosition().getY());
	glVertex2i( getPosition().getX()+this->width, getPosition().getY());
	glVertex2i( getPosition().getX()+this->width,getPosition().getY()+this->height);
	glVertex2i( getPosition().getX(), getPosition().getY()+this->height);
	glEnd();

glPopMatrix();
}
