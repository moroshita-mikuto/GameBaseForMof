#pragma once
#include "SceneBase.h"

namespace Game
{
	class GameScene :public SceneBase
	{
	public:
		//�R���X�g���N�^
		GameScene();
		//�f�X�g���N�^
		virtual~GameScene();

		//�ǂݍ���
		virtual bool Load() override;
		//������
		virtual void Initialize() override;
		//�X�V
		virtual void Update() override;
		//�`��
		virtual void Render() override;
		//���
		virtual void Release() override;
	};
}



