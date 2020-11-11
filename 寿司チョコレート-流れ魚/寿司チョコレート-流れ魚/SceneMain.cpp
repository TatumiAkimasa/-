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

	//外部グラフィックファイルを読み込み12番に登録(障害物一覧）
	Draw::LoadImage(L"syougaibutu.png", 12, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み13番に登録(100円）
	Draw::LoadImage(L"100enn.png", 13, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み14番に登録(1000円）
	Draw::LoadImage(L"1000enn.png", 14, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み15番に登録(10000円）
	Draw::LoadImage(L"10000enn.png", 15, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み16番に登録(偽ライフ）
	Draw::LoadImage(L"badlife.png", 16, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み17番に登録(木アイテム)
	Draw::LoadImage(L"木 アイテム.png", 17, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み18番に登録(木)
	Draw::LoadImage(L"木.png", 18, TEX_SIZE_512);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"シーンBGM(仮).wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(3, L"シーンBGM2(仮)修正.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(4, L"シーンBGM(仮)スピードup.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"上昇.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(2, L"ダメージ音テスト.wav", SOUND_TYPE::EFFECT);

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

	bgm_flag = false;
}

//ゲーム実行中メソッド
void CSceneMain::Scene()
{
	//乱数複雑化
	rand(); rand(); rand(); rand(); rand();

	//障害物が落ちてくる確率
	//通常障害物 50/全体　ギミック 1/全体
	int x = rand() % 58;

	//フレーム数の計算
	m_time++;

	

	//BGM変更
	if (((UserData*)Save::GetData())->sp >= 6.0f && bgm_flag == false)
	{
		Audio::Stop(0);
		Audio::Start(3);
		bgm_flag = true;
	}
	else if (((UserData*)Save::GetData())->sp < 6.0f && bgm_flag == true)
	{
		Audio::Stop(3);
		Audio::Start(0);
		bgm_flag = false;
	}

	
	//落下の初期化
	if (t == 0)
	{
		((UserData*)Save::GetData())->sp = 5.0f;
		t++;
	}

	//障害物に当たった時、スピードが初期に戻る処理
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

	//水の流れの処理
	if (m_time%29 == 0)
	{
		CObjwater_flow* flow = new CObjwater_flow(((UserData*)Save::GetData())->sp);
		Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
	}
	else if (m_time % 73 == 0)
	{
		CObjwater_flow* flow = new CObjwater_flow(((UserData*)Save::GetData())->sp);
		Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
	}
	else if (m_time % 127 == 0)
	{
		CObjwater_flow* flow = new CObjwater_flow(((UserData*)Save::GetData())->sp);
		Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
	}



	//障害物の出現
	if (m_time % 60 == 0)
	{
		//乱数複雑化
		rand(); rand(); rand(); rand(); rand();

		//ランダムに3レーンから流す処理
		//1レーン流す
		if (x <= 50)
		{

			//通常障害物の表示
			x = rand() % 6;
			if (x == 0)
			{
				CObjFlow* f = new CObjFlow(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(f, OBJ_FLOW, 50);


				((UserData*)Save::GetData())->sp_lv++;
			}
			else if (x == 1)
			{

				CObjFlow* f = new CObjFlow(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(f, OBJ_FLOW, 50);

				((UserData*)Save::GetData())->sp_lv++;
			}
			else if (x == 2)
			{
				CObjFlow* f = new CObjFlow(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(f, OBJ_FLOW, 50);


				((UserData*)Save::GetData())->sp_lv++;
			}
			else if (x == 3)
			{
				CObjFlow* f = new CObjFlow(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(f, OBJ_FLOW, 50);

				f = new CObjFlow(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(f, OBJ_FLOW, 50);

				((UserData*)Save::GetData())->sp_lv++;
			}
			else if (x == 4)
			{
				CObjFlow* f = new CObjFlow(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(f, OBJ_FLOW, 50);

				f = new CObjFlow(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(f, OBJ_FLOW, 50);


				((UserData*)Save::GetData())->sp_lv++;
			}
			else if (x == 5)
			{
				CObjFlow* f = new CObjFlow(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(f, OBJ_FLOW, 50);

				f = new CObjFlow(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(f, OBJ_FLOW, 50);

				((UserData*)Save::GetData())->sp_lv++;
			}

		}

		//ライフ回復
		else if (x == 51)
		{
			CObjLifeItem* lt = new CObjLifeItem(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
			Objs::InsertObj(lt, OBJ_LIFE_ITEM, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		//スピードアップ
		else if (x == 52)
		{
			CObjsp_up* obj = new CObjsp_up(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
			Objs::InsertObj(obj, OBJ_SP_UP, 50);


			((UserData*)Save::GetData())->sp_lv++;
		}

		//スコアアップ(10)
		else if (x == 53)
		{
			CObj10enn* obj = new CObj10enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		//操作反転
		else if (x == 54)
		{
			CObjmirror* m = new CObjmirror(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
			Objs::InsertObj(m, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		//スコアアップ(100)
		else if (x == 55)
		{
			CObj100enn* obj = new CObj100enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
			Objs::InsertObj(obj, OBJ_100ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		//スコアアップ(1000)
		else if (x == 56)
		{
		CObj1000enn* obj = new CObj1000enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
		Objs::InsertObj(obj, OBJ_1000ENN, 50);

		((UserData*)Save::GetData())->sp_lv++;
		}
		//スコアアップ(10000)
		else if (x == 57)
		{
		CObj10000enn* obj = new CObj10000enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
		Objs::InsertObj(obj, OBJ_10000ENN, 50);

		((UserData*)Save::GetData())->sp_lv++;
		}
		//偽ライフ
		else if (x == 58)
		{
		CObjbadlife* bl = new CObjbadlife(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
		Objs::InsertObj(bl, OBJ_BAD_LIFE, 50);

		((UserData*)Save::GetData())->sp_lv++;
		}
		//木アイテム
		else if (x == 59)
		{
			CObjTreeItem* t = new CObjTreeItem(385, -64, ((UserData*)Save::GetData())->sp);
			Objs::InsertObj(t, OBJ_TREEITEM, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		//木
		if (((UserData*)Save::GetData())->Tree_flag == true)
		{
			CObjTree* t = new CObjTree(380, -120);
			Objs::InsertObj(t, OBJ_TREE, 50);

			((UserData*)Save::GetData())->Tree_flag = false;
		}

		//落下加速
		if (((UserData*)Save::GetData())->sp <= 20)
		{
			((UserData*)Save::GetData())->sp += 0.1f;
		}
	}
}

