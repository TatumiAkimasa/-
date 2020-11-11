#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：木アイテム
class CObjTreeItem : public CObj
{
public:
	CObjTreeItem(float x, float y, float s);
	~CObjTreeItem() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//木アイテムの位置
	float m_y;
	float m_vy;			//木アイテムの落下です
	float s;
};