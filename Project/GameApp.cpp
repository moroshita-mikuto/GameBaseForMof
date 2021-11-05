/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
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
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){
	//シーンをタイトルで初期化
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
		@brief			アプリケーションの更新
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//キーの更新
	g_pInput->RefreshKey();
	//シーンを更新
	sceneManager.Update();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの描画
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//描画開始
	g_pGraphics->RenderStart();
	//画面のクリア
	g_pGraphics->ClearTarget(0.0f,0.0f,1.0f,0.0f,1.0f,0);
	//シーンを描画
	sceneManager.Render();

	//描画の終了
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの解放
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Release(void){
	//シーンを開放
	sceneManager.Release();
	return TRUE;
}