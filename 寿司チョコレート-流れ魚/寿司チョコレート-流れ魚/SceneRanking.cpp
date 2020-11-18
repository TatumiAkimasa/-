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
#include "SceneRanking.h"
#include "GameHead.h"


//�R���X�g���N�^
CSceneRanking::CSceneRanking()
{

}

//�Q�[�����C�����������\�b�h
void CSceneRanking::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i���Ȃ��w�i�j
	Draw::LoadImageW(L"tatami_ranking.png", 0, TEX_SIZE_512);

	//�����L���O�I�u�W�F�N�g�쐬
	CObjRanking* obj = new CObjRanking();//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_RANKING, 10);//��l���I�u�W�F�N�g�o�^

	//�w�i�I�u�W�F�N�g�쐬
	CObjTatami* ot = new CObjTatami();//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(ot, OBJ_TATAMI, 5);//��l���I�u�W�F�N�g�o�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneRanking::Scene()
{



}