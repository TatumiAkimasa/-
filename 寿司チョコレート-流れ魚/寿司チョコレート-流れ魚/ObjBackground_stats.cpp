//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "ObjBackground_stats.h"
#include "GameHead.h"



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
	src.m_bottom = 560.0f;

	//6�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������Ƃɕ`��
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f;
	dst.m_right = 490.0f;
	dst.m_bottom = 600.0f ;

	if (((UserData*)Save::GetData())->space_flag == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 300.0f;
		src.m_bottom = 500.0f;

		//6�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������Ƃɕ`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 300.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(26, &src, &dst, c, 0.0f);
	}
	else
	    Draw::Draw(6, &src, &dst, c, 0.0f);
	

}
