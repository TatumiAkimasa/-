#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_BACK_GROUND,
	OBJ_BACK_GROUND_2,
	OBJ_BACK_GROUND_STATS,
	OBJ_WATER_FLOW,
	OBJ_TITLE,
	OBJ_RESULT,
	OBJ_10ENN,
	OBJ_FISH_PLAYER,
	OBJ_MAIN,
	OBJ_LIFE_ITEM,
	OBJ_SP_UP,
	OBJ_SP_DOWN,
	OBJ_FLOW,
	OBJ_MIRROR,
	OBJ_TREEITEM,
	OBJ_TREE,
	OBJ_100ENN,
	OBJ_1000ENN,
	OBJ_10000ENN,
	OBJ_BAD_LIFE,
	OBJ_RANKING,
	OBJ_TATAMI,
	OBJ_ACHIEVEMENT,

};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_HEAL,
	ELEMENT_COIN,
	ELEMENT_MIRROR,
	ELEMENT_TREEITEM,
	ELEMENT_TREE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;			//�T���v���Z�[�u�f�[�^
	int save_s_time;		//s_time�Z�[�u�p�ϐ�
	int save_m_time;		//m_time�Z�[�u�p�ϐ�
	int save_score;		    //score�Z�[�u�p�ϐ�
	float sp;				//�X�s�[�h�p�ϐ�
	int sp_lv = 1;			//�X�s�[�h�Ǘ��p�ϐ�
	int life_point = 3;		//��l���̃��C�t
	bool Tree_flag;			//�ؗp�t���O
	int Tree_time = 0;		//�؂̕\�����ԗp�ϐ�
	bool Tree_said;			//�؂̕\���p�t���O
	bool key_flag_mirror;	//���씽�]�p�t���O
	int Ranking[11];        //�����L���O�̕\���p�ϐ�
	bool Achievement_flag[29];//���т��������Ă��邩�̃t���O

};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--
//������ʂȂ��̏�Q��
enum FLOW_OBJ_ID
{
	FLOW1,//
	FLOW2,//
	FLOW3,//
	

};
//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "ObjBackground.h"
#include "ObjBackground_2.h"
#include "ObjBackground_stats.h"
#include "Objwater_flow.h"
#include "ObjTitle.h"
#include "ObjFishPlayer.h"
#include "Obj10enn.h"
#include "ObjResult.h"
#include "ObjMain.h"
#include "ObjLifeItem.h"
#include "Objsp_up.h"
#include "Objsp_down.h"
#include "ObjFlow.h"
#include "Objmirror.h"
#include "ObjTreeItem.h"
#include "ObjTree.h"
#include "Obj100enn.h"
#include "Obj1000enn.h"
#include "Obj10000enn.h"
#include "Objbadlife.h"
#include "ObjRanking.h"
#include "ObjTatami.h"
#include "ObjAchievement.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneResult.h"
#include "SceneRanking.h"
#include "SceneAchievement.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle
//-----------------------------------------------