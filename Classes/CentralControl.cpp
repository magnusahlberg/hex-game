/*
 *  CentralControl.mm
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-04-16.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "CentralControl.h"
#include "TextureCatalog.h"
#include "ViewController.h"
#include "ViewControllerManager.h"
#include "ModelManager.h"
#include "UnitFactory.h"
#include "HexMap.h"
#include "InputManager.h"
#include "toolkit.h"

#include "UnitView.h"
#include "UnitModel.h"

CentralControl* CentralControl::_instance = 0;

void CentralControl::destroy() {
	if (_instance != 0) {
        
        delete _instance->_input;
        delete _instance->_hexMap;
        delete _instance->_viewControllerManager;
        delete _instance->_modelManager;
        delete _instance->_unitFactory;
        
		delete _instance;
		_instance=0;
	}
}

CentralControl::CentralControl() {
    _mode = 1;
	
	TextureCatalog* catalog = TextureCatalog::instance();
		
	_hexMap = new HexMap(catalog->get("hexTiles"), 4, 4, 80.0f, 80.0f);
    _viewControllerManager = new ViewControllerManager();
    _modelManager = new ModelManager();
    _unitFactory = new UnitFactory(_modelManager, _viewControllerManager);
	_input = new InputManager();
    
    _unitFactory->produceAndRegisterUnit("soldier", 1, MPointMake(0, 0));
    _unitFactory->produceAndRegisterUnit("soldier", 1, MPointMake(2, 1));
    
}

void CentralControl::update() {
	TouchEvent event;
	
	if (_input->hasEvent()) {
		
		event = _input->popEvent();
		
		// dispatch event to current event handler
		switch (this->_mode) {
			case 1:
				this->handleEventNormal(event);
				break;
				
			case 2:
				this->handleEventFocus(event);				
break;
				
		}
	}
}

void CentralControl::draw() {
	
	switch(_mode) {
		case 1:
			_hexMap->draw();
			_viewControllerManager->draw();
            //_viewControllerManager->drawGUI();
			break;
		case 2:
			_hexMap->draw();
			_viewControllerManager->draw();
            _viewControllerManager->drawGUI();
			break;
	}
	
}

void CentralControl::handleEventNormal(const TouchEvent& event) {
    ViewController* selection = 0;
	 
	if (event.type == 1) {
        selection = _viewControllerManager->getTouched(event.point);
	 
        if (selection != 0) {
            _selectedViewController = selection;
            this->switchMode(2);
        }
    }
}

void CentralControl::handleEventFocus(const TouchEvent& event) {
    _selectedViewController->handleEvent(event);
	
	if (event.type == 3) {
		this->switchMode(1);
	}	
}

void CentralControl::touchesBegan(const GPoint& touchPoint) {
	_input->touchesBegan(touchPoint);
}

void CentralControl::touchesMoved(const GPoint& touchPoint) {
	_input->touchesMoved(touchPoint);
}

void CentralControl::touchesEnded(const GPoint& touchPoint) {
	_input->touchesEnded(touchPoint);
}

void CentralControl::touchesCancelled(const GPoint& touchPoint) {
	_input->touchesCancelled(touchPoint);
}


void CentralControl::switchMode(int mode) {
	_mode = mode;
}
