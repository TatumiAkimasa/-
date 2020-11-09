//使用するヘッダーファイル
#include "ObjBackground_2.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBackground_2::Init()
{
	m_y1 = 600.0f;
	count = 2;
}

//アクション
void CObjBackground_2::Action()
{
	//背景①の動作
	//みず（白線）を流せばこの処理は不要
	m_y1 -= 5.0f;
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
		dst.m_bottom = 610.0f - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//背景①の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 238.0f;
		dst.m_right = 808.0f;
		dst.m_bottom = 601.0f - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//背景①の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 233.2f;
		dst.m_right = 803.2f;
		dst.m_bottom = 600.0f - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}