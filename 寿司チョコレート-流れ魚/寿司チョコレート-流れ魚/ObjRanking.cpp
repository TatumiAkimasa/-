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
	//�_����0�ɂ���
	((UserData*)Save::GetData())->save_score = 0;
	D_flag = false;
	U_flag = false;
}
//�A�N�V����
void CObjRanking::Action()
{
	//�㉺�L�[�������ăV�[���F�����L���O�Ɉڍs����B/
	if (Input::GetVKey(VK_UP) == true)
	{
		if (U_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			U_flag = false;
		}
	}
	else
	{
		U_flag = true;
	}

	//�㉺�L�[�������ăV�[���F�����L���O�Ɉڍs����B/
	if (Input::GetVKey(VK_DOWN) == true)
	{
		if (D_flag == true)
		{
			Scene::SetScene(new CSceneAchievement());
			D_flag = false;
		}
	}
	else
	{
		D_flag = true;
	}
}
//�h���[//�^�C�g��
void CObjRanking::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,.0f,0.0f,1.0f };
	float d[4] = { 0.0f,.0f,0.0f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�����L���O
	Font::StrDraw(L"�����L���O", 280, 25, 50, c);
	Font::StrDraw(L"��{�^���Ń^�C�g���ɖ߂�", 570, 555, 17, c);


	for (int i = 0; i < 10; i++)
	{
		wchar_t str[256];
		swprintf_s(str, L"%2d��       %12d����", i + 1, ((UserData*)Save::GetData())->Ranking[i]);
		Font::StrDraw(str, 230, 100 + 48 * i, 24, d);
	}

}

