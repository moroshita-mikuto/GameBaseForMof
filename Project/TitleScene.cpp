#include "TitleScene.h"
#include <Mof.h>

using namespace Game;

//�R���X�g���N�^
TitleScene::TitleScene()
{
}

//�f�X�g���N�^
TitleScene::~TitleScene()
{
}
//�ǂݍ���
bool TitleScene::Load()
{
    return false;
}
//������
void TitleScene::Initialize()
{
}
//�X�V
void TitleScene::Update()
{
}
//�`��
void TitleScene::Render()
{
    CGraphicsUtilities::RenderString(0, 0, "TITLE SCENE");
}
//���
void TitleScene::Release()
{
}
