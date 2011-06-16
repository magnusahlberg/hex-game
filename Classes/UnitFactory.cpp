/*
 *  UnitFactory.cpp
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-05-02.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
#include "UnitFactory.h"
#include "ModelManager.h"
#include "ViewControllerManager.h"
#include "UnitModel.h"
#include "UnitView.h"
#include "Action.h"

UnitFactory::UnitFactory(ViewControllerManager* viewControllerManager) {
    //_modelManager = modelManager; 
    _viewControllerManager = viewControllerManager;
}

void UnitFactory::produceAndRegisterUnit(const std::string& unitClass, int owner, const MPoint& pos, int direction) {
    UnitModel* unit;
    UnitView* view;
    int hp, ap, power, skill, defense, image;
    std::vector<int> actions;
    
    if (unitClass == "swordsman") {
        hp = 3; ap = 3; power = 3; skill = 2; defense = 3; image = 0;
        actions.push_back(ACTION_MOVE); actions.push_back(ACTION_STRIKE);
    } else if (unitClass == "soldier") {
        hp = 2; ap = 3; power = 2; skill = 2; defense = 2; image = 1;
        actions.push_back(ACTION_MOVE); actions.push_back(ACTION_STRIKE);
    } else if (unitClass == "archer") {
        hp = 2; ap = 3; power = 2; skill = 3; defense = 1; image = 2;
        actions.push_back(ACTION_MOVE); actions.push_back(ACTION_FIRE);
    } else if (unitClass == "channeler") {
        hp = 2; ap = 3; power = 2; skill = 3; defense = 1; image = 3;
        actions.push_back(ACTION_MOVE); actions.push_back(ACTION_BURN); actions.push_back(ACTION_GALE);
    } else {
        return;
    }
    
    unit = new UnitModel(pos.x, pos.y, direction, owner, hp, ap, power, skill, defense, actions);
    //unit = new UnitModel(pos.x, pos.y, direction, owner);
	view = new UnitView(unit, 64.0f, 64.0f, image);

    unit->addObserver(view);
    ModelManager::instance()->add(unit);
    _viewControllerManager->add(view);

}

