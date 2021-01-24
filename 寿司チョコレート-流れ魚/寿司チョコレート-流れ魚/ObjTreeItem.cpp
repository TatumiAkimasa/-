//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjTreeItem.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjTreeItem::CObjTreeItem(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}

//イニシャライズ
void CObjTreeItem::Init()
{
	//当たり判定用Hitboxを作成
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 48, 48, ELEMENT_TREEITEM, OBJ_TREEITEM, 1);
}

//アクション
void CObjTreeItem::Action()
{
	if (((UserData*)Save::GetData())->life_point > 0)
	{
		m_y += m_vy;
	}

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);	//作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_x + 16, m_y + 16);		//入り口から新しい位置(木の位置)情報に置き換える

	//画面外に出たらHitBoxを削除
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//主人公オブジェクトと接触したら木アイテムを削除
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		Audio::Start(11);
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//木アイテムが所有するHitBoxを削除する
	
		((UserData*)Save::GetData())->Tree_flag = true;
		((UserData*)Save::GetData())->Tree_said = true;
		((UserData*)Save::GetData())->Tree_time = 600;
	}
}

//ドロー
void CObjTreeItem::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + 15.0f + m_x;
	dst.m_bottom = 64.0f + 15.0f + m_y;

	Draw::Draw(17, &src, &dst, c, 0.0f);
}