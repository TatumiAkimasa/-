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