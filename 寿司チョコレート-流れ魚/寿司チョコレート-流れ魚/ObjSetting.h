#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjSetting :public CObj
{
public:
	CObjSetting() {};
	~CObjSetting() {};
	void Init();
	void Action();
	void Draw();
private:

};