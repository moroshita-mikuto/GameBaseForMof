#include "GameScene.h"
#include <Mof.h>
#include"GameDefine.h"

using namespace Game;

//�R���X�g���N�^
GameScene::GameScene()
{
}

//�f�X�g���N�^
GameScene::~GameScene()
{
}
//�ǂݍ���
bool GameScene::Load()
{
    return false;
}
//������
void GameScene::Initialize()
{
}
//�X�V
void GameScene::Update()
{
    //�G���^�[�L�[�Ń^�C�g����
    if (g_pInput->IsKeyPush(MOFKEY_RETURN)) 
    {
        changeFlag = true;
        nextScene = SceneName_Title;
    }
}
//�`��
void GameScene::Render()
{
    CGraphicsUtilities::RenderString(0, 0, "GAME SCENE");
}
//���
void GameScene::Release()
{
}