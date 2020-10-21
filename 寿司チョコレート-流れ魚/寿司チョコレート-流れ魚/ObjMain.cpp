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
	f = 0;
	s_time = 0;
	m_time = 0;
	((UserData*)Save::GetData())->save_s_time = 0;//�Z�[�u�pm_time������
	((UserData*)Save::GetData())->save_m_time = 0;//�Z�[�u�ps_time������
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

	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"�^�C���@%d:%d", m_time, s_time);
	Font::StrDraw(str, 20, 40, 40, c);

}