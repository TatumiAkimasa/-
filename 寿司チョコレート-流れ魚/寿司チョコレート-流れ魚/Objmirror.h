#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：操作反転アイテム
class CObjmirror : public CObj
{
public:
	CObjmirror(float x, float y, float s);
	~CObjmirror() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//操作反転アイテムの位置
	float m_y;
	float m_vy;			//操作反転アイテムの落下です
};