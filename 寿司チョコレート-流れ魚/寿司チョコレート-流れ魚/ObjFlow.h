#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F10�~
class CObjFlow : public CObj
{
public:
	CObjFlow(float x, float y, float s);
	~CObjFlow() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x;			//10�~�̈ʒu
	float m_y;
	float m_vy;			//10�~�̗����ł�
	float s;            //�X�s�[�h�p�ϐ�
	int m_id;           //��Q��ID
	int g_ani;          //�����߂񔽓]�؂�ւ�
	
};