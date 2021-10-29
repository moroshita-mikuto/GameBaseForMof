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
	public:
		SceneManager();
		~SceneManager();
		bool Load();
		void Initialize(int sceneNo);
		void Update();
		void Render();
		void Release();
		ScenePtr Create(int sceneNo);

	};
}


