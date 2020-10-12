#include "stdafx.h"
#include "MainGame.h"
#include "TestScene.h"
#include "CollisionManager03.h"
#include "Scene03.h"
#include "Scene02.h"
#include "Scene4.h"

using namespace PKH;

PKH::MainGame* pMainGame = nullptr;

PKH::MainGame::MainGame()
{
}

PKH::MainGame::~MainGame()
{
}

PKH::MainGame* MainGame::GetInstance()
{
    if (pMainGame == nullptr)
    {
        pMainGame = new MainGame;
    }
    
    return pMainGame;
}

void PKH::MainGame::Destroy()
{
    if (pMainGame)
    {
        delete pMainGame;
        pMainGame = nullptr;
    }
}

void PKH::MainGame::Initialize()
{
    // �ٸ� ��� �Ŵ��� �ʱ�ȭ
	TimeManager::GetInstance();
	TimeManager::SetFPS(60.f);
	D2DRenderManager::GetInstance();
	CollisionManager::GetInstance();
	CollisionManager03::GetInstance();
	InputManager::GetInstance();
	
	//RenderManager::GetInstance();

	SceneManager::GetInstance();

	Camera::GetInstance();
	FileManager::GetInstance();
	Cursor::GetInstance();

	SoundManager::GetInstance()->Initialize();

    // ���ҽ� �ε�
	D2DRenderManager::LoadSprite(TextureKey::SKY_U, L"Texture\\SKYBOX_U.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_D, L"Texture\\SKYBOX_D.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_L, L"Texture\\SKYBOX_L.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_R, L"Texture\\SKYBOX_R.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_F, L"Texture\\SKYBOX_F.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_B, L"Texture\\SKYBOX_B.png");

	D2DRenderManager::LoadSprite(TextureKey::CURSOR_TARGET, L"Texture\\HUD_TARGET.png");

	ObjectManager::GetInstance();

	// ���ε�
	SceneManager::LoadScene<Scene02>();

}

void PKH::MainGame::Release()
{
    // �ٸ� ��� �Ŵ��� ����
	SceneManager::Destroy();
	TimeManager::Destroy();
	ObjectManager::Destroy();
	//RenderManager::Release();
	D2DRenderManager::Destroy();
	InputManager::Destroy();
	CollisionManager::Destroy();
	CollisionManager03::Destroy();
	Camera::Destroy();
	FileManager::Destroy();

	SoundManager::Destroy();
	Cursor::Destroy();
}

void PKH::MainGame::Update()
{
	InputManager::Update();
	ObjectManager::Update();
	Camera::GetInstance()->Update();
	CollisionManager::Update();

	CollisionManager03::Update();
	ObjectManager::PostUpdate();

	if (!TimeManager::SkipFrame())
	{
		D2DRenderManager::Clear();

		ObjectManager::PreRender();
		ObjectManager::Render();
		ObjectManager::PostRender();


		D2DRenderManager::Present();
	}

	SceneManager::Update();
}

void PKH::MainGame::Pause()
{
}

void PKH::MainGame::Resume()
{
}

void PKH::MainGame::Shutdown()
{
}
