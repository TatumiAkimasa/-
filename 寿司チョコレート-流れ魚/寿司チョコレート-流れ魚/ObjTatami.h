#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ObjBackground
class CObjTatami : public CObj
{
public:
	CObjTatami() {};
	~CObjTatami() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:

};