#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F10�~
class CObj10enn : public CObj
{
	public:
		CObj10enn(float x, float y, float s) ;
		~CObj10enn() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[
	private:
		float m_x;			//10�~�̈ʒu
		float m_y;
		float m_vy;			//10�~�̗���
		int s;
};