//�g�p����w�b�_�[�t�@�C��
#include "ObjBackground_2.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBackground_2::Init()
{
	m_y1 = 600.0f;
	count = 2;
}

//�A�N�V����
void CObjBackground_2::Action()
{
	//�w�i�@�̓���
	//�݂��i�����j�𗬂��΂��̏����͕s�v
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
		dst.m_bottom = 610.0f - m_y1;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	else if (count == 2)
	{
		//�w�i�@�̈ʒu�ݒ肵�`��
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 238.0f;
		dst.m_right = 808.0f;
		dst.m_bottom = 601.0f - m_y1;

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (count == 3)
	{
		//�w�i�@�̈ʒu�ݒ肵�`��
		dst.m_top = 0.0f - m_y1;
		dst.m_left = 233.2f;
		dst.m_right = 803.2f;
		dst.m_bottom = 600.0f - m_y1;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

}