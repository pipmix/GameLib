#include "Game.h"


Game::Game() {
	noMaps = noEnemy = noPlayer = 0;


	textures["chara"] = new Texture(L"chara", _engine._device);

	tex[0] = new Texture(L"wallTopFloor",_engine._device);
	tex[1] = new Texture(L"classical_ruin_tiles2", _engine._device);

	lev[0] = new LevelData(L"level02", tex[1], 0 ,0);
	noMaps++;

	players[0] = new Player();
	noPlayer++;


	camera = new Camera();
	SetGameState(GameGS);
}
Game::~Game() {


}
bool Game::Update() {

	auto k = _engine._keyboard.GetState();
	auto m = _engine._mouse.GetState();
	auto g = _engine._gamePad.GetState(0);

	// KEYBOARD
	if (k.Escape)return 1;

	// MOUSE

	// GAMEPAD
	if (g.IsConnected()) {
		_engine._buttons.Update(g);

		if (_engine._buttons.a == GamePad::ButtonStateTracker::PRESSED){

		}
		if (_engine._buttons.a == GamePad::ButtonStateTracker::RELEASED) {

		}


		if (_engine._buttons.b == GamePad::ButtonStateTracker::PRESSED) {

		}
		if (_engine._buttons.b == GamePad::ButtonStateTracker::RELEASED) {

		}

		//state.triggers.left
		//state.IsAPressed()
	}

	switch (currentGameState) {
		InitGS: {

		break;
		}
		TitleGS: {


			break;
		}
		GameGS: {
				 for (int i = 0; i < noMaps; i++) lev[i]->Update();
				 camera->Update(0.0f); 

				 break;
		}

	}

	//_engine._primitiveBatch = new PrimitiveBatch<VertexPositionColor>(_engine._deviceContext);
	//_engine._basicEffect = new BasicEffect(_engine._device);
	//_engine._basicEffect->SetProjection(XMMatrixOrthographicOffCenterRH(0, 720, 480, 0, 0, 1));
	//_engine._basicEffect->SetVertexColorEnabled(1);
	//_engine._basicEffect->GetVertexShaderBytecode(&_engine.shaderByteCode, &_engine.byteCodeLength);
	//_engine._device->CreateInputLayout(VertexPositionColor::InputElements, VertexPositionColor::InputElementCount, _engine.shaderByteCode, _engine.byteCodeLength, &_engine._inputLayout);



	return 0;


}
void Game::Draw() {

	const float fillColor[] = { 0.0f, 0.0f, 0.0f, 1.000f };
	_engine.context->ClearRenderTargetView(_engine.rtv, fillColor);


	switch (currentGameState){
		case InitGS: {
			sb->Begin(SpriteSortMode_Immediate, _engine._commonStates->NonPremultiplied());
			sb->Draw(tex[0]->textureResourceView, XMFLOAT2(0, 0));
			for (int i = 0; i < noMaps; i++) lev[i]->Draw();
			sb->End();

			break;
		}
		case TitleGS: {
			sb->Begin(SpriteSortMode_Immediate, _engine._commonStates->NonPremultiplied());
			sb->Draw(tex[0]->textureResourceView, XMFLOAT2(0, 0));
			sb->End();

		break;
		}
		case GameGS: {
				 sb->Begin(SpriteSortMode_Immediate, _engine._commonStates->NonPremultiplied(), _engine._commonStates->PointWrap(), nullptr, nullptr, nullptr, camera->transformMatrix());
				 for (int i = 0; i < noMaps; i++) lev[i]->Draw();

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



	_engine._swapChain->Present(1, 0);
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