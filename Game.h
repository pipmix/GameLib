#pragma once

#include <DirectXMath.h>
#include <string>
#include <map>
#include <vector>



#include "Library\EngineCore.h"


using namespace DirectX;


extern int gWidth;
extern int gHeight;
extern int gScale;



extern SpriteBatch* sb;
extern Input* input;
extern float gravity;
extern HINSTANCE hInst;
extern HWND hWnd;

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


enum GameState { InitGS , TitleGS, GameGS };


class Game {



	public:

		Game();
		~Game();

		bool Update();
		void Draw();
		void Suspend();
		void Resume();
		void Resize();
		void Minimize();
		void Restore();
		void DeviceLost();

		void SetGameState(GameState gs);

		void PrintString_Game(std::string s, int x, int y);
		void DrawRect_Game(RECT* r);
		void DrawF2_Game(XMFLOAT2* f);
		void DrawF4_Game(XMFLOAT4* f);
		std::map<std::string, Texture*> textures;


	private:

		EngineCore engine;

		GameState currentGameState = InitGS;

		Player* player;
		int noPlayers = 0;

		bool _quit;

		Texture* tex [20];
		LevelData* lev[20];
		Camera* camera;
		int noMaps, noEnemy;

		RECT heart;

		bool isCollide = 0;

		std::vector<Particle*> particles;

		Particle** part;

		Randomize Randomize;

		int particleTest;

		Particle* part01;

};