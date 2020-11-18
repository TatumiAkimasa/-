//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "Objmirror.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjmirror::CObjmirror(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}

//�C�j�V�����C�Y
void CObjmirror::Init()
{
	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 48, 48, ELEMENT_MIRROR, OBJ_MIRROR, 1);
}

//�A�N�V����
void CObjmirror::Action()
{
	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x + 16, m_y + 16);					//���������V�����ʒu(��l���̈ʒu)���ɒu��������

	//��ʊO�ɏo����HitBox���폜
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//��l���I�u�W�F�N�g�ƐڐG�����瑀�씽�]�A�C�e�����폜
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//���씽�]�A�C�e�������L����HitBox���폜����

		//��l���I�u�W�F�N�g�ƐڐG������true�ɂ���
		((UserData*)Save::GetData())->key_flag_mirror = true;

		//�X�R�A�̉��Z
		((UserData*)Save::GetData())->save_score += 500;
	}
}

//�h���[
void CObjmirror::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 616.0f;
	src.m_bottom = 616.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + 15.0f + m_x;
	dst.m_bottom = 64.0f + 15.0f + m_y;

	Draw::Draw(11, &src, &dst, c, 0.0f);
}