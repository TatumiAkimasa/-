//STL�f�o�b�O�@�\���I�t�ɂ���
#define _SECURESCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include"GameL/DrawTexture.h"

//�g�p����Q�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "SceneAchievement.h"
#include "GameHead.h"


//�R���X�g���N�^
CSceneAchievement::CSceneAchievement()
{

}

//�Q�[�����C�����������\�b�h
void CSceneAchievement::InitScene()
{
	//�����L���O�I�u�W�F�N�g�쐬
	CObjAchievement* ca = new CObjAchievement();//���уu�W�F�N�g�쐬
	Objs::InsertObj(ca, OBJ_ACHIEVEMENT, 10);//���уI�u�W�F�N�g�o�^


	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"�����L���OBGM�i���j.wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float volume = Audio::VolumeMaster(0.0f);
	Audio::Start(0);//���y�X�^�[�g
}

//�Q�[�����C�����s�����\�b�h
void CSceneAchievement::Scene()
{

}