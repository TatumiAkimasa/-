#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：10円
class CObj10enn : public CObj
{
	public:
		CObj10enn(float x, float y, float s) ;
		~CObj10enn() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー
	private:
		float m_x;			//10円の位置
		float m_y;
		float m_vy;			//10円の落下
		int s;
};