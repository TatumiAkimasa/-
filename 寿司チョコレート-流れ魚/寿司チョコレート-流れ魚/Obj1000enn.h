#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F1000�~
class CObj1000enn : public CObj
{
public:
	CObj1000enn(float x, float y, float s);
	~CObj1000enn() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x;			//1000�~�̈ʒu
	float m_y;
	float m_vy;			//1000�~�̗����ł�
};