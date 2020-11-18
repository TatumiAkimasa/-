#pragma once
//使用するヘッダーファイル
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;


//オブジェクト：魚
class CObjFishPlayer :public CObj
{
public:
	CObjFishPlayer() {};
	~CObjFishPlayer() {};
	void Init();  //イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー
	bool heel_flag();
private:
	float m_px;     //位置
	float m_py;
	float m_vx;     //主人公のｘ方向移動ベクトル用変数
	float m_vy;
	bool m_f;       //移動キーを押したとき連続で動かない為の変数
	bool m_right_move;//右移動操作審議
	bool m_left_move;//左移動操作審議
	bool m_damage;
	int m_time;		//操作反転用
	int m_move;		//移動量制御用変数
	bool come_heel_flag;//コメント回復用フラグ

	int m_ani_time; //主人公アニメーションタイム用変数
	int m_ani_frame; //主人公アニメーションフレーム用変数
	int m_key_time = 0;	//操作反転管理用タイム
};