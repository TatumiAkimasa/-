//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

int CObjTitle::key_num_T()
{
	return num;
}

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false;
	num = 10;//�`��D��x

	static bool init_point = false;
	if (init_point == false)
	{
		//�_����0�ɂ���
		((UserData*)Save::GetData())->save_score = 0;//�_����0�ɂ���

		//�����L���O������
		for (int i = 0; i < 11; i++)
		{
			((UserData*)Save::GetData())->Ranking[i] = 0;
		}
		init_point = true;
	}

	//���_�����L���O�ŉ���(�`�ʌ��O)�ɓo�^
	((UserData*)Save::GetData())->Ranking[10] = ((UserData*)Save::GetData())->save_score;

	//���_���������ɕ��ёւ�������
	RankingSort(((UserData*)Save::GetData())->Ranking);
}
//�A�N�V����
void CObjTitle::Action()
{
	CObjDescription* obj = (CObjDescription*)Objs::GetObj(OBJ_DESCRIPTION);

	num = obj->key_num_D();

	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����B
	if (Input::GetVKey(VK_RETURN) == true)
	{
		//�J�n���r�d
		Audio::Start(1);

		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	//�㉺�L�[�������ăV�[���F�����L���O�Ɉڍs����B/
	if (Input::GetVKey(VK_DOWN) == true)
	{
		Scene::SetScene(new CSceneRanking());
	}
	

	//���E�L�[�������ăV�[���F�Q�[�������Ɉڍs����B/
	if (Input::GetVKey(VK_RIGHT) == true)
	{

		if (m_key_flag == true)
		{

			//+=2�Ń^�C�g���߂�Ƃ����܂�2��^�b�v�����_��
			num += 2;
			//�����I�u�W�F�N�g�쐬
			CObjDescription* obj = new CObjDescription();
			Objs::InsertObj(obj, OBJ_DESCRIPTION, num);

			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//�h���[//�^�C�g��
void CObjTitle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };



	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

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

	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

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