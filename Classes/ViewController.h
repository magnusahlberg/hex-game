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
protected:	
    GPoint _pos;
	GLfloat _width, _height;
	bool _hasFocus;
    
	//virtual void reactToEvent(int eventType) = 0;
	
public:
    ViewController();
	bool isWithin(const GPoint& point);
    void setFocus(bool hasFocus);
	virtual bool handleEvent(const TouchEvent& event) = 0;
	virtual void draw() = 0;
	virtual void drawGUI() = 0;
};