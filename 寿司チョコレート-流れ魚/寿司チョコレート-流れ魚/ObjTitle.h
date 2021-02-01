#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjTitle :public CObj
{
public:
	CObjTitle();
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();
	int key_num_T();
	bool key_num2_T();
private:
	bool R_flag;//キーフラグ(右）
	bool L_flag;//キーフラグ（左）
	bool D_flag;//キーフラグ(下)
	int num;//描画優先度
	

	//ランキングソートメソッド
	void RankingSort(int rank[11]);
};
