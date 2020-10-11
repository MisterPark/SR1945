#include "stdafx.h"
#include "Player4.h"
#include "PlayerBullet4.h"
#include "IComponent.h"
#include "Mesh.h"
#include "Cube.h"
#include "CollisionManager4.h"
#include "QuakeManager4.h"
using namespace PKH;

PKH::Player4::Player4()
{
	moveSpeed = 3.f;
	Key_Z = false;
	Key_X = false;
	Key_T = false;
	Dimension3D = true;
	//transform->position.z = 0.1f;
}

PKH::Player4::~Player4()
{
}

void PKH::Player4::Update()
{
	if (InputManager::GetKey(VK_UP))
	{
		MoveToTarget(transform->position + Vector3::UP);
	}
	if (InputManager::GetKey(VK_DOWN))
	{
		MoveToTarget(transform->position + Vector3::DOWN);
	}
	if (InputManager::GetKey(VK_LEFT))
	{
		MoveToTarget(transform->position + Vector3::LEFT);
	}
	if (InputManager::GetKey(VK_RIGHT))
	{
		MoveToTarget(transform->position + Vector3::RIGHT);
	}
	//if (InputManager::GetKey('C'))
	//{
	//	Move(transform->position + Vector3::FORWARD);
	//}
	//if (InputManager::GetKey('V'))
	//{
	//	Move(transform->position + Vector3::BACK);
	//}
	if (InputManager::GetKey('Z'))
	{
		if (!Key_Z) {
			CreateBullet(1);
			Key_Z = true;
		}
	}
	else {
		Key_Z = false;
	}
	if (InputManager::GetKey('X'))
	{
		if (!Key_X) {
			CreateBullet(2);
			Key_X = true;
		}
	}
	else {
		Key_X = false;
	}
	if (InputManager::GetKey('T'))
	{
		if (!Key_T) {
			Key_T = true;
			QuakeManager4::SetQuakeStart();
			if (Dimension3D) {
				Dimension3D = false;
				Camera::SetProjection3D(false);
			}
			else {
				Dimension3D = true;
				Camera::SetProjection3D(true);
			}
		}
	}
	else {
		Key_T = false;
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

	GameObject::Update();
}

void PKH::Player4::CreateBullet(int Code) {
	PlayerBullet4* b = (PlayerBullet4*)ObjectManager::GetInstance()->CreateObject<PlayerBullet4>();
	CollisionManager4::GetInstance()->RegisterObject(CollisionManager4::PLAYER_BULLET, b);
	Cube* Comp = dynamic_cast<Cube*>(b->AddComponent<PKH::Cube>(L"Mesh"));
	Comp->SetColor(D3DCOLOR_XRGB(103, 153, 255));
	b->SetCode(Code);
	*(b->GetTransform()->Get_Pos()) = transform->position;
	b->Ready();
}