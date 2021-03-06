#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：10円
class CObjLifeItem : public CObj
{
public:
	CObjLifeItem(float x, float y, float s);
	~CObjLifeItem() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
	
private:
	float m_x;			//ライフアイテムの位置
	float m_y;
	float m_vy;			//ライフアイテムの落下	
};