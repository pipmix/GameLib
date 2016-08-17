#include "Game.h"


Game::Game() {
	noMaps = noEnemy  = 0;
	input = new Input();

	player = new Player();



	textures["chara"] = new Texture(L"chara", engine._device);
	textures["chara"]->SetAsTileMap(4,4,16,16);

	textures["dat"] = new Texture(L"dat", engine._device);
	textures["dat"]->SetAsTileMap(16, 16, 8, 8);

	textures["alpha"] = new Texture(L"alpha", engine._device);
	textures["alpha"]->SetAsTileMap(8, 4, 8, 8);

	tex[0] = new Texture(L"wallTopFloor", engine._device);
	tex[1] = new Texture(L"ruins", engine._device);

	lev[0] = new LevelData(L"level02", tex[1], 0 ,0);
	lev[1] = new LevelData(L"level03", tex[1], 320, 320);
	noMaps = 2;


	player->texture = textures["chara"];
	player->InitCollision();

	camera = new Camera();
	SetGameState(GameGS);

	
	
}
Game::~Game() {


}
bool Game::Update() {

	engine.engineTimer.Update();


	if (currentGameState == GameGS) {

		for (int i = 0; i < noMaps; i++) lev[i]->Update();
		player->Update(engine.engineTimer.GetDelta());

		if (lev[0]->CollideEnclosureRect(player)) {
			lev[0]->Collide(player);
			lev[0]->CollidePoints(player);
		}
		if (lev[1]->CollideEnclosureRect(player)) {
			lev[1]->Collide(player);
			lev[1]->CollidePoints(player);
		}




		//player->SetCollision();
		//isCollide = lev[0]->Collide2(player);


		camera->Update(0.0f);


	}






	return 0;


}
void Game::Draw() {

	const float fillColor[] = { 0.0f, 0.0f, 0.2f, 1.000f };
	engine.context->ClearRenderTargetView(engine.rtv, fillColor);

	if (currentGameState = GameGS) {





		// Draw Everything else
		sb->Begin(SpriteSortMode_Deferred, nullptr, engine._commonStates->PointWrap(), nullptr, nullptr, nullptr, camera->transformMatrix(player->position));
		for (int i = 0; i < noMaps; i++) lev[i]->Draw();
		player->Draw();
		sb->End();



		// DRAW HUD
		sb->Begin(SpriteSortMode_Deferred, engine._commonStates->NonPremultiplied());

		if (isCollide) {
			textures["dat"]->MoveSourceRect(0);
			sb->Draw(textures["dat"]->textureResourceView, XMFLOAT2(0.0f, 10.0f), &textures["dat"]->sourceRect);
			textures["dat"]->MoveSourceRect(1);
			sb->Draw(textures["dat"]->textureResourceView, XMFLOAT2(0.0f, 18.0f), &textures["dat"]->sourceRect);
			textures["dat"]->MoveSourceRect(2);
			sb->Draw(textures["dat"]->textureResourceView, XMFLOAT2(0.0f, 26.0f), &textures["dat"]->sourceRect);
			textures["dat"]->MoveSourceRect(3);
			sb->Draw(textures["dat"]->textureResourceView, XMFLOAT2(0.0f, 34.0f), &textures["dat"]->sourceRect);



		}

		textures["alpha"]->MoveSourceRect(1);
		sb->Draw(textures["alpha"]->textureResourceView, XMFLOAT2(30.0f, 34.0f), &textures["alpha"]->sourceRect);

		PrintString("af ce", 0200, 200);
		PrintString("aaaaa bbbbbb aaaaa cccc fffff", 0, 0);

		PrintString(debugStr01, 0, 20);
		PrintString(debugStr02, 0, 30);

		sb->End();


		
		
	}


	engine._swapChain->Present(1, 0);
}

void Game::Suspend() {

}
void Game::Resume() {

}
void Game::Resize() {

}
void Game::Minimize() {

}

void Game::Restore() {

}

void Game::DeviceLost() {



}


void Game::SetGameState(GameState gs) {

	currentGameState = gs;

	switch (currentGameState) {
	case InitGS: {
		break;
	}
	case TitleGS: {
		break;
	}
	case GameGS: {
		break;
	}


	}
}



void Game::PrintString(string s, int x, int y) {
	Texture* t = textures["alpha"];
	int index = 0;
	int tW = t->tileW;


	// num 0 = 48
	// num 9 = 57
	// . = 46
	// ! = 33      , = 44
	

	for (int i = 0; i <= s.length(); i++) {

		if (static_cast<int>(s[i]) == 32)index = 31;
		else index = (static_cast<int>(s[i])) - 96;

		textures["alpha"]->MoveSourceRect(index);
		sb->Draw(textures["alpha"]->textureResourceView, XMFLOAT2((float)((i*tW)+x), (float)y), &textures["alpha"]->sourceRect);


	}



}