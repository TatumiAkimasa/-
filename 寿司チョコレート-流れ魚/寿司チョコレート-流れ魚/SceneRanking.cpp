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
	//�^�C�g���I�u�W�F�N�g�쐬
	CObjRanking* obj = new CObjRanking();//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_RANKING, 10);//��l���I�u�W�F�N�g�o�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneRanking::Scene()
{



}