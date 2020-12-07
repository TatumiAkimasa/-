//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjFlow.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjFlow::CObjFlow(float x, float y, float s)
{
	//乱数複雑化
	rand(); rand(); rand(); rand(); rand();

	m_x = x;
	m_y = y;
	m_vy = s;
	m_id = FLOW1 + rand() % 3;
}

//イニシャライズ
void CObjFlow::Init()
{
	//当たり判定用Hitboxを作成
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 48, 48, ELEMENT_ENEMY, OBJ_FLOW, 1);
}

//アクション
void CObjFlow::Action()
{
	m_y += m_vy;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);	//作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_x + 16, m_y + 16);					//入り口から新しい位置(主人公機の位置)情報に置き換える

	//画面外に出たらHitBoxを削除
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//スコアの加算
		if (((UserData*)Save::GetData())->sp >= 5.0f && ((UserData*)Save::GetData())->sp < 10.0f)
		{
			//mirrorの時スコア2倍の処理
			if (((UserData*)Save::GetData())->key_flag_mirror == true)
			{
				((UserData*)Save::GetData())->save_score += 200;
			}
			else
			{
				((UserData*)Save::GetData())->save_score += 100;
			}
		}
		else if (((UserData*)Save::GetData())->sp >= 10.0f && ((UserData*)Save::GetData())->sp < 15.0f)
		{
			if (((UserData*)Save::GetData())->key_flag_mirror == true)
			{
				((UserData*)Save::GetData())->save_score += 400;
			}
			else
			{
				((UserData*)Save::GetData())->save_score += 200;
			}
		}
		else if (((UserData*)Save::GetData())->sp >= 15.0f && ((UserData*)Save::GetData())->sp < 20.0f)
		{
			if (((UserData*)Save::GetData())->key_flag_mirror == true)
			{
				((UserData*)Save::GetData())->save_score += 600;
			}
			else
			{
				((UserData*)Save::GetData())->save_score += 300;
			}
		}
		else if (((UserData*)Save::GetData())->sp >= 20.0f)
		{
			if (((UserData*)Save::GetData())->key_flag_mirror == true)
			{
				((UserData*)Save::GetData())->save_score += 1000;
			}
			else
			{
				((UserData*)Save::GetData())->save_score += 500;
			}
		}
	}

	//主人公オブジェクトと接触したら10円を削除
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//10円が所有するHitBoxを削除する
	}
}

//ドロー
void CObjFlow::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 128 * (m_id - FLOW1);
	src.m_right = src.m_left + 128;
	src.m_bottom = src.m_top + 128;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 100.0f + m_x;
	dst.m_bottom = 100.0f + m_y;

	Draw::Draw(12, &src, &dst, c, 0.0f);
}