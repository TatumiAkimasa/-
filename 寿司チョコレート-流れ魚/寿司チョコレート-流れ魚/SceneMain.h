#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームメイン
class CSceneMain :public CScene
{
public:
	CSceneMain();
	~CSceneMain();
	void InitScene();//ゲームメインの初期化メソッド
	void Scene();//ゲームメインの実行中メソッド
private:
	int m_time;
	int x;
	int t = 0;
	bool bgm_flag;//BGM切り替えフラグ
};

//関数の定義
void flow(int x, int y);

