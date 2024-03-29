//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "Objmirror.h"
#include "GameL\Audio.h"
//
//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjmirror::CObjmirror(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}

//イニシャライズ
void CObjmirror::Init()
{
	//当たり判定用Hitboxを作成
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 48, 48, ELEMENT_MIRROR, OBJ_MIRROR, 1);
}

//アクション
void CObjmirror::Action()
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

	//主人公オブジェクトと接触したら操作反転アイテムを削除
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		Audio::Start(10);
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//操作反転アイテムが所有するHitBoxを削除する

		//主人公オブジェクトと接触したらtrueにする
		((UserData*)Save::GetData())->key_flag_mirror = true;
		Audio::Start(18);//操作反転中の効果音
		
		//スコアの加算
		((UserData*)Save::GetData())->save_score += 1000;
	}
}

//ドロー
void CObjmirror::Draw()
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

	Draw::Draw(11, &src, &dst, c, 0.0f);
}