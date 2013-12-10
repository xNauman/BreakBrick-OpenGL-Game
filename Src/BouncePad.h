/*
 * BouncePad.h
 *
 *  Created on: Mar 29, 2010
 *      Author: Admin
 */

#ifndef BOUNCEPAD_H_
#define BOUNCEPAD_H_
#include "../mathraw/IRect.h"
#include "../mathraw/IPoint.h"

class BouncePad:public IRect {
public:
	BouncePad();
	virtual ~BouncePad();

	bool	MoveLeft();

	bool	MoveRight();

	bool	Resize(const int);

	void setPadPosition(IPoint);

	IPoint getPadPosition();


	void setMoveMinMax(int pMin,int pMax){mXMin = pMin; mXMax=pMax;};
	//float getMoveMin();
	//float getMoveMax();

	void debug();
	int getSpeed();
	void setSpeed(int);
	private:
		IPoint mPadPosition;

		int  mXMax;
		int  mXMin;

		int mSpeed;
		//float mMoveMin;
		//float mMoveMax;
	/*const int SHORT_PAD = -1;

	const int LONG_PAD = 1;

	const int NORMAL_PAD = 0;
	*/
};

#endif
