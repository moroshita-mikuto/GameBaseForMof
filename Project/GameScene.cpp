#include "GameScene.h"
#include <Mof.h>

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