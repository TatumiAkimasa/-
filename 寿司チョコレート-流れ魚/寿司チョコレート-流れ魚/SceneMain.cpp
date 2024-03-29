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
	//落下速度の初期化
	if (t == 0)
	{
		((UserData*)Save::GetData())->sp = ((UserData*)Save::GetData())->start_sp;
		t++;
	}

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
	Draw::LoadImage(L"まとめそうめん.png", 12, TEX_SIZE_512);

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

	//外部グラフィックファイルを読み込み19番に登録(☆)
	Draw::LoadImage(L"hosi.png", 19, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み20番に登録(Armor)
	Draw::LoadImage(L"Armor.png", 20, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み21番に登録(Ren)
	Draw::LoadImage(L"ani氷.png", 21, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み22番に登録(鈍足)
	Draw::LoadImage(L"鈍足.png", 22, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み23番に登録(Armor（オーラ）)
	Draw::LoadImage(L"金魚装甲可視化.png", 23, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み24番に登録(ぴよこ)
	Draw::LoadImage(L"aniぴよこ.png", 24, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み25番に登録(主人公ver.宇宙)アニメーション
	Draw::LoadImage(L"ani金魚_宇宙.png", 25, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み26番に登録(ステータス宇宙)
	Draw::LoadImage(L"宇宙_ステータス背景.png", 26, TEX_SIZE_512);

	//音楽情報の読み込み
	//BGM
	Audio::LoadAudio(0, L"シーンBGM.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"シーンBGM2.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(2, L"シーンBGM3.wav", SOUND_TYPE::BACK_MUSIC);

	//SE
	Audio::LoadAudio(3, L"上昇.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(4, L"ダメージ音テスト.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(5, L"やられ時（仮）.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(6, L"コイン取得.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(7, L"回復.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(8, L"スピードダウン.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(9, L"コイン取得2.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(10, L"操作反転.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(11, L"隠し.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(12, L"装甲取得音.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(13, L"装甲消滅音.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(14, L"鈍足アイテム取得音.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(15, L"氷アイテム取得音.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(16, L"氷連打音.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(17, L"氷破壊音.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(18, L"操作反転中SE.wav", SOUND_TYPE::BACK_MUSIC);

	
	//バックミュージックスタート
	float volume = Audio::VolumeMaster(0.0f);//マスターボリュームを0.0下げる
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

	m_t = 0;

	bgm_flag = false;
	bgm_flag2 = false;
}

//ゲーム実行中メソッド
void CSceneMain::Scene()
{
	//乱数複雑化
	rand(); rand(); rand(); rand(); rand();

	//障害物が落ちてくる確率
	//通常障害物 50/全体　ギミック 1/全体
	int x = rand() % 63;
	
	
	//BGM変更
	//速度が10を超えたときBGM変更
	if (((UserData*)Save::GetData())->sp >= 10.0f && bgm_flag == false)
	{
		Audio::Start(3);
		Audio::Stop(0);
		Audio::Start(1);
		bgm_flag = true;
	}
	//速度が10を下回ったときBGMを変更
	if (((UserData*)Save::GetData())->sp < 10.0f && bgm_flag == true)
	{
		Audio::Stop(1);
		Audio::Start(0);
		bgm_flag = false;

	}
	//BGM変更（第二段階）
	//速度が15を超えたときBGM変更
	if (((UserData*)Save::GetData())->sp >= 15.0f && bgm_flag2 == false)
	{
		Audio::Start(3);
		Audio::Stop(1);
		Audio::Start(2);
		bgm_flag2 = true;
	}
	//速度が15を下回ったときBGMを変更
	if (((UserData*)Save::GetData())->sp < 15.0f && bgm_flag2 == true)
	{
		Audio::Stop(2);
		Audio::Start(1);
		bgm_flag2 = false;
	}
	
	//障害物に当たった時、スピードが初期に戻る処理
	if (((UserData*)Save::GetData())->sp_lv == 0)
	{
		if (((UserData*)Save::GetData())->sp >= 6.0f)
		{
			((UserData*)Save::GetData())->sp -= 1.0f;
			((UserData*)Save::GetData())->sp_lv += 1;
		}
		else
		{
			((UserData*)Save::GetData())->sp = 5.0f;
		}
	}

	if (((UserData*)Save::GetData())->life_point > 0)
	{
		//フレーム数の計算！
		m_time++;
		//水の流れの処理/
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
		else if (((UserData*)Save::GetData())->space_flag == true && m_time % 9 == 0)
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
			if (x <= 50)
			{

				//通常障害物の表示
				x = rand() % 6;
				if (x == FLOW_PROBABILITY_0)
				{
					CObjFlow* f = new CObjFlow(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, FLOW_PICTURE_PRIORITY);


					((UserData*)Save::GetData())->sp_lv++;
				}
				else if (x == FLOW_PROBABILITY_1)
				{

					CObjFlow* f = new CObjFlow(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, FLOW_PICTURE_PRIORITY);

					((UserData*)Save::GetData())->sp_lv++;
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjFlow* f = new CObjFlow(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, FLOW_PICTURE_PRIORITY);


					((UserData*)Save::GetData())->sp_lv++;
				}
				else if (x == FLOW_PROBABILITY_3)
				{
					CObjFlow* f = new CObjFlow(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, FLOW_PICTURE_PRIORITY);

					f = new CObjFlow(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, FLOW_PICTURE_PRIORITY);

					((UserData*)Save::GetData())->sp_lv++;
				}
				else if (x == FLOW_PROBABILITY_4)
				{
					CObjFlow* f = new CObjFlow(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, FLOW_PICTURE_PRIORITY);

					f = new CObjFlow(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, FLOW_PICTURE_PRIORITY);


					((UserData*)Save::GetData())->sp_lv++;
				}
				else if (x == FLOW_PROBABILITY_5)
				{
					CObjFlow* f = new CObjFlow(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, FLOW_PICTURE_PRIORITY);

					f = new CObjFlow(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, FLOW_PICTURE_PRIORITY);

					((UserData*)Save::GetData())->sp_lv++;
				}

			}

			//ライフ回復
			else if (x == 51)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObjLifeItem* lt = new CObjLifeItem(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(lt, OBJ_LIFE_ITEM, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObjLifeItem* lt = new CObjLifeItem(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(lt, OBJ_LIFE_ITEM, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjLifeItem* lt = new CObjLifeItem(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(lt, OBJ_LIFE_ITEM, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//スピードアップ
			else if (x == 52)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObjsp_up* obj = new CObjsp_up(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_UP, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObjsp_up* obj = new CObjsp_up(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_UP, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjsp_up* obj = new CObjsp_up(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_UP, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//スピードダウン
			else if (x == 53)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObjsp_down* obj = new CObjsp_down(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_DOWN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObjsp_down* obj = new CObjsp_down(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_DOWN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjsp_down* obj = new CObjsp_down(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_DOWN, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}

			//操作反転
			else if (x == 54)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObjmirror* m = new CObjmirror(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(m, OBJ_10ENN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObjmirror* m = new CObjmirror(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(m, OBJ_10ENN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjmirror* m = new CObjmirror(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(m, OBJ_10ENN, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//スコアアップ(100)
			else if (x == 55)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObj100enn* obj = new CObj100enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_100ENN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObj100enn* obj = new CObj100enn(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_100ENN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObj100enn* obj = new CObj100enn(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_100ENN, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//スコアアップ(1000)
			else if (x == 56)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObj1000enn* obj = new CObj1000enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_1000ENN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObj1000enn* obj = new CObj1000enn(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_1000ENN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObj1000enn* obj = new CObj1000enn(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_1000ENN, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//スコアアップ(10000)
			else if (x == 57)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObj10000enn* obj = new CObj10000enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_10000ENN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObj10000enn* obj = new CObj10000enn(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_10000ENN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObj10000enn* obj = new CObj10000enn(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_10000ENN, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//偽ライフ
			else if (x == 58)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObjbadlife* bl = new CObjbadlife(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(bl, OBJ_BAD_LIFE, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObjbadlife* bl = new CObjbadlife(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(bl, OBJ_BAD_LIFE, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjbadlife* bl = new CObjbadlife(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(bl, OBJ_BAD_LIFE, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//木アイテム
			else if (x == 59)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObjTreeItem* t = new CObjTreeItem(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_TREEITEM, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObjTreeItem* t = new CObjTreeItem(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_TREEITEM, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjTreeItem* t = new CObjTreeItem(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_TREEITEM, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//木
			if (((UserData*)Save::GetData())->Tree_flag == true)
			{
				int x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObjTree* t = new CObjTree(FLOW_TREE_SIDE, -100);
					Objs::InsertObj(t, OBJ_TREE, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObjTree* t = new CObjTree(FLOW_TREE_SIDE, 20);
					Objs::InsertObj(t, OBJ_TREE, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjTree* t = new CObjTree(FLOW_TREE_SIDE, 250);
					Objs::InsertObj(t, OBJ_TREE, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->Tree_flag = false;
			}
			//Armorアイテム
			else if (x == 60)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObjArmor* t = new CObjArmor(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_ARMOR, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObjArmor* t = new CObjArmor(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_ARMOR, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjArmor* t = new CObjArmor(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_ARMOR, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//Ren
			else if (x == 61)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObjRen* t = new CObjRen(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_REN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObjRen* t = new CObjRen(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_REN, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjRen* t = new CObjRen(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_REN, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//slow
			if (x == 62)
			{
				x = rand() % FLOW_GIMMICK_PROBABILITY;

				if (x == FLOW_PROBABILITY_0)
				{
					CObjSlow* t = new CObjSlow(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_SLOW, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_1)
				{
					CObjSlow* t = new CObjSlow(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_SLOW, FLOW_PICTURE_PRIORITY);
				}
				else if (x == FLOW_PROBABILITY_2)
				{
					CObjSlow* t = new CObjSlow(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_SLOW, FLOW_PICTURE_PRIORITY);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}

			//落下加速
			if (((UserData*)Save::GetData())->sp >= 5.0 && ((UserData*)Save::GetData())->sp < 20.0)
			{
				((UserData*)Save::GetData())->sp += 0.1f;
			}
		}
	}
}

