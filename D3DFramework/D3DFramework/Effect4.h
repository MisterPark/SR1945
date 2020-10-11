#pragma once
#include "GameObject.h"

namespace PKH {
	class Effect4 :
		public GameObject
	{
	public:
		Effect4();
		~Effect4();
		void Ready();
		virtual void Update() override;
	public:
		Vector3 dir;
		float Frame;
	};
}

