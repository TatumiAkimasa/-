#pragma once 
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�Fsp_up
class CObjsp_up : public CObj
{
	public:
		CObjsp_up(float x, float y, float s);
		~CObjsp_up() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[
	private:
		float m_x;			//sp_up�̈ʒu
		float m_y;
		float m_vy;			//sp_up�̗���
		float s;
};