#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjDescription :public CObj
{
public:
	CObjDescription() {};
	~CObjDescription() {};
	void Init();
	void Action();
	void Draw();
	int key_num_D();
private:
	bool m_key_flag;//�L�[�t���O
	int numd;//�`��D��x�i�����p�j
	int i;
};

