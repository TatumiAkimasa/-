//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjTree.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjTree::CObjTree(float x, float y)
{
	m_x = x;
	m_y = y;
}

//アクション
void CObjTree::Action()
{
	//木用タイム
	if (((UserData*)Save::GetData())->life_point > 0)
	{
		((UserData*)Save::GetData())->Tree_time--;
	}
}

//ドロー
void CObjTree::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//木の初期値用変数
	static float r = -80.0f;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 510.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 1000.0f + m_x;
	dst.m_bottom = 450.0f + m_y;

	//木を出現させる処理
	if (((UserData*)Save::GetData())->Tree_said == true)
	{
		//木を回転させる処理
		r += 1.5f;
		if (r >= 6.0f)
			r = 6.0f;
	}
	
	//木を消す処理
	if (((UserData*)Save::GetData())->Tree_time <= 0)
	{
		//出現処理のif文に入らないようにする為のフラグ
		((UserData*)Save::GetData())->Tree_said = false;

		//木を回転させる処理
		r -= 1.5f;
		if (r <= -100.0f)
		{
			r = -100.0f;
			this->SetStatus(false);
			((UserData*)Save::GetData())->Tree_time = 0;
		}
	}
	
	((UserData*)Save::GetData())->Tree_flag = false;

	Draw::Draw(18, &src, &dst, c, r);
}