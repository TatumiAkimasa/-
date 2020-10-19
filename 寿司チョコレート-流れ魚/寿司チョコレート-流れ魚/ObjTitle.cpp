//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false;
}
//�A�N�V����
void CObjTitle::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����B
	if (Input::GetVKey(VK_RETURN) == true)
	{
	if(m_key_flag==true)
	{
		Scene::SetScene(new CSceneMain());
		m_key_flag=false;
	}
	}
	else
	{
		m_key_flag = true;
	}
}
//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 0.0f,1.0f,1.0f,1.0f };
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�t�狛", 300, 250, 64, c);
	Font::StrDraw(L"GameStart:EnterKey",200,400,48,d);
}