//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "Objsp_down.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjsp_down::CObjsp_down(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}

//�C�j�V�����C�Y
void CObjsp_down::Init()
{
	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 42, 42, ELEMENT_ITEM, OBJ_SP_DOWN, 1);
}

//�A�N�V����
void CObjsp_down::Action()
{
	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x + 10, m_y + 8);					//���������V�����ʒu(sp_down�̈ʒu)���ɒu��������

	//��ʊO�ɏo����HitBox���폜
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//��l���I�u�W�F�N�g�ƐڐG������I�u�W�F�N�g���폜���X�s�[�h��������
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		Audio::Start(8);

		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//�I�u�W�F�N�g�����L����HitBox���폜����
		
		//�X�R�A�̉��Z
		((UserData*)Save::GetData())->save_score += 1000;

		if (((UserData*)Save::GetData())->sp >= 6)
		{
			((UserData*)Save::GetData())->sp -= 1.0f;
		}
		else
		{
			((UserData*)Save::GetData())->sp = 5.0f;
		}
	}
}

//�h���[
void CObjsp_down::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 360.0f;
	src.m_bottom = 360.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(9, &src, &dst, c, 0.0f);
}