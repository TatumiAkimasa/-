//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjRanking.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjRanking::Init()
{
	
}
//�A�N�V����
void CObjRanking::Action()
{
	//�㉺�L�[�������ăV�[���F�^�C�g���Ɉڍs����B/
	if (Input::GetVKey(VK_UP) == true)
	{
		Scene::SetScene(new CSceneTitle());
	}
}
//�h���[//�^�C�g��
void CObjRanking::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };



	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	


	//�����L���O
	Font::StrDraw(L"�����L���O", 270, 0, 50, c);
	for (int i = 0; i < 10; i++)
	{
		wchar_t str[256];
		swprintf_s(str, L"%2d��       %12d����", i + 1, ((UserData*)Save::GetData())->save_score);
		Font::StrDraw(str, 230, 70 + 48 * i, 24, c);
	}
}