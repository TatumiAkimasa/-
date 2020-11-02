#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：10円
class CObjsp_down : public CObj
{
	public:
		CObjsp_down(float x, float y, float s);
		~CObjsp_down() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー
	private:
		float m_x;			//sp_downの位置
		float m_y;
		float m_vy;			//sp_downの落下
		float s;
};