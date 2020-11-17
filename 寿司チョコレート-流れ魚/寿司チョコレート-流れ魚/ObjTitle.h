#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjTitle :public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();
	int key_num_T();
private:
	bool m_key_flag;//キーフラグ
	int num;//描画優先度

	//ランキングソートメソッド
	void RankingSort(int rank[11]);
};
