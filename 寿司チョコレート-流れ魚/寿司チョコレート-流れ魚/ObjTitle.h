#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjTitle :public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();
	int key_num_T();
private:
	bool m_key_flag;//�L�[�t���O
	int num;//�`��D��x

	//�����L���O�\�[�g���\�b�h
	void RankingSort(int rank[11]);
};
