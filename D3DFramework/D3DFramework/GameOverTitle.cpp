#include "stdafx.h"
#include "GameOverTitle.h"

PKH::GameOverTitle::GameOverTitle()
{
}

PKH::GameOverTitle::~GameOverTitle()
{
}

void PKH::GameOverTitle::Update()
{
}

void PKH::GameOverTitle::Render()
{
	D2DRenderManager::DrawFont(L"°¨»çÇÕ´Ï´Ù", 350, 100, Color::Black);

	D2DRenderManager::DrawFont(L"BÆÀ", 400, 300, Color::Red);
	D2DRenderManager::DrawFont(L"¹Ú°æÈÆ, °­ÈñÀç, ±æ¹®È£, Â÷½ÂÇö", 250, 350, Color::Blue);
}
