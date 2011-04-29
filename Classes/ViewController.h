/*
 *  ViewController.h
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-04-17.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "toolkit.h"

//struct GPoint;
struct TouchEvent;

class ViewController {
	GPoint _pos;
	GLfloat _width, _height;
	
	virtual void reactToEvent(int eventType) = 0;
	
public:
	bool isWithin(const GPoint& point);
	bool handleEvent(const TouchEvent& event);
	virtual void draw() = 0;
};