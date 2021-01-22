//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjArmor.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjArmor::CObjArmor(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}

//�C�j�V�����C�Y
void CObjArmor::Init()
{
	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 48, 48, ELEMENT_ARMOR, OBJ_ARMOR, 1);
}

//�A�N�V����
void CObjArmor::Action()
{
	if (((UserData*)Save::GetData())->life_point > 0)
	{
		m_y += m_vy;
	}

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x + 16, m_y + 16);		//���������V�����ʒu(Armor�̈ʒu)���ɒu��������

	//��ʊO�ɏo����HitBox���폜
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//��l���I�u�W�F�N�g�ƐڐG������Armor�t���O��true�ɂ���
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//Armor�����L����HitBox���폜����

		//Armor�t���O��true�ɂ���
		((UserData*)Save::GetData())->Armor_flag = true;
	}
}

//�h���[
void CObjArmor::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + 15.0f + m_x;
	dst.m_bottom = 64.0f + 15.0f + m_y;

	Draw::Draw(20, &src, &dst, c, 0.0f);
}