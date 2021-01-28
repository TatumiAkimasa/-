//Žg—p‚·‚éƒwƒbƒ_[ƒtƒ@ƒCƒ‹
#include "ObjBackground_2.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//Žg—p‚·‚éƒl[ƒ€ƒXƒy[ƒX
using namespace GameL;

bool CObjBackground_2::End_point()
{
	return End_P;
}

//ƒCƒjƒVƒƒƒ‰ƒCƒY
void CObjBackground_2::Init()
{
	m_y1 = 590.0f;
	count = 2;
	n = 0;
	end_P=false;
	End_P = false;
}

//ƒAƒNƒVƒ‡ƒ“
void CObjBackground_2::Action()
{
	//”wŒi‡@‚Ì“®ì
	
	//Bcakground‚©‚ç‘¬“x‚ÆŒ»ÝˆÊ’uŽæ“¾
	CObjBackground* obj = (CObjBackground*)Objs::GetObj(OBJ_BACK_GROUND);
	if (obj != nullptr)
	{
		n = obj->speed_back();
		end_P = obj->end_point();
	}

	//Background2‚ÌŒ»Ý’n‚ð”»’è‚µA‰º‚És‚Á‚½‚©‚Ç‚¤‚©‚ð‘ŠŽè(Background)‚É“n‚·
	if (End_P == false)
	{
		if (n>=10&& m_y1 >= 13.0f && m_y1 <= 27.0f)
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
		else if (n == 9 && m_y1 >= 9.0f && m_y1 <= 17.0f)
		{
			End_P = true;
		}
		
	}
	else
	{
		End_P = false;
	}

	//‚à‚µA‰º‚És‚Á‚½‚çã‚É•\Ž¦iC³—pj
	
	if (end_P == true)
	{
		m_y1 = 600;
	}
	
	//Ž€‚ñ‚¾‚ç”wŒistop
	if (((UserData*)Save::GetData())->life_point == 0)
	{
		n = 0;
	}

	//‘¬“x‚Ì•Ï‰»—p
	if (n > 14 && n < 20)
		m_y1 -= 15;
	else
		m_y1 -= n;
	
	//”wŒiØ‚è‘Ö‚¦
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

//ƒhƒ[
void CObjBackground_2::Draw()
{
	//•`ŽÊƒJƒ‰[î•ñ@R=RED G=Green B=Blue A=Alpha(“§‰ßî•ñj
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //•`‰æŒ³Ø‚èŽæ‚èˆÊ’u
	RECT_F dst;  //•`‰ææ•\Ž¦ˆÊ’u

	//Ø‚èŽæ‚èˆÊ’u‚ÌÝ’è
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//1”Ô–Ú‚É“o˜^‚µ‚½ƒOƒ‰ƒtƒBƒbƒN‚ðsrcEdstEc‚Ìî•ñ‚ð‚à‚Æ‚É•`‰æ
    if (count == 1)
	{
		//”wŒi‡@‚ÌˆÊ’uÝ’è‚µ•`‰æ
		dst.m_top = 0.0f - m_y1;
		dst.m_left = LEFT;
		dst.m_right = RIGHT;
		dst.m_bottom = UNDER - m_y1;
		if (n >= 10)
			dst.m_bottom = UNDER + 5 - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//”wŒi‡@‚ÌˆÊ’uÝ’è‚µ•`‰æ
		dst.m_top = 0.0f - m_y1;
		dst.m_left = LEFT - 12.0f;
		dst.m_right = RIGHT - 12.0f;
		dst.m_bottom = UNDER - m_y1;
		if (n >= 10)
			dst.m_bottom = UNDER + 5 - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//”wŒi‡@‚ÌˆÊ’uÝ’è‚µ•`‰æ
		dst.m_top = 0.0f - m_y1;
		dst.m_left = LEFT - 16.8f;
		dst.m_right = RIGHT - 16.8f;
		dst.m_bottom = UNDER - m_y1;
		if (n >= 10)
			dst.m_bottom = UNDER + 5 - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}