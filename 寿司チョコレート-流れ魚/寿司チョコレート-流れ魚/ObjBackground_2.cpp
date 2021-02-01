//使用するヘッダーファイル
#include "ObjBackground_2.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//使用するネームスペース
using namespace GameL;

bool CObjBackground_2::End_point()
{
	return End_P;
}

//コンストラクタ
CObjBackground_2::CObjBackground_2()
{
	m_y1 = 590.0f;
	count = 2;
	n = 0;
	end_P = false;
	End_P = false;
}

//イニシャライズ
void CObjBackground_2::Init()
{

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

	//Background2の現在地を判定し、下に行ったかどうかを相手(Background)に渡す
	if (End_P == false)
	{
		if (n >= 15 && m_y1 >= 20.0f && m_y1 <= 40.0f)
		{
			End_P = true;
		}
		else if (n>=10&& m_y1 >= 13.0f && m_y1 <= 27.0f)
		{
			End_P = true;
		}
		else if (n == 7 && m_y1 >= 10.0f && m_y1 <= 14.0f)
		{
			End_P = true;
		}
		else if (n < 9 && m_y1 >= 0.0f && m_y1 <= 9.0f)
		{
			End_P = true;
		}
		else if (n == 9 && m_y1 >= 5.0f && m_y1 <= 20.0f)
		{
			End_P = true;
		}
		
	}
	else
	{
		End_P = false;
	}

	//もし、下に行ったら上に表示（修正用）
	
	if (end_P == true)
	{
		m_y1 = 600;
	}
	
	//死んだら背景stop
	if (((UserData*)Save::GetData())->life_point == 0)
	{
		n = 0;
	}

	//速度の変化用
	if (n > 14 && n < 20)
		m_y1 -= 15;
	else
		m_y1 -= n;
	
	//背景切り替え
	if (n >= 9 && n <=20)
	{
		if (m_y1 < -595.0f && count == 1)
		{
			
			count = 3;
		}
		else if (m_y1 < -595.0f && count == 2)
		{
			
			count = 1;
		}
		else if (m_y1 < -595.0f && count == 3)
		{
			
			count = 2;
		}
		else if (m_y1 < -595.0f && count == 10)
		{
			
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
		dst.m_left = LEFT;
		dst.m_right = RIGHT;
		dst.m_bottom = UNDER - m_y1;
		if (n >= 10)
			dst.m_bottom = UNDER + n - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//背景①の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = LEFT - 12.0f;
		dst.m_right = RIGHT - 12.0f;
		dst.m_bottom = UNDER - m_y1;
		if (n >= 10)
			dst.m_bottom = UNDER + n - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//背景①の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = LEFT - 16.8f;
		dst.m_right = RIGHT - 16.8f;
		dst.m_bottom = UNDER - m_y1;
		if (n >= 10)
			dst.m_bottom = UNDER + n - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}