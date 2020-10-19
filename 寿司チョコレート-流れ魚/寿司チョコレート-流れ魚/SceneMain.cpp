//STLデバック機能をOffにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GmameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\Audio.h"
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
	Draw::LoadImageW(L"メイン背景_512.png", 0, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み1番に登録（386*564ピクセル）
	Draw::LoadImageW(L"水の流れ.png", 1, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み(魚)
	Draw::LoadImage(L"fishplayer.png", 2, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み3番に登録
	Draw::LoadImage(L"10enn.png", 3, TEX_SIZE_512);

	//背景オブジェクト作成
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACK_GROUND, 1);

	//主人公オブジェクト作成
	CObjFishPlayer* fp = new CObjFishPlayer();
	Objs::InsertObj(fp, OBJ_FISH_PLAYER, 10);

	m_time = 0;
}

//ゲーム実行中メソッド
void CSceneMain::Scene()
{
	//乱数複雑化
	rand(); rand(); rand(); rand();

	//ランダム変数
	int x = rand() % 3;

	m_time++;

	if (m_time % 50 == 0)
	{
		CObjwater_flow* flow = new CObjwater_flow();
		Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
	}

	//10円の出現
	if (m_time % 60 == 0)
	{
		//ランダムに3レーンから降らす処理
		if (x == 0)
		{
			CObj10enn* obj = new CObj10enn(385, 0);
			Objs::InsertObj(obj, OBJ_10ENN, 50);
		}
		else if (x == 1)
		{
			CObj10enn* obj = new CObj10enn(505, 0);
			Objs::InsertObj(obj, OBJ_10ENN, 50);
		}
		else if (x == 2)
		{
			CObj10enn* obj = new CObj10enn(625, 0);
			Objs::InsertObj(obj, OBJ_10ENN, 50);
		}
	}
}