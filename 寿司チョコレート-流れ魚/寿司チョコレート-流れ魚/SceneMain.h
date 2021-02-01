#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define FLOW_HIGHT -128
#define FLOW_SPACE_LEFT 385
#define FLOW_SPACE_CENTER 505
#define FLOW_SPACE_RIGHT 625
#define FLOW_PICTURE_PRIORITY 50
#define FLOW_TREE_SIDE 370
#define FLOW_GIMMICK_PROBABILITY 3
#define FLOW_PROBABILITY_0 0
#define FLOW_PROBABILITY_1 1
#define FLOW_PROBABILITY_2 2
#define FLOW_PROBABILITY_3 3
#define FLOW_PROBABILITY_4 4
#define FLOW_PROBABILITY_5 5

//�V�[���F�Q�[�����C��
class CSceneMain :public CScene
{
public:
	CSceneMain();
	~CSceneMain();
	void InitScene();//�Q�[�����C���̏��������\�b�h
	void Scene();//�Q�[�����C���̎��s�����\�b�h
private:
	int m_time;
	int x;
	int t = 0;
	bool bgm_flag;//BGM�؂�ւ��t���O
	bool bgm_flag2;//BGM�؂�ւ��t���O2�i�K��
	int m_ani_time; //��l���A�j���[�V�����^�C���p�ϐ�
	int m_ani_frame; //��l���A�j���[�V�����t���[���p�ϐ�
	int m_t;
};


