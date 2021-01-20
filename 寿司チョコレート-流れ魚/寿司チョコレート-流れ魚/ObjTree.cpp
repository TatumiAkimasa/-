//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjTree.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjTree::CObjTree(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�A�N�V����
void CObjTree::Action()
{
	//�ؗp�^�C��
	if (((UserData*)Save::GetData())->life_point > 0)
	{
		((UserData*)Save::GetData())->Tree_time--;
	}
}

//�h���[
void CObjTree::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�؂̏����l�p�ϐ�
	static float r = -80.0f;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 510.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 1000.0f + m_x;
	dst.m_bottom = 450.0f + m_y;

	//�؂��o�������鏈��
	if (((UserData*)Save::GetData())->Tree_said == true)
	{
		//�؂���]�����鏈��
		r += 1.5f;
		if (r >= 6.0f)
			r = 6.0f;
	}
	
	//�؂���������
	if (((UserData*)Save::GetData())->Tree_time <= 0)
	{
		//�o��������if���ɓ���Ȃ��悤�ɂ���ׂ̃t���O
		((UserData*)Save::GetData())->Tree_said = false;

		//�؂���]�����鏈��
		r -= 1.5f;
		if (r <= -100.0f)
		{
			r = -100.0f;
			this->SetStatus(false);
			((UserData*)Save::GetData())->Tree_time = 0;
		}
	}
	
	((UserData*)Save::GetData())->Tree_flag = false;

	Draw::Draw(18, &src, &dst, c, r);
}