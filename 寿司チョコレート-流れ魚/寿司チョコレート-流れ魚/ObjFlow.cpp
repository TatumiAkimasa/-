//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjFlow.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjFlow::CObjFlow(float x, float y, float s)
{
	//�������G��
	rand(); rand(); rand(); rand(); rand();

	m_x = x;
	m_y = y;
	m_vy = s;
	m_id = FLOW1 + rand() % 4;
	g_ani = rand() % 5;
}

//�C�j�V�����C�Y
void CObjFlow::Init()
{
	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_x + 24, m_y + 45, 48, 72, ELEMENT_ENEMY, OBJ_FLOW, 1);
}

//�A�N�V����
void CObjFlow::Action()
{
	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x + 24, m_y + 45);					//���������V�����ʒu(��l���@�̈ʒu)���ɒu��������

	//��ʊO�ɏo����HitBox���폜
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//�X�R�A�̉��Z
		if (((UserData*)Save::GetData())->sp >= 5.0f && ((UserData*)Save::GetData())->sp < 10.0f)
		{
			//mirror�̎��X�R�A2�{�̏���
			if (((UserData*)Save::GetData())->key_flag_mirror == true)
			{
				((UserData*)Save::GetData())->save_score += 200;
			}
			else
			{
				((UserData*)Save::GetData())->save_score += 100;
			}
		}
		else if (((UserData*)Save::GetData())->sp >= 10.0f && ((UserData*)Save::GetData())->sp < 15.0f)
		{
			if (((UserData*)Save::GetData())->key_flag_mirror == true)
			{
				((UserData*)Save::GetData())->save_score += 400;
			}
			else
			{
				((UserData*)Save::GetData())->save_score += 200;
			}
		}
		else if (((UserData*)Save::GetData())->sp >= 15.0f && ((UserData*)Save::GetData())->sp < 20.0f)
		{
			if (((UserData*)Save::GetData())->key_flag_mirror == true)
			{
				((UserData*)Save::GetData())->save_score += 600;
			}
			else
			{
				((UserData*)Save::GetData())->save_score += 300;
			}
		}
		else if (((UserData*)Save::GetData())->sp >= 20.0f)
		{
			if (((UserData*)Save::GetData())->key_flag_mirror == true)
			{
				((UserData*)Save::GetData())->save_score += 1000;
			}
			else
			{
				((UserData*)Save::GetData())->save_score += 500;
			}
		}
	}

	//��l���I�u�W�F�N�g�ƐڐG������10�~���폜
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//10�~�����L����HitBox���폜����
	}
}

//�h���[
void CObjFlow::Draw()
{
	float p[4] = { 0.9f,0.9f,1.0f,1.0f };
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.8f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 128 * 1;
	src.m_right = src.m_left + 128;
	src.m_bottom = src.m_top + 128;

	
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 120.0f + m_x;
	dst.m_bottom = 140.0f + m_y;
	

	
	if (g_ani <= 3)
	{
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (g_ani == 3)
	{
		Draw::Draw(12, &src, &dst, p, 0.0f);
	}
	if (g_ani == 4)
	{
		Draw::Draw(12, &src, &dst, y, 0.0f);
	}

}