#include "GameHead.h"
#include "ObjResult.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\UserData.h"
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"

//�g�p����Q�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjResult::Init()
{
	m_key_flag = false;
	m_time = 0;
	s_time = 0;
}

//�A�N�V����
void CObjResult::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[���^�C�g���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjResult::Draw()
{
	wchar_t str[256];
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�R�����g�\��
	if (((UserData*)Save::GetData())->save_score == 0)
	{
		Font::StrDraw(L"���̕���ɂ��u���Ȃ��c", 150, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 0 && ((UserData*)Save::GetData())->save_score <= 500)
	{
		Font::StrDraw(L"�t��", 370, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 500 && ((UserData*)Save::GetData())->save_score <= 1000)
	{
		Font::StrDraw(L"�����Ƃ���΂낤�I", 200, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 1000 && ((UserData*)Save::GetData())->save_score <= 2500)
	{
		Font::StrDraw(L"���Ƃ͙R�����̂���", 190, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 2500 && ((UserData*)Save::GetData())->save_score <= 5000)
	{
		Font::StrDraw(L"����", 370, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 5000 && ((UserData*)Save::GetData())->save_score <= 10000)
	{
		Font::StrDraw(L"���催�催��", 270, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 10000 && ((UserData*)Save::GetData())->save_score <= 25000)
	{
		Font::StrDraw(L"�Z���X�̉�", 280, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 25000 && ((UserData*)Save::GetData())->save_score <= 50000)
	{
		Font::StrDraw(L"���͂�T��", 280, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 50000 && ((UserData*)Save::GetData())->save_score <= 75000)
	{
		Font::StrDraw(L"���͂���", 280, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 75000 && ((UserData*)Save::GetData())->save_score <= 100000)
	{
		Font::StrDraw(L"���̉�", 340, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 100000 && ((UserData*)Save::GetData())->save_score <= 250000)
	{
		Font::StrDraw(L"����҂���肢�I", 190, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score > 250000 && ((UserData*)Save::GetData())->save_score < 530000)
	{
		Font::StrDraw(L"�M�����N�e�B�b�N�t�B�b�V��", 90, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score >= 530000 && ((UserData*)Save::GetData())->save_score < 1000000)
	{
		Font::StrDraw(L"����53���z������", 210, 400, 48, c);
	}
	else if (((UserData*)Save::GetData())->save_score >= 1000000)
	{
		Font::StrDraw(L"�`�[�g�����o����܂���", 140, 400, 48, c);
	}

	//�^�C���\��
	if (((UserData*)Save::GetData())->save_s_time <= 9)
	{
		swprintf_s
		(
			str,
			L"�^�C���@%d:0%d",
			((UserData*)Save::GetData())->save_m_time,
			((UserData*)Save::GetData())->save_s_time
		);
	}
	else
	{
		swprintf_s
		(
			str,
			L"�^�C���@%d:%d",
			((UserData*)Save::GetData())->save_m_time,
			((UserData*)Save::GetData())->save_s_time
		);
	}
	Font::StrDraw(str, 200, 100, 64, c);
	
	//�X�R�A�\��
	swprintf_s
	(
		str,
		L"���́@%05d",
		((UserData*)Save::GetData())->save_score
	);
	Font::StrDraw(str, 230, 250, 64, c);
	
	//�G���^�[�L�[�ňړ�
	Font::StrDraw(L"�G���^�[�Ń^�C�g��", 410, 495, 32, c);

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	dst.m_top = 0.0f;
	dst.m_left = 75.0f;
	dst.m_right = 775.0f;
	dst.m_bottom = 565.0f;

	Draw::Draw(15, &src, &dst, c, -0.0f);
}