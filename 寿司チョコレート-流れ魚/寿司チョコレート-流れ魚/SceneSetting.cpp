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
#include "SceneSetting.h"
#include "GameHead.h"


//コンストラクタ
CSceneSetting::CSceneSetting()
{

}

//ゲームメイン初期化メソッド
void CSceneSetting::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録（線なし背景）
	Draw::LoadImageW(L"tatami_ranking.png", 0, TEX_SIZE_512);

	CObjSetting* cs = new CObjSetting();//実績ブジェクト作成
	Objs::InsertObj(cs, OBJ_SETTING, 10);//実績オブジェクト登録

	//背景オブジェクト作成
	CObjTatami* aot = new CObjTatami();
	Objs::InsertObj(aot, OBJ_TATAMI, 5);

		//音楽情報の読み込み
	Audio::LoadAudio(0, L"カーソル移動.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(1, L"速度マイナス音.wav", SOUND_TYPE::EFFECT);
}

//ゲームメイン実行中メソッド
void CSceneSetting::Scene()
{

}