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

	//�O���O���t�B�b�N�t�@�C����ǂݍ���12�Ԃɓo�^(��Q���ꗗ�j
	Draw::LoadImage(L"�܂Ƃ߂����߂�.png", 12, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���13�Ԃɓo�^(100�~�j
	Draw::LoadImage(L"100enn.png", 13, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���14�Ԃɓo�^(1000�~�j
	Draw::LoadImage(L"1000enn.png", 14, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���15�Ԃɓo�^(10000�~�j
	Draw::LoadImage(L"10000enn.png", 15, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���16�Ԃɓo�^(�U���C�t�j
	Draw::LoadImage(L"badlife.png", 16, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���17�Ԃɓo�^(�؃A�C�e��)
	Draw::LoadImage(L"�� �A�C�e��.png", 17, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���18�Ԃɓo�^(��)
	Draw::LoadImage(L"��.png", 18, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���19�Ԃɓo�^(������C�̋���)
	Draw::LoadImage(L"hosi.png", 19, TEX_SIZE_512);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"�V�[��BGM(��).wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"�V�[��BGM2(��)�C��.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(2, L"�V�[��BGM���i�K.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(3, L"�㏸.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(4, L"�_���[�W���e�X�g.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(5, L"���ꎞ�i���j.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(6, L"�R�C���擾.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(7, L"��.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(8, L"�X�s�[�h�_�E��.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(9, L"�R�C���擾2.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(10, L"���씽�].wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(11, L"�B��.wav", SOUND_TYPE::EFFECT);

	Audio::LoadAudio(12, L"�B��3.wav", SOUND_TYPE::EFFECT);

	
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

	bgm_flag = false;
	bgm_flag2 = false;
}

//�Q�[�����s�����\�b�h
void CSceneMain::Scene()
{
	//�������G��
	rand(); rand(); rand(); rand(); rand();

	//��Q���������Ă���m��
	//�ʏ��Q�� 50/�S�́@�M�~�b�N 1/�S��
	int x = rand() % 61;
	

	//�����̏�����
	if (t == 0)
	{
		((UserData*)Save::GetData())->sp = 5.0f;
		t++;
	}

	//BGM�ύX
	if (((UserData*)Save::GetData())->sp >= 10.0f && bgm_flag == false)
	{
		Audio::Start(3);
		Audio::Stop(0);
		Audio::Start(1);
		bgm_flag = true;
	}
	if (((UserData*)Save::GetData())->sp < 10.0f && bgm_flag == true)
	{
		Audio::Stop(1);
		Audio::Start(0);
		bgm_flag = false;

	}
	//BGM�ύX�i���i�K�j
	if (((UserData*)Save::GetData())->sp >= 15.0f && bgm_flag2 == false)
	{
		Audio::Start(3);
		Audio::Stop(1);
		Audio::Start(2);
		bgm_flag2 = true;
	}
	if (((UserData*)Save::GetData())->sp < 15.0f && bgm_flag2 == true)
	{
		Audio::Stop(2);
		Audio::Start(1);
		bgm_flag2 = false;
	}

	//��Q���ɓ����������A�X�s�[�h�������ɖ߂鏈��
	if (((UserData*)Save::GetData())->sp_lv == 0)
	{
		if (((UserData*)Save::GetData())->sp >= 6.0f)
		{
			((UserData*)Save::GetData())->sp -= 1.0f;
			((UserData*)Save::GetData())->sp_lv += 1;
		}
	}

	if (((UserData*)Save::GetData())->life_point > 0)
	{
		//�t���[�����̌v�Z
		m_time++;
		//���̗���̏���
		if (m_time%29 == 0)
		{
			CObjwater_flow* flow = new CObjwater_flow(((UserData*)Save::GetData())->sp);
			Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
		}
		else if (m_time % 73 == 0)
		{
			CObjwater_flow* flow = new CObjwater_flow(((UserData*)Save::GetData())->sp);
			Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
		}
		else if (m_time % 127 == 0)
		{
			CObjwater_flow* flow = new CObjwater_flow(((UserData*)Save::GetData())->sp);
			Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
		}

		//��Q���̏o��
		if (m_time % 60 == 0)
		{
			//�������G��
			rand(); rand(); rand(); rand(); rand();

			//�����_����3���[�����痬������
			if (x <= 50)
			{

				//�ʏ��Q���̕\��
				x = rand() % 6;
				if (x == 0)
				{
					CObjFlow* f = new CObjFlow(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, 50);


					((UserData*)Save::GetData())->sp_lv++;
				}
				else if (x == 1)
				{

					CObjFlow* f = new CObjFlow(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, 50);

					((UserData*)Save::GetData())->sp_lv++;
				}
				else if (x == 2)
				{
					CObjFlow* f = new CObjFlow(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, 50);


					((UserData*)Save::GetData())->sp_lv++;
				}
				else if (x == 3)
				{
					CObjFlow* f = new CObjFlow(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, 50);

					f = new CObjFlow(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, 50);

					((UserData*)Save::GetData())->sp_lv++;
				}
				else if (x == 4)
				{
					CObjFlow* f = new CObjFlow(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, 50);

					f = new CObjFlow(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, 50);


					((UserData*)Save::GetData())->sp_lv++;
				}
				else if (x == 5)
				{
					CObjFlow* f = new CObjFlow(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, 50);

					f = new CObjFlow(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(f, OBJ_FLOW, 50);

					((UserData*)Save::GetData())->sp_lv++;
				}

			}

			//���C�t��
			else if (x == 51)
			{
				x = rand() % 3;

				if (x == 0)
				{
					CObjLifeItem* lt = new CObjLifeItem(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(lt, OBJ_LIFE_ITEM, 50);
				}
				else if (x == 1)
				{
					CObjLifeItem* lt = new CObjLifeItem(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(lt, OBJ_LIFE_ITEM, 50);
				}
				else if (x == 2)
				{
					CObjLifeItem* lt = new CObjLifeItem(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(lt, OBJ_LIFE_ITEM, 50);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//�X�s�[�h�A�b�v
			else if (x == 52)
			{
				x = rand() % 3;

				if (x == 0)
				{
					CObjsp_up* obj = new CObjsp_up(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_UP, 50);
				}
				else if (x == 1)
				{
					CObjsp_up* obj = new CObjsp_up(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_UP, 50);
				}
				else if (x == 2)
				{
					CObjsp_up* obj = new CObjsp_up(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_UP, 50);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//�X�s�[�h�_�E��
			else if (x == 53)
			{
				x = rand() % 3;

				if (x == 0)
				{
					CObjsp_down* obj = new CObjsp_down(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_DOWN, 50);
				}
				else if (x == 1)
				{
					CObjsp_down* obj = new CObjsp_down(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_DOWN, 50);
				}
				else if (x == 2)
				{
					CObjsp_down* obj = new CObjsp_down(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_SP_DOWN, 50);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//�X�R�A�A�b�v(10)
			else if (x == 54)
			{
				x = rand() % 3;

				if (x == 0)
				{
					CObj10enn* obj = new CObj10enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_10ENN, 50);
				}
				else if (x == 1)
				{
					CObj10enn* obj = new CObj10enn(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_10ENN, 50);
				}
				else if (x == 2)
				{
					CObj10enn* obj = new CObj10enn(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_10ENN, 50);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//���씽�]
			else if (x == 55)
			{
				x = rand() % 3;

				if (x == 0)
				{
					CObjmirror* m = new CObjmirror(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(m, OBJ_10ENN, 50);
				}
				else if (x == 1)
				{
					CObjmirror* m = new CObjmirror(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(m, OBJ_10ENN, 50);
				}
				else if (x == 2)
				{
					CObjmirror* m = new CObjmirror(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(m, OBJ_10ENN, 50);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//�X�R�A�A�b�v(100)
			else if (x == 56)
			{
				x = rand() % 3;

				if (x == 0)
				{
					CObj100enn* obj = new CObj100enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_100ENN, 50);
				}
				else if (x == 1)
				{
					CObj100enn* obj = new CObj100enn(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_100ENN, 50);
				}
				else if (x == 2)
				{
					CObj100enn* obj = new CObj100enn(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_100ENN, 50);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//�X�R�A�A�b�v(1000)
			else if (x == 57)
			{
				x = rand() % 3;

				if (x == 0)
				{
					CObj1000enn* obj = new CObj1000enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_1000ENN, 50);
				}
				else if (x == 1)
				{
					CObj1000enn* obj = new CObj1000enn(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_1000ENN, 50);
				}
				else if (x == 2)
				{
					CObj1000enn* obj = new CObj1000enn(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_1000ENN, 50);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//�X�R�A�A�b�v(10000)
			else if (x == 58)
			{
				x = rand() % 3;

				if (x == 0)
				{
					CObj10000enn* obj = new CObj10000enn(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_10000ENN, 50);
				}
				else if (x == 1)
				{
					CObj10000enn* obj = new CObj10000enn(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_10000ENN, 50);
				}
				else if (x == 2)
				{
					CObj10000enn* obj = new CObj10000enn(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(obj, OBJ_10000ENN, 50);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//�U���C�t
			else if (x == 59)
			{
				x = rand() % 3;

				if (x == 0)
				{
					CObjbadlife* bl = new CObjbadlife(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(bl, OBJ_BAD_LIFE, 50);
				}
				else if (x == 1)
				{
					CObjbadlife* bl = new CObjbadlife(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(bl, OBJ_BAD_LIFE, 50);
				}
				else if (x == 2)
				{
					CObjbadlife* bl = new CObjbadlife(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(bl, OBJ_BAD_LIFE, 50);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//�؃A�C�e��
			else if (x == 60)
			{
				x = rand() % 3;

				if (x == 0)
				{
					CObjTreeItem* t = new CObjTreeItem(FLOW_SPACE_LEFT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_TREEITEM, 50);
				}
				else if (x == 1)
				{
					CObjTreeItem* t = new CObjTreeItem(FLOW_SPACE_CENTER, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_TREEITEM, 50);
				}
				else if (x == 2)
				{
					CObjTreeItem* t = new CObjTreeItem(FLOW_SPACE_RIGHT, FLOW_HIGHT, ((UserData*)Save::GetData())->sp);
					Objs::InsertObj(t, OBJ_TREEITEM, 50);
				}

				((UserData*)Save::GetData())->sp_lv++;
			}
			//��
			if (((UserData*)Save::GetData())->Tree_flag == true)
			{
				CObjTree* t = new CObjTree(380, -120);
				Objs::InsertObj(t, OBJ_TREE, 50);

				((UserData*)Save::GetData())->Tree_flag = false;
			}

			//��������
			if (((UserData*)Save::GetData())->sp >= 5.0 && ((UserData*)Save::GetData())->sp < 20.0)
			{
				((UserData*)Save::GetData())->sp += 0.1f;
			}
		}
	}
}

