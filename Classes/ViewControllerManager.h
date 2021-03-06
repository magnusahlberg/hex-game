/*
 *  ViewControllerManager.h
 *  hex-game
 *
 *  Created by Johan Ekholm on 2011-04-17.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
#include "toolkit.h"
class ViewController;
class HexMap;
class ShapeImage;

class ViewControllerManager {
    static ViewControllerManager* _instance;
	std::vector<ViewController*> _views, _stagedViews;
    HexMap *_mapView;
    ViewController* _focus;
    GPoint _cameraPos;
    GPoint _cameraTargetPos;	
    ShapeImage *_hudBackground;

    ViewControllerManager();

public:
    static ViewControllerManager* instance();
    static void destroy();

	void add(ViewController* view);
    GPoint adjustForCamera(const GPoint& pos);
	void applyCameraBoundaries(GPoint& pos);
    void centerCamera(const GPoint& pos, bool sweep=true);
	void centerCamera(const MPoint& pos, bool sweep=true);
    void draw();
    void drawGUI();
    void drawMap();
    ViewController* getFocus();
    ViewController* getTouched(const GPoint& point);
	void insert(ViewController* view);
    void moveCamera(const GPoint& pos);
	void passFocus();
    void purge();
    void remove(ViewController* view);
    void removeAllSoftly();
    void removeSoft(ViewController* view);
    void setCameraPosition(const GPoint& pos);
    void setCameraTargetPosition(const GPoint& pos);
    void setFocus(ViewController* view);
    void setMapView(HexMap* mapView);
    GPoint transformModelPositionToView(const MPoint& pos);
    void translateToCamera();
    void translateToCameraAndPosition(const GPoint& pos);
    void update();
	void updateCamera();
};

