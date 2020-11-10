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

//イニシャライズ
void CObjTree::Init()
{
	m_x = 800;
	m_vx = 0.0f;
}

//アクション
void CObjTree::Action()
{
	//木用タイム
	((UserData*)Save::GetData())->Tree_time--;

	//木の出現処理
	if (((UserData*)Save::GetData())->Tree_said == true)
	{
		//木を動かす処理
		if (m_vx >= -450.0f)
		{
			m_vx -= 3.0f;
		}
		//木を止める処理
		if (m_vx == -450.0f)
		{
			m_vx = -450.0f;
		}
	}

	//木の削除処理
	if (((UserData*)Save::GetData())->Tree_time <= 0)
	{
		//出現処理のif文に入らないようにする為のフラグ
		((UserData*)Save::GetData())->Tree_said = false;

		//木を動かす処理
		if (m_vx <= 0.0f)
		{
			m_vx += 3.0f;
		}
		//木を画面外に出た時に
		if (m_vx >= 0.0f)
		{
			this->SetStatus(false);
			((UserData*)Save::GetData())->Tree_time = 0;
		}
	}
}

//ドロー
void CObjTree::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 510.0f;
	src.m_bottom = 510.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x + m_vx;
	dst.m_right = 500.0f + m_x + m_vx;
	dst.m_bottom = 500.0f + m_y;

	Draw::Draw(14, &src, &dst, c, 0.0f);
}