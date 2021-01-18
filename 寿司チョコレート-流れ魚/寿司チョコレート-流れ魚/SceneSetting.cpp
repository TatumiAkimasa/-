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
	CObjSetting* cs = new CObjSetting();//実績ブジェクト作成
	Objs::InsertObj(cs, OBJ_SETTING, 10);//実績オブジェクト登録

		//音楽情報の読み込み
	Audio::LoadAudio(0, L"カーソル移動.wav", SOUND_TYPE::EFFECT);
}

//ゲームメイン実行中メソッド
void CSceneSetting::Scene()
{

}