/*
 *  ModelManager.mm
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-05-02.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ModelManager.h"
#include "UnitModel.h"
#include "HexMapModel.h"
#include "geometry.h"
#include <iostream>

ModelManager* ModelManager::_instance = 0;

void ModelManager::destroy() {
	if (_instance != 0) {
		_instance->_units.clear();
        delete _instance->_map;
		delete _instance;
		_instance=0;
	}
}

ModelManager::ModelManager() {
    
}

void ModelManager::add(UnitModel* unit) {
	_units.push_back(unit);
}

void ModelManager::remove(UnitModel* unit) {
    // to-do: implement remove unit from vector and delete 
    for (std::vector<UnitModel*>::iterator it = _units.begin(); it != _units.end(); ++it) {
		if (*it == unit) {
            delete (*it);
            *it = 0;
            //std::cout << "Iterator pointer: " << *it << std::endl;
            return;
        }
	}
}

void ModelManager::setMap(HexMapModel* map) {
    _map = map;
}

HexMapModel* ModelManager::getMap() {
    return _map;
}

void ModelManager::tick() {
    std::cout << "--- Tick ---" << std::endl;
	for (std::vector<UnitModel*>::iterator it = _units.begin(); it != _units.end();) {
        //std::cout << "Iterator pointer: " << *it << std::endl;
        if ((*it) != 0) {
            (*it)->tick();
            ++it;
        } else {
            it = _units.erase(it);
        }
	}
}

UnitModel* ModelManager::getUnitAtPos(const MPoint& pos) {
	for (std::vector<UnitModel*>::iterator it = _units.begin(); it != _units.end(); ++it) {
		if ((*it)->getPosition() == pos) {
            return *it;
        }
	}
    return 0;
}

UnitModel* ModelManager::getClosestTo(const MPoint& pos) {
    int distance = 0;
    int minDistance = 99;
    UnitModel* closestUnit = 0;
    
	for (std::vector<UnitModel*>::iterator it = _units.begin(); it != _units.end(); ++it) {
		distance = hexDistance(pos, (*it)->getPosition());
        if ((*it)->getOwner() == 1 && distance < minDistance) {
            minDistance = distance;
            closestUnit = (*it);
            std::cout << "Unit found at distance: " << minDistance << std::endl;
        }
	}
    return closestUnit;
}

std::vector<UnitModel*> ModelManager::getAllUnits() {
    return _units;
}
