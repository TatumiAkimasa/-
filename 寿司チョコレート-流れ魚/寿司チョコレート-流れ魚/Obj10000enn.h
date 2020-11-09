#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：1000円
class CObj10000enn : public CObj
{
public:
	CObj10000enn(float x, float y, float s);
	~CObj10000enn() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//100円の位置
	float m_y;
	float m_vy;			//100円の落下です
	float s;
};