#include "GameHead.h"
#include "ObjResult.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\UserData.h"
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"

//使用するゲームスペース
using namespace GameL;

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

	//コメント表示
	//魚力 0
	if (((UserData*)Save::GetData())->save_score == 0)
	{
		Font::StrDraw(L"魚の風上にも置けない…", 150, 400, 48, c);
	}
	//魚力 0〜500
	else if (((UserData*)Save::GetData())->save_score > 0 && ((UserData*)Save::GetData())->save_score < 500)
	{
		Font::StrDraw(L"稚魚", 370, 400, 48, c);
	}
	//魚力 500〜1000
	else if (((UserData*)Save::GetData())->save_score >= 500 && ((UserData*)Save::GetData())->save_score < 1000)
	{
		Font::StrDraw(L"もっとがんばろう！", 200, 400, 48, c);
	}
	//魚力 1000〜2500
	else if (((UserData*)Save::GetData())->save_score >= 1000 && ((UserData*)Save::GetData())->save_score < 2500)
	{
		Font::StrDraw(L"命とは儚いものだね", 190, 400, 48, c);
	}
	//魚力 2500〜5000
	else if (((UserData*)Save::GetData())->save_score >= 2500 && ((UserData*)Save::GetData())->save_score < 5000)
	{
		Font::StrDraw(L"成魚", 370, 400, 48, c);
	}
	//魚力 5000〜7500
	else if (((UserData*)Save::GetData())->save_score >= 5000 && ((UserData*)Save::GetData())->save_score < 7500)
	{
		Font::StrDraw(L"まるで魚", 300, 400, 48, c);
	}
	//魚力 7500〜10000
	else if (((UserData*)Save::GetData())->save_score >= 7500 && ((UserData*)Save::GetData())->save_score < 10000)
	{
		Font::StrDraw(L"ぎょぎょぎょ", 270, 400, 48, c);
	}
	//魚力 10000〜20000
	else if (((UserData*)Save::GetData())->save_score >= 10000 && ((UserData*)Save::GetData())->save_score < 20000)
	{
		Font::StrDraw(L"もはや魚", 300, 400, 48, c);
	}
	//魚力 20000〜30000
	else if (((UserData*)Save::GetData())->save_score >= 20000 && ((UserData*)Save::GetData())->save_score < 30000)
	{
		Font::StrDraw(L"魚魚魚〜♪", 290, 400, 48, c);
	}
	//魚力 30000〜40000
	else if (((UserData*)Save::GetData())->save_score >= 30000 && ((UserData*)Save::GetData())->save_score < 40000)
	{
		Font::StrDraw(L"センスの塊", 290, 400, 48, c);
	}
	//魚力 40000〜50000
	else if (((UserData*)Save::GetData())->save_score >= 40000 && ((UserData*)Save::GetData())->save_score < 50000)
	{
		Font::StrDraw(L"狂気的にすごい！", 220, 400, 48, c);
	}
	//魚力 50000〜60000
	else if (((UserData*)Save::GetData())->save_score >= 50000 && ((UserData*)Save::GetData())->save_score < 60000)
	{
		Font::StrDraw(L"魚とは", 320, 400, 48, c);
	}
	//魚力 60000〜70000
	else if (((UserData*)Save::GetData())->save_score >= 60000 && ((UserData*)Save::GetData())->save_score < 70000)
	{
		Font::StrDraw(L"もはやサメ", 290, 400, 48, c);
	}
	//魚力 70000〜80000
	else if (((UserData*)Save::GetData())->save_score >= 70000 && ((UserData*)Save::GetData())->save_score < 80000)
	{
		Font::StrDraw(L"もはや戦艦", 290, 400, 48, c);
	}
	//魚力 70000〜80000
	else if (((UserData*)Save::GetData())->save_score >= 80000 && ((UserData*)Save::GetData())->save_score < 90000)
	{
		Font::StrDraw(L"魚の王", 320, 400, 48, c);
	}
	//魚力 90000〜100000
	else if (((UserData*)Save::GetData())->save_score >= 90000 && ((UserData*)Save::GetData())->save_score < 100000)
	{
		Font::StrDraw(L"制作者の人ですか？", 190, 400, 48, c);
	}
	//魚力 100000〜250000
	else if (((UserData*)Save::GetData())->save_score >= 100000 && ((UserData*)Save::GetData())->save_score < 250000)
	{
		Font::StrDraw(L"制作者より上手い！", 190, 400, 48, c);
	}
	//魚力 250000〜530000
	else if (((UserData*)Save::GetData())->save_score >= 250000 && ((UserData*)Save::GetData())->save_score < 530000)
	{
		Font::StrDraw(L"ギャラクティックフィッシュ", 90, 400, 48, c);
	}
	//魚力 530000〜1000000
	else if (((UserData*)Save::GetData())->save_score >= 530000 && ((UserData*)Save::GetData())->save_score < 1000000)
	{
		Font::StrDraw(L"魚力53万越えだと", 210, 400, 48, c);
	}
	//魚力 1000000〜
	else if (((UserData*)Save::GetData())->save_score >= 1000000)
	{
		Font::StrDraw(L"チートが検出されました", 140, 400, 48, c);
	}

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
	Font::StrDraw(L"エンターでタイトル", 410, 495, 32, c);

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	dst.m_top = 0.0f;
	dst.m_left = 75.0f;
	dst.m_right = 775.0f;
	dst.m_bottom = 565.0f;

	Draw::Draw(15, &src, &dst, c, -0.0f);
}