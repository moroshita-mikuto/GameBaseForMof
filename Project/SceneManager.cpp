#include "SceneManager.h"
#include "GameDefine.h"
#include<Mof.h>

#include"TitleScene.h"
#include"GameScene.h"
using namespace Game;

//コンストラクタ
SceneManager::SceneManager()
{
}

//デストラクタ
SceneManager::~SceneManager()
{
}
//読み込み
bool SceneManager::Load()
{
    return false;
}
//初期化
void SceneManager::Initialize(int sceneNo)
{
    //初期シーンの生成
    currentScene = Create(sceneNo);
    if (currentScene == nullptr) 
    {
        MOF_PRINTLOG("Scene Create failured\n");
        return;
    }

    //読み込み失敗した場合エラーログを残す
    if (!currentScene->Load())
    {
        MOF_PRINTLOG("Scene Load Failured\n");
        return;
    }
    currentScene->Initialize();
}
//更新
void SceneManager::Update()
{
    //シーン生成できていない場合、更新しない
    if (!currentScene) 
    {
        return;
    }
    //シーンの更新
    currentScene->Update();

}
//描画
void SceneManager::Render()
{
    //シーン生成できていない場合、描画しない
    if (!currentScene)
    {
        return;
    }
    //シーンの描画
    currentScene->Render();
}
//解放
void SceneManager::Release()
{
}

ScenePtr SceneManager::Create(int sceneNo)
{
    switch(sceneNo) 
    {
    case SceneName_Title:
        return std::make_shared<TitleScene>();
    case SceneName_Game:
         break;
    default:
        break;
    }
    return ScenePtr();
}
