#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F10�~
class CObj100enn : public CObj
{
public:
	CObj100enn(float x, float y, float s);
	~CObj100enn() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x;			//100�~�̈ʒu
	float m_y;
	float m_vy;			//100�~�̗����ł�
	float s;
};