//使用するヘッダーファイル
#include "ObjBackground_2.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBackground_2::Init()
{
	m_y1 = 600.0f;
	count = 2;
	n = 0;
	end_P=0;
}

//アクション
void CObjBackground_2::Action()
{
	//背景①の動作
	
	//Bcakgroundから速度と現在位置取得

	CObjBackground* obj = (CObjBackground*)Objs::GetObj(OBJ_BACK_GROUND);
	if (obj != nullptr)
	{
		n = obj->speed_back();
		end_P = obj->end_point();
	}

	//もし、下に行ったら上に表示（修正用）
	if (n < 10)
	{
		if (end_P == 0.0f)
		{
			m_y1 = 600;
		}
	}
	else
	{
		if (end_P == 0.0f)
		{
			m_y1 = 590;
		}
	}

	//速度の変化用
	if (n > 14 && n < 20)
		m_y1 -= 15;
	else
		m_y1 -= n;
	

	if (n >= 9 && n <=20)
	{
		if (m_y1 < -595.0f && count == 1)
		{
			m_y1 = 600;
			count = 3;
		}
		else if (m_y1 < -595.0f && count == 2)
		{
			m_y1 = 600;
			count = 1;
		}
		else if (m_y1 < -595.0f && count == 3)
		{
			m_y1 = 600;
			count = 2;
		}
		else if (m_y1 < -595.0f && count == 10)
		{
			m_y1 = 600;
			count = 3;
		}
	}
	else
	{
		if (m_y1 < -600.0f && count == 1)
		{
			m_y1 = 600;
			count = 3;
		}
		else if (m_y1 < -600.0f && count == 2)
		{
			m_y1 = 600;
			count = 1;
		}
		else if (m_y1 < -600.0f && count == 3)
		{
			m_y1 = 600;
			count = 2;
		}
		else if (m_y1 < -600.0f && count == 10)
		{
			m_y1 = 600;
			count = 3;
		}
	}

}

//ドロー
void CObjBackground_2::Draw()
{
	//描写カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //描画元切り取り位置
	RECT_F dst;  //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//1番目に登録したグラフィックをsrc・dst・cの情報をもとに描画
	if (count == 1)
	{
		//背景①の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 250.0f;
		dst.m_right = 820.0f;
		dst.m_bottom = 620.0f  - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//背景①の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 238.0f;
		dst.m_right = 808.0f;
		dst.m_bottom = 620.0f - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//背景①の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 233.2f;
		dst.m_right = 803.2f;
		dst.m_bottom = 620.0f  - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}