//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitboxManager.h"
#include "GameHead.h"
#include "ObjPiyokoFish.h"
#include "GameL/WinInputs.h"
#include "GameL/UserData.h"

#include<math.h>

//使用するゲームスペース
using namespace GameL;

//コンストラクタ
CObjPiyokoFish::CObjPiyokoFish(float x, float y, float r)
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_fp_x = 0.0f;
	m_r = r;
	m_px = x;
	m_py = y;
	m_obj = (CObjFishPlayer*)Objs::GetObj(OBJ_FISH_PLAYER);
}

//イニシャライズ
void CObjPiyokoFish::Init()
{
	m_obj = (CObjFishPlayer*)Objs::GetObj(OBJ_FISH_PLAYER);
	m_fp_x = m_obj->GetX();
	m_ani_frame = 0;
	m_ani_time = 0;
	//当たり判定用ヒットボックスを作成
	Hits::SetHitBox(this, m_px, m_py, 0, 0, NULL, NULL, 1);
}

//アクション
void CObjPiyokoFish::Action()
{
	m_obj = (CObjFishPlayer*)Objs::GetObj(OBJ_FISH_PLAYER);
	m_fp_x = m_obj->GetX();

	if (((UserData*)Save::GetData())->life_point > 0)
	{
		m_ani_time++;
		if (m_ani_time == 30)
		{
			m_ani_frame++;
			m_ani_time = 0;
			if (m_ani_frame >= 2)
			{
				m_ani_frame = 0;
			}
		}
		m_r += 2.0f;

		if (m_r > 360)
		{
			m_r = 0;
		}

	m_vx = cos(3.14f / 180.0f * m_r);
	m_vy = sin(3.14f / 180.0f * m_r);

		float r = 0.0f;
		r = m_vx * m_vx + m_vy * m_vy;
		r = sqrt(r);

	if (r == 0.0f)
	{
		;
	}
	else
	{
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}

		m_vx *= 1.5f;
		m_vy *= 1.5f;

		m_px += m_vx;
		m_py += m_vy;
	}
	else
	{
		m_vx = 0.0f;
		m_vy = 0.0f;

		m_px += m_vx;
		m_py += m_vy;
	}
	//piyokoのHitBox用ポインターを取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);

	if (((UserData*)Save::GetData())->key_flag_mirror == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void CObjPiyokoFish::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画切り取り位置
	RECT_F dst;//描画表示位置


	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 16.0f + m_px + m_fp_x;
	dst.m_right = 48.0f + m_px + m_fp_x;
	dst.m_bottom = -32.0f + m_py;


	//切り取り位置の設定
	src.m_top = 250.0f * m_ani_frame;
	src.m_left = 0.0f;
	src.m_right = 250.0f;
	src.m_bottom = 250.0f * (m_ani_frame + 1);
	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(24, &src, &dst, c, 180.0f);
}
