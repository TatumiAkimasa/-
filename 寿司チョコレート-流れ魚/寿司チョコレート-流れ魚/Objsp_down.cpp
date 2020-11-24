//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "Objsp_down.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjsp_down::CObjsp_down(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}

//イニシャライズ
void CObjsp_down::Init()
{
	//当たり判定用Hitboxを作成
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 42, 42, ELEMENT_ITEM, OBJ_SP_DOWN, 1);
}

//アクション
void CObjsp_down::Action()
{
	m_y += m_vy;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);	//作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_x + 10, m_y + 8);					//入り口から新しい位置(sp_downの位置)情報に置き換える

	//画面外に出たらHitBoxを削除
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//主人公オブジェクトと接触したらオブジェクトを削除しスピードを下げる
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		Audio::Start(8);

		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//オブジェクトが所有するHitBoxを削除する
		
		//スコアの加算
		((UserData*)Save::GetData())->save_score += 1000;

		if (((UserData*)Save::GetData())->sp >= 6)
		{
			((UserData*)Save::GetData())->sp -= 1.0f;
		}
		else
		{
			((UserData*)Save::GetData())->sp = 5.0f;
		}
	}
}

//ドロー
void CObjsp_down::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 360.0f;
	src.m_bottom = 360.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(9, &src, &dst, c, 0.0f);
}