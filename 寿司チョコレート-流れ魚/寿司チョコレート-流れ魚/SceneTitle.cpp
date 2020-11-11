//STL�f�o�b�O�@�\��OFF�ɂ���B
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"


//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[�����C�����������\�b�h
void CSceneTitle::InitScene()
{
	
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i386*564�s�N�Z���j
	Draw::LoadImageW(L"���^�C�g��ver2.5.png", 0, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i386*564�s�N�Z���j
	Draw::LoadImageW(L"�V�������.png", 1, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i386*564�s�N�Z���j
	Draw::LoadImageW(L"�V�������2.png", 2, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i386*564�s�N�Z���j
	Draw::LoadImageW(L"�V�������3.png", 3, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i386*564�s�N�Z���j
	Draw::LoadImageW(L"�V�������4.png", 4, TEX_SIZE_512);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"�^�C�g��BGM.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"�J�nSE.wav", SOUND_TYPE::EFFECT);
	//�o�b�N�~���[�W�b�N�X�^�[�g
	float volume = Audio::VolumeMaster(0.0f);//�}�X�^�[�{�����[����0.8������
	Audio::Start(0);//���y�X�^�[�g

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* obj = new CObjTitle();//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_TITLE, 10);//��l���I�u�W�F�N�g�o�^

	//�^�C�g���I�u�W�F�N�g�쐬
	//CObjDescription* obj2 = new CObjDescription();//�^�C�g���I�u�W�F�N�g�쐬
	//Objs::InsertObj(obj2, OBJ_DESCRIPTION, 9);//��l���I�u�W�F�N�g�o�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneTitle::Scene()
{

}