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
#include "SceneResult.h"
#include "GameHead.h"


//�R���X�g���N�^
CSceneResult::CSceneResult()
{

}

//�Q�[�����C�����������\�b�h
void CSceneResult::InitScene()
{
	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"���U���gBGM(��).wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float volume = Audio::VolumeMaster(0.0f);//�}�X�^�[�{�����[����0.8������
	Audio::Start(0);//���y�X�^�[�g
	//����XBGM����Ǝv�����̂œK���ɏ����Ƃ��܂����B
	//�K�v�Ȃ���Ώ����Ă�������

	//�O���O���t�B�b�N�t�@�C����ǂݍ���16�Ԃɓo�^(���S�j
	Draw::LoadImage(L"���� ���F��_256.png", 16, TEX_SIZE_256);

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"�������������搶������");
	Font::SetStrTex(L"�G���^�[�Ń^�C�g����");

	//�^�C�g���I�u�W�F�N�g�쐬
	//��l���I�u�W�F�N�g�쐬
	CObjResult* obj = new CObjResult();//���U���g�쐬
	Objs::InsertObj(obj, OBJ_RESULT, 10);//��������U���g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneResult::Scene()
{



}