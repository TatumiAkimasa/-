#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ObjBackground
class CObjBackground : public CObj
{
public:
	~CObjBackground() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
	float speed_back();
	float end_point();
private:

	float m_y1; //背景①の描画情報
	int count;//画面切り替え用
	int add;
	int n;
};
