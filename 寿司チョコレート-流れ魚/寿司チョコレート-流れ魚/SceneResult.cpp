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
#include "SceneResult.h"
#include "GameHead.h"

//ゲームメイン初期化メソッド
void CSceneResult::InitScene()
{
	//音楽情報の読み込み
	Audio::LoadAudio(0, L"リザルトBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float volume = Audio::VolumeMaster(0.0f);//マスターボリュームを0.8下げる
	Audio::Start(0);//音楽スタート
	//↑後々BGM入ると思ったので適当に書いときました。
	//必要なければ消してください

	//外部グラフィックファイルを読み込み16番に登録(ロゴ）
	Draw::LoadImage(L"合成 黄色丸_256.png", 16, TEX_SIZE_256);
	//外部グラフィックファイルを読み込み16番に登録(ロゴ）
	Draw::LoadImage(L"リザルト枠組み_512.png", 15, TEX_SIZE_512);

	//タイトルオブジェクト作成
	CObjResult* obj = new CObjResult();//リザルト作成
	Objs::InsertObj(obj, OBJ_RESULT, 10);//作ったリザルトをオブジェクトマネージャーに登録
}

//ゲームメイン実行中メソッド
void  CSceneResult::Scene()
{

}