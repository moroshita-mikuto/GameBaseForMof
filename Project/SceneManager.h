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
			//エフェクト発生フラグ
			bool effectStart;
			bool effectInStart;
			bool effectOutStart;
			//シーンエフェクト実行フレーム
			int waitCount;
			//シーンエフェクトカウンタ
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


