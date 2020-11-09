//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMain::Init()
{
	f = 0;//�t���[���v�Z
	s_time = 0;
	m_time = 0;
	((UserData*)Save::GetData())->save_s_time = 0;//�Z�[�u�pm_time������
	((UserData*)Save::GetData())->save_m_time = 0;//�Z�[�u�ps_time������
	((UserData*)Save::GetData())->life_point = 3;//�Z�[�u�plife_point������
}

//�A�N�V����
void CObjMain::Action()
{
	f++;
	//f��60�����1�b�J�E���g
	if (f == 60)
	{
		f = 0;
		s_time++;
		//s_time++�̎��_�ŃZ�[�u�ps_time���C���N�������g
		((UserData*)Save::GetData())->save_s_time++;
	
	}
	//s_time��60��1���ł�
	if (s_time == 60)
	{
		s_time = 0;
		m_time++;
		//m_time++�̎��_�ŃZ�[�u�pm_time���C���N�������g
		((UserData*)Save::GetData())->save_m_time++;
		((UserData*)Save::GetData())->save_s_time = 0;
	}
}

//�h���[
void CObjMain::Draw()
{
	float c[4] = { 1,1,1,1 };

	//�^�C���̕\��
	wchar_t str[256];
	swprintf_s(str, L"�^�C���@%02d:%02d", m_time, s_time);
	Font::StrDraw(str, 20, 40, 40, c);

	//�X�R�A�̕\��
	swprintf_s(str, L"���́@�@%05d", ((UserData*)Save::GetData())->save_score);
	Font::StrDraw(str, 20, 100, 40, c);

	//�X�s�[�h�̕\��
	swprintf_s(str, L"���x�@�@%f", ((UserData*)Save::GetData())->sp);
	Font::StrDraw(str, 20, 350, 40, c);

	//���C�t�̕\��
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	swprintf_s(str, L"���C�t");
	Font::StrDraw(str, 20, 160, 40, c);
	RECT_F src;
	RECT_F dst;

	if (((UserData*)Save::GetData())->life_point >= 1)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		dst.m_top = 200.0f;
		dst.m_left = 20.0f;
		dst.m_right = 64.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		Draw::Draw(10, &src, &dst, d, 0.0f);
	}

	if (((UserData*)Save::GetData())->life_point >= 2)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		dst.m_top = 200.0f;
		dst.m_left = 100.0f;
		dst.m_right = 64.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		Draw::Draw(10, &src, &dst, d, 0.0f);
	}

	if (((UserData*)Save::GetData())->life_point >= 3)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		dst.m_top = 200.0f;
		dst.m_left = 180.0f;
		dst.m_right = 64.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		Draw::Draw(10, &src, &dst, d, 0.0f);
	}
}