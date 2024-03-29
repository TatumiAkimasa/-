#pragma once
//使用するヘッダーファイル
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;


//オブジェクト：魚
class CObjFishPlayer :public CObj
{
public:
	CObjFishPlayer();
	~CObjFishPlayer() {};
	void Init();  //イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー
	bool heel_flag();
	float GetX() { return m_px; };

private:
	float m_px;     //位置
	float m_py;
	float m_vx;     //主人公のｘ方向移動ベクトル用変数
	float m_vy;
	bool m_f;       //移動キーを押したとき連続で動かない為の変数
	bool m_right_move;//右移動操作審議
	bool m_left_move;//左移動操作審議
	bool m_damage;
	int m_time;		//キラキラ間隔用変数
	int m_inv_time;	//無敵時間用タイム変数
	int m_stop_time;//金魚のライフ0で処理停止の時間用
	int m_move;		//移動量制御用変数
	int m_i;		//ピヨコ呼び出しfor分
	float m_spin;		//魚回転用
	int cont;
	bool come_heel_flag;//コメント回復用フラグ
	bool m_not_move_time;//操作不能時間

	int m_ani_time; //主人公アニメーションタイム用変数
	int m_ani_frame; //主人公アニメーションフレーム用変数
	int m_ice_ani_frame;
	int m_key_time = 0;	//操作反転管理用タイム
 
	bool slow_right_move;//右への移動が遅くなるフラグ
	bool slow_left_move; //左への移動が遅くなるフラグ
	int slow_count;      //slow状態で移動した数をカウントする
};