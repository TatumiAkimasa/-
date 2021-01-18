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
	bool end_point();
private:

	float m_y1; //背景①の描画情報
	int count;//画面切り替え用
	int add;
	int n;
	bool End_P;//Background2の終端受け取り用
	bool end_P;//Background1の終端判定用
};
