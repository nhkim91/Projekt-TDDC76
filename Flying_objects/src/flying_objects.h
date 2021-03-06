/*
 * Flying_objects.h
 *
 *  Created on: 23 nov 2014
 *      Author: samanthavi
 */

#ifndef FLYING_OBJECTS_H_
#define FLYING_OBJECTS_H_
#include <vector>


////////////////////////////////////////////////////////////////
class flying_objects
{
public:
	virtual void  hit(flying_objects&)  = 0;
	virtual std::vector<int> movement() const = 0;
	virtual int get_life() const = 0;


	virtual ~flying_objects() {}

};


////////////////////////////////////////////////////////////////

#endif /* FLYING_OBJECTS_H_ */
