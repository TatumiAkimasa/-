#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjTitle :public CObj
{
public:
	CObjTitle();
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();
	int key_num_T();
	bool key_num2_T();
private:
	bool R_flag;//�L�[�t���O(�E�j
	bool L_flag;//�L�[�t���O�i���j
	bool D_flag;//�L�[�t���O(��)
	int num;//�`��D��x
	

	//�����L���O�\�[�g���\�b�h
	void RankingSort(int rank[11]);
};
