//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "Objsp_up.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjsp_up::CObjsp_up(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}

//イニシャライズ
void CObjsp_up::Init()
{
	//当たり判定用Hitboxを作成
	Hits::SetHitBox(this, m_x + 70, m_y + 35, 32, 60, ELEMENT_ITEM, OBJ_SP_UP, 1);
}

//アクション
void CObjsp_up::Action()
{
	m_y += m_vy;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);	//作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_x + 70, m_y + 35);					//入り口から新しい位置(sp_upの位置)情報に置き換える

	//画面外に出たらHitBoxを削除
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//主人公オブジェクトと接触したらオブジェクトを削除しスピードを上げる
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		Audio::Start(1);

		this->SetStatus(false);    //自身に削除命令を出す
		Hits::DeleteHitBox(this);  //アイテムオブジェクトが所有するHitBoxに削除する
	
		if (((UserData*)Save::GetData())->sp < 20.0f)
		{
			((UserData*)Save::GetData())->sp += 1.0f;
		}
	}
}

//ドロー
void CObjsp_up::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 696.0f;
	src.m_bottom = 564.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 170.0f + m_x;
	dst.m_bottom = 130.0f + m_y;

	Draw::Draw(8, &src, &dst, c, 0.0f);
}