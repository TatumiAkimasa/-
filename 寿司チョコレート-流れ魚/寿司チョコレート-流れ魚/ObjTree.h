#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��
class CObjTree : public CObj
{
public:
	CObjTree(float x, float y);
	~CObjTree() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x;			//�؂̈ʒu
	float m_y;
	float m_vx;			//�؂̏o���p�x�N�g��
};