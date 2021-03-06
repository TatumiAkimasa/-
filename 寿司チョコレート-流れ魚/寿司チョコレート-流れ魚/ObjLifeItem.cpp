//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjLifeItem.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjLifeItem::CObjLifeItem(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}


//イニシャライズ
void CObjLifeItem::Init()
{
	
	//当たり判定用Hitboxを作成
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 40, 40, ELEMENT_HEAL, OBJ_LIFE_ITEM, 1);
}

//アクション
void CObjLifeItem::Action()
{
	if (((UserData*)Save::GetData())->life_point > 0)
	{
		m_y += m_vy;
	}

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);	//作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_x + 16, m_y + 16);					//入り口から新しい位置(主人公の位置)情報に置き換える

	//画面外に出たらHitBoxを削除
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//主人公オブジェクトと接触したらライフアイテムを削除
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//ライフアイテムが所有するHitBoxを削除する
	}
	
}

//ドロー
void CObjLifeItem::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top =0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 55.0f + 15.0f + m_x;
	dst.m_bottom = 50.0f + 15.0f + m_y;

	Draw::Draw(7, &src, &dst, c, 0.0f);
}