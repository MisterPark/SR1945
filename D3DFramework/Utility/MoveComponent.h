#pragma once
#include "Component.h"
class MoveComponent :
	public Component
{
public:
	MoveComponent();
	virtual ~MoveComponent();

	// Component��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;
	

};

