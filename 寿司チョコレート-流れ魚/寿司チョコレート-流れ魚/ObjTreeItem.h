#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�؃A�C�e��
class CObjTreeItem : public CObj
{
public:
	CObjTreeItem(float x, float y, float s);
	~CObjTreeItem() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x;			//�؃A�C�e���̈ʒu
	float m_y;
	float m_vy;			//�؃A�C�e���̗����ł�
	float s;
};