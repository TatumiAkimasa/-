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
	float a[4] = { 1.0f,0.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,0.0f,1.0f };
	float c[4] = { 0.6f,0.5f,0.0f,1.0f };
	float d[4] = { 0.5f,0.5f,0.5f,1.0f };
	float e[4] = { 0.8f,0.4f,0.1f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�����L���O
	Font::StrDraw(L"�����L���O", 270, 25, 50, a);
	Font::StrDraw(L"��{�^���Ń^�C�g���ɖ߂�", 25, 550, 17, a);
	Font::StrDraw(L"���{�^���Ŏ��щ�ʂɈړ�", 570, 550, 17, a);

	wchar_t str[256];
	swprintf_s(str, L" 1��  %4d����", ((UserData*)Save::GetData())->Ranking[0]);
	Font::StrDraw(str, 190, 95, 50, c);

	swprintf_s(str, L"________________");
	Font::StrDraw(str, 210, 98, 50, c);

	swprintf_s(str, L" 2��  %4d����", ((UserData*)Save::GetData())->Ranking[1]);
	Font::StrDraw(str, 60, 170, 35, d);

	swprintf_s(str, L"_______________");
	Font::StrDraw(str, 75, 173, 35, d);

	swprintf_s(str, L" 3��  %4d����", ((UserData*)Save::GetData())->Ranking[2]);
	Font::StrDraw(str, 440, 170, 35, e);

	swprintf_s(str, L"_______________");
	Font::StrDraw(str, 455, 173, 35, e);

	for (int i = 3; i < 10; i++)
	{
		
		swprintf_s(str, L"%2d��       %10d����", i + 1, ((UserData*)Save::GetData())->Ranking[i]);
		Font::StrDraw(str, 250, 90 + 48 * i, 24, b);
	}
}

