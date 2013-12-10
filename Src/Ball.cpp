/*
 * Ball.cpp
 *
 *  Created on: Mar 29, 2010
 *      Author: Admin
 */

#include "Ball.h"

int Ball::mBallCount = 0;
Ball::Ball() {

		mBallCount++;
this->mBallSize =5;
this->mSpeed = 2;

this->mInitXLimit = 20;
this->mInitYLimit = 20;

this->mXMoveFlag = 1;
this->mYMoveFlag = 1;

this->mBallID = mBallCount;
}
/**********************
 * CopyConstructor
 */
Ball::Ball(const Ball &pBall) {

this->mBallSize = pBall.mBallSize;
this->mSpeed = pBall.mSpeed;

this->mInitXLimit = pBall.mInitXLimit;
this->mInitYLimit = pBall.mInitYLimit;

this->mXMoveFlag = pBall.mXMoveFlag;
this->mYMoveFlag = pBall.mYMoveFlag;

this->mXLimit = pBall.mXLimit;
this->mYLimit = pBall.mYLimit;


}
Ball::~Ball() {

}

void Ball::renderMe(){
	this->move();
	//cout<<"\n Rendering ball: "<<mBallID;
	glColor3f(mColor[0],mColor[1],mColor[2]);
glPushMatrix();
glTranslatef(this->mPos.getX()+mSpeed, this->mPos.getY()+mSpeed,0);
glBegin(GL_POLYGON);

	for(int k=0;k<(int)this->mGeometry.size();k++)
	glVertex2i(this->mGeometry[k].getX(),this->mGeometry[k].getY());

glEnd();

glPopMatrix();
}
/*******************************/
void Ball::Init()
{
	int x,y;
		for(int i=0;i<360;i++){
			x = (int)mBallSize*cos(i)+1;
			y = (int)mBallSize*sin(i)+1;

	this->mGeometry.push_back(IPoint(x,y));
		}
}
/*******************************/
void Ball::setPoisition(int pX,int pY)
{
	if(pX < this->mInitXLimit)
		pX = this->mInitXLimit;

	else if(pX > this->mXLimit)
			pX= this->mXLimit;

	if(pY < this->mInitYLimit)
			pY= this->mInitYLimit;
	else if(pY > this->mYLimit)
			pY = this->mYLimit;

	this->mPos.setXY(pX,pY);
}
/******************************/
IPoint Ball::getPoistion()
{
return this->mPos;
}
/***********************************/
void Ball::setBallSize(int pSize)
{
               this->mBallSize = pSize;
}
/***********************************/
int Ball::getBallSize(){
	return this->mBallSize;
}
/*******************************/
void Ball::move(){
	if( this->mPos.getX() >=this->mXLimit || this->mPos.getX() <= this->mInitXLimit )
		this->mXMoveFlag *= -1;

		if(this->mPos.getY() >= this->mYLimit || this->mPos.getY() <= this->mInitYLimit )
				this->mYMoveFlag *= -1;

	int vX = this->mPos.getX()+ this->mSpeed*this->mXMoveFlag ;
	int vY = this->mPos.getY()+ this->mSpeed*this->mYMoveFlag ;


	this->setPoisition(vX,vY);
}
/*************************************
 *
 */
void Ball::setMoveBoundry(int _iX,int _iY ,int _fX,int _fY)
{
	this->mInitXLimit = _iX;
	this->mInitYLimit = _iY;

	this->mXLimit = _fX;
	this->mYLimit = _fY;
}
/****************************************
 *
 */
void Ball::setMoveDirection(bool pXDirection,bool pYDirection)
{
			if(pXDirection)this->mXMoveFlag *=-1;

			if(pYDirection)this->mYMoveFlag *=-1;
}
/****************************************
 *
 */
void Ball::resetXYMoveFlags(){
	this->mXMoveFlag =1;
	this->mYMoveFlag =1;
}
/***********EOF*******************/
