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

//�C�j�V�����C�Y
void CObjTree::Init()
{
	m_x = 800;
	m_vx = 0.0f;
}

//�A�N�V����
void CObjTree::Action()
{
	//�ؗp�^�C��
	((UserData*)Save::GetData())->Tree_time--;

	//�؂̏o������
	if (((UserData*)Save::GetData())->Tree_said == true)
	{
		//�؂𓮂�������
		if (m_vx >= -450.0f)
		{
			m_vx -= 3.0f;
		}
		//�؂��~�߂鏈��
		if (m_vx == -450.0f)
		{
			m_vx = -450.0f;
		}
	}

	//�؂̍폜����
	if (((UserData*)Save::GetData())->Tree_time <= 0)
	{
		//�o��������if���ɓ���Ȃ��悤�ɂ���ׂ̃t���O
		((UserData*)Save::GetData())->Tree_said = false;

		//�؂𓮂�������
		if (m_vx <= 0.0f)
		{
			m_vx += 3.0f;
		}
		//�؂���ʊO�ɏo������
		if (m_vx >= 0.0f)
		{
			this->SetStatus(false);
			((UserData*)Save::GetData())->Tree_time = 0;
		}
	}
}

//�h���[
void CObjTree::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 510.0f;
	src.m_bottom = 510.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x + m_vx;
	dst.m_right = 500.0f + m_x + m_vx;
	dst.m_bottom = 500.0f + m_y;

	Draw::Draw(14, &src, &dst, c, 0.0f);
}