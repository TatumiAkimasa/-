#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ObjBackground
class CObjBackground_2 : public CObj
{
public:
	CObjBackground_2() {};
	~CObjBackground_2() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:

	float m_y1; //背景①の描画情報
	int count;//画面切り替え用
	int n;//基本速度変数
	float end_P;//Background1の終端受け取り用
};