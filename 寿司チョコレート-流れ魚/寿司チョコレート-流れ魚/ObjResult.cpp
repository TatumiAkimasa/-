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
	//���� 0
	if (((UserData*)Save::GetData())->save_score == 0)
	{
		Font::StrDraw(L"���̕���ɂ��u���Ȃ��c", 150, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[0] = true;
	}
	//���� 0�`500
	else if (((UserData*)Save::GetData())->save_score > 0 && ((UserData*)Save::GetData())->save_score < 500)
	{
		Font::StrDraw(L"�t��", 370, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[1] = true;
	}
	//���� 500�`1000
	else if (((UserData*)Save::GetData())->save_score >= 500 && ((UserData*)Save::GetData())->save_score < 1000)
	{
		Font::StrDraw(L"�����Ƃ���΂낤�I", 200, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[2] = true;
	}
	//���� 1000�`2500
	else if (((UserData*)Save::GetData())->save_score >= 1000 && ((UserData*)Save::GetData())->save_score < 2500)
	{
		Font::StrDraw(L"���Ƃ͙R�����̂���", 190, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[3] = true;
	}
	//���� 2500�`5000
	else if (((UserData*)Save::GetData())->save_score >= 2500 && ((UserData*)Save::GetData())->save_score < 5000)
	{
		Font::StrDraw(L"����", 370, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[4] = true;
	}
	//���� 5000�`7500
	else if (((UserData*)Save::GetData())->save_score >= 5000 && ((UserData*)Save::GetData())->save_score < 7500)
	{
		Font::StrDraw(L"�܂�ŋ�", 300, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[5] = true;
	}
	//���� 7500�`10000
	else if (((UserData*)Save::GetData())->save_score >= 7500 && ((UserData*)Save::GetData())->save_score < 10000)
	{
		Font::StrDraw(L"���催�催��", 270, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[6] = true;
	}
	//���� 10000�`20000
	else if (((UserData*)Save::GetData())->save_score >= 10000 && ((UserData*)Save::GetData())->save_score < 20000)
	{
		Font::StrDraw(L"���͂⋛", 300, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[7] = true;
	}
	//���� 20000�`30000
	else if (((UserData*)Save::GetData())->save_score >= 20000 && ((UserData*)Save::GetData())->save_score < 30000)
	{
		Font::StrDraw(L"�������`��", 290, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[8] = true;
	}
	//���� 30000�`40000
	else if (((UserData*)Save::GetData())->save_score >= 30000 && ((UserData*)Save::GetData())->save_score < 40000)
	{
		Font::StrDraw(L"�Z���X�̉�", 290, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[9] = true;
	}
	//���� 40000�`50000
	else if (((UserData*)Save::GetData())->save_score >= 40000 && ((UserData*)Save::GetData())->save_score < 50000)
	{
		Font::StrDraw(L"���C�I�ɂ������I", 220, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[10] = true;
	}
	//���� 50000�`60000
	else if (((UserData*)Save::GetData())->save_score >= 50000 && ((UserData*)Save::GetData())->save_score < 60000)
	{
		Font::StrDraw(L"���Ƃ�", 320, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[11] = true;
	}
	//���� 60000�`70000
	else if (((UserData*)Save::GetData())->save_score >= 60000 && ((UserData*)Save::GetData())->save_score < 70000)
	{
		Font::StrDraw(L"���͂�T��", 290, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[12] = true;
	}
	//���� 70000�`80000
	else if (((UserData*)Save::GetData())->save_score >= 70000 && ((UserData*)Save::GetData())->save_score < 80000)
	{
		Font::StrDraw(L"���͂���", 290, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[13] = true;
	}
	//���� 80000�`90000
	else if (((UserData*)Save::GetData())->save_score >= 80000 && ((UserData*)Save::GetData())->save_score < 90000)
	{
		Font::StrDraw(L"���̉�", 320, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[14] = true;
	}
	//���� 90000�`100000
	else if (((UserData*)Save::GetData())->save_score >= 90000 && ((UserData*)Save::GetData())->save_score < 100000)
	{
		Font::StrDraw(L"����҂̐l�ł����H", 190, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[15] = true;
	}
	//���� 100000�`110000
	else if (((UserData*)Save::GetData())->save_score >= 100000 && ((UserData*)Save::GetData())->save_score < 110000)
	{
		Font::StrDraw(L"����҂̐l�ł��ˁI", 190, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[16] = true;
	}
	//���� 110000�`120000
	else if (((UserData*)Save::GetData())->save_score >= 110000 && ((UserData*)Save::GetData())->save_score < 120000)
	{
		Font::StrDraw(L"����҂ł��������c", 190, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[17] = true;
	}
	//���� 120000�`130000
	else if (((UserData*)Save::GetData())->save_score >= 120000 && ((UserData*)Save::GetData())->save_score < 130000)
	{
		Font::StrDraw(L"����҂���肢�I", 190, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[18] = true;
	}
	//���� 130000�`140000
	else if (((UserData*)Save::GetData())->save_score >= 130000 && ((UserData*)Save::GetData())->save_score < 140000)
	{
		Font::StrDraw(L"����҂ł������c�c", 190, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[19] = true;
	}
	//���� 140000�`150000
	else if (((UserData*)Save::GetData())->save_score >= 140000 && ((UserData*)Save::GetData())->save_score < 150000)
	{
		Font::StrDraw(L"�O�{��", 190, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[20] = true;
	}
	//���� 150000�`160000
	else if (((UserData*)Save::GetData())->save_score >= 150000 && ((UserData*)Save::GetData())->save_score < 160000)
	{
		Font::StrDraw(L"���Ⴉ�ɂ�", 290, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[21] = true;
	}
	//���� 160000�`170000
	else if (((UserData*)Save::GetData())->save_score >= 160000 && ((UserData*)Save::GetData())->save_score < 170000)
	{
		Font::StrDraw(L"���C��16���͂�����Ɓc", 190, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[22] = true;
	}
	//���� 170000�`180000
	else if (((UserData*)Save::GetData())->save_score >= 170000 && ((UserData*)Save::GetData())->save_score < 180000)
	{
		Font::StrDraw(L"���͐���ґS���ޏ����܂���", 90, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[23] = true;
	}
	//���� 180000�`190000
	else if (((UserData*)Save::GetData())->save_score >= 180000 && ((UserData*)Save::GetData())->save_score < 190000)
	{
		Font::StrDraw(L"�T�P�̐؂�g�A���͐��Ȃ�", 90, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[24] = true;
	}
	//���� 190000�`200000
	else if (((UserData*)Save::GetData())->save_score >= 190000 && ((UserData*)Save::GetData())->save_score < 200000)
	{
		Font::StrDraw(L"��肱��ł���Ă��肪�Ƃ�", 90, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[25] = true;
	}
	//���� 200000�`530000
	else if (((UserData*)Save::GetData())->save_score >= 200000 && ((UserData*)Save::GetData())->save_score < 530000)
	{
		Font::StrDraw(L"�M�����N�e�B�b�N�t�B�b�V��", 90, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[26] = true;
	}
	//���� 530000�`1000000
	else if (((UserData*)Save::GetData())->save_score >= 530000 && ((UserData*)Save::GetData())->save_score < 1000000)
	{
		Font::StrDraw(L"����53���z������", 210, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[27] = true;
	}
	//���� 1000000�`
	else if (((UserData*)Save::GetData())->save_score >= 1000000)
	{
		Font::StrDraw(L"�`�[�g�����o����܂���", 140, COMMENT_POS, COMMENT_SIZE, c);
		((UserData*)Save::GetData())->Achievement_flag[28] = true;
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