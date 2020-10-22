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
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i386*564�s�N�Z���j
	Draw::LoadImageW(L"���C���w�i_512.png", 0, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^�i386*564�s�N�Z���j
	Draw::LoadImageW(L"���̗���.png", 1, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���(��)
	Draw::LoadImage(L"fishplayer.png", 2, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^
	Draw::LoadImage(L"10enn.png", 3, TEX_SIZE_512);

	//�w�i�I�u�W�F�N�g�쐬
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACK_GROUND, 1);

	//��l���I�u�W�F�N�g�쐬
	CObjFishPlayer* fp = new CObjFishPlayer();
	Objs::InsertObj(fp, OBJ_FISH_PLAYER, 10);

	//�^�C���̕\��
	CObjMain* m = new CObjMain();
	Objs::InsertObj(m, OBJ_MAIN, 1);

	m_time = 0;

	t = 0;
}

//�Q�[�����s�����\�b�h
void CSceneMain::Scene()
{
	//�������G��
	rand(); rand(); rand(); rand();

	//�����_���ϐ�
	int x = rand() % 3;

	m_time++;

	if (m_time % 50 == 0)
	{
		CObjwater_flow* flow = new CObjwater_flow();
		Objs::InsertObj(flow, OBJ_WATER_FLOW, 2);
	}

	//�����̏�����
	if (t == 0)
	{
		float sp = 5.0f;
		t++;
	}

	if (((UserData*)Save::GetData())->sp_lv == 0)
	{
		if (sp >= 8)
		{
			sp -= 3.0f;
		}
		else
		{
			sp = 5.0f;
		}
	}

	//10�~�̏o��
	if (m_time % 55 == 0)
	{
		//�����_����3���[������~�炷����
		if (x == 0)
		{
			CObj10enn* obj = new CObj10enn(385, 0, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 1)
		{
			CObj10enn* obj = new CObj10enn(505, 0, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		else if (x == 2)
		{
			CObj10enn* obj = new CObj10enn(625, 0, sp);
			Objs::InsertObj(obj, OBJ_10ENN, 50);

			((UserData*)Save::GetData())->sp_lv++;
		}
		//��������
		if (sp <= 15)
		{
			sp += 0.3f;
		}
	}	
}