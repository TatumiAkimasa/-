#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�I�u�W�F�N�g�F��
class CObjFishPlayer :public CObj
{
public:
	CObjFishPlayer() {};
	~CObjFishPlayer() {};
	void Init();  //�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();  //�h���[
private:
	float m_px;     //�ʒu
	float m_py;
	float m_vx;     //��l���̂������ړ��x�N�g���p�ϐ�
	float m_vy;
	bool m_f;       //�ړ��L�[���������Ƃ��A���œ����Ȃ��ׂ̕ϐ�
	int m_time;		//���씽�]�p

	int m_ani_time; //��l���A�j���[�V�����^�C���p�ϐ�
	int m_ani_frame; //��l���A�j���[�V�����t���[���p�ϐ�
	int m_ani_frame2; //��l���A�j���[�V�����t���[���p�ϐ�
};