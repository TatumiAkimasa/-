#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�I�u�W�F�N�g�F��
class ObjDriftFish :public CObj
{
public:
	ObjDriftFish(float x, float y);
	~ObjDriftFish() {};
	void Init();  //�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();  //�h���[
private:
	float m_px;     //�ʒu
	float m_py;
	float m_vx;     //��l���̂������ړ��x�N�g���p�ϐ�
	float m_vy;
	float m_spin;	//��]�����p�ϐ�
};
