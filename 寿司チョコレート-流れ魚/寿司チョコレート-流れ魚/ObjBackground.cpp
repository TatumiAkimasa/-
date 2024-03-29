//使用するヘッダーファイル
#include "ObjBackground.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//使用するネームスペース
using namespace GameL;

float CObjBackground::speed_back()
{
	return (float)n;
}

bool CObjBackground::end_point()
{
	return end_P;
}

//イニシャライズ
void CObjBackground::Init()
{
	m_y1 = -0.001f;
	count = 10;
	n = 0;
	End_P = false;
	end_P = false;
}

//アクション
void CObjBackground::Action()
{
	//背景�@の動作

	//もう一つの背景の現在地が規定値（流しなおすタイミング）に達したかどうか
	CObjBackground_2* obj = (CObjBackground_2*)Objs::GetObj(OBJ_BACK_GROUND_2);
	if (obj != nullptr)
	{
		End_P = obj->End_point();
	}

	//この背景の現在地が規定値に達したかどうかを判定
	if (end_P == false)
	{
		if (n >= 15 && m_y1 >= 20.0f && m_y1 <= 40.0f)
		{
			end_P = true;
		}
		else if (n >= 10 && m_y1 >= 13.0f && m_y1 <= 27.0f)
		{
			end_P = true;
		}
		else if (n == 7 && m_y1 >= 10.0f && m_y1 <= 14.0f)
		{
			end_P = true;
		}
		else if (n < 9 && m_y1 >= 0.0f && m_y1 <= 9.0f)
		{
			end_P = true;
		}
		else if (n == 9 && m_y1 >= 5.0f && m_y1 <= 20.0f)
		{
			end_P = true;
		}
		
	}
	else
	{
		end_P = false;
	}

	//もし、下に行ったら上に表示（修正用）
	if (End_P==true)
	{
		m_y1 = 600;
	}
	
	//速度をspから受け取る
	n = ((UserData*)Save::GetData())->sp;
	
	//死んだら背景stop
	if (((UserData*)Save::GetData())->life_point == 0)
	{
		n = 0;
	}

	//もし、途中で1異常の変化があった場合無視する
	//endポイント系があるなら多分いらない。（初期設定の邪魔にもなる）
	/*if (n != add)
		n = add;*/

	//速度の差別化(15→20)
	if (n == 20)
		m_y1 -= n;
	else if (n > 14)
		m_y1 -= 15;
	else
		m_y1 -= n;

	//背景切り替え
	if (n >= 9 && n <= 20)
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
		dst.m_left = LEFT;
		dst.m_right = RIGHT;
		dst.m_bottom = UNDER - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 1)
	{
		//背景�@の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = LEFT;
		dst.m_right = RIGHT;
		dst.m_bottom = UNDER  - m_y1;
		if(n>=10)
			dst.m_bottom = UNDER+n - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//背景�@の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = LEFT-12.0f;
		dst.m_right = RIGHT-12.0f;
		dst.m_bottom = UNDER  - m_y1;
		if (n >= 10)
			dst.m_bottom = UNDER+n - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//背景�@の位置設定し描画
		dst.m_top = 0.0f - m_y1;
		dst.m_left = LEFT-16.8f;
		dst.m_right = RIGHT-16.8f;
		dst.m_bottom = UNDER  - m_y1;
		if (n >= 10)
			dst.m_bottom = UNDER+n - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}
