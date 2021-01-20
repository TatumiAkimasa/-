//�g�p����w�b�_�[�t�@�C��
#include "ObjBackground.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

float CObjBackground::speed_back()
{
	return n;
}

bool CObjBackground::end_point()
{
	return end_P;
}

//�C�j�V�����C�Y
void CObjBackground::Init()
{
	m_y1 = 0.0f;
	count = 10;
	add =5;
	n = 0;
	End_P = false;
	end_P = false;
}

//�A�N�V����
void CObjBackground::Action()
{
	//�w�i�@�̓���

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

	//�����A���ɍs�������ɕ\���i�C���p�j
	if (End_P==true)
	{
		m_y1 = 600;
	}
	
	//���x��sp����󂯎��
	n = ((UserData*)Save::GetData())->sp;

	//���x���ŏ��̂ق��̕����Œ艻
	if (m_y1 >= 580)
		add = n;
	
	if (((UserData*)Save::GetData())->life_point == 0)
	{
		n = 0;
		add = 0;
	}

	//�����A�r����1�ُ�̕ω����������ꍇ��������
	//end�|�C���g�n������Ȃ瑽������Ȃ��B�i�����ݒ�̎ז��ɂ��Ȃ�j
	/*if (n != add)
		n = add;*/

	//���x�̍��ʉ�(15��20)
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

//�h���[
void CObjBackground::Draw()
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
	if (count == 10)
	{
		//�w�i�@�̈ʒu�ݒ肵�`��
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 250.0f;
		dst.m_right = 820.0f;
		dst.m_bottom = 605.0f  - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 1)
	{
		//�w�i�@�̈ʒu�ݒ肵�`��
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 250.0f;
		dst.m_right = 820.0f;
		dst.m_bottom = 605.0f  - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//�w�i�@�̈ʒu�ݒ肵�`��
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 238.0f;
		dst.m_right = 808.0f;
		dst.m_bottom = 605.0f  - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//�w�i�@�̈ʒu�ݒ肵�`��
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 233.2f;
		dst.m_right = 803.2f;
		dst.m_bottom = 605.0f  - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}
