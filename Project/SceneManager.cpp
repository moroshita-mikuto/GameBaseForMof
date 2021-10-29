#include "SceneManager.h"
#include "GameDefine.h"
#include<Mof.h>

#include"TitleScene.h"
#include"GameScene.h"
using namespace Game;

//�R���X�g���N�^
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

//�f�X�g���N�^
SceneManager::~SceneManager()
{
}
//�ǂݍ���
bool SceneManager::Load()
{
    return false;
}
//������
void SceneManager::Initialize(int sceneNo,int wait)
{
    //�e�����o�[�̏�����
    Release();
    waitCount = wait;
    effectCount = wait / 2;
    effectStart = true;
    effectOutStart = true;
    effectInStart = false;
    //�����V�[���̐���
    currentScene = Create(sceneNo);
    if (currentScene == nullptr) 
    {
        MOF_PRINTLOG("Scene Create failured\n");
        return;
    }

    //�ǂݍ��ݎ��s�����ꍇ�G���[���O���c��
    if (!currentScene->Load())
    {
        MOF_PRINTLOG("Scene Load Failured\n");
        return;
    }
    currentScene->Initialize();
}
//�X�V
void SceneManager::Update()
{
    //�V�[�������ł��Ă��Ȃ��ꍇ�A�X�V���Ȃ�
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
    //�V�[���̍X�V
    currentScene->Update();
    //�V�[���̕ύX
    if (currentScene->IsChange())
    {
        //�V�[���G�t�F�N�g�𔭐�������
        if (!effectStart)
        {
            effectStart = true;
            effectInStart = true;
            effectOutStart = false;
        }
        if (effectOutStart) 
        {
            //���̃V�[���̎擾
            int next = currentScene->GetNextScene();
            //���̃V�[���̐���
            nextScene = Create(next);
            //���̃V�[���̓ǂݍ��݂Ə�����
            if (nextScene)
            {
                nextScene->Load();
                nextScene->Initialize();
            }
            currentScene->Release();
            currentScene.reset();
            //�V�����V�[���ɐ؂�ւ�
            currentScene = nextScene;
            nextScene = nullptr;
            effectStart = false;
        }
    }

}
//�`��
void SceneManager::Render()
{
    //�V�[�������ł��Ă��Ȃ��ꍇ�A�`�悵�Ȃ�
    if (!currentScene)
    {
        return;
    }
    //�V�[���̕`��
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
//���
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
