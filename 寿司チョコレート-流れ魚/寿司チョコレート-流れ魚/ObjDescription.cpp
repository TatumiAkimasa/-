//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

int CObjDescription::key_num_D()
{
	return numd;
}

//�C�j�V�����C�Y
void CObjDescription::Init()
{
	m_key_flag = false;
	numd = 10;//�`��D��x
	int i = 1;
}
//�A�N�V����
void CObjDescription::Action()
{
	CObjTitle* obj = (CObjTitle*)Objs::GetObj(OBJ_TITLE);

	numd = obj->key_num_T();

	//�X�y�[�X�L�[�������ăV�[���F�Q�[���^�C�g���Ɉڍs����B
	if (Input::GetVKey(VK_LEFT) == true)
	{
		if (m_key_flag == true)
		{
			numd++;
			//�^�C�g���I�u�W�F�N�g�쐬
			CObjTitle* obj = new CObjTitle();
			Objs::InsertObj(obj, OBJ_TITLE, numd);


			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//�h���[//�^�C�g��
void CObjDescription::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̕\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 776.0f;
	src.m_bottom = 616.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	if (Input::GetVKey(VK_RIGHT) == true)
	{
		i++;
	}

	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(i, &src, &dst, c, 0.0f);

	
}