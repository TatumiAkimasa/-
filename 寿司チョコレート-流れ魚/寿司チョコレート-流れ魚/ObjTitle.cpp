//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"
#include <thread>
#include <chrono>


//�g�p����l�[���X�y�[�X
using namespace GameL;

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
	R_flag = false;
	L_flag = false;
	num = 0;//�`��D��x
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

	if (num > 4)
	{
		num = 4;
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
		std::this_thread::sleep_for(std::chrono::seconds(2)); 
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
		src.m_right = 765.0f;
		src.m_bottom = 640.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 616.0f;
	}
	

	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(num, &src, &dst, c, 0.0f);
}