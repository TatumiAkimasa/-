#include "GameHead.h"
#include "ObjResult.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\UserData.h"
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"
//ぼんてんですよおおおおおお

//使用するゲームスペース
using namespace GameL;

//コンストラクタ
CObjResult::CObjResult()
{
     
}

//イニシャライズ
void CObjResult::Init()
{
	m_key_flag = false;
	m_time = 0;
	s_time = 0;
}

//アクション
void CObjResult::Action()
{
	//エンターキーを押してシーン：ゲームタイトルに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			((UserData*)Save::GetData())->save_score = 0;
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjResult::Draw()
{
	wchar_t str[256];
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"終了！", 300, 100, 64, c);
	//タイム表示
	if (((UserData*)Save::GetData())->save_s_time <= 9)
	{
		swprintf_s
		(
			str,
			L"タイム　%d:0%d",
			((UserData*)Save::GetData())->save_m_time,
			((UserData*)Save::GetData())->save_s_time
		);
	}
	else
	{
		swprintf_s
		(
			str,
			L"タイム　%d:%d",
			((UserData*)Save::GetData())->save_m_time,
			((UserData*)Save::GetData())->save_s_time
		);
	}
	Font::StrDraw(str, 200, 200, 64, c);
	//スコア表示
	swprintf_s
	(
		str,
		L"魚力　%05d",
		((UserData*)Save::GetData())->save_score
	);
	Font::StrDraw(str, 230, 300, 64, c);
	//エンターキーで移動
	Font::StrDraw(L"Push Enter", 230, 400, 64, c);
}