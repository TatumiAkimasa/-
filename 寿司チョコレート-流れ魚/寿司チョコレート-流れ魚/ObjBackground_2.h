#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�FObjBackground
class CObjBackground_2 : public CObj
{
public:
	CObjBackground_2() {};
	~CObjBackground_2() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:

	float m_y1; //�w�i�@�̕`����
	int count;//��ʐ؂�ւ��p
	int n;//��{���x�ϐ�
	float end_P;//Background1�̏I�[�󂯎��p
};