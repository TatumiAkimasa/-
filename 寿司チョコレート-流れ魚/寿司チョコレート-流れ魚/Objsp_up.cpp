//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "Objsp_up.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjsp_up::CObjsp_up(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}

//�C�j�V�����C�Y
void CObjsp_up::Init()
{
	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_x + 70, m_y + 35, 32, 60, ELEMENT_ITEM, OBJ_SP_UP, 1);
}

//�A�N�V����
void CObjsp_up::Action()
{
	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x + 70, m_y + 35);					//���������V�����ʒu(sp_up�̈ʒu)���ɒu��������

	//��ʊO�ɏo����HitBox���폜
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//��l���I�u�W�F�N�g�ƐڐG������I�u�W�F�N�g���폜���X�s�[�h���グ��
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		Audio::Start(1);

		this->SetStatus(false);    //���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);  //�A�C�e���I�u�W�F�N�g�����L����HitBox�ɍ폜����
	
		if (((UserData*)Save::GetData())->sp < 20.0f)
		{
			((UserData*)Save::GetData())->sp += 1.0f;
		}
	}
}

//�h���[
void CObjsp_up::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 696.0f;
	src.m_bottom = 564.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 170.0f + m_x;
	dst.m_bottom = 130.0f + m_y;

	Draw::Draw(8, &src, &dst, c, 0.0f);
}