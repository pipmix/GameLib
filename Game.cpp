#include "Game.h"


Game::Game() {
	noMaps = noEnemy  = 0;

	players[0] = new Player();
	noPlayers++;


	textures["chara"] = new Texture(L"chara", engine._device);
	textures["chara"]->SetAsTileMap(4,4,16,16);


	tex[0] = new Texture(L"wallTopFloor", engine._device);
	tex[1] = new Texture(L"ruins", engine._device);

	lev[0] = new LevelData(L"level02", tex[1], 0 ,0);
	noMaps++;


	players[0]->tex = textures["chara"];
	players[0]->pos = { 50, 100 };

	camera = new Camera();
	SetGameState(GameGS);
}
Game::~Game() {


}
bool Game::Update() {

	engine.engineTimer.Update();

	auto k = engine._keyboard.GetState();
	auto m = engine._mouse.GetState();
	auto g = engine._gamePad.GetState(0);

	// KEYBOARD
	if (k.Escape)return 1;

	// MOUSE

	// GAMEPAD
	if (g.IsConnected()) {
		engine._buttons.Update(g);

		if (engine._buttons.a == GamePad::ButtonStateTracker::PRESSED) moves.attack = 1;
		if (engine._buttons.a == GamePad::ButtonStateTracker::RELEASED) moves.attack = 0;
		if (engine._buttons.b == GamePad::ButtonStateTracker::PRESSED) moves.jump = 1;
		if (engine._buttons.b == GamePad::ButtonStateTracker::RELEASED) moves.jump = 0;

		if (g.thumbSticks.leftX < 0) {
			moves.left = 1;
			moves.right = 0;
		}
		else if (g.thumbSticks.leftX > 0) {
			moves.left = 0;
			moves.right = 1;
		}
		else {
			moves.left = 0;
			moves.right = 0;
		}
		

		if (g.thumbSticks.leftY < 0) {
			moves.up = 1;
			moves.down = 0;
		}
		else if (g.thumbSticks.leftY > 0) {
			moves.up = 0;
			moves.down = 1;
		}
		else {
			moves.up = 0;
			moves.down = 0;
		}
		
		
		

		

		//state.triggers.left
		//state.IsAPressed()
	}

	switch (currentGameState) {
		case InitGS: {

		break;
		}
		case TitleGS: {


			break;
		}
		case GameGS: {

				 // Update Camera
				 // Update Enemys
				 // Update Players
				 // Update Weapons
				 // Update HUD

				 for (int i = 0; i < noMaps; i++) lev[i]->Update();
				 for (int i = 0; i < noPlayers; i++) players[i]->Update(engine.engineTimer.GetDelta());
				 camera->Update(0.0f); 

				 break;
		}

	}



	return 0;


}
void Game::Draw() {

	const float fillColor[] = { 0.0f, 0.0f, 0.2f, 1.000f };
	engine.context->ClearRenderTargetView(engine.rtv, fillColor);


	switch (currentGameState){
		case InitGS: {
			sb->Begin(SpriteSortMode_Immediate, engine._commonStates->NonPremultiplied());
			sb->Draw(tex[0]->textureResourceView, XMFLOAT2(0, 0));
			for (int i = 0; i < noMaps; i++) lev[i]->Draw();
			sb->End();

			break;
		}
		case TitleGS: {
			sb->Begin(SpriteSortMode_Immediate, engine._commonStates->NonPremultiplied());
			sb->Draw(tex[0]->textureResourceView, XMFLOAT2(0, 0));
			sb->End();

		break;
		}
		case GameGS: {
				 sb->Begin(SpriteSortMode_Deferred, nullptr, engine._commonStates->PointWrap(), nullptr, nullptr, nullptr, camera->transformMatrix());
				 for (int i = 0; i < noMaps; i++) lev[i]->Draw();
				 for (int i = 0; i < noPlayers; i++) players[i]->Draw();
				 sb->End();
		break;
		}

	}



	/*
	CommonStates states(_engine._device);
	_engine._deviceContext->OMSetBlendState(states.Opaque(), nullptr, 0xFFFFFFFF);
	_engine._deviceContext->OMSetDepthStencilState(states.DepthNone(), 0);
	_engine._deviceContext->RSSetState(states.CullNone());

	_engine._basicEffect->Apply(_engine._deviceContext);
	_engine._deviceContext->IASetInputLayout(_engine._inputLayout);

	_engine._primitiveBatch->Begin();

	_engine._primitiveBatch->DrawLine( VertexPositionColor(XMFLOAT3{ 0.0f,0.0f,0.0f }, XMFLOAT4{ 1.0f,1.0f,0.0f,0.0f }), VertexPositionColor(XMFLOAT3{ 0.5f,0.5f,1.0f }, XMFLOAT4{ 1.0f,1.0f,0.0f,1.0f }));

	
	//XMFLOAT3 const& position, XMFLOAT4 const& color

	_engine._primitiveBatch->End();
	*/



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
	/*
	_engine._buttons.Reset();

	char buffer[MAX_PATH];
	//GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	std::string str1 =  std::string(buffer).substr(0, pos);

	MYVERTEX sqaure[] = 
	{
		{0.0f, 2.0f, 0.0f, 0.0f, coolorrgb },
		{ 0.0f, 2.0f, 0.0f, 0.0f, coolorrgb },
		{ 0.0f, 2.0f, 0.0f, 0.0f, coolorrgb }

	};

	void DrawRect(int x, int y, int w, int h) {

		RECT r = { x,y,x + w,y + h };
		_engine.


	}
	*/

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