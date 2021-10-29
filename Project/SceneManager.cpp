#include "SceneManager.h"
#include "GameDefine.h"
#include<Mof.h>

#include"TitleScene.h"
#include"GameScene.h"
using namespace Game;

//コンストラクタ
SceneManager::SceneManager()
    :currentScene(nullptr)
    , nextScene(nullptr)
    ,effectStart(true)
    ,effectOutStart(true)
    , effectInStart(false)
    , effectCount(0)
    ,waitCount(30)
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
void SceneManager::Initialize(int sceneNo,int wait)
{
    //各メンバーの初期化
    Release();
    waitCount = wait;
    effectCount = wait / 2;
    effectStart = true;
    effectOutStart = true;
    effectInStart = false;
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
    if (effectInStart) 
    {
        effectCount++;
        if (effectCount >= waitCount / 2) 
        {
            effectInStart = false;
            effectOutStart = true;
        }
    }
    else if (effectOutStart) 
    {
        effectCount++;
        if (effectCount >= waitCount)
        {
            effectCount = 0;
            effectOutStart = false;
        }
    }
    else if (effectStart)
    {
        effectStart = false;
    }
    //シーンの更新
    currentScene->Update();
    //シーンの変更
    if (currentScene->IsChange())
    {
        //シーンエフェクトを発生させる
        if (!effectStart)
        {
            effectStart = true;
            effectInStart = true;
            effectOutStart = false;
        }
        if (effectOutStart) 
        {
            //次のシーンの取得
            int next = currentScene->GetNextScene();
            //次のシーンの生成
            nextScene = Create(next);
            //次のシーンの読み込みと初期化
            if (nextScene)
            {
                nextScene->Load();
                nextScene->Initialize();
            }
            currentScene->Release();
            currentScene.reset();
            //新しいシーンに切り替え
            currentScene = nextScene;
            nextScene = nullptr;
            effectStart = false;
        }
    }

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

    CRectangle feadRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());

    if (effectInStart)
    {
        float alpha = effectCount / (waitCount * 0.5f);
        CGraphicsUtilities::RenderFillRect(feadRect, MOF_ALPHA_BLACK((int)(255 * alpha)));
    }
    else if (effectOutStart)
    {
        float alpha = (effectCount - (waitCount * 0.5f)) / (waitCount * 0.5f);
        CGraphicsUtilities::RenderFillRect(feadRect, MOF_ALPHA_BLACK((int)(255 * (1.0f - alpha))));
    }
}
//解放
void SceneManager::Release()
{
    if (currentScene) 
    {
        currentScene->Release();
        currentScene.reset();
    }
    if (nextScene)
    {
        nextScene->Release();
        nextScene.reset();
    }
}

ScenePtr SceneManager::Create(int sceneNo)
{
    switch(sceneNo) 
    {
    case SceneName_Title:
        return std::make_shared<TitleScene>();
    case SceneName_Game:
        return std::make_shared<GameScene>();
    default:
        break;
    }
    return ScenePtr();
}
