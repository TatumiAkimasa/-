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
	m_id = FLOW_TAKO + rand() % 5;
}

//�C�j�V�����C�Y
void CObjFlow::Init()
{
	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 48, 48, ELEMENT_ENEMY, OBJ_FLOW, 1);
}

//�A�N�V����
void CObjFlow::Action()
{
	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x + 16, m_y + 16);					//���������V�����ʒu(��l���@�̈ʒu)���ɒu��������

	//��ʊO�ɏo����HitBox���폜
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//�X�R�A�̉��Z
		((UserData*)Save::GetData())->save_score += 10;
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
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 95 * (m_id - FLOW_TAKO);
	src.m_right = src.m_left + 96;
	src.m_bottom = src.m_top + 96;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + 15.0f + m_x;
	dst.m_bottom = 64.0f + 15.0f + m_y;

	Draw::Draw(11, &src, &dst, c, 0.0f);
}