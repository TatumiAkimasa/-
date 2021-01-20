//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitboxManager.h"
#include "GameHead.h"
#include "ObjPiyokoFish.h"
#include "GameL/WinInputs.h"
#include "GameL/UserData.h"


//�g�p����Q�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjPiyokoFish::CObjPiyokoFish(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjPiyokoFish::Init()
{
	m_r = 0.0f;
	//�����蔻��p�q�b�g�{�b�N�X���쐬
	Hits::SetHitBox(this, m_px, m_py, 0, 0, NULL, NULL, 1);

}

//�A�N�V����
void CObjPiyokoFish::Action()
{
	m_r += 2.0f;
	CObjFishPlayer* obj = (CObjFishPlayer*)Objs::GetObj(OBJ_FISH_PLAYER);
	float x = obj->GetVX();
	
	if (m_r > 360)
	{
		m_r = 0;
	}

	m_vx += 5;
	m_vy = sin(3.14 / 180 * m_r);
	//m_vx = cos(3.14 / 180 * m_r);

	//�G�@�g�U�e��HitBox�p�|�C���^�[���擾
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
	dst.m_left = 0.0f + m_px;
	dst.m_right = 32.0f + m_px;
	dst.m_bottom = 32.0f + m_py;


	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 254.0f;
	src.m_bottom = 254.0f;
	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(22, &src, &dst, c, m_r);
}
