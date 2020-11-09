//STLデバック機能をOffにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GmameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\Audio.h"
#include "GameL/UserData.h"
#include <stdlib.h>
#include <time.h>


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録（線なし背景）
	Draw::LoadImageW(L"背景線無し-1_512.png", 0, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み1番に登録（水の流れ）
	Draw::LoadImageW(L"水の流れ.png", 1, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み2番に登録(主人公)アニメーション１
	Draw::LoadImage(L"ani金魚.png", 2, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み3番に登録（10円）
	Draw::LoadImage(L"10enn.png", 3, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み4番に登録（線なし背景2）
	Draw::LoadImageW(L"背景線無し-2_512.png", 4, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み5番に登録（線なし背景3）
	Draw::LoadImageW(L"背景線無し-3_512.png", 5, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み6番に登録（ステータス側の背景）
	Draw::LoadImageW(L"メイン_背景_ステータス側.png", 6, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み7番に登録(ライフアイテム）
	Draw::LoadImage(L"LifeItem2.png", 7, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み8番に登録（加速アイテム）
	Draw::LoadImage(L"sp_up.png", 8, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み9番に登録（減速アイテム）
	Draw::LoadImage(L"sp_down.png", 9, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み10番に登録(ライフ表示）
	Draw::LoadImage(L"LifeItem.png", 10, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み11番に登録(操作反転アイテム）
	Draw::LoadImage(L"反転アイコン.png", 11, TEX_SIZE_512);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"シーンBGM(仮).wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float volume = Audio::VolumeMaster(0.0f);//マスターボリュームを0.8下げる
	Audio::Start(0);//音楽スタート

	//背景オブジェクト作成
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACK_GROUND, 1);

	
	CObjBackground_2* back_2 = new CObjBackground_2();
	Objs::InsertObj(back_2, OBJ_BACK_GROUND_2, 1);
	

	CObjBackground_stats* back_3 = new CObjBackground_stats();
	Objs::InsertObj(back_3, OBJ_BACK_GROUND_STATS, 0);
	

	//主人公オブジェクト作成
	CObjFishPlayer* fp = new CObjFishPlayer();
	Objs::InsertObj(fp, OBJ_FISH_PLAYER, 10);

	//タイムの表示
	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_MAIN, 1);

	m_time = 0;
	m_ani_time = 0;

	((UserData*)Save::GetData())->save_score = 0;

	t = 0;
}

//ゲーム実行中メソッド
void CSceneMain::Scene()
{
	//乱数複雑化
	rand(); rand(); rand(); rand(); rand();

	//ランダム変数
	int x = rand() % 7;

	m_time++;

	if (m_time % 50 == 0)
	{
		CObjwater_flow* flow = new CObjwater_flow();
		Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
	}
	
	//落下の初期化
	if (t == 0)
	{
		((UserData*)Save::GetData())->sp = 5.0f;
		t++;
	}

	if (((UserData*)Save::GetData())->sp_lv == 0)
	{
		if (((UserData*)Save::GetData())->sp >= 7)
		{
			((UserData*)Save::GetData())->sp -= 2.0f;
		}
		else
		{
			((UserData*)Save::GetData())->sp = 5.0f;
		}
	}

	//障害物の出現
	if (m_time % 60 == 0)
	{
		//ランダムに3レーンから流す処理
		//1レーン流す
		if (x == 0)
		{
			//ランダムで流す
			int x = rand() % 2;
			if (x == 0)
			{
				flow(385, -64);

				((UserData*)Save::GetData())->sp_lv++;
			}
			else if (x == 1)
			{
				CObjsp_up* fp = new CObjsp_up(345, -64, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(fp, OBJ_SP_UP, 10);

				((UserData*)Save::GetData())->sp_lv++;
			}
			
		}
		else if (x == 1)
		{
			flow(505, -64);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 2)
		{
			flow(625, -64);

			((UserData*)Save::GetData())->sp_lv++;
		}
		//2レーン流す
		else if (x == 3)
		{
			flow(385, -64);

			flow(505, -64);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 4)
		{
			flow(505, -64);

			flow(625, -64);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 5)
		{
			flow(385, -64);

			flow(625, -64);

			((UserData*)Save::GetData())->sp_lv++;
		}

		//ライフ回復
		else if (x == 6)
		{
			CObjLifeItem* li = new CObjLifeItem(385, -64, ((UserData*)Save::GetData())->sp);
			Objs::InsertObj(li, OBJ_LIFE_ITEM, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}


		//3レーン流す

		//落下加速
		if (((UserData*)Save::GetData())->sp <= 20)
		{
			((UserData*)Save::GetData())->sp += 0.1f;
		}
	}	
}

//障害物を流す関数
void flow(int x, int y)
{
	CObj10enn* obj = new CObj10enn(x, y, ((UserData*)Save::GetData())->sp);
	Objs::InsertObj(obj, OBJ_10ENN, 50);
}