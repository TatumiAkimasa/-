//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjAchievement.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjAchievement::Init()
{
	//���щ���p�t���O�̏�����
	for (int i = 0; i < 30; i++)
	{
		if (((UserData*)Save::GetData())->Achievement_flag[i] == true)
		{
			;
		}
		else
		{
			((UserData*)Save::GetData())->Achievement_flag[i] = false;
		}
	}
	/*for (int i = 0; i < 30; i++)
	{
		((UserData*)Save::GetData())->Achievement_flag[i] = true;
		
	}*/
	/*for (int i = 0; i < 30; i++)
	{
		((UserData*)Save::GetData())->Achievement_flag[i] = false;

	}*/
}
//�A�N�V����
void CObjAchievement::Action()
{
	//�㉺�L�[�������ăV�[���F�^�C�g���Ɉڍs����B/
	if (Input::GetVKey(VK_UP) == true)
	{
		Scene::SetScene(new CSceneRanking());
	}
}
//�h���[
void CObjAchievement::Draw()
{
	wchar_t str[256];
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float b[4] = { 0.3f,0.3f,2.5f,1.0f };

	Font::StrDraw(L"����", 340, 25, 50, r);
	Font::StrDraw(L"��{�^���Ń����L���O�ɖ߂�", 25, 550, 17, r);

	swprintf_s(str, L" 1��  %4d����", ((UserData*)Save::GetData())->Ranking[0]);
	Font::StrDraw(str, 190, 95, 50, c);

	achi Achi[58] =
	{
		{"1.���̕���ɂ��u���Ȃ��c",100},{"0����",100},
		{"2.�t��",100},{"2.1�`499����",100},
		{"3.�����Ƃ���΂낤�I",100},{"3.500�`999����",100},
		{"4.���Ƃ͙R�����̂���",100},{"4.1000�`2499����",100},
		{"5.����",100},{"5.2500�`4999����",100},
		{"6.�܂�ŋ�",100},{"6.5000�`7499����",100},
		{"7.���催�催��",100},{"7.7500�`9999����",100},
		{"8.���͂⋛",100},{"8.10000�`19999����",100},
		{"9.�������`��",100},{"9.20000�`29999����",100},
		{"10.�Z���X�̉�",100},{"10.30000�`39999����",100},

		{"11.���C�I�ɂ������I",100},{"11.40000�`49999����",100},
		{"12.���Ƃ�",100},{"12.50000�`59999����",100},
		{"13.���͂�T��",100},{"13.60000�`69999����",100},
		{"14.���͂���",100},{"14.70000�`79999����",100},
		{"15.���̉�",100},{"15.80000�`89999����",100},
		{"16.����҂̐l�ł����H",100},{"16.90000�`99999����",100},
		{"17.100000�`109999����",100},{"17.100000�`109999����",100},
		{"18.����҂ł��������c",100},{"18.110000�`119999����",100},
		{"19.����҂���肢�I",100},{"19.120000�`129999����",100},
		{"20.����҂ł������c�c",100},{"20.130000�`139999����",100},

		{"21.�O�{��",100},{"21.140000�`149999����",100},
		{"22.���Ⴉ�ɂ�",100},{"22.150000�`159999����",100},
		{"23.���C��16���͂�����Ɓc",100},{"23.160000�`169999����",100},
		{"24.���͐���ґS���ޏ����܂���",100},{"24.170000�`179999����",100},
		{"25.�T�P�̐؂�g�A���͐��Ȃ�",100},{"25.180000�`189999����",100},
		{"26.��肱��ł���Ă��肪�Ƃ�",100},{"26.190000�`199999����",100},
		{"27.�M�����N�e�B�b�N�t�B�b�V��",100},{"27.190000�`529999����",100},
		{"28.����53���z������",100},{"28.530000�`999999����",100},
		{"29.�`�[�g�����o����܂���",100},{"29.1000000����",100},

	};

	for (int i = 0; i < 58; i += 2)
	{
		if (((UserData*)Save::GetData())->Achievement_flag[0] == true)
		{
			swprintf_s(str, L"%s", Achi[i].coment);
			Font::StrDraw(str, ACHIEVEMENT_POS_L, Achi[0].hight + (30 * i), ACHIEVEMENT_SIZE, c);
		}
		else
		{
			swprintf_s(str, L"%s", Achi[i + 1].coment);
			Font::StrDraw(str, ACHIEVEMENT_POS_L, Achi[0].hight + (30 * (i - 1)), ACHIEVEMENT_SIZE, c);
		}
		
	}

	//0
	//if (((UserData*)Save::GetData())->Achievement_flag[0] == true)
	//{
	//	Font::StrDraw(L"1.���̕���ɂ��u���Ȃ��c", ACHIEVEMENT_POS_L, 100, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"1.0����", ACHIEVEMENT_POS_L, 100, ACHIEVEMENT_SIZE, c);
	//}
	////0�`500�h�D�G�[�X
	//if (((UserData*)Save::GetData())->Achievement_flag[1] == true)
	//{
	//	Font::StrDraw(L"2.�t��", ACHIEVEMENT_POS_L, 130, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"2.1�`499����", ACHIEVEMENT_POS_L, 130, ACHIEVEMENT_SIZE, c);
	//}
	////500�`1000
	//if (((UserData*)Save::GetData())->Achievement_flag[2] == true)
	//{
	//	Font::StrDraw(L"3.�����Ƃ���΂낤�I", ACHIEVEMENT_POS_L, 160, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"3.500�`999����", ACHIEVEMENT_POS_L, 160, ACHIEVEMENT_SIZE, c);
	//}
	////1000�`2500
	//if (((UserData*)Save::GetData())->Achievement_flag[3] == true)
	//{
	//	Font::StrDraw(L"4.���Ƃ͙R�����̂���", ACHIEVEMENT_POS_L, 190, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"4.1000�`2499����", ACHIEVEMENT_POS_L, 190, ACHIEVEMENT_SIZE, c);
	//}
	////2500�`5000
	//if (((UserData*)Save::GetData())->Achievement_flag[4] == true)
	//{
	//	Font::StrDraw(L"5.����", ACHIEVEMENT_POS_L, 220, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"5.2500�`4999����", ACHIEVEMENT_POS_L, 220, ACHIEVEMENT_SIZE, c);
	//}
	////5000�`7500
	//if (((UserData*)Save::GetData())->Achievement_flag[5] == true)
	//{
	//	Font::StrDraw(L"6.�܂�ŋ�", ACHIEVEMENT_POS_L, 250, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"6.5000�`7499����", ACHIEVEMENT_POS_L, 250, ACHIEVEMENT_SIZE, c);
	//}
	////7500�`10000
	//if (((UserData*)Save::GetData())->Achievement_flag[6] == true)
	//{
	//	Font::StrDraw(L"7.���催�催��", ACHIEVEMENT_POS_L, 280, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"7.7500�`9999����", ACHIEVEMENT_POS_L, 280, ACHIEVEMENT_SIZE, c);
	//}
	////10000�`20000
	//if (((UserData*)Save::GetData())->Achievement_flag[7] == true)
	//{
	//	Font::StrDraw(L"8.���͂⋛", ACHIEVEMENT_POS_L, 310, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"8.10000�`19999����", ACHIEVEMENT_POS_L, 310, ACHIEVEMENT_SIZE, c);
	//}
	////20000�`30000
	//if (((UserData*)Save::GetData())->Achievement_flag[8] == true)
	//{
	//	Font::StrDraw(L"9.�������`��", ACHIEVEMENT_POS_L, 340, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"9.20000�`29999����", ACHIEVEMENT_POS_L, 340, ACHIEVEMENT_SIZE, c);
	//}
	////30000�`40000
	//if (((UserData*)Save::GetData())->Achievement_flag[9] == true)
	//{
	//	Font::StrDraw(L"10.�Z���X�̉�", ACHIEVEMENT_POS_L, 370, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"10.30000�`39999����", ACHIEVEMENT_POS_L, 370, ACHIEVEMENT_SIZE, c);
	//}
	////40000�`50000
	//if (((UserData*)Save::GetData())->Achievement_flag[10] == true)
	//{
	//	Font::StrDraw(L"11.���C�I�ɂ������I", ACHIEVEMENT_POS_L, 400, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"11.40000�`49999����", ACHIEVEMENT_POS_L, 400, ACHIEVEMENT_SIZE, c);
	//}
	////50000�`60000
	//if (((UserData*)Save::GetData())->Achievement_flag[11] == true)
	//{
	//	Font::StrDraw(L"12.���Ƃ�", ACHIEVEMENT_POS_L, 430, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"12.50000�`59999����", ACHIEVEMENT_POS_L, 430, ACHIEVEMENT_SIZE, c);
	//}
	////60000�`70000
	//if (((UserData*)Save::GetData())->Achievement_flag[12] == true)
	//{
	//	Font::StrDraw(L"13.���͂�T��", ACHIEVEMENT_POS_L, 460, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"13.60000�`69999����", ACHIEVEMENT_POS_L, 460, ACHIEVEMENT_SIZE, c);
	//}
	////70000�`80000
	//if (((UserData*)Save::GetData())->Achievement_flag[13] == true)
	//{
	//	Font::StrDraw(L"14.���͂���", ACHIEVEMENT_POS_L, 490, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"14.70000�`79999����", ACHIEVEMENT_POS_L, 490, ACHIEVEMENT_SIZE, c);
	//}
	////80000�`90000
	//if (((UserData*)Save::GetData())->Achievement_flag[14] == true)
	//{
	//	Font::StrDraw(L"15.���̉�", ACHIEVEMENT_POS_L, 520, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"15.80000�`89999����", ACHIEVEMENT_POS_L, 520, ACHIEVEMENT_SIZE, c);
	//}
	////90000�`100000
	//if (((UserData*)Save::GetData())->Achievement_flag[15] == true)
	//{
	//	Font::StrDraw(L"16.����҂̐l�ł����H", ACHIEVEMENT_POS_R, 100, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"16.90000�`99999����", ACHIEVEMENT_POS_R, 100, ACHIEVEMENT_SIZE, c);
	//}
	////100000�`110000
	//if (((UserData*)Save::GetData())->Achievement_flag[16] == true)
	//{
	//	Font::StrDraw(L"17.����҂̐l�ł��ˁI", ACHIEVEMENT_POS_R, 130, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"17.100000�`109999����", ACHIEVEMENT_POS_R, 130, ACHIEVEMENT_SIZE, c);
	//}
	////110000�`120000
	//if (((UserData*)Save::GetData())->Achievement_flag[17] == true)
	//{
	//	Font::StrDraw(L"18.����҂ł��������c", ACHIEVEMENT_POS_R, 160, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"18.110000�`119999����", ACHIEVEMENT_POS_R, 160, ACHIEVEMENT_SIZE, c);
	//}
	////120000�`130000
	//if (((UserData*)Save::GetData())->Achievement_flag[18] == true)
	//{
	//	Font::StrDraw(L"19.����҂���肢�I", ACHIEVEMENT_POS_R, 190, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"19.120000�`129999����", ACHIEVEMENT_POS_R, 190, ACHIEVEMENT_SIZE, c);
	//}
	////130000�`140000
	//if (((UserData*)Save::GetData())->Achievement_flag[19] == true)
	//{
	//	Font::StrDraw(L"20.����҂ł������c�c", ACHIEVEMENT_POS_R, 220, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"20.130000�`139999����", ACHIEVEMENT_POS_R, 220, ACHIEVEMENT_SIZE, c);
	//}
	////140000�`150000
	//if (((UserData*)Save::GetData())->Achievement_flag[20] == true)
	//{
	//	Font::StrDraw(L"21.�O�{��", ACHIEVEMENT_POS_R, 250, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"21.140000�`149999����", ACHIEVEMENT_POS_R, 250, ACHIEVEMENT_SIZE, c);
	//}
	////150000�`160000
	//if (((UserData*)Save::GetData())->Achievement_flag[21] == true)
	//{
	//	Font::StrDraw(L"22.���Ⴉ�ɂ�", ACHIEVEMENT_POS_R, 280, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"22.150000�`159999����", ACHIEVEMENT_POS_R, 280, ACHIEVEMENT_SIZE, c);
	//}
	////160000�`170000
	//if (((UserData*)Save::GetData())->Achievement_flag[22] == true)
	//{
	//	Font::StrDraw(L"23.���C��16���͂�����Ɓc", ACHIEVEMENT_POS_R, 310, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"23.160000�`169999����", ACHIEVEMENT_POS_R, 310, ACHIEVEMENT_SIZE, c);
	//}
	////170000�`180000
	//if (((UserData*)Save::GetData())->Achievement_flag[23] == true)
	//{
	//	Font::StrDraw(L"24.���͐���ґS���ޏ����܂���", ACHIEVEMENT_POS_R, 340, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"24.170000�`179999����", ACHIEVEMENT_POS_R, 340, ACHIEVEMENT_SIZE, c);
	//}
	////180000�`190000
	//if (((UserData*)Save::GetData())->Achievement_flag[24] == true)
	//{
	//	Font::StrDraw(L"25.�T�P�̐؂�g�A���͐��Ȃ�", ACHIEVEMENT_POS_R, 370, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"25.180000�`189999����", ACHIEVEMENT_POS_R, 370, ACHIEVEMENT_SIZE, c);
	//}
	////190000�`200000
	//if (((UserData*)Save::GetData())->Achievement_flag[25] == true)
	//{
	//	Font::StrDraw(L"26.��肱��ł���Ă��肪�Ƃ�", ACHIEVEMENT_POS_R, 400, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"26.190000�`199999����", ACHIEVEMENT_POS_R, 400, ACHIEVEMENT_SIZE, c);
	//}
	////200000�`530000
	//if (((UserData*)Save::GetData())->Achievement_flag[26] == true)
	//{
	//	Font::StrDraw(L"27.�M�����N�e�B�b�N�t�B�b�V��", ACHIEVEMENT_POS_R, 430, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"27.190000�`529999����", ACHIEVEMENT_POS_R, 430, ACHIEVEMENT_SIZE, c);
	//}
	////530000�`1000000
	//if (((UserData*)Save::GetData())->Achievement_flag[27] == true)
	//{
	//	Font::StrDraw(L"28.����53���z������", ACHIEVEMENT_POS_R, 460, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"28.530000�`999999����", ACHIEVEMENT_POS_R, 460, ACHIEVEMENT_SIZE, c);
	//}
	////1000000�`
	//if (((UserData*)Save::GetData())->Achievement_flag[28] == true)
	//{
	//	Font::StrDraw(L"29.�`�[�g�����o����܂���", ACHIEVEMENT_POS_R, 490, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"29.1000000����", ACHIEVEMENT_POS_R, 490, ACHIEVEMENT_SIZE, c);
	//}
	//���x20����10�b�ȏ�ϋv
	if (((UserData*)Save::GetData())->Achievement_flag[29] == true)
	{
		if (((UserData*)Save::GetData())->m_max_time < ((UserData*)Save::GetData())->max_time)
			((UserData*)Save::GetData())->m_max_time = ((UserData*)Save::GetData())->max_time;
		//�Ȃ���������������o�O�C��
		if (((UserData*)Save::GetData())->m_max_time / 60 < 29)
		{
			swprintf_s(str, L"30.�t�狛 : %0.1f�b", (((UserData*)Save::GetData())->m_max_time / 60) );
			Font::StrDraw(str, ACHIEVEMENT_POS_R, 520, ACHIEVEMENT_SIZE, b);
		}
		else
		{
			swprintf_s(str, L"30.�t�狛 : %0.1f�b", ((UserData*)Save::GetData())->m_max_time / 60);
			Font::StrDraw(str, ACHIEVEMENT_POS_R, 520, ACHIEVEMENT_SIZE, b);
		}
		
	}
	else
	{
		Font::StrDraw(L"30.???????????", ACHIEVEMENT_POS_R, 520, ACHIEVEMENT_SIZE, c);
	}

}