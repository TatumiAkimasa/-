#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ひよこ
class CObjPiyokoFish :public CObj
{
public:
	CObjPiyokoFish(float x, float y);
	~CObjPiyokoFish() {};
	void Init();  //イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー
private:
	float m_px;     //位置
	float m_py;
	float m_vx;     //主人公のｘ方向移動ベクトル用変数
	float m_vy;
	float m_spin;	//回転処理用変数
	float m_r;
}; 
