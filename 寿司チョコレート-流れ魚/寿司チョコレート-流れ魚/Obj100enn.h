#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：100円
class CObj100enn : public CObj
{
public:
	CObj100enn(float x, float y, float s);
	~CObj100enn() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//100円の位置
	float m_y;
	float m_vy;			//100円の落下です
};