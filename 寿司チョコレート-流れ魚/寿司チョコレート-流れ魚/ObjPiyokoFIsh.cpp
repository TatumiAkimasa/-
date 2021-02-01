//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitboxManager.h"
#include "GameHead.h"
#include "ObjPiyokoFish.h"
#include "GameL/WinInputs.h"
#include "GameL/UserData.h"

#include<math.h>

//�g�p����Q�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjPiyokoFish::CObjPiyokoFish(float x, float y, float r)
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_fp_x = 0.0f;
	m_r = r;
	m_px = x;
	m_py = y;
	m_obj = (CObjFishPlayer*)Objs::GetObj(OBJ_FISH_PLAYER);
}

//�C�j�V�����C�Y
void CObjPiyokoFish::Init()
{
	m_obj = (CObjFishPlayer*)Objs::GetObj(OBJ_FISH_PLAYER);
	m_fp_x = m_obj->GetX();
	m_ani_frame = 0;
	m_ani_time = 0;
	//�����蔻��p�q�b�g�{�b�N�X���쐬
	Hits::SetHitBox(this, m_px, m_py, 0, 0, NULL, NULL, 1);
}

//�A�N�V����
void CObjPiyokoFish::Action()
{
	m_obj = (CObjFishPlayer*)Objs::GetObj(OBJ_FISH_PLAYER);
	m_fp_x = m_obj->GetX();

	if (((UserData*)Save::GetData())->life_point > 0)
	{
		m_ani_time++;
		if (m_ani_time == 30)
		{
			m_ani_frame++;
			m_ani_time = 0;
			if (m_ani_frame >= 2)
			{
				m_ani_frame = 0;
			}
		}
		m_r += 2.0f;

		if (m_r > 360)
		{
			m_r = 0;
		}

	m_vx = cos(3.14f / 180.0f * m_r);
	m_vy = sin(3.14f / 180.0f * m_r);

		float r = 0.0f;
		r = m_vx * m_vx + m_vy * m_vy;
		r = sqrt(r);

	if (r == 0.0f)
	{
		;
	}
	else
	{
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}

		m_vx *= 1.5f;
		m_vy *= 1.5f;

		m_px += m_vx;
		m_py += m_vy;
	}
	else
	{
		m_vx = 0.0f;
		m_vy = 0.0f;

		m_px += m_vx;
		m_py += m_vy;
	}
	//piyoko��HitBox�p�|�C���^�[���擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);

	if (((UserData*)Save::GetData())->key_flag_mirror == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjPiyokoFish::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//�`��؂���ʒu
	RECT_F dst;//�`��\���ʒu


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 16.0f + m_px + m_fp_x;
	dst.m_right = 48.0f + m_px + m_fp_x;
	dst.m_bottom = -32.0f + m_py;


	//�؂���ʒu�̐ݒ�
	src.m_top = 250.0f * m_ani_frame;
	src.m_left = 0.0f;
	src.m_right = 250.0f;
	src.m_bottom = 250.0f * (m_ani_frame + 1);
	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(24, &src, &dst, c, 180.0f);
}
