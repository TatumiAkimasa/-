#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：1000円
class CObj1000enn : public CObj
{
public:
	CObj1000enn(float x, float y, float s);
	~CObj1000enn() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//1000円の位置
	float m_y;
	float m_vy;			//1000円の落下です
};