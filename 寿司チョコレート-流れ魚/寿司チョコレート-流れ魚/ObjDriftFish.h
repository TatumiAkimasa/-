#pragma once
//使用するヘッダーファイル
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;


//オブジェクト：魚
class ObjDriftFish :public CObj
{
public:
	ObjDriftFish(float x, float y);
	~ObjDriftFish() {};
	void Init();  //イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー
private:
	float m_px;     //位置
	float m_py;
	float m_vx;     //主人公のｘ方向移動ベクトル用変数
	float m_vy;
	float m_spin;	//回転処理用変数
};
