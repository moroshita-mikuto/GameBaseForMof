#pragma once
#include "SceneBase.h"
namespace Game 
{
	//シーン管理クラス
	class SceneManager
	{
		private:
			//現在実行されているシーン
			ScenePtr currentScene;
			//変更後実行されるシーン
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


