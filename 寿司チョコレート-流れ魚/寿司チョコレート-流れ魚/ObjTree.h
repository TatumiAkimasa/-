#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：木
class CObjTree : public CObj
{
public:
	CObjTree(float x, float y);
	~CObjTree() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x;			//木の位置
	float m_y;
	float m_vx;			//木の出現用ベクトル
};