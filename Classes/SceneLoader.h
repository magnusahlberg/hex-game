/*
 *  TextureCatalog.h
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-04-10.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SCENELOADER_H
#define SCENELOADER_H

#include <map>
#include <string>
#include "toolkit.h"


class SceneLoader {
	static SceneLoader* _instance;
    
	SceneLoader();

public:
	static SceneLoader* instance() {
		if (_instance == 0) {
			_instance = new SceneLoader();
		}
		
		return _instance;
	}
	
	static void destroy();
	
    void loadAdventureScene();
    void loadBattleScene();
    void switchToAdventureScene();
};

#endif