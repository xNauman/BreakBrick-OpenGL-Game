#ifndef GMAINFUNCS_H
#define  GMAINFUNCS_H
#include <GL/glut.h>
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include "BouncePad.h"
#include "Ball.h"
#include "RectanglesBreaker.h"
//#

using namespace std;

RectanglesBreaker  gRectBreak(350,350,50,50);
vector<CBrick*> gBrickList;
IPoint gWindowSize(1024,740);
BouncePad gPad;
Ball gBall;
Ball gNBall[3];
float mAnimTiming = 30.0;
int score=0;
int lifeLines=5;
char vAStr[20];//for int to str
bool gamePause = false;
bool gameReset = false;

/********************************
 *
 * To Update score board
 * */
char* itoa(int a)
{

			char vDStr[20];
			int i=5,t=0;
			static char digits[]="0123456789abcdefghijklmnopqrstuvwxyz";

			memset(vDStr,'\0',20);
			memset(vAStr,'\0',20);

			//strcpy(vAStr,"score:");
			while(a != 0){
				vDStr[t] = digits[a%10];
				t++;
				a/=10;
			}

			--t;
			i=strlen(vAStr);
			while(t>=0){
					vAStr[i] = vDStr[t];
					i++;
					t--;
			}
			cout<<"\n  "<<strlen(vAStr)<<endl<<vAStr;
	return vAStr;


}
/***********************************
 * To update life lines.
 * **/
void UpdateLifeLinesBoard(int pX,int pY,int pLifeLines){


	char *vStatusText = new char[15];
	memset(vStatusText,'\0',15);
	strcat(vStatusText,"Lives:");
	strcat(vStatusText,itoa(lifeLines));
	//vStatusText = itoa(lifeLines);

	//vStatusText[6]=0;
	glColor3f(1.0, 0.80, 0.20);
	int j=0,k=10;//k is for the distance b/w charectors.

	//cout<<endl<<strlen(vAStr);
	for(char i=(char)vStatusText[0];i!='\0';i=(char)vStatusText[j])
	{
		glRasterPos2i(pX +k,pY);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,i);

		j++;
		k+=10;
	}


}
/***********************************
 * To update score board.
 * **/
void UpdateScoreBoard(int pX,int pY){


	char *vStatusText = new char[15];
	memset(vStatusText,'\0',15);
	strcat(vStatusText,"Score:");
	strcat(vStatusText,itoa(score));

	//vStatusText[6]=0;
	glColor3f(1.0, 0.0, 0.0);
	int j=0,k=10;//k is for the distance b/w charectors.


	for(char i=(char)vStatusText[0];i!='\0';i=(char)vStatusText[j])
	{
		glRasterPos2i(pX +k,pY);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,i);

		j++;
		k+=10;
	}


}
/****************
 * To put text at given window cordinate.
 */
void TextAt(int pX,int pY,char pStr[])
{


	//glColor3f(0.0, 0.0, 1.0);
	int j=0,k=50;//k is for the distance b/w charectors.


	for(char i=(char)pStr[0];i!='\0';i=(char)pStr[j])
	{

		glRasterPos2i(pX +k,pY);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,i);

		j++;
		k+=50;

	}


}
/****************************************/
void Display()
{


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1024, 0, 740);
	Sleep(15);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	UpdateScoreBoard(gWindowSize.getX()-100,gWindowSize.getY()-20);
	UpdateLifeLinesBoard(5,gWindowSize.getY()-20,lifeLines);

 glPushMatrix();
 gPad.Render();
 glPopMatrix();

 if(gamePause == true)
 {
	 glutPostRedisplay();
	 return;
 }

 if(gBall.getPoistion().getY() <4)
 {

	// gPad.setPadPosition();
	 lifeLines -=1;

	 if(lifeLines <= 0){
	 TextAt(::gWindowSize.getX()/2-200,gWindowSize.getY()/2,"Game Over");
       glFlush();
	 glutPostRedisplay();
	 	 return;
	 }
	 else
	 {

		 gBall.resetXYMoveFlags();
		 gBall.setPoisition(10,20);
	 }

 }
    int vTest = gPad.HitTestEx( gBall.getPoistion() );

if( vTest == 1)
{
    //if coming from left means X Increasing and Y Decreasing.
	//if coming from Right X is Decreasing and Y Decreasing.
	//so Y always have to be true.
	//making this check.
	if(gBall.getXMoveFlag() == -1)
		gBall.setMoveDirection(false,true);
	else
	    gBall.setMoveDirection(true,true);
	//  cout<<"\n Left side pad, ball hit pad";
}
	else if(vTest == 2)
	{
		if(gBall.getXMoveFlag() == 1)
			gBall.setMoveDirection(false,true);
		else
			gBall.setMoveDirection(true,true);
		// cout<<"\n Right side pad ,ball hit pad ";
	}
	else  if(vTest == 3){
		gBall.setMoveDirection(false,true);
		//cout<<"\n Middle ball hit pad ";
	}

if(gBrickList.size() == 0)
		TextAt(::gWindowSize.getX()/2-200,gWindowSize.getY()/2,"Game Over");
	else{
		glColor3f(0.0,1.0,0.5);
		for(int iLoop=0;iLoop<(int) gBrickList.size();iLoop++)
			{
			vTest = gBrickList[iLoop]->HitTestEx( gBall.getPoistion());

				if( vTest == 1)
				{
						if(gBall.getXMoveFlag() == -1)
							gBall.setMoveDirection(false,true);
						else
							gBall.setMoveDirection(true,true);
						gBrickList.erase(gBrickList.begin()+iLoop);
						score+=10;
				}
				else if(vTest == 2)
				{
					if(gBall.getXMoveFlag() == 1)
						gBall.setMoveDirection(false,true);
					else
						gBall.setMoveDirection(true,true);

					gBrickList.erase(gBrickList.begin()+iLoop);
					score+=10;
		}
		else  if(vTest == 3){
			gBall.setMoveDirection(false,true);
			gBrickList.erase(gBrickList.begin()+iLoop);
			score+=10;
		}


			    gBrickList[iLoop]->renderMe();
		}

	gBall.renderMe();
}


//::gNBall[0].renderMe();
//::gNBall[1].renderMe();
//glutSwapBuffers();

	glFlush();
glutPostRedisplay();

}
/**********************************/
//void testT
/*************************************/
void initGlobals(void)
{
	score=0;
	lifeLines=5;
	gRectBreak.setInitPos(IPoint(gWindowSize.getX()/3,gWindowSize.getY()/2));
		if(gameReset==false)
			gRectBreak.BreakRectNormal();

	//cout<<gRectBreak.getInnerRectCount()<<endl;
	//for(int i=0;i< (int)gBrickList.size();i++)
	//gBrickList.erase(gBrickList.begin()+i);

	gBrickList = gRectBreak.getBrokenRectList();

	/*
	 * setting up bouncing pad.
	 */     ::gPad.setP1(IPoint(10,10));
			gPad.setP2(IPoint(150,15));
			//::gPad.setPadPosition(IPoint(200,200));
			gPad.setColor(1.0,1.0,1.0);
			gPad.setWithBorder(true);
			gPad.setSpeed(20);
			gPad.setMoveMinMax(1,1023);
			//gPad.setWithBorder(false);
	/*
	 *setting up ball.
	 **/
			::gBall.setBallSize(10);
			gBall.setPoisition(10,20);
			gBall.setMoveBoundry(1,3,::gWindowSize.getX()-10,::gWindowSize.getY()-10);
			gBall.setColor(0.52,0.7,0.7);
			gBall.Init();
			gBall.setSpeed(5);
			gBall.resetXYMoveFlags();
/*
			::gNBall[0]= Ball();
			::gNBall[0].setBallSize(5);
						::gNBall[0].setPoisition(13,3);
						::gNBall[0].setMoveBoundry(1,1,::gWindowSize.getX()-10,::gWindowSize.getY()-10);
						::gNBall[0].Init();

						::gNBall[1]= Ball(gBall);
						 gNBall[1].setColor(0.2,0.4,0.5);
						 gNBall[1].setPoisition(1,3);
						gNBall[1].Init();
*/

			//::gBall.s
}
/********************************/
void changeWindowSize(int w,int h)
{
	if(h == 0)
		h =1;

glViewport(0,0,w,h);

}
/*******************************/
void keysController(unsigned char uKey,int y,int t){

	switch(uKey){

		case 'a':
			if(gamePause== true)
				return;
				::gPad.MoveLeft();
			break;
		case 'd':
			if(gamePause== true)
				return;
					::gPad.MoveRight();
			break;

		case 'p':
			if(gamePause == true)
				gamePause = false;
			else
				gamePause = true;
			break;
		case 'P':
					if(gamePause == true)
						gamePause = false;
					else
						gamePause = true;
					break;
		case '1':
			initGlobals();
			gameReset =true;
			break;
		/*case GLUT_KEY_LEFT:

						::gPad.MoveLeft();

						break;
*/

default:
	cout<<"\n Unhandled key:"<<(int)uKey;
	break;
	}

	//glutPostRedisplay();
}
/*******************************/
void keyDown(int key,int q,int r){
	if(gamePause== true)
		return;
	switch(key){
		case GLUT_KEY_LEFT:
		{
			gPad.setSpeed(gPad.getSpeed()+10);
		::gPad.MoveLeft();
		}
//		cout<<"key down";
			break;

		case GLUT_KEY_RIGHT:
		{
			gPad.setSpeed(gPad.getSpeed()+10);
			::gPad.MoveRight();
		}
		default:
			;
	}
glutPostRedisplay();
}
/*******************************/
/**/
void keyUp(int key,int i,int j){
	if(gamePause== true)
		return;
	switch(key){
			case GLUT_KEY_LEFT:
			{
				gPad.setSpeed(10);
			 ::gPad.MoveLeft();
			cout<<"left key UP";
			}
			//cout<<"key up";
				break;

			case GLUT_KEY_RIGHT:
			{
				gPad.setSpeed(10);
			 ::gPad.MoveRight();
				cout<<"Right key up";
			}
			default:
				;
		}
	//glutPostRedisplay();
}
/*******************************/
#endif
