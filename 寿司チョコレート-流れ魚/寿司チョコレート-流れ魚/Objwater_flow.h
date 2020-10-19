#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ObjBackground
class CObjwater_flow : public CObj
{
public:
	CObjwater_flow() {};
	~CObjwater_flow() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	int right;
	float m_y1; //背景①の描画情報
};