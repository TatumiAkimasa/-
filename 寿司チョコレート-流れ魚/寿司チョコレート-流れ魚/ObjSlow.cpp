//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjSlow.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjSlow::CObjSlow(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}

//イニシャライズ
void CObjSlow::Init()
{
	//当たり判定用Hitboxを作成
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 48, 48, ELEMENT_COIN, OBJ_SLOW, 1);
}

//アクション
void CObjSlow::Action()
{
	
}

//ドロー
void CObjSlow::Draw()
{
	
}