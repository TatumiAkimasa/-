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
	m_id = FLOW_TAKO + rand() % 5;
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
		((UserData*)Save::GetData())->save_score += 10;
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
	src.m_left = 95 * (m_id - FLOW_TAKO);
	src.m_right = src.m_left + 96;
	src.m_bottom = src.m_top + 96;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + 15.0f + m_x;
	dst.m_bottom = 64.0f + 15.0f + m_y;

	Draw::Draw(11, &src, &dst, c, 0.0f);
}