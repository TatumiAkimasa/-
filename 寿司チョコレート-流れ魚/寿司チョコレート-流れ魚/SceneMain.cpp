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
	//外部グラフィックファイルを読み込み0番に登録（386*564ピクセル）
	Draw::LoadImageW(L"背景線無し-1_512.png", 0, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み1番に登録（386*564ピクセル）
	Draw::LoadImageW(L"水の流れ.png", 1, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み(魚)
	Draw::LoadImage(L"fishplayer.png", 2, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み3番に登録
	Draw::LoadImage(L"10enn.png", 3, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み4番に登録（512*512ピクセル）
	Draw::LoadImageW(L"背景線無し-2_512.png", 4, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み5番に登録（512*512ピクセル）
	Draw::LoadImageW(L"背景線無し-3_512.png", 5, TEX_SIZE_512);


	//音楽情報の読み込み
	Audio::LoadAudio(0, L"シーンBGM(仮).wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float volume = Audio::VolumeMaster(0.0f);//マスターボリュームを0.8下げる
	Audio::Start(0);//音楽スタート



	//外部グラフィックファイルを読み込み5番に登録（512*512ピクセル）
	Draw::LoadImageW(L"メイン_背景_ステータス側.png", 6, TEX_SIZE_512);

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

	((UserData*)Save::GetData())->save_score = 0;

	t = 0;
}

//ゲーム実行中メソッド
void CSceneMain::Scene()
{
	//乱数複雑化
	rand(); rand(); rand(); rand(); rand();

	//ランダム変数
	int x = rand() % 6;

	m_time++;

	if (m_time % 50 == 0)
	{
		CObjwater_flow* flow = new CObjwater_flow();
		Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
	}
	

	//落下の初期化
	if (t == 0)
	{
		float sp = 5.0f;
		t++;
	}

	if (((UserData*)Save::GetData())->sp_lv == 0)
	{
		if (sp >= 8)
		{
			sp -= 3.0f;
		}
		else
		{
			sp = 5.0f;
		}
	}

	//10円の出現
	if (m_time % 55 == 0)
	{
		//ランダムに3レーンから降らす処理
		if (x == 0)
		{
			CObj10enn* obj = new CObj10enn(385, -64, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 1)
		{
			CObj10enn* obj = new CObj10enn(505, -64, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 2)
		{
			CObj10enn* obj = new CObj10enn(625, -64, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 3)
		{
			CObj10enn* obj = new CObj10enn(385, -64, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			obj = new CObj10enn(505, -64, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 4)
		{
			CObj10enn* obj = new CObj10enn(505, -64, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			obj = new CObj10enn(625, -64, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 5)
		{
			CObj10enn* obj = new CObj10enn(385, -64, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			obj = new CObj10enn(625, -64, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		//落下加速
		if (sp <= 15)
		{
			sp += 0.3f;
		}
	}	
}