#include "stdafx.h"
#include "Player.h"
#include "IComponent.h"
#include "Mesh.h"
#include "Missile.h"
#include "Monster.h"
#include "Cube.h"

using namespace PKH;

PKH::Player::Player()
{
	transform->position = { 0,0,0 };
	transform->scale = { 8.f,8.f,24.f };
	moveSpeed = 30.f;

	Mesh* mesh = (Mesh*)AddComponent<PKH::Cube>(L"Mesh");
	mesh->SetColor(D3DCOLOR_XRGB(50, 50, 50));


	CollisionManager::RegisterObject(this);
}

PKH::Player::~Player()
{
}

void PKH::Player::Update()
{

	if (InputManager::GetKey('W'))
	{
		transform->eulerAngles.x -= D3DXToRadian(20.f)* TimeManager::DeltaTime();
	}
	if (InputManager::GetKey('S'))
	{
		transform->eulerAngles.x += D3DXToRadian(20.f) * TimeManager::DeltaTime();
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
		Attack();
	}

	// ��� ������
	Move(transform->look);
	// ȸ��
	RotateProcess();

	// ������ ī����
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
		// TODO : ���� / HP ���̳ʽ�
	}
	else if (dynamic_cast<Missile*>(target))
	{
		
	}
}

void PKH::Player::Die()
{
	GameObject::Die();
	CollisionManager::DisregisterObject(this);
}

void PKH::Player::PostRender()
{
	
}

void PKH::Player::Attack()
{
	if (attackFlag)
	{
		attackTick = 0.f;
		attackFlag = false;

		//��
		Missile* missile = (Missile*)ObjectManager::GetInstance()->CreateObject<Missile>();
		missile->transform->position = transform->position - (transform->right);
		missile->transform->position.y -= 0.3f;
		Vector3 mousePos = Cursor::GetMousePos();
		Vector3 mouseWorld = Camera::ScreenToWorldPoint(mousePos);
		missile->targetPos = mouseWorld;
		missile->moveSpeed = 200.f;

		// ��
		missile = (Missile*)ObjectManager::GetInstance()->CreateObject<Missile>();
		missile->transform->position = transform->position + (transform->right);
		missile->transform->position.y -= 0.3f;
		missile->targetPos = mouseWorld;
		missile->moveSpeed = 200.f;

		
	}
}

void PKH::Player::RotateProcess()
{
	// Y�� ȸ��
	Vector3 mousePos = Cursor::GetMousePos();
	float half = (dfCLIENT_WIDTH / 2.f);
	float comp = mousePos.x - half;
	float angle = comp * 0.1f;
	//���� ���� 45��
	transform->eulerAngles.y += angle * 0.05f * TimeManager::DeltaTime();

	//// X�� ȸ��
	//float half2 = (dfCLIENT_HEIGHT / 2.f);
	//float comp2 = mousePos.y - half2;
	//float angle2 = comp2 * 0.1f;
	//
	//transform->eulerAngles.x += angle2 * 0.08f * TimeManager::DeltaTime();

	//// ����� ��¦ ���� ����
	//transform->eulerAngles.z = angle *0.05f * TimeManager::DeltaTime();


	//ī�޶� ȸ��
	Vector3 pos = transform->position - (transform->look * 8.f);
	pos.y -= 5.f;
	Vector3 camLook = transform->position + (transform->look * 10.0f);
	pos.y += 10.f;
	
	
	Camera::GetInstance()->SetPosition(pos);
	Camera::GetInstance()->transform->look = camLook;
}
