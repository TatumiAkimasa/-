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


//コンストラクタ
CSceneResult::CSceneResult()
{

}

//ゲームメイン初期化メソッド
void CSceneResult::InitScene()
{
	//音楽情報の読み込み
	Audio::LoadAudio(0, L"リザルトBGM(仮).wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float volume = Audio::VolumeMaster(0.0f);//マスターボリュームを0.8下げる
	Audio::Start(0);//音楽スタート
	//↑後々BGM入ると思ったので適当に書いときました。
	//必要なければ消してください

	//外部グラフィックファイルを読み込み16番に登録(ロゴ）
	Draw::LoadImage(L"合成 黄色丸_256.png", 16, TEX_SIZE_256);

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"☆★☆さすが先生☆★☆");
	Font::SetStrTex(L"エンターでタイトルへ");

	//タイトルオブジェクト作成
	//主人公オブジェクト作成
	CObjResult* obj = new CObjResult();//リザルト作成
	Objs::InsertObj(obj, OBJ_RESULT, 10);//作ったリザルトをオブジェクトマネージャーに登録
}

//ゲームメイン実行中メソッド
void CSceneResult::Scene()
{



}