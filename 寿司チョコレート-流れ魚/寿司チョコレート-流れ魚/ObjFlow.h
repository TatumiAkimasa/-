#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：10円
class CObjFlow : public CObj
{
public:
	CObjFlow(float x, float y, float s);
	~CObjFlow() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//10円の位置
	float m_y;
	float m_vy;			//10円の落下です
	float s;            //スピード用変数
	int m_id;           //障害物ID
	int g_ani;          //そうめん反転切り替え
	
};