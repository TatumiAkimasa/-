#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�����߂�
class CObjFlow : public CObj
{
public:
	CObjFlow(float x, float y, float s);
	~CObjFlow() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x;			//�����߂�̈ʒu
	float m_y;
	float m_vy;			//�����߂�̗����ł�
	int m_id;           //��Q��ID
	int g_ani;          //�����߂񔽓]�؂�ւ�
	
};