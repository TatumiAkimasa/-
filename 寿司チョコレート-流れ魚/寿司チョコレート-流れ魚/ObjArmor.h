#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：Armor
class CObjArmor : public CObj
{
public:
	CObjArmor(float x, float y, float s);
	~CObjArmor() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//Armorの位置
	float m_y;
	float m_vy;			//Armorの落下
};