#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

#define UNDER 605.0f
#define RIGHT 820.0f
#define LEFT  250.0f
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

	float m_y1; //背景�@の描画情報
	int count;//画面切り替え用
	int n;//現在速度受け取り用変数
	bool End_P;//Background2の終端受け取り用
	bool end_P;//Background1の終端判定用
};
