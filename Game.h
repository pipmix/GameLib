#pragma once

#include "Library\EngineCore.h"

extern SpriteBatch* sb;
extern Input* input;
extern float gravity;
extern Moves moves;
extern HINSTANCE hInst;
extern HWND hWnd;

extern std::string debugStr01;
extern std::string debugStr02;


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

		void PrintString(string s, int x, int y);


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

};