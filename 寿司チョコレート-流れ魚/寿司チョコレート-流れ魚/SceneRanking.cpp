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
	//タイトルオブジェクト作成
	CObjRanking* obj = new CObjRanking();//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_RANKING, 10);//主人公オブジェクト登録

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"ランキングBGM（仮）.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float volume = Audio::VolumeMaster(0.0f);
	Audio::Start(0);//音楽スタート
}

//ゲームメイン実行中メソッド
void CSceneRanking::Scene()
{



}