#pragma once
//使用するヘッダーファイル
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;



//シーン：メイン
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
	float m_vx;     //主人公機のｘ方向移動ベクトル用変数
	float m_vy;
	bool m_f;       //移動キーを押したとき連続で動かない為の変数
};