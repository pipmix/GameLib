#pragma once

#include "../Util/tinyxml2.h"
#include "EngineDataTypes.h"
#include "Player.h"
#include <fstream>
#include <iostream>
#include <locale>
#include <codecvt>



//#include "../VS/GameLib/Util.h"



using namespace std;
using namespace tinyxml2;

extern std::wstring gPath;
extern SpriteBatch* sb;

extern std::string debugStr01;
extern std::string debugStr02;


extern RECT* DebugRect01;
extern RECT* DebugRect02;
extern RECT* DebugRect03;
extern RECT* DebugRect04;

extern XMFLOAT2* DebugF2_01;
extern XMFLOAT2* DebugF2_02;
extern XMFLOAT2* DebugF2_03;
extern XMFLOAT2* DebugF2_04;

extern XMFLOAT4* DebugF4_01;
extern XMFLOAT4* DebugF4_02;



class LevelData{


public:


	LevelData(std::wstring fN, Texture* t, int x, int y);
	int				countObjectsXML		(tinyxml2::XMLNode*);

	void			LoadXML				();
	void			SetLocation			(int x, int y);

	void			Draw();
	void			MoveRect(int i);
	void			Update();
	void			SetEnclosureRect();
	bool			CollideEnclosureRect(Player* p);

	int originX, originY, xx, yy;
	RECT enclosureRect;
	std::string  textureName, mapID;
	std::wstring fileName;
	RECT sourceRect;

	int mapTileW, mapTileH, mapNoTilesX, mapNoTilesY, mapArrSize;
	int texTileW, texTileH, texNoColumns, texNoRows, texNoTiles;
	short int* mapArrayData;

	int noColliders, noWayPoints, noSpawnPoints, noTriggers, noLinks, noItems;
	Location* spawnPoints = nullptr;
	Location* itemPoints = nullptr;
	Location* wayPoints = nullptr;
	RECT* collisionRects = nullptr;
	RECT* triggerRects = nullptr;
	RECT* linkRects = nullptr;
	Texture* tex = nullptr;

	bool Collide(Player* p);
	bool Collide2(Player* p);


	bool CollidePoints(Player*p);

};