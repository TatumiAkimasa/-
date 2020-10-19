//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Obj10enn.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObj10enn::CObj10enn(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObj10enn::Init()
{
	m_vy = 0;
	m_vy = 5.0;

	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_10ENN, 1);
}

//�A�N�V����
void CObj10enn::Action()
{
	//��ʊO�ɏo����10�~���폜�����͂����Z
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		//�������x��������
		m_vy += 10.0;
		
		//���͉��Z����
	}

	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x, m_y);					//���������V�����ʒu(��l���@�̈ʒu)���ɒu��������
	
	//��ʊO�ɏo����HitBox���폜
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//��l���I�u�W�F�N�g�ƐڐG������10�~���폜
	if (hit->CheckObjNameHit(ELEMENT_PLAYER) != nullptr)
	{
		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//10�~�����L����HitBox���폜����
	}
}

//�h���[
void CObj10enn::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 768.0f;
	src.m_bottom = 768.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(3, &src, &dst, c, 0.0f);
}