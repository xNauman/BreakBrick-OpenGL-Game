/*************
 *
 *
 * @author: Nouman Saeed
 * @Class RectanglesBreaker
 * This class takes measurments of to rectangles.
 * First rectangle is the big one and second one is the sample to generate
 * rest of the rectangles within big rectangles  boundries.
 *
 * there is intial position is of big rectangle which can be chnaged BEFORE
 * genrateing rectangles.
 * BreakRectNoraml is the method generate the rectangles.
 *
 *
 */

#pragma once
#include "Brick.h"

#include <vector>

#include <iostream>

using namespace std;

class RectanglesBreaker
{
public:
	RectanglesBreaker(void);
	~RectanglesBreaker(void);
	RectanglesBreaker(int pMainRectLenght,int pMainRectWidth,int pInnerRectLenght,int pInnerRectWidth);

	bool BreakRectNormal();
	bool BreakRectCustom();
	int getInnerRectCount();
	void setInitPos(IPoint pPos);
	IPoint getInitPos();
	vector<CBrick*> getBrokenRectList(void);
private:
	//TODO: gap b/w rects.
//int gap
	bool sequnce;

	vector<CBrick*> mInnerRectList;

	int mInnerRectsHeight;
	int mInnerRectsWidth;

	int mMainRectHeight;
	int mMainRectWidth;
 
	IPoint mRectListPos;

	int numberOfInnerRects;
	
};
