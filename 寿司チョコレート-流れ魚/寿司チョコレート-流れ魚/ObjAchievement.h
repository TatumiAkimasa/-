#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define ACHIEVEMENT_POS_L 100
#define ACHIEVEMENT_POS_R 450
#define ACHIEVEMENT_SIZE 20

typedef struct STRUCT_ACHIEVEMENT
{
	char coment[40];
	int hight;
}achi;

//�I�u�W�F�N�g�F�^�C�g��
class CObjAchievement :public CObj
{
public:
	CObjAchievement() {};
	~CObjAchievement() {};
	void Init();
	void Action();
	void Draw();
private:
	
};