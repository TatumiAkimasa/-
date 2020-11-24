//�g�p����w�b�_�[�t�@�C��
#include "ObjBackground_2.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBackground_2::Init()
{
	m_y1 = 600.0f;
	count = 2;
	n = 0;
	end_P=0;
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

	//�����A���ɍs�������ɕ\���i�C���p�j
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

	//���x�̕ω��p
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
		dst.m_left = 250.0f;
		dst.m_right = 820.0f;
		dst.m_bottom = 620.0f  - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//�w�i�@�̈ʒu�ݒ肵�`��
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 238.0f;
		dst.m_right = 808.0f;
		dst.m_bottom = 620.0f - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//�w�i�@�̈ʒu�ݒ肵�`��
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 233.2f;
		dst.m_right = 803.2f;
		dst.m_bottom = 620.0f  - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}