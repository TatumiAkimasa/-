#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：10000円
class CObj10000enn : public CObj
{
public:
	CObj10000enn(float x, float y, float s);
	~CObj10000enn() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//10000円の位置
	float m_y;
	float m_vy;			//10000円の落下です
};