#pragma once
//使用するヘッダーファイル
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;



//シーン：メイン
class CObjMain :public CObj
{
public:
	CObjMain() {};
	~CObjMain() {};
	void Init();  //イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー
private:
	int f;
	int s_time;
	int m_time;
	
};