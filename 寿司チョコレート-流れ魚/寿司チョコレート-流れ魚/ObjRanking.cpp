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
	//static bool init_point = false;
	//if (init_point == false)
	//{
	//	//点数を0にする
	//	((UserData*)Save::GetData())->save_score = 0;//点数を0にする

	//	//ランキング初期化
	//	for (int i = 0; i < 11; i++)
	//	{
	//		((UserData*)Save::GetData())->Ranking[i] = 0;
	//	}
	//	init_point = true;
	//}

	////得点ランキング最下位(描写圏外)に登録
	//((UserData*)Save::GetData())->Ranking[10] = ((UserData*)Save::GetData())->save_score;

	////得点が高い順に並び替えをする
	//RankingSort(((UserData*)Save::GetData())->Ranking);
}
//アクション
void CObjRanking::Action()
{
	//上下キーを押してシーン：タイトルに移行する。/
	if (Input::GetVKey(VK_UP) == true)
	{
		Scene::SetScene(new CSceneTitle());
	}
}
//ドロー//タイトル
void CObjRanking::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//ランキング
	Font::StrDraw(L"ランキング", 280, 0, 50, c);
	for (int i = 0; i < 10; i++)
	{
		wchar_t str[256];
		swprintf_s(str, L"%2d位       %12d魚力", i + 1, ((UserData*)Save::GetData())->Ranking[0]);
		Font::StrDraw(str, 230, 90 + 48 * i, 24, c);
	}
}

