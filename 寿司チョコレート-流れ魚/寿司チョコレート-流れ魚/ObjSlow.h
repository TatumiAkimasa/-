#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F100�~
class CObjSlow : public CObj
{
public:
	CObjSlow(float x, float y, float s);
	~CObjSlow() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x;			//100�~�̈ʒu
	float m_y;
	float m_vy;			//100�~�̗����ł�
};