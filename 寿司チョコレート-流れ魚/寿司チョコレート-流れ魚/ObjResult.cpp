#include "GameHead.h"
#include "ObjResult.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\UserData.h"
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"
//�ڂ�Ă�ł��B

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
	//
	Font::StrDraw(L"�I���I", 300, 250, 64, c);
	//
	swprintf_s(str, L"%d:%d", m_time, s_time);
	Font::StrDraw(str, 300, 250, 64, c);
	//
	//Font::StrDraw(L"�I���I", 300, 250, 64, c);
	//
	Font::StrDraw(L"Push Enter", 230, 400, 64, c);
}