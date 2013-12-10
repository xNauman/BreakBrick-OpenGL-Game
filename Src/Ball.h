/*
 * Ball.h
 *
 *  Created on: Mar 29, 2010
 *      Author: Admin
 */

#ifndef BALL_H_
#define BALL_H_
#include <math.h>
#include <vector>
#include "../mathraw/IPoint.h"
#include "../mathraw/iRect.h"


#include "../graphicsraw/BoundingBox.h"


class Ball:public IRect{
public:
	Ball();
	Ball(const Ball&);
	virtual ~Ball();
	void move();
	void renderMe();
	void 	Init();
	void setPoisition(int,int);
	IPoint getPoistion();
	void setBallSize(int);
	int getBallSize();
	void setMoveBoundry(int,int,int,int);

	int getSpeed(){ return mSpeed;}
	void setSpeed(int _S){ mSpeed = _S;}
	void setColor(GLfloat r,GLfloat g,GLfloat b){mColor[0]= r; mColor[1]= g;mColor[1]= b;};

	void setMoveDirection(bool,bool);

	int getXMoveFlag(){return mXMoveFlag;}
	int getYMoveFlag(){return mYMoveFlag;}
	void resetXYMoveFlags();
private:
	static int mBallCount ;
	GLfloat mColor[3];
	int mBallID;
	int mXLimit;
	int mYLimit;
	int mInitXLimit;
	int mInitYLimit;

	int mXMoveFlag;// -1 or 1
	int mYMoveFlag;// -1 or 1
	int mSpeed;

	vector<IPoint> mGeometry;
	int mBallSize;
	IPoint mPos;
};

#endif /* BALL_H_ */
