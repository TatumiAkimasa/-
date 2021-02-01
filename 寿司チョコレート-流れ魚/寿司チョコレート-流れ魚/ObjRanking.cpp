//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjRanking.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjRanking::Init()
{
	//点数を0にする
	((UserData*)Save::GetData())->save_score = 0;
	D_flag = false;
	U_flag = false;
}
//アクション
void CObjRanking::Action()
{
	//上下キーを押してシーン：ランキングに移行する。/
	if (Input::GetVKey(VK_UP) == true)
	{
		if (U_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			U_flag = false;
		}
	}
	else
	{
		U_flag = true;
	}

	//上下キーを押してシーン：ランキングに移行する。/
	if (Input::GetVKey(VK_DOWN) == true)
	{
		if (D_flag == true)
		{
			Scene::SetScene(new CSceneAchievement());
			D_flag = false;
		}
	}
	else
	{
		D_flag = true;
	}
}
//ドロー//タイトル
void CObjRanking::Draw()
{
	//描画カラー情報
	float a[4] = { 1.0f,0.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,0.0f,1.0f };
	float c[4] = { 0.6f,0.5f,0.0f,1.0f };
	float d[4] = { 0.5f,0.5f,0.5f,1.0f };
	float e[4] = { 0.8f,0.4f,0.1f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//ランキング
	Font::StrDraw(L"ランキング", 270, 25, 50, a);
	Font::StrDraw(L"上ボタンでタイトルに戻る", 25, 550, 17, a);
	Font::StrDraw(L"下ボタンで実績画面に移動", 570, 550, 17, a);

	wchar_t str[256];
	swprintf_s(str, L" 1位  %4d魚力", ((UserData*)Save::GetData())->Ranking[0]);
	Font::StrDraw(str, 190, 95, 50, c);

	swprintf_s(str, L"________________");
	Font::StrDraw(str, 210, 98, 50, c);

	swprintf_s(str, L" 2位  %4d魚力", ((UserData*)Save::GetData())->Ranking[1]);
	Font::StrDraw(str, 60, 170, 35, d);

	swprintf_s(str, L"_______________");
	Font::StrDraw(str, 75, 173, 35, d);

	swprintf_s(str, L" 3位  %4d魚力", ((UserData*)Save::GetData())->Ranking[2]);
	Font::StrDraw(str, 440, 170, 35, e);

	swprintf_s(str, L"_______________");
	Font::StrDraw(str, 455, 173, 35, e);

	for (int i = 3; i < 10; i++)
	{
		
		swprintf_s(str, L"%2d位       %10d魚力", i + 1, ((UserData*)Save::GetData())->Ranking[i]);
		Font::StrDraw(str, 250, 90 + 48 * i, 24, b);
	}
}

