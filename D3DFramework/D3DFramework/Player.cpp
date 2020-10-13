#include "stdafx.h"
#include "Player.h"
#include "IComponent.h"
#include "Mesh.h"
#include "Missile.h"
#include "Monster.h"
#include "Cube.h"
#include "AirPlaneBodyMesh.h"
#include "AirPlaneWingMesh.h"
#include "AirPlaneTailMesh.h"

using namespace PKH;

PKH::Player::Player()
{
	// TODO : 유도탄
	transform->position = { 0,0,0 };
	transform->scale = { 0.5f,0.5f,0.5f };
	moveSpeed = 50.f;
	transform->eulerAngles.x = D3DXToRadian(90.f);
	isAlliance = true;

	Mesh* mesh = (Mesh*)AddComponent<PKH::AirPlaneBodyMesh>(L"Mesh");
	mesh->SetColor(D3DCOLOR_XRGB(50, 50, 50));
	mesh = (Mesh*)AddComponent<PKH::AirPlaneWingMesh>(L"Mesh2");
	mesh->SetColor(D3DCOLOR_XRGB(100, 100, 100));
	mesh = (Mesh*)AddComponent<PKH::AirPlaneTailMesh>(L"Mesh3");
	mesh->SetColor(D3DCOLOR_XRGB(100, 100, 100));


	CollisionManager::RegisterObject(this);
}

PKH::Player::~Player()
{
	CollisionManager::DisregisterObject(this);
}

void PKH::Player::Update()
{

	if (InputManager::GetKey('W'))
	{
		float angleX = transform->eulerAngles.x;
		transform->eulerAngles.x -= D3DXToRadian(20.f)* TimeManager::DeltaTime();
		if (transform->eulerAngles.x < D3DXToRadian(10.f))
		{
			transform->eulerAngles.x = angleX;
		}
	}
	if (InputManager::GetKey('S'))
	{
		float angleX = transform->eulerAngles.x;
		transform->eulerAngles.x += D3DXToRadian(20.f) * TimeManager::DeltaTime();
		if (transform->eulerAngles.x > D3DXToRadian(170.f))
		{
			transform->eulerAngles.x = angleX;
		}
	}
	if (InputManager::GetKey('A'))
	{
		Move(Vector3::LEFT);
	}
	if (InputManager::GetKey('D'))
	{
		Move(Vector3::RIGHT);
	}
	if (InputManager::GetKey('Q'))
	{
		Move(Vector3::FORWARD);
	}
	if (InputManager::GetKey('E'))
	{
		Move(Vector3::BACK);
	}

	if (InputManager::GetKey(VK_NUMPAD7))
	{
		transform->eulerAngles.x += TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD4))
	{
		transform->eulerAngles.x -= TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD8))
	{
		transform->eulerAngles.y += TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD5))
	{
		transform->eulerAngles.y -= TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD9))
	{
		transform->eulerAngles.z += TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD6))
	{
		transform->eulerAngles.z -= TimeManager::DeltaTime();
	}


	if (InputManager::GetMouseLButton())
	{
		Attack();
	}
	if (InputManager::GetKey(VK_SPACE))
	{
		Move(transform->up);
	}

	// 계속 앞으로
	//Move(transform->up);
	// 회전
	RotateProcess();

	// 딜레이 카운터
	attackTick += TimeManager::DeltaTime();
	if (attackTick > attackDelay)
	{
		attackTick = 0.f;
		attackFlag = true;
	}
		

	GameObject::Update();
}

void PKH::Player::OnCollision(GameObject* target)
{
	if (dynamic_cast<Monster*>(target))
	{
		// TODO : 경훈 / HP 마이너스
	}
	else if (dynamic_cast<Missile*>(target))
	{
		if (target->isAlliance != isAlliance)
		{
			hp--;
			if (hp < 1)
			{
				//Die();
			}
				
		}
	}
}

void PKH::Player::Die()
{
	GameObject::Die();
}

void PKH::Player::PostRender()
{
	WCHAR wstr[64] = {};
	wsprintf(wstr, L"HP : %d / 100", hp);
	D2DRenderManager::DrawFont(wstr);
}

void PKH::Player::Attack()
{
	if (attackFlag)
	{
		attackTick = 0.f;
		attackFlag = false;

		//좌
		Missile* missile = (Missile*)ObjectManager::GetInstance()->CreateObject<Missile>();
		missile->transform->position = transform->position - (transform->right);
		missile->transform->position.y -= 0.3f;
		Vector3 mousePos = Cursor::GetMousePos();
		Vector3 mouseWorld = Camera::ScreenToWorldPoint(mousePos);
		missile->targetPos = mouseWorld;
		missile->moveSpeed = 200.f;

		// 우
		missile = (Missile*)ObjectManager::GetInstance()->CreateObject<Missile>();
		missile->transform->position = transform->position + (transform->right);
		missile->transform->position.y -= 0.3f;
		missile->targetPos = mouseWorld;
		missile->moveSpeed = 200.f;

		
	}
}

void PKH::Player::RotateProcess()
{

	
	// Y축 회전
	Vector3 mousePos = Cursor::GetMousePos();
	float half = (dfCLIENT_WIDTH / 2.f);
	float comp = mousePos.x - half;
	float angle = comp * 0.1f;
	//각도 제한 45도
	transform->eulerAngles.y += angle * 0.05f * TimeManager::DeltaTime();

	//// X축 회전
	//float half2 = (dfCLIENT_HEIGHT / 2.f);
	//float comp2 = mousePos.y - half2;
	//float angle2 = comp2 * 0.1f;
	//
	//transform->eulerAngles.x += angle2 * 0.08f * TimeManager::DeltaTime();

	//// 비행기 살짝 기우는 느낌
	//transform->eulerAngles.z = angle *0.05f * TimeManager::DeltaTime();


	//카메라 회전
	Vector3 pos = transform->position - (transform->up * 8.f);
	pos.y -= 5.f;
	Vector3 camLook = transform->position + (transform->up * 10.0f);
	pos.y += 10.f;
	
	
	Camera::GetInstance()->SetPosition(pos);
	Camera::GetInstance()->transform->look = camLook;
}
