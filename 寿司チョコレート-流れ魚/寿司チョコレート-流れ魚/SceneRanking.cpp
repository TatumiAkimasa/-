//STLデバッグ機能をオフにする
#define _SECURESCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include"GameL/DrawTexture.h"

//使用するゲームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneRanking.h"
#include "GameHead.h"


//コンストラクタ
CSceneRanking::CSceneRanking()
{

}

//ゲームメイン初期化メソッド
void CSceneRanking::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録（線なし背景）
	Draw::LoadImageW(L"tatami_ranking.png", 0, TEX_SIZE_512);

	//ランキングオブジェクト作成
	CObjRanking* obj = new CObjRanking();//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_RANKING, 10);//主人公オブジェクト登録

	//背景オブジェクト作成
	CObjTatami* ot = new CObjTatami();//タイトルオブジェクト作成
	Objs::InsertObj(ot, OBJ_TATAMI, 5);//主人公オブジェクト登録
}

//ゲームメイン実行中メソッド
void CSceneRanking::Scene()
{



}