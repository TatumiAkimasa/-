#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���씽�]�A�C�e��
class CObjmirror : public CObj
{
public:
	CObjmirror(float x, float y, float s);
	~CObjmirror() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x;			//���씽�]�A�C�e���̈ʒu
	float m_y;
	float m_vy;			//���씽�]�A�C�e���̗����ł�
};