#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjRanking :public CObj
{
public:
	CObjRanking() {};
	~CObjRanking() {};
	void Init();
	void Action();
	void Draw();
private:
	//ランキングソートメソッド
	void RankingSort(int rank[11]);

};