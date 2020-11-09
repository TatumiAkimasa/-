#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ObjBackground
class CObjwater_flow : public CObj
{
public:
	CObjwater_flow(float a) ;
	~CObjwater_flow() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	int right; //右にどれだけずれてるか
	int right_d;//rightの変数保存用
	float m_y1; //背景①の描画情報
	float flow_flag;//途中で線が変わらない用。
	float speed;//速さ
};