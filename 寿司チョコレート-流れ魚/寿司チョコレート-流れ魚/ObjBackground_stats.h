#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ObjBackground
class CObjBackground_stats : public CObj
{
public:
	CObjBackground_stats() {};
	~CObjBackground_stats() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:

};