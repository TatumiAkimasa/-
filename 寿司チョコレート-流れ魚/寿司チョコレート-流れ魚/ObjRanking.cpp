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
	//static bool init_point = false;
	//if (init_point == false)
	//{
	//	//�_����0�ɂ���
	//	((UserData*)Save::GetData())->save_score = 0;//�_����0�ɂ���

	//	//�����L���O������
	//	for (int i = 0; i < 11; i++)
	//	{
	//		((UserData*)Save::GetData())->Ranking[i] = 0;
	//	}
	//	init_point = true;
	//}

	////���_�����L���O�ŉ���(�`�ʌ��O)�ɓo�^
	//((UserData*)Save::GetData())->Ranking[10] = ((UserData*)Save::GetData())->save_score;

	////���_���������ɕ��ёւ�������
	//RankingSort(((UserData*)Save::GetData())->Ranking);
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
	Font::StrDraw(L"�����L���O", 280, 0, 50, c);
	for (int i = 0; i < 10; i++)
	{
		wchar_t str[256];
		swprintf_s(str, L"%2d��       %12d����", i + 1, ((UserData*)Save::GetData())->Ranking[0]);
		Font::StrDraw(str, 230, 90 + 48 * i, 24, c);
	}
}

