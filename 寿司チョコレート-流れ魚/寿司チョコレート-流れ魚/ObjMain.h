#pragma once
//使用するヘッダーファイル
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define PLAY_INFO_SIZE 40
#define PLAY_INFO_POS 20
#define COM_SIZE 30
#define COM_POS_1 430
#define COM_POS_2 470
#define COM_POS_3 510

//シーン：メイン
class CObjMain :public CObj
{
public:
	CObjMain();
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

	bool mirrior_flag;//コメント用反転終了基準フラグ
	bool ren_flag;    //コメント用連打終了基準フラグ

	int fps;//操作反転の時使う
	int i;//操作反転の時使う
	int second;//操作反転の時使う

	
};