#include "SceneManager.h"
#include "GameDefine.h"
#include<Mof.h>

#include"TitleScene.h"
#include"GameScene.h"
using namespace Game;

//�R���X�g���N�^
SceneManager::SceneManager()
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
void SceneManager::Initialize(int sceneNo)
{
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
    //�V�[���̍X�V
    currentScene->Update();

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
}
//���
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
