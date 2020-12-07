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
#include "SceneAchievement.h"
#include "GameHead.h"


//コンストラクタ
CSceneAchievement::CSceneAchievement()
{

}

//ゲームメイン初期化メソッド
void CSceneAchievement::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録（線なし背景）
	Draw::LoadImageW(L"tatami_ranking.png", 0, TEX_SIZE_512);

	CObjAchievement* ca = new CObjAchievement();//実績ブジェクト作成
	Objs::InsertObj(ca, OBJ_ACHIEVEMENT, 10);//実績オブジェクト登録

	//背景オブジェクト作成
	CObjTatami* aot = new CObjTatami();
	Objs::InsertObj(aot, OBJ_TATAMI, 5);
}

//ゲームメイン実行中メソッド
void CSceneAchievement::Scene()
{

}