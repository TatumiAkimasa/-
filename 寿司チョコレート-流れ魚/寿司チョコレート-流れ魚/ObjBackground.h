#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

#define UNDER 605.0f
#define RIGHT 820.0f
#define LEFT  250.0f
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�FObjBackground
class CObjBackground : public CObj
{
public:
	~CObjBackground() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
	float speed_back();
	bool end_point();
private:

	float m_y1; //�w�i�@�̕`����
	int count;//��ʐ؂�ւ��p
	int n;//���ݑ��x�󂯎��p�ϐ�
	bool End_P;//Background2�̏I�[�󂯎��p
	bool end_P;//Background1�̏I�[����p
};
