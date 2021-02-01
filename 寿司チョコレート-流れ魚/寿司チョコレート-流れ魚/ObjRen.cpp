//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjRen.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjRen::CObjRen(float x, float y, float s)
{
	m_x = x;
	m_y = y;
	m_vy = s;
}

//�C�j�V�����C�Y
void CObjRen::Init()
{
	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_x + 16, m_y + 16, 48, 48, ELEMENT_REN, OBJ_REN, 1);
}

//�A�N�V����
void CObjRen::Action()
{
	if (((UserData*)Save::GetData())->life_point > 0)
	{
		m_y += m_vy;
	}

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x + 16, m_y + 16);		//���������V�����ʒu(Ren�̈ʒu)���ɒu��������

	//��ʊO�ɏo����HitBox���폜
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{

		Audio::Start(15);

		this->SetStatus(false);		//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);	//Armor�����L����HitBox���폜����

		//Ren_flag��true
		((UserData*)Save::GetData())->Ren_flag = true;

		//ren��4����
		((UserData*)Save::GetData())->ren = 4;
	}
}

//�h���[
void CObjRen::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + 15.0f + m_x;
	dst.m_right = 64.0f + 15.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(21, &src, &dst, c, 0.0f);
}