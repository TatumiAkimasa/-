#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：Ren
class CObjRen : public CObj
{
public:
	CObjRen(float x, float y, float s);
	~CObjRen() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//Renの位置
	float m_y;
	float m_vy;			//Renの落下
};