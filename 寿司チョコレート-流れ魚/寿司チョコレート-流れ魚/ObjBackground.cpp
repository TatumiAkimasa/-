//使用するヘッダーファイル
#include "ObjBackground.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//使用するネームスペース
using namespace GameL;

float CObjBackground::speed_back()
{
	return n;
}

float CObjBackground::end_point()
{
	return m_y1;
}

//イニシャライズ
void CObjBackground::Init()
{
	m_y1 = 0.0f;
	count = 10;
	add =5;
	n = 0;
}

//アクション
void CObjBackground::Action()
{
	//背景�@の動作
	
	//速度をspから受け取る
	n = ((UserData*)Save::GetData())->sp;

	//速度を最初のほうの物を固定化
	if (m_y1 >= 580)
		add = n;
	
	if (((UserData*)Save::GetData())->life_point == 0)
	{
		n = 0;
		add = 0;
	}

	//もし、途中で1異常の変化があった場合無視する
	if (n != add)
		n = add;



	//速度の差別化(15→20)
	if (n == 20)
		m_y1 -= n;
	else if (n > 14)
		m_y1 -= 15;
	else
		m_y1 -= n;

	if (n >= 9 && n <= 20)
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
void CObjBackground::Draw()
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
	if (count == 10)
	{
		//背景�@の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 250.0f;
		dst.m_right = 820.0f;
		dst.m_bottom = 600.0f  - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 1)
	{
		//背景�@の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 250.0f;
		dst.m_right = 820.0f;
		dst.m_bottom = 620.0f  - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//背景�@の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 238.0f;
		dst.m_right = 808.0f;
		dst.m_bottom = 620.0f  - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//背景�@の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 233.2f;
		dst.m_right = 803.2f;
		dst.m_bottom = 620.0f  - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}
