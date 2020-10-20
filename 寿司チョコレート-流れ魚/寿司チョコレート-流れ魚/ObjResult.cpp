#include "GameHead.h"
#include "ObjResult.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\UserData.h"
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
//ぼんてんです。

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
	//
	Font::StrDraw(L"終了！", 300, 250, 64, c);
	//
	swprintf_s(str, L"%d:%d", m_time, s_time);
	Font::StrDraw(str, 300, 250, 64, c);
	//
	//Font::StrDraw(L"終了！", 300, 250, 64, c);
	//
	Font::StrDraw(L"Push Enter", 230, 400, 64, c);
}