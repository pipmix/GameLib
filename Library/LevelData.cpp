#include "LevelData.h"


LevelData::LevelData(std::wstring fN, Texture* t, int x, int y) : fileName(fN), tex(t), originX(x), originY(y){

	LoadXML();
	sourceRect = { 0, 0, texTileW , texTileH };

}




void LevelData::Draw() {

	int curCol = 0;
	int curRow = 0;
	for (int i = 0; i < mapArrSize; i++) {
		MoveRect(i);
		if (mapArrayData[i] != 0)sb->Draw(tex->textureResourceView, Vector2((float)(curCol*texTileW + originX), (float)(curRow*texTileH + originY)), &sourceRect, Colors::White);

		if (curCol < mapNoTilesX - 1) curCol++;
		else {
			curCol = 0;
			curRow++;
		}
	}

}
void LevelData::MoveRect(int i) {

	// starts at 0
	int tLocX = (mapArrayData[i] % texNoColumns) - 1; // 2
	int tLocY = (mapArrayData[i] / texNoColumns) ; //12

	sourceRect.left = (tLocX * texTileW) ;
	sourceRect.top = (tLocY * texTileH) ;
	sourceRect.right = sourceRect.left + texTileW;
	sourceRect.bottom = sourceRect.top + texTileH;

}



void LevelData::Update() {

}


void LevelData::LoadXML() {

	tinyxml2::XMLDocument		doc;
	XMLNode*					node;
	XMLNode*					loopNode;
	XMLElement*					element;

	wstring comb = gPath + L"Levels/" + fileName + L".tmx";

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::string strPath = converter.to_bytes(comb);



	doc.LoadFile(strPath.c_str());

	//DOCUMENT
	node = doc.FirstChild();
	//XML
	node = node->NextSibling();
	//MAP
	element = node->ToElement();
	mapNoTilesX = stoi(element->Attribute("width"));
	mapNoTilesY = stoi(element->Attribute("height"));
	mapTileW = stoi(element->Attribute("tilewidth"));
	mapTileH = stoi(element->Attribute("tileheight"));
	mapArrSize = mapNoTilesX*mapNoTilesY;
	mapArrayData = new short int[mapArrSize];
	//TILESET
	node = node->FirstChild();
	element = node->ToElement();
	textureName = element->Attribute("name");
	texTileW = stoi(element->Attribute("tilewidth"));
	texTileH = stoi(element->Attribute("tileheight"));
	texNoColumns = stoi(element->Attribute("columns"));
	texNoTiles = stoi(element->Attribute("tilecount"));
	texNoRows = texNoTiles / texNoColumns;
	//IMAGE
	node = node->FirstChild();
	element = node->ToElement();
	node = node->Parent();
	node = node->NextSibling();
	//LAYER
	element = node->ToElement();
	mapID = element->Attribute("name");
	//DATA
	//LOAD MAP DATA
	node = node->FirstChild();
	element = node->ToElement();
	const char* getData = element->GetText();
	char mapData[8192]; //maybe increase size?
	strcpy(mapData, getData);
	int	wordCount = 0;
	char * pch;
	pch = strtok(mapData, " ,\n");
	while (pch != NULL) {
		mapArrayData[wordCount] = stoi(pch);
		wordCount++;
		pch = strtok(NULL, " ,\n");
	}
	//END LOAD MAP DATA
	node = node->Parent();

	string tempStr = "";
	string tempStr3 = "";
	while (1) {
		node = node->NextSibling();
		if (node == NULL)break;
		//OBJECTGROUP
		element = node->ToElement();

		tempStr = element->Attribute("name");
		if (tempStr == "Waypoint") {
			noWayPoints = countObjectsXML(node->FirstChild());
			wayPoints = new Location[noWayPoints];
		}
		else if (tempStr == "Collide") {
			noColliders = countObjectsXML(node->FirstChild());
			collisionRects = new RECT[noColliders];
		}
		else if (tempStr == "Spawn") {
			noSpawnPoints = countObjectsXML(node->FirstChild());
			spawnPoints = new Location[noSpawnPoints];
		}
		else if (tempStr == "Link") {
			noLinks = countObjectsXML(node->FirstChild());
			linkRects = new RECT[noLinks];
		}
		else if (tempStr == "Item") {
			noItems = countObjectsXML(node->FirstChild());
			itemPoints = new Location[noItems];
		}
		else if (tempStr == "Trigger") {
			noTriggers = countObjectsXML(node->FirstChild());
			triggerRects = new RECT[noTriggers];
		}
		//OBJECT
		loopNode = node->FirstChild();
		int i = 0;
		while (1) {
			string tempStr2 = "";

			element = loopNode->ToElement();
			if (element != NULL)tempStr2 = element->Attribute("type");
			if (tempStr2 == "rect") {
				if (tempStr == "Collide") {
					collisionRects[i].left = stoi(element->Attribute("x")) + originX;
					collisionRects[i].top = stoi(element->Attribute("y")) + originY;
					collisionRects[i].right = (stoi(element->Attribute("width")) + collisionRects[i].left);
					collisionRects[i].bottom = (stoi(element->Attribute("height")) + collisionRects[i].top);
				}
				else if (tempStr == "Link") {
					linkRects[i].left = stoi(element->Attribute("x")) + originX;
					linkRects[i].top = stoi(element->Attribute("y")) + originY;
					linkRects[i].right = (stoi(element->Attribute("width")) + collisionRects[i].left);
					linkRects[i].bottom = (stoi(element->Attribute("height")) + collisionRects[i].top);
				}
				else if (tempStr == "Trigger") {
					triggerRects[i].left = stoi(element->Attribute("x")) + originX;
					triggerRects[i].top = stoi(element->Attribute("y")) + originY;
					triggerRects[i].right = (stoi(element->Attribute("width")) + collisionRects[i].left);
					triggerRects[i].bottom = (stoi(element->Attribute("height")) + collisionRects[i].top);
				}
			}
			else if (tempStr2 == "circle") {
				//if (element->Attribute("name") != NULL)
				tempStr3 = element->Attribute("name");
				xx = stoi(element->Attribute("x"));
				yy = stoi(element->Attribute("y"));
				if (tempStr == "Waypoint") {
					wayPoints[i].SetLocation(xx, yy, 1, tempStr3);
				}
				else if (tempStr == "Spawn") {
					spawnPoints[i].SetLocation(xx, yy, 1, tempStr3);
				}
				else if (tempStr == "Item") {
					itemPoints[i].SetLocation(xx, yy, 1, tempStr3);
				}
			}
			loopNode = loopNode->NextSibling();
			i++;
			if (loopNode == NULL)break;
		}
	}

}

int LevelData::countObjectsXML(tinyxml2::XMLNode* n) {
	tinyxml2::XMLNode* countNode = n;
	int x = 0;
	if (countNode == NULL)return x;
	while (1) {
		x++;
		countNode = countNode->NextSibling();
		if (countNode == NULL)return x;
	}
}

