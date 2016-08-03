#pragma once

#include "Library\EngineCore.h"

extern SpriteBatch* sb;
extern float gravity;
extern Moves moves;


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


		std::map<std::string, Texture*> textures;


	private:

		EngineCore engine;

		GameState currentGameState = InitGS;

		Player* players[4];
		int noPlayers = 0;

		bool _quit;

		Texture* tex [20];
		LevelData* lev[20];
		Camera* camera;
		int noMaps, noEnemy;

};