//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Obj10enn.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObj10enn::CObj10enn(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObj10enn::Init()
{
	m_vy = 0;
	m_vy = 5.0;

	//当たり判定用Hitboxを作成
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_10ENN, 1);
}

//アクション
void CObj10enn::Action()
{
	//画面外に出たら10円を削除し魚力を加算
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		//落下速度加速処理
		m_vy += 10.0;
		
		//魚力加算処理
	}

	m_y += m_vy;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);	//作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_x, m_y);					//入り口から新しい位置(主人公機の位置)情報に置き換える
	
	//画面外に出たらHitBoxを削除
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//主人公オブジェクトと接触したら10円を削除
	if (hit->CheckObjNameHit(ELEMENT_PLAYER) != nullptr)
	{
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//10円が所有するHitBoxを削除する
	}
}

//ドロー
void CObj10enn::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 768.0f;
	src.m_bottom = 768.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(3, &src, &dst, c, 0.0f);
}