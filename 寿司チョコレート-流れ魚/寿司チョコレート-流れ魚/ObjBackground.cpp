//Žg—p‚·‚éƒwƒbƒ_[ƒtƒ@ƒCƒ‹
#include "ObjBackground.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//Žg—p‚·‚éƒl[ƒ€ƒXƒy[ƒX
using namespace GameL;

float CObjBackground::speed_back()
{
	return n;
}

bool CObjBackground::end_point()
{
	return end_P;
}

//ƒCƒjƒVƒƒƒ‰ƒCƒY
void CObjBackground::Init()
{
	m_y1 = 0.0f;
	count = 10;
	add =5;
	n = 0;
	End_P = false;
	end_P = false;
}

//ƒAƒNƒVƒ‡ƒ“
void CObjBackground::Action()
{
	//”wŒi‡@‚Ì“®ì

	CObjBackground_2* obj = (CObjBackground_2*)Objs::GetObj(OBJ_BACK_GROUND_2);
	if (obj != nullptr)
	{
		End_P = obj->End_point();
	}

	if (end_P == false)
	{
		if (n >= 10 && m_y1 >= 15.0f && m_y1 <= 27.0f)
		{
			end_P = true;
		}
		else if (n < 9 && m_y1 >= 0.0f && m_y1 <= 9.0f)
		{
			end_P = true;
		}
		else if (n==7&&n == 9 && m_y1 >= 12.0f && m_y1 <= 16.0f)
		{
			end_P = true;
		}
	}
	else
	{
		end_P = false;
	}

	//‚à‚µA‰º‚És‚Á‚½‚çã‚É•\Ž¦iC³—pj
	if (End_P==true)
	{
		m_y1 = 600;
	}
	
	//‘¬“x‚ðsp‚©‚çŽó‚¯Žæ‚é
	n = ((UserData*)Save::GetData())->sp;

	//‘¬“x‚ðÅ‰‚Ì‚Ù‚¤‚Ì•¨‚ðŒÅ’è‰»
	if (m_y1 >= 580)
		add = n;
	
	if (((UserData*)Save::GetData())->life_point == 0)
	{
		n = 0;
		add = 0;
	}

	//‚à‚µA“r’†‚Å1ˆÙí‚Ì•Ï‰»‚ª‚ ‚Á‚½ê‡–³Ž‹‚·‚é
	//endƒ|ƒCƒ“ƒgŒn‚ª‚ ‚é‚È‚ç‘½•ª‚¢‚ç‚È‚¢Bi‰ŠúÝ’è‚ÌŽ×–‚‚É‚à‚È‚éj
	/*if (n != add)
		n = add;*/

	//‘¬“x‚Ì·•Ê‰»(15¨20)
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
void CObjBackground::Draw()
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
	if (count == 10)
	{
		//”wŒi‡@‚ÌˆÊ’uÝ’è‚µ•`‰æ
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 250.0f;
		dst.m_right = 820.0f;
		dst.m_bottom = 605.0f  - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 1)
	{
		//”wŒi‡@‚ÌˆÊ’uÝ’è‚µ•`‰æ
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 250.0f;
		dst.m_right = 820.0f;
		dst.m_bottom = 605.0f  - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//”wŒi‡@‚ÌˆÊ’uÝ’è‚µ•`‰æ
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 238.0f;
		dst.m_right = 808.0f;
		dst.m_bottom = 605.0f  - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//”wŒi‡@‚ÌˆÊ’uÝ’è‚µ•`‰æ
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 233.2f;
		dst.m_right = 803.2f;
		dst.m_bottom = 605.0f  - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}
