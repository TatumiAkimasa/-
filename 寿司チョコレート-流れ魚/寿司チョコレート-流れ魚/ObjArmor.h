#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�FArmor
class CObjArmor : public CObj
{
public:
	CObjArmor(float x, float y, float s);
	~CObjArmor() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x;			//Armor�̈ʒu
	float m_y;
	float m_vy;			//Armor�̗���
};