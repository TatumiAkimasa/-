//Žg—p‚·‚éƒwƒbƒ_[ƒtƒ@ƒCƒ‹
#include "ObjBackground.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//Žg—p‚·‚éƒl[ƒ€ƒXƒy[ƒX
using namespace GameL;

//ƒCƒjƒVƒƒƒ‰ƒCƒY
void CObjBackground::Init()
{
	m_y1 = 0.0f;
	count = 10;
	add = 0;
	n = 0;
}

//ƒAƒNƒVƒ‡ƒ“
void CObjBackground::Action()
{
	//”wŒi‡@‚Ì“®ì
	//‚Ý‚¸i”’üj‚ð—¬‚¹‚Î‚±‚Ìˆ—‚Í•s—v
    n = ((UserData*)Save::GetData())->sp;


	if (n == 20)
		m_y1 -= n;
	else if (n > 14)
		m_y1 -= 15;
	else
		m_y1 -= n;

	add = n;

	if (n >= 9 && n <= 15)
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
		if(n>=11&&n<=15)
		dst.m_bottom = 620.0f+add - m_y1;
		else
		dst.m_bottom = 620.0f + add - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 1)
	{
		//”wŒi‡@‚ÌˆÊ’uÝ’è‚µ•`‰æ
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 250.0f;
		dst.m_right = 820.0f;
		if (n >= 11 && n <= 15)
			dst.m_bottom = 630.0f + add - m_y1;
		else
			dst.m_bottom = 630.0f + add - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//”wŒi‡@‚ÌˆÊ’uÝ’è‚µ•`‰æ
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 238.0f;
		dst.m_right = 808.0f;
		if (n >= 11 && n <= 15)
			dst.m_bottom = 631.0f + add - m_y1;
		else
			dst.m_bottom = 631.0f + add - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//”wŒi‡@‚ÌˆÊ’uÝ’è‚µ•`‰æ
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 233.2f;
		dst.m_right = 803.2f;
		if (n >= 11 && n <= 15)
			dst.m_bottom = 631.0f + add - m_y1;
		else
			dst.m_bottom = 631.0f + add - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}
