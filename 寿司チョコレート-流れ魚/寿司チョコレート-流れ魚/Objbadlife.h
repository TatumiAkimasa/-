#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�Fbadlife
class CObjbadlife : public CObj
{
public:
	CObjbadlife(float x, float y, float s);
	~CObjbadlife() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x;			//badlife�̈ʒu
	float m_y;
	float m_vy;			//badlife�̗����ł�	
};