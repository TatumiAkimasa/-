//�g�p����w�b�_�[�t�@�C��
#include "ObjBackground_2.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

bool CObjBackground_2::End_point()
{
	return End_P;
}

//�R���X�g���N�^
CObjBackground_2::CObjBackground_2()
{
	m_y1 = 590.0f;
	count = 2;
	n = 0;
	end_P = false;
	End_P = false;
}

//�C�j�V�����C�Y
void CObjBackground_2::Init()
{

}

//�A�N�V����
void CObjBackground_2::Action()
{
	//�w�i�@�̓���
	
	//Bcakground���瑬�x�ƌ��݈ʒu�擾
	CObjBackground* obj = (CObjBackground*)Objs::GetObj(OBJ_BACK_GROUND);
	if (obj != nullptr)
	{
		n = obj->speed_back();
		end_P = obj->end_point();
	}

	//Background2�̌��ݒn�𔻒肵�A���ɍs�������ǂ����𑊎�(Background)�ɓn��
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

	//�����A���ɍs�������ɕ\���i�C���p�j
	
	if (end_P == true)
	{
		m_y1 = 600;
	}
	
	//���񂾂�w�istop
	if (((UserData*)Save::GetData())->life_point == 0)
	{
		n = 0;
	}

	//���x�̕ω��p
	if (n > 14 && n < 20)
		m_y1 -= 15;
	else
		m_y1 -= n;
	
	//�w�i�؂�ւ�
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

//�h���[
void CObjBackground_2::Draw()
{
	//�`�ʃJ���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //�`�挳�؂���ʒu
	RECT_F dst;  //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//1�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������Ƃɕ`��
    if (count == 1)
	{
		//�w�i�@�̈ʒu�ݒ肵�`��
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
		//�w�i�@�̈ʒu�ݒ肵�`��
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
		//�w�i�@�̈ʒu�ݒ肵�`��
		dst.m_top = 0.0f - m_y1;
		dst.m_left = LEFT - 16.8f;
		dst.m_right = RIGHT - 16.8f;
		dst.m_bottom = UNDER - m_y1;
		if (n >= 10)
			dst.m_bottom = UNDER + n - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}