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
	D2DRenderManager::DrawFont(L"�����մϴ�", 350, 100, Color::Black);

	D2DRenderManager::DrawFont(L"B��", 400, 300, Color::Red);
	D2DRenderManager::DrawFont(L"�ڰ���, ������, �湮ȣ, ������", 250, 350, Color::Blue);
}
