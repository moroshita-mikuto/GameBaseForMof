/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include	"GameDefine.h"

#include	<vector>
#include	<list>
#include	<string>

#include	<map>
#include	<unordered_map>
#include	<utility>

std::vector<std::pair<std::string, CTexture>>pairTexture{"aiueo",CTexture()};
std::unordered_map<std::string, CTexture>textureMap;
void Func() 
{
	textureMap["aiueo"].Release("");
}

using TexturePtr = std::shared_ptr<CTexture>;
std::vector<TexturePtr> textureArray;
std::vector<int> testArray;
std::list<int> testList;
std::string name = { "aiueo" };

using namespace Game;

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){
	//�V�[�����^�C�g���ŏ�����
	sceneManager.Initialize(SceneName_Title,60);

	
		MOF_PRINTLOG("%s \n",name.c_str());
		MOF_PRINTLOG("%d \n", name.length());
		MOF_PRINTLOG("%d \n", name.size());
		name += "ka";
		MOF_PRINTLOG("%d \n", name.c_str());
		name.substr(1, 2);
		MOF_PRINTLOG("%d \n", name.c_str());
		
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̍X�V
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//�L�[�̍X�V
	g_pInput->RefreshKey();
	//�V�[�����X�V
	sceneManager.Update();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̕`��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//�`��J�n
	g_pGraphics->RenderStart();
	//��ʂ̃N���A
	g_pGraphics->ClearTarget(0.0f,0.0f,1.0f,0.0f,1.0f,0);
	//�V�[����`��
	sceneManager.Render();

	//�`��̏I��
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̉��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Release(void){
	//�V�[�����J��
	sceneManager.Release();
	return TRUE;
}