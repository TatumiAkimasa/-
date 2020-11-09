#pragma once 
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：sp_up
class CObjsp_up : public CObj
{
	public:
		CObjsp_up(float x, float y, float s);
		~CObjsp_up() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー
	private:
		float m_x;			//sp_upの位置
		float m_y;
		float m_vy;			//sp_upの落下
		float s;
};