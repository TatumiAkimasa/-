#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�V�[���F���C��
class CObjFishPlayer :public CObj
{
public:
	CObjFishPlayer() {};
	~CObjFishPlayer() {};
	void Init();  //�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();  //�h���[
private:
	float m_px;     //�ʒu
	float m_py;
	float m_vx;     //��l���@�̂������ړ��x�N�g���p�ϐ�
	float m_vy;
	bool m_f;       //�ړ��L�[���������Ƃ��A���œ����Ȃ��ׂ̕ϐ�
};