#include "GameHead.h"
#include "ObjResult.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\UserData.h"
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"
//�ڂ�Ă�ł��您����������

//�g�p����Q�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjResult::CObjResult()
{
     
}

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
			((UserData*)Save::GetData())->save_score = 0;
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
	Font::StrDraw(L"�I���I", 300, 100, 64, c);
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
	Font::StrDraw(str, 200, 200, 64, c);
	//�X�R�A�\��
	swprintf_s
	(
		str,
		L"���́@%05d",
		((UserData*)Save::GetData())->save_score
	);
	Font::StrDraw(str, 230, 300, 64, c);
	//�G���^�[�L�[�ňړ�
	Font::StrDraw(L"Push Enter", 230, 400, 64, c);
}