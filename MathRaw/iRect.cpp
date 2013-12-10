#include "iRect.h"

/*Rectangle class*/

IRect::IRect(){
}

IRect::IRect(IPoint _p1,IPoint _p2){
 p1 = _p1;
 p2 = _p2;
}
/***********************/

IRect::~IRect() {

}
/***********************/

void IRect::setWithBorder(bool vChoice)
{
	this->withBorder = vChoice;

}
/***********************/

void IRect::setColor(GLfloat pR,GLfloat pG,GLfloat pB)
{
this->mColor[0] = pR ;
this->mColor[1] = pG;
this->mColor[2] = pB;
}
/***********************/

bool IRect::HitTest(IPoint _Point){
   if(  _Point.getX()>=this->p1.getX() &&
		    _Point.getX()<=this->p2.getX() &&

		   _Point.getY()>= this->p1.getY() &&
		    _Point.getY()<=this->p2.getY())
   {
	 //  cout<<"\n Hit Sucess!!";
	   return true;
   }


return false;
}
/***********************/

bool IRect::HitTest(IRect pRect1){
                       //edited: it was &&
return 	(this->HitTest( pRect1.getP1()) || this->HitTest(pRect1.getP2()));

}
/***************************
 *
 */
int IRect::HitTestEx(IRect pRect)
{
	int vXMid = ((p2.getX() + p1.getX())/2);
	//cout<<"\n vMid x is:"<<vXMid;

	if (this->HitTest(pRect))
	{

		if(HitTest(pRect))
		{
			if(pRect.getP1().getX() < vXMid )
				return 1;
			else if(pRect.getP1().getX() > vXMid )
				return 2;
		}
		else return 3;

	}
	return 0;
}
/*********************
 *
 */
int IRect::HitTestEx(IPoint pPoint)
{
	//int vXMid = ( (p2.getX() + p1.getX())/2 );
	int tenPer = ((p2.getX() + p1.getX())*0.10);
	//cout<<"\n vMid x is:"<<vXMid;
	if (this->HitTest(pPoint))
	{
//pPoint.PrintToConsole();
			if ( pPoint.getX() <= ( p1.getX() + 25))
				    return 1;

			if (pPoint.getX() >= ( p2.getX() - 25))
					return 2;
	  		else
	  			    return 3;
	}
	return 0;
}

/***********************/

bool IRect::Render()
{
	int x1 = this->p1.getX();
	int y1 = this->p1.getY();

	int x2 = this->p2.getX();
	int y2 = this->p2.getY();

glColor3f(mColor[0],mColor[1],mColor[2]);
	glBegin(GL_POLYGON);

	glVertex2i(x1,y1);

	glVertex2i(x2,y1);

	glVertex2i(x2,y2);

	glVertex2i(x1,y2);

	glEnd();

if (this->withBorder == true){
	glColor3f(mColor[0],mColor[1],mColor[2]);
	glBegin(GL_LINE_LOOP);

		glVertex2i(x1,y1);

		glVertex2i(x2,y1);

		glVertex2i(x2,y2);

		glVertex2i(x1,y2);

		glEnd();
	}
	//cout<<"\nrendering rect: x1: "<<x1<<" x2: "<<x2<<" y1: "<<y1<<" y2: "<<y2<<"\n";
	return true;

}
/********************/

void IRect::setColor(GLfloat pColor[3]){
	this->mColor[0] = pColor[0];
	this->mColor[1] = pColor[1];
	this->mColor[2] = pColor[2];
}
/**********************EOF********************/
