#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

#define FLOW_HIGHT -128
#define FLOW_SPACE_LEFT 385
#define FLOW_SPACE_CENTER 505
#define FLOW_SPACE_RIGHT 625

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
	bool bgm_flag2;//BGM切り替えフラグ2
	int m_ani_time; //主人公アニメーションタイム用変数
	int m_ani_frame; //主人公アニメーションフレーム用変数
};


