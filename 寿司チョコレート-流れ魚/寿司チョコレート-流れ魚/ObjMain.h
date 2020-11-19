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
	int random;//コメント用ランダム変数
	int life;//コメント用ライフ管理変数
	bool come_flag;//コメント用フラグ
	bool life_flag;//コメント用ライフ管理フラグ
	bool heel_flag;//コメント用回復フラグ
	int fps = 0;//操作反転の時使う
	int i = 9;//操作反転の時使う
	int second = 10;//操作反転の時使う
	
	bool mirrior_flag;//コメント用反転終了基準フラグ
};