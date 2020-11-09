//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMain::Init()
{
	f = 0;//フレーム計算
	s_time = 0;
	m_time = 0;
	((UserData*)Save::GetData())->save_s_time = 0;//セーブ用m_time初期化
	((UserData*)Save::GetData())->save_m_time = 0;//セーブ用s_time初期化
	((UserData*)Save::GetData())->life_point = 3;//セーブ用life_point初期化
}

//アクション
void CObjMain::Action()
{
	f++;
	//fが60回回ると1秒カウント
	if (f == 60)
	{
		f = 0;
		s_time++;
		//s_time++の時点でセーブ用s_timeもインクリメント
		((UserData*)Save::GetData())->save_s_time++;
	
	}
	//s_timeが60で1分です
	if (s_time == 60)
	{
		s_time = 0;
		m_time++;
		//m_time++の時点でセーブ用m_timeもインクリメント
		((UserData*)Save::GetData())->save_m_time++;
		((UserData*)Save::GetData())->save_s_time = 0;
	}
}

//ドロー
void CObjMain::Draw()
{
	float c[4] = { 1,1,1,1 };

	//タイムの表示
	wchar_t str[256];
	swprintf_s(str, L"タイム　%02d:%02d", m_time, s_time);
	Font::StrDraw(str, 20, 40, 40, c);

	//スコアの表示
	swprintf_s(str, L"魚力　　%05d", ((UserData*)Save::GetData())->save_score);
	Font::StrDraw(str, 20, 100, 40, c);

	//スピードの表示
	swprintf_s(str, L"速度　　%f", ((UserData*)Save::GetData())->sp);
	Font::StrDraw(str, 20, 350, 40, c);

	//ライフの表示
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	swprintf_s(str, L"ライフ");
	Font::StrDraw(str, 20, 160, 40, c);
	RECT_F src;
	RECT_F dst;

	if (((UserData*)Save::GetData())->life_point >= 1)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		dst.m_top = 200.0f;
		dst.m_left = 20.0f;
		dst.m_right = 64.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		Draw::Draw(10, &src, &dst, d, 0.0f);
	}

	if (((UserData*)Save::GetData())->life_point >= 2)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		dst.m_top = 200.0f;
		dst.m_left = 100.0f;
		dst.m_right = 64.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		Draw::Draw(10, &src, &dst, d, 0.0f);
	}

	if (((UserData*)Save::GetData())->life_point >= 3)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		dst.m_top = 200.0f;
		dst.m_left = 180.0f;
		dst.m_right = 64.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		Draw::Draw(10, &src, &dst, d, 0.0f);
	}
}