//STLデバッグ機能をOFFにする。
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"逆ら魚");
	Font::SetStrTex(L"GameStart:EnterKey");

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 10);//主人公オブジェクト登録
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{//STLデバッグ機能をOFFにする。
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
	using namespace GameL;

	//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"


//コンストラクタ
	CSceneTitle::CSceneTitle()
	{

	}

	//デストラクタ
	CSceneTitle::~CSceneTitle()
	{

	}

	//ゲームメイン初期化メソッド
	void CSceneTitle::InitScene()
	{

		//外部グラフィックファイルを読み込み0番に登録（386*564ピクセル）
		Draw::LoadImageW(L"仮タイトルver2.5.png", 1, TEX_SIZE_512);

		//外部グラフィックファイルを読み込み0番に登録（386*564ピクセル）
		Draw::LoadImageW(L"説明_512.png", 0, TEX_SIZE_512);

		//音楽情報の読み込み
		Audio::LoadAudio(0, L"タイトルBGM.wav", SOUND_TYPE::BACK_MUSIC);

		//バックミュージックスタート
		float volume = Audio::VolumeMaster(-0.8f);//マスターボリュームを0.8下げる
		Audio::Start(0);//音楽スタート

		//タイトルオブジェクト作成
		CObjTitle* obj = new CObjTitle();//タイトルオブジェクト作成
		Objs::InsertObj(obj, OBJ_TITLE, 10);//主人公オブジェクト登録

		//タイトルオブジェクト作成
		CObjDescription* obj2 = new CObjDescription();//タイトルオブジェクト作成
		Objs::InsertObj(obj2, OBJ_DESCRIPTION, 9);//主人公オブジェクト登録
	}

	//ゲームメイン実行中メソッド
	void CSceneTitle::Scene()
	{

	}

}