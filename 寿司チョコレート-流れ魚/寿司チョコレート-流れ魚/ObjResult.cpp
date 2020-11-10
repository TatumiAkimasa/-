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
	Font::StrDraw(L"☆★☆さすが先生☆★☆", 45, 400, 64, c);
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
	Font::StrDraw(str, 200, 100, 64, c);
	//スコア表示
	swprintf_s
	(
		str,
		L"魚力　%05d",
		((UserData*)Save::GetData())->save_score
	);
	Font::StrDraw(str, 230, 250, 64, c);
	//エンターキーで移動
	Font::StrDraw(L"エンターでタイトル", 510, 565, 32, c);

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//ロゴ
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	dst.m_top = 150.0f;//kuro 420
	dst.m_left = 0.0f;//40
	dst.m_right = 150.0f;//280
	dst.m_bottom = 300.0f;//620

	Draw::Draw(16, &src, &dst, c, -0.0f);
}