//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjAchievement.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjAchievement::Init()
{
	
}
//アクション
void CObjAchievement::Action()
{
	//上下キーを押してシーン：タイトルに移行する。/
	if (Input::GetVKey(VK_UP) == true)
	{
		Scene::SetScene(new CSceneRanking());
	}
}
//ドロー
void CObjAchievement::Draw()
{
	
}