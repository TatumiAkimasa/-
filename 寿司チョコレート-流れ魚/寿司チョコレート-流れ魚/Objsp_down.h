#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F10�~
class CObjsp_down : public CObj
{
	public:
		CObjsp_down(float x, float y, float s);
		~CObjsp_down() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[
	private:
		float m_x;			//sp_down�̈ʒu
		float m_y;
		float m_vy;			//sp_down�̗���
		float s;
};