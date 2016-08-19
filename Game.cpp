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


	/*
	part01 = new Particle(
		XMFLOAT2(150.0f, 150.0f), 
		XMFLOAT2(2.0f, -XM_PIDIV2),
		XMFLOAT2(0.1f, 0.1f)
	);
	*/

	part01 = new Particle(
		XMFLOAT2(10.0f, 10.0f)
	);

	part01->SetSpeed(part01->velocity, 2.0f);
	part01->SetAngle(part01->velocity, XM_PI / 4);

	particleTest = 100;
	part = new Particle*[particleTest];
	for (int i = 0; i < particleTest; i++) {

		part[i] = new Particle(
			XMFLOAT2(0.0f, 50.0f),
			XMFLOAT2(0.0f, 0.0f),
			XMFLOAT2(0.0f, 0.06f)
		
		);

		part[i]->SetSpeed(part[i]->velocity, Randomize.GetRealDist(0.01f,2.0f));
		part[i]->SetAngle(part[i]->velocity, Randomize.GetRealDist(0.0f, XM_2PI));

		part[i]->friction = { 0.15f, 0.0f };

		//spd  0.15, angle 0


		//part[i]->SetAngle(Randomize.GetRealDist(0.0f, XM_2PI));

		/*
			part[i] = new Particle(XMFLOAT2(00.0f, 00.0f), XMFLOAT2(
			Randomize.GetRealDist(0.01f, XM_2PI),
			Randomize.GetRealDist(0.0f, XM_2PI)
		));
		
		
		*/

		/*
		particles.push_back(new Particle(XMFLOAT2(00.0f, 00.0f), XMFLOAT2(
			Randomize.GetRealDist(0.01f, XM_2PI),
			Randomize.GetRealDist(0.0f, XM_2PI)
		)));*/

	}
	
	

	camera = new Camera();
	SetGameState(GameGS);



	
	
}
Game::~Game() {


	for (int i = 0; i < particleTest; ++i)
	{
		delete[] part[i];
	}
	delete[] part;

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

		//for (auto i : particles)i->Update();

		
		
		for (int i = 0; i < particleTest; i++) part[i]->Update();
		part01->Update();



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

		//sb->Begin(SpriteSortMode_Deferred, engine._commonStates->NonPremultiplied());
		for (int i = 0; i < noMaps; i++) lev[i]->Draw();
		player->Draw();

		//textures["chara"]->MoveSourceRect(2);
		sb->Draw(textures["chara"]->textureResourceView, part01->position, &textures["chara"]->sourceRect);
		for (int i = 0; i < particleTest; i++) sb->Draw(textures["chara"]->textureResourceView, part[i]->position, &textures["chara"]->sourceRect);



		if (DebugRect01 != nullptr)DrawRect_Game(DebugRect01);
		if (DebugRect02 != nullptr)DrawRect_Game(DebugRect02);
		if (DebugRect03 != nullptr)DrawRect_Game(DebugRect03);
		if (DebugRect04 != nullptr)DrawRect_Game(DebugRect04);

		if (DebugF2_01 != nullptr)DrawF2_Game(DebugF2_01);
		if (DebugF2_02 != nullptr)DrawF2_Game(DebugF2_02);
		if (DebugF2_03 != nullptr)DrawF2_Game(DebugF2_03);
		if (DebugF2_04 != nullptr)DrawF2_Game(DebugF2_04);

		if (DebugF4_01 != nullptr)DrawF4_Game(DebugF4_01);
		if (DebugF4_02 != nullptr)DrawF4_Game(DebugF4_02);

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

		if (player->edgeCollide_L)PrintString_Game("aa", 0, 60);
		if (player->edgeCollide_T)PrintString_Game("bb", 15, 50);
		if (player->edgeCollide_R)PrintString_Game("cc", 30, 60);
		if (player->edgeCollide_B)PrintString_Game("dd", 15, 70);


		
		//for (int i = 0; i < particleTest; i++) sb->Draw(textures["chara"]->textureResourceView, part[i]->position, &textures["chara"]->sourceRect);
			
		
		



		/*
		for (auto i : particles) {
			
			textures["chara"]->MoveSourceRect(1);
			sb->Draw(textures["chara"]->textureResourceView, i->position , &textures["chara"]->sourceRect);
			

		}


		*/
		
		
		

		/*
		textures["alpha"]->MoveSourceRect(1);
		sb->Draw(textures["alpha"]->textureResourceView, XMFLOAT2(30.0f, 34.0f), &textures["alpha"]->sourceRect);

		PrintString("af ce", 0200, 200);
		PrintString("aaaaa bbbbbb aaaaa cccc fffff", 0, 0);
		*/

		PrintString_Game(debugStr01, 0, 20);
		PrintString_Game(debugStr02, 0, 30);

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



void Game::PrintString_Game(string s, int x, int y) {
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


void Game::DrawRect_Game(RECT* r) {

	RECT tempREct = { 3,1,4,2 };

	XMFLOAT2 tempFloat = { (float)r->left, (float)r->top };
	sb->Draw(textures["alpha"]->textureResourceView, tempFloat, &tempREct);

	tempFloat = { (float)r->right, (float)r->top };
	sb->Draw(textures["alpha"]->textureResourceView, tempFloat, &tempREct);

	tempFloat = { (float)r->right, (float)r->bottom };
	sb->Draw(textures["alpha"]->textureResourceView, tempFloat, &tempREct);

	tempFloat = { (float)r->left, (float)r->bottom };
	sb->Draw(textures["alpha"]->textureResourceView, tempFloat, &tempREct);



}


void Game::DrawF2_Game(XMFLOAT2* f) {
	RECT tempREct = { 3,1,4,2 };
	XMFLOAT2 tempFloat = { f->x, f->y };

	//textures["alpha"]->sourceRect = { 4,3,4,3 };
	//sb->Draw(textures["alpha"]->textureResourceView, XMFLOAT2(2,2), &tempREct );
	sb->Draw(textures["alpha"]->textureResourceView, tempFloat, &tempREct);

}

void Game::DrawF4_Game(XMFLOAT4* f) {

	RECT tempREct = { 3,1,4,2 };


	XMFLOAT2 tempFloat = { f->x, f->y };


	sb->Draw(textures["alpha"]->textureResourceView, tempFloat, &tempREct);

	tempFloat = { f->z, f->y };
	sb->Draw(textures["alpha"]->textureResourceView, tempFloat, &tempREct);

	tempFloat = { f->z, f->w };
	sb->Draw(textures["alpha"]->textureResourceView, tempFloat, &tempREct);

	tempFloat = { f->x, f->w };
	sb->Draw(textures["alpha"]->textureResourceView, tempFloat, &tempREct);








}