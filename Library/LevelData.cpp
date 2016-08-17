#include "LevelData.h"


LevelData::LevelData(std::wstring fN, Texture* t, int x, int y) : fileName(fN), tex(t), originX(x), originY(y){

	LoadXML();
	sourceRect = { 0, 0, texTileW , texTileH };
	enclosureRect = { 0,0,0,0 };

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
			if (tempStr2 == "Rect") {
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

	std::ofstream myfile;
	myfile.open("example.txt");
	myfile << noColliders ;

	for (int i = 0; i < noColliders; i++) {
		myfile << "\n" << collisionRects[i].left << "  " << collisionRects[i].top << "  " << collisionRects[i].right << "  " << collisionRects[i].bottom;

	}
	myfile.close();


	SetEnclosureRect();

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



bool LevelData::Collide(Player* p) {


	//Intersect(p->collision, p->velocity, p->position);

	Vector4 b1;
	Vector4 b2;
	b1.x = p->collision.left;
	b1.y = p->collision.top;
	b1.w = p->collision.right - p->collision.left;
	b1.z = p->collision.bottom - p->collision.top;
	for (int i = 0; i < noColliders; i++) {
		b2.x = (float)(collisionRects[i].left);
		b2.y = (float)(collisionRects[i].top);
		b2.w = (float)(collisionRects[i].right - collisionRects[i].left);
		b2.z = (float)(collisionRects[i].bottom - collisionRects[i].top);
		p->velocity.x = p->velocity.y = 0.0f;
		float l = b2.x - (b1.x + b1.w);
		float r = (b2.x + b2.w) - b1.x;
		float t = b2.y - (b1.y + b1.z);
		float b = (b2.y + b2.z) - b1.y;
		if (l > 0 || r < 0 || t > 0 || b < 0)
			continue;
		p->velocity.x = abs(l) < r ? l : r;
		p->velocity.y = abs(t) < b ? t : b;
		if (abs(p->velocity.x) < abs(p->velocity.y))p->velocity.y = 0.0f;
		else p->velocity.x = 0.0f;
		// NEED TO RESET COLLISION HERE IF MOVED
		p->position += p->velocity;
		p->SetCollision();
		p->SetEdgePoints();
		continue;
	}
	return 0;









}



// This just shows if something is overlapping, for testing collision boxes, wont show anything if AABB does the moving
bool LevelData::Collide2(Player* p) {

	RECT RectA = p->collision;
	RECT RectB;
	for (int i = 0; i < noColliders; i++) {

		RectB = collisionRects[i];
		if (RectA.left < RectB.right && RectA.right > RectB.left &&
			RectA.top < RectB.bottom && RectA.bottom > RectB.top)return 1;
	}
	return 0;
}


bool LevelData::CollideEnclosureRect(Player* p) {
	RECT RectA = p->collision;
	SetEnclosureRect();
	if (RectA.left < enclosureRect.right && RectA.right > enclosureRect.left &&
			RectA.top < enclosureRect.bottom && RectA.bottom > enclosureRect.top)return 1;



	return 0;

}

// Reusable in case moving levels
void LevelData::SetEnclosureRect() {

	enclosureRect = {originX, originY, originX + (mapNoTilesX*texTileW), originY + (mapNoTilesY*texTileH)};


}

bool LevelData::CollidePoints(Player* p) {

	return 0;
}
