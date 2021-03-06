#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：badlife
class CObjbadlife : public CObj
{
public:
	CObjbadlife(float x, float y, float s);
	~CObjbadlife() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//badlifeの位置
	float m_y;
	float m_vy;			//badlifeの落下です	
};