//STL�f�o�b�N�@�\��Off�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GmameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\Audio.h"
#include "GameL/UserData.h"
#include <stdlib.h>
#include <time.h>


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i���Ȃ��w�i�j
	Draw::LoadImageW(L"�w�i������-1_512.png", 0, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^�i���̗���j
	Draw::LoadImageW(L"���̗���.png", 1, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���2�Ԃɓo�^(��l��)�A�j���[�V�����P
	Draw::LoadImage(L"ani����.png", 2, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^�i10�~�j
	Draw::LoadImage(L"10enn.png", 3, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���4�Ԃɓo�^�i���Ȃ��w�i2�j
	Draw::LoadImageW(L"�w�i������-2_512.png", 4, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���5�Ԃɓo�^�i���Ȃ��w�i3�j
	Draw::LoadImageW(L"�w�i������-3_512.png", 5, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���6�Ԃɓo�^�i�X�e�[�^�X���̔w�i�j
	Draw::LoadImageW(L"���C��_�w�i_�X�e�[�^�X��.png", 6, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���7�Ԃɓo�^(���C�t�A�C�e���j
	Draw::LoadImage(L"LifeItem2.png", 7, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���8�Ԃɓo�^�i�����A�C�e���j
	Draw::LoadImage(L"sp_up.png", 8, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���9�Ԃɓo�^�i�����A�C�e���j
	Draw::LoadImage(L"sp_down.png", 9, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���10�Ԃɓo�^(���C�t�\���j
	Draw::LoadImage(L"LifeItem.png", 10, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���11�Ԃɓo�^(���씽�]�A�C�e���j
	Draw::LoadImage(L"���]�A�C�R��.png", 11, TEX_SIZE_512);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"�V�[��BGM(��).wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float volume = Audio::VolumeMaster(0.0f);//�}�X�^�[�{�����[����0.8������
	Audio::Start(0);//���y�X�^�[�g

	//�w�i�I�u�W�F�N�g�쐬
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACK_GROUND, 1);

	
	CObjBackground_2* back_2 = new CObjBackground_2();
	Objs::InsertObj(back_2, OBJ_BACK_GROUND_2, 1);
	

	CObjBackground_stats* back_3 = new CObjBackground_stats();
	Objs::InsertObj(back_3, OBJ_BACK_GROUND_STATS, 0);
	

	//��l���I�u�W�F�N�g�쐬
	CObjFishPlayer* fp = new CObjFishPlayer();
	Objs::InsertObj(fp, OBJ_FISH_PLAYER, 10);

	//�^�C���̕\��
	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_MAIN, 1);

	m_time = 0;
	m_ani_time = 0;

	((UserData*)Save::GetData())->save_score = 0;

	t = 0;
}

//�Q�[�����s�����\�b�h
void CSceneMain::Scene()
{
	//�������G��
	rand(); rand(); rand(); rand(); rand();

	//�����_���ϐ�
	int x = rand() % 7;

	m_time++;

	if (m_time % 50 == 0)
	{
		CObjwater_flow* flow = new CObjwater_flow();
		Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
	}
	
	//�����̏�����
	if (t == 0)
	{
		((UserData*)Save::GetData())->sp = 5.0f;
		t++;
	}

	if (((UserData*)Save::GetData())->sp_lv == 0)
	{
		if (((UserData*)Save::GetData())->sp >= 7)
		{
			((UserData*)Save::GetData())->sp -= 2.0f;
		}
		else
		{
			((UserData*)Save::GetData())->sp = 5.0f;
		}
	}

	//��Q���̏o��
	if (m_time % 60 == 0)
	{
		//�����_����3���[�����痬������
		//1���[������
		if (x == 0)
		{
			//�����_���ŗ���
			int x = rand() % 2;
			if (x == 0)
			{
				flow(385, -64);

				((UserData*)Save::GetData())->sp_lv++;
			}
			else if (x == 1)
			{
				CObjsp_up* fp = new CObjsp_up(345, -64, ((UserData*)Save::GetData())->sp);
				Objs::InsertObj(fp, OBJ_SP_UP, 10);

				((UserData*)Save::GetData())->sp_lv++;
			}
			
		}
		else if (x == 1)
		{
			flow(505, -64);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 2)
		{
			flow(625, -64);

			((UserData*)Save::GetData())->sp_lv++;
		}
		//2���[������
		else if (x == 3)
		{
			flow(385, -64);

			flow(505, -64);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 4)
		{
			flow(505, -64);

			flow(625, -64);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 5)
		{
			flow(385, -64);

			flow(625, -64);

			((UserData*)Save::GetData())->sp_lv++;
		}

		//���C�t��
		else if (x == 6)
		{
			CObjLifeItem* li = new CObjLifeItem(385, -64, ((UserData*)Save::GetData())->sp);
			Objs::InsertObj(li, OBJ_LIFE_ITEM, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}


		//3���[������

		//��������
		if (((UserData*)Save::GetData())->sp <= 20)
		{
			((UserData*)Save::GetData())->sp += 0.1f;
		}
	}	
}

//��Q���𗬂��֐�
void flow(int x, int y)
{
	CObj10enn* obj = new CObj10enn(x, y, ((UserData*)Save::GetData())->sp);
	Objs::InsertObj(obj, OBJ_10ENN, 50);
}