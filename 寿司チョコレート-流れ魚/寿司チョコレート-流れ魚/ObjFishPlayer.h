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
private:
	float m_px;     //位置
	float m_py;
	float m_vx;     //主人公のｘ方向移動ベクトル用変数
	float m_vy;
	bool m_f;       //移動キーを押したとき連続で動かない為の変数
	int m_time;		//操作反転用

};