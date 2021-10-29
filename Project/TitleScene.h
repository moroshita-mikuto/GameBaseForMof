#pragma once
#include "SceneBase.h"

namespace Game
{
	//�^�C�g���V�[���N���X
	class TitleScene :public SceneBase
	{
	public:
		//�R���X�g���N�^
		TitleScene();
		//�f�X�g���N�^
		virtual~TitleScene();

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

