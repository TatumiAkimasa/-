//�g�p����w�b�_�[�t�@�C��
#include "Objwater_flow.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"
#include <stdlib.h>
#include <time.h>
#include"GameL/UserData.h"


//�g�p����l�[���X�y�[�X////////
using namespace GameL;

CObjwater_flow::CObjwater_flow(float a)
{
	speed = a;
}

//�C�j�V�����C�Y
void CObjwater_flow::Init()
{
	m_y1 = 0.0f;
	right = 0;
	right_d = 0;
	flow_flag = true;
	speed = 0;
	srand(time(NULL)); // �����_������������
}

//�A�N�V����
void CObjwater_flow::Action()
{
	
	//�������G��
	rand(); rand(); rand(); rand();

	right = rand() % 320;//�E�֍s���l�i�����_���j
	
	speed += 0.5;

	if (m_y1 < 1.0f)
	{
		right_d = right;
		flow_flag = false;
	}

	//�w�i�@�̓���
	m_y1 += speed;
	if (((UserData*)Save::GetData())->life_point == 0)
	{
		m_y1 = 0;
	}

	if (m_y1 > 650.0f)
	{
		this->SetStatus(false);//���g�ɍ폜����
		flow_flag = true;
		return;
	}

}

//�h���[
void CObjwater_flow::Draw()
{
	//�`�ʃJ���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //�`�挳�؂���ʒu
	RECT_F dst;  //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	//�F��
	if (((UserData*)Save::GetData())->space_flag == true)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		//�w�i�@�̈ʒu�ݒ肵�`��
		if (flow_flag == true)
		{
			dst.m_top = -16.0f + m_y1;
			dst.m_left = 360.0f + right;
			dst.m_right = 376.0f + right;
			dst.m_bottom = 0.0f + m_y1;
		}
		else if (flow_flag == false)
		{
			dst.m_top = -16.0f + m_y1;
			dst.m_left = 360.0f + right_d;
			dst.m_right = 376.0f + right_d;
			dst.m_bottom = 0.0f + m_y1;
		}
		//19�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������Ƃɕ`��
		Draw::Draw(19, &src, &dst, c, 0.0f);
	}
	//�n��
	else
	{
		src.m_top = 0.0f;
		src.m_left = 60.0f;
		src.m_right = 500.0f;
		src.m_bottom = 512.0f;

		//�w�i�@�̈ʒu�ݒ肵�`��
		if (flow_flag == true)
		{
			dst.m_top = -200.0f + m_y1;
			dst.m_left = 360.0f + right;
			dst.m_right = 380.0f + right;
			dst.m_bottom = -10.0f + m_y1;
		}
		else if (flow_flag == false)
		{
			dst.m_top = -200.0f + m_y1;
			dst.m_left = 360.0f + right_d;
			dst.m_right = 380.0f + right_d;
			dst.m_bottom = -10.0f + m_y1;
		}
		//1�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������Ƃɕ`��
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
}
