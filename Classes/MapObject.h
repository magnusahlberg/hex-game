//
//  MapObject.h
//  hex-game
//
//  Created by Johan Ekholm
//

#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "Observable.h"
#include "Action.h"
#include "Item.h"
#include "toolkit.h"
#include "json-forwards.h"
#include <vector>

namespace MapObjectNS {
    const int PARTY = 1;
    const int CITY = 2;
    const int DUNGEON = 3;
}

//struct ActionState;
class Item;

namespace MapObjectCategory {
    const int PARTY = 1;
    const int BUILDING = 2;
    const int CITY = 2;
    const int DUNGEON = 3;
};


struct MapObjectState {
    MPoint pos;
    std::vector<ActionState> actions;
	int owner;
};

class MapObject : public ItemHandler, public Observable {
    
protected:
    int _category;
    MPoint _pos;
    int _id;
    int _owner;
    int _layer;
    int _visualType;
	std::string _text;
    std::map<int, AdventureAction*> _actions;
    std::vector<UnitModel*> _memberUnits;
    

public:
    virtual ~MapObject();
    MapObject();
    MapObject(int category, MPoint pos, int owner, int layer, int visualType, std::vector<int> actionIds, const std::vector<UnitModel*>& members);
    Json::Value serialize();
    void deserialize(Json::Value& root);

    MPoint getPosition();
    AdventureAction* addAction(int action);
	UnitModel* addMember(UnitModel* unit);
    bool canMoveTo(const MPoint& pos);
	void doAction(const ActionState& statePoint);
	void doAI();
	void doTurn();
    std::vector<ActionState> getActions();
	int getId();
    int getLayer();
	UnitModel* getMember(int unitId);
    std::vector<UnitModel*> getMembers();
    int getOwner();
	std::string getText();
    int getVisualType();
    virtual MapObjectState getState();
    bool matchesCategory(int category);
    void move(const MPoint& targetPos);
    std::vector<UnitModel*> removeMembers();
    void setId(int id);
};


#endif