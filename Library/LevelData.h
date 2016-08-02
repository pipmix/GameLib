#pragma once
#include "../stdafx.h"
#include "../Util/tinyxml2.h"
#include "EngineDataTypes.h"
#include <locale>
#include <codecvt>
#include "Texture.h"

using namespace std;
using namespace tinyxml2;

extern std::wstring gPath;
extern SpriteBatch* sb;


class LevelData{


public:


	LevelData(std::wstring fN, Texture* t, int x, int y);
	int				countObjectsXML		(tinyxml2::XMLNode*);

	void			LoadXML				();
	void			SetLocation			(int x, int y);

	void			Draw();
	void			MoveRect(int i);
	void			Update();

	int originX, originY, xx, yy;
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


};