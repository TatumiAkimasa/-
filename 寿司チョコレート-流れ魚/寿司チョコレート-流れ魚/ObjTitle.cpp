//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"
#include <thread>
#include <chrono>


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjTitle::CObjTitle()
{
	R_flag = false;
	L_flag = false;
	D_flag = false;
	num = 0;//�`��D��x
}

int CObjTitle::key_num_T()
{
	return num;
}

bool CObjTitle::key_num2_T()
{
	return R_flag;
}
//�C�j�V�����C�Y
void CObjTitle::Init()
{
	//((UserData*)Save::GetData())->sp_lv = 0;//�X�s�[�h���x��������

	static bool init_point = false;
	if (init_point == false)
	{
		//�����L���O������
		for (int i = 0; i < 11; i++)
		{
			((UserData*)Save::GetData())->Ranking[i] = 0;
		}

		Save::Open();//���t�H���_�uUserData�v����f�[�^�擾

		//�_����0�ɂ���
		((UserData*)Save::GetData())->save_score = 0;
		init_point = true;
	}

	//���_�����L���O�ŉ���(�`�ʌ��O)�ɓo�^
	((UserData*)Save::GetData())->Ranking[10] = ((UserData*)Save::GetData())->save_score;

	//���_���������ɕ��ёւ�������
	RankingSort(((UserData*)Save::GetData())->Ranking);

	//�Q�[�����s���Ĉ��݈̂ȊO�A�����L���O�������Z�[�u����
	if (init_point == true)
	{
		Save::Seve();//UserData�̏��𓯂��t�H���_�uUserData�v���쐬����
	}
}

//�A�N�V����
void CObjTitle::Action()
{
	//�X�y�[�X�L�[�������ăV�[���F�Q�[�������Ɉڍs����B/
	if (Input::GetVKey(VK_RIGHT) == true)
	{

		if (R_flag == true)
		{

			//+=2�Ń^�C�g���߂�Ƃ����܂�2��^�b�v�����_��
			num ++;
			
			R_flag = false;
		}
	}
	else
	{
		R_flag = true;
	}

	//�X�y�[�X�L�[�������ăV�[���F�Q�[�������Ɉڍs����B/
	if (Input::GetVKey(VK_LEFT) == true)
	{

		if (L_flag == true)
		{

			//+=2�Ń^�C�g���߂�Ƃ����܂�2��^�b�v�����_��
			num--;
			L_flag = false;
		}
	}
	else
	{
		L_flag = true;
	}
	//�㉺�L�[�������ăV�[���F�����L���O�Ɉڍs����B/
	if (Input::GetVKey(VK_DOWN) == true)
	{
		if (D_flag == true)
		{
			Scene::SetScene(new CSceneRanking());
			D_flag = false;
		}
	}
	else
	{
		D_flag = true;
	}

	//S�L�[�Őݒ藓�Ɉړ�
	if (Input::GetVKey('S') == true)
	{
		Scene::SetScene(new CSceneSetting());
	}

	//�`�搔�i������ʁj
	if (num > 7)
	{
		num = 7;
	}
	else if (num < 0)
	{
		num = 0;
	}

	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����B
	if (Input::GetVKey(VK_RETURN) == true)
	{
		//�J�n���r�d
		Audio::Start(1);
		std::this_thread::sleep_for(std::chrono::seconds(2)); //�J�n��������2�b�~�߂�(�J�nSE��炷���߁j
			Scene::SetScene(new CSceneMain());

	}
	
}
//�h���[//�^�C�g��
void CObjTitle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };



	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	if (num == 0)
	{
		//�؂���ʒu�̕\��
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1020.0f;
		src.m_bottom = 680.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
	}
	else
	{
		//�؂���ʒu�̕\��
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1024.0f;
		src.m_bottom = 683.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
	}
	

	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��ł�

	Draw::Draw(num, &src, &dst, c, 0.0f);


}

//�����L���O�\�[�g���\�b�h
//����1�@int[11] :�����L���O�p�z��
//�����Ńo�u���\�[�g���s��
void CObjTitle::RankingSort(int rank[11])
{
	//�l�����p�ϐ�
	int w;

	//�o�u���\�[�g
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 11; j++)
		{
			if (rank[i] < rank[j])
			{
				//�l�̌���
				w = rank[i];
				rank[i] = rank[j];
				rank[j] = w;
			}
		}
	}

}