#include "RectanglesBreaker.h"


RectanglesBreaker::RectanglesBreaker(void)
{

}

RectanglesBreaker::~RectanglesBreaker(void)
{

}

RectanglesBreaker::RectanglesBreaker(int pMainRectWidth, int pMainRectHeight, int pInnerRectWidth, int pInnerRectHeight)
{
	this->mInnerRectsHeight = pInnerRectHeight;
	this->mInnerRectsWidth = pInnerRectWidth;
	
	this->mMainRectHeight = pMainRectHeight;
	this->mMainRectWidth = pMainRectWidth;


	//this->mRectListPos.setX(150);
//	this->mRectListPos.setY(150);
	
}

bool RectanglesBreaker::BreakRectNormal()
{

	//todo: chnaged to int previous float
	int i,j;
	i = this->mRectListPos.getX() ; j = this->mRectListPos.getY() ;

    int vHeight,vWidth;
	int vHeightDivision, vWidthDivision;

	vHeightDivision = mMainRectHeight / mInnerRectsHeight;
		vWidthDivision = mMainRectWidth / mInnerRectsWidth;

	vHeight = this->mInnerRectsHeight;
	vWidth = this->mInnerRectsWidth;

			//calculating number of rectangles possible in Mian Rectangle.
			numberOfInnerRects = ((mMainRectHeight / mInnerRectsHeight) * (mMainRectWidth / mInnerRectsWidth));

        //Run loops to generate rects and position them accordingly.
	   //int tCount;

			for(int k = vHeightDivision; k>0; k--, i+=vHeight ,j = this->mRectListPos.getY()){
				for(int p = vWidthDivision; p>0; p-- , j += vWidth){
		this->mInnerRectList.push_back(new CBrick(vWidth,vHeight,IPoint(i,j)));
		
				}

			}

		cout<<"Bricks stored in the array list"<<this->mInnerRectList.size()<<endl;
	return true;
}

//this must act according to a squence
bool RectanglesBreaker::BreakRectCustom()
{
   return true;
}

int RectanglesBreaker::getInnerRectCount()
{
	return numberOfInnerRects;
}

vector<CBrick*> RectanglesBreaker::getBrokenRectList()
{
	return this->mInnerRectList;
}

IPoint RectanglesBreaker::getInitPos()
{
	return mRectListPos;
}

void RectanglesBreaker::setInitPos(IPoint pPos)
{
	this->mRectListPos = pPos;
}
