//�g�p����w�b�_�[�t�@�C��
#include "ObjBackground_stats.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBackground_stats::Init()
{
	
}

//�A�N�V����
void CObjBackground_stats::Action()
{
	
}

//�h���[
void CObjBackground_stats::Draw()
{
	//�`�ʃJ���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //�`�挳�؂���ʒu
	RECT_F dst;  //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//1�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������Ƃɕ`��
	//�w�i�@�̈ʒu�ݒ肵�`��
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f;
	dst.m_right = 490.0f;
	dst.m_bottom = 600.0f ;

	Draw::Draw(6, &src, &dst, c, 0.0f);
	

}
