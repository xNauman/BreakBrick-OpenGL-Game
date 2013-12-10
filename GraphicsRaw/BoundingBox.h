/*
 * BoundingBox.h
 *
 *  Created on: Mar 30, 2010
 *      Author: Admin
 */

#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_
#include "../mathraw/IRect.h"

class BoundingBox:public IRect {
public:
	BoundingBox();
	virtual ~BoundingBox();
};

#endif /* BOUNDINGBOX_H_ */
