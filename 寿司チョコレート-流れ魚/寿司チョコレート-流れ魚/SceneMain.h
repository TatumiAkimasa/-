#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

#define FLOW_HIGHT -128
#define FLOW_SPACE_LEFT 385
#define FLOW_SPACE_CENTER 505
#define FLOW_SPACE_RIGHT 625
#define FLOW_PICTURE_PRIORITY 50
#define FLOW_TREE_SIDE 370
#define FLOW_GIMMICK_PROBABILITY 3
#define FLOW_PROBABILITY_0 0
#define FLOW_PROBABILITY_1 1
#define FLOW_PROBABILITY_2 2
#define FLOW_PROBABILITY_3 3
#define FLOW_PROBABILITY_4 4
#define FLOW_PROBABILITY_5 5

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
	bool bgm_flag2;//BGM切り替えフラグ2段階目
	int m_ani_time; //主人公アニメーションタイム用変数
	int m_ani_frame; //主人公アニメーションフレーム用変数
	int m_t;
};


