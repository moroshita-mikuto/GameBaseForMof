#pragma once
#include "SceneBase.h"
namespace Game 
{
	//�V�[���Ǘ��N���X
	class SceneManager
	{
		private:
			//���ݎ��s����Ă���V�[��
			ScenePtr currentScene;
			//�ύX����s�����V�[��
			ScenePtr nextScene;
			//�G�t�F�N�g�����t���O
			bool effectStart;
			bool effectInStart;
			bool effectOutStart;
			//�V�[���G�t�F�N�g���s�t���[��
			int waitCount;
			//�V�[���G�t�F�N�g�J�E���^
			int effectCount;
	public:
		SceneManager();
		~SceneManager();
		bool Load();
		void Initialize(int sceneNo,int wait);
		void Update();
		void Render();
		void Release();
		ScenePtr Create(int sceneNo);

	};
}


