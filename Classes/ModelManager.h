/*
 *  ModelManager.h
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-05-02.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
#include <map>
#include "toolkit.h"

class UnitModel;
class HexMapModel;
class MapObject;

class ModelManager {
    static ModelManager* _instance;
	std::map<int, UnitModel*> _units;
	std::map<int, MapObject*> _mapObjects;
    HexMapModel *_map;
    int _unitIdCounter, _objectIdCounter;
    
    ModelManager();

public:
    static ModelManager* instance();
    static void destroy();

    void addMapObject(MapObject* object);
	void addUnit(UnitModel*);
    HexMapModel* getMap();    
    std::vector<MapObject*> getAllMapObjects();
    std::vector<UnitModel*> getAllUnits();
    UnitModel* getClosestTo(const MPoint& pos);
    int getDistanceToClosestEnemy(int owner, const MPoint& pos);
    MapObject* getMapObjectAtPos(const MPoint& pos);
    MapObject* getMapObjectById(int mapObjectId);
    int getOwnerWithNoUnits();
    UnitModel* getUnitAtPos(const MPoint& pos);
    UnitModel* getUnitById(int unitId);
    bool mapObjectExistAtPos(int category, const MPoint& pos);
    void deleteAllMapObjects();
    void deleteAllUnits();
    std::vector<UnitModel*> removeAllUnits();
    void removeMapObject(int objectId);
    void removeUnit(int unitId);
    void setMap(HexMapModel* map);
    void tick();
};

