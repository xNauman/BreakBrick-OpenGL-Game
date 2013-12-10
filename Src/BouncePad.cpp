/*
 * BouncePad.cpp
 *
 *  Created on: Mar 29, 2010
 *      Author: Admin
 */

#include "BouncePad.h"

BouncePad::BouncePad(){

}
BouncePad::~BouncePad() {

}
/**********************
*
*/
void BouncePad::setSpeed(int pSpeed){
	this->mSpeed = pSpeed;
}
/**********************
*
*/
int BouncePad::getSpeed(){
	return this->mSpeed;
}
/*********************
 *to move pad left
 */

bool BouncePad::MoveLeft()
{

	int vTXPos = this->getP1().getX() - (20 + mSpeed);

		if(getP1().getX()> this->mXMin)
		{
			this->mPadPosition.setX(vTXPos);
			this->setP1(this->getP1().getX()-20, this->getP1().getY());
			this->setP2(this->getP2().getX()-20, this->getP2().getY());
		}

return true;
}
/************************
 *to move pad right
 */

bool BouncePad::MoveRight()
{

int vTXPos = this->getP2().getX() + 20;

	if(getP2().getX()< this->mXMax){
	this->mPadPosition.setX(vTXPos);
		this->setP1(this->getP1().getX()+ 20, this->getP1().getY());

		this->setP2(this->getP2().getX()+ 20, this->getP2().getY());
}

return true;
}
/********************/
bool BouncePad::Resize(const int pType)
{

	return true;
}
/***************************
 * to set  pad position
 */
void BouncePad::setPadPosition(IPoint pPoint)
{
	//this->setP1(pPoint);
}
/*
float getMin()
{
return 0;
}
float getMoveMax()
{
	return 0;

}

*/
