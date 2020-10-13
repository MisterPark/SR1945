#include "stdafx.h"
#include "GameOverScene.h"
#include "GameOverTitle.h"

void GameOverScene::OnLoaded()
{
	ObjectManager::GetInstance()->CreateObject<GameOverTitle>();
}

void GameOverScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void GameOverScene::Update()
{
	if (InputManager::GetKeyDown(VK_RETURN))
	{
		MainGame::Shutdown();
	}
	else if (InputManager::GetKeyDown(VK_ESCAPE))
	{
		MainGame::Shutdown();
	}
	
}
