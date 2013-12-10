/*
 * Point.cpp
 *
 *  Created on: Mar 18, 2010
 *      Author: Admin
 */

#include "iPoint.h"


IPoint::IPoint() {


	x = 0;
	y = 0;

}
/******************/

IPoint::IPoint(int pX , int pY)
{
    x = pX;
    y = pY;
}
/********************/
IPoint::~IPoint() {

}
/*******************************/
void IPoint::setX(int pX){
this->x = pX;
}
/****************************/
void IPoint::setY(int pY){

this->y = pY;

}
/****************************/
int IPoint::getX(){
return this->x;
}
/****************************/
int IPoint::getY(){
return this->y;
}
/****************************/
void IPoint::setXY(int pX,int pY){
	this->x=pX;
	this->y=pY;
}
/****************************/
void IPoint::PrintToConsole(){

	cout<<"("<<x<<" , "<<y<<")";
}
