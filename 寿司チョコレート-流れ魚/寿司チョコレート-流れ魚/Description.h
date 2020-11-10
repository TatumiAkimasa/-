#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjDescription :public CObj
{
public:
	CObjDescription() {};
	~CObjDescription() {};
	void Init();
	void Action();
	void Draw();
	int key_num_D();
private:
	bool m_key_flag;//キーフラグ
	int numd;//描画優先度（説明用）
	int i;
};

