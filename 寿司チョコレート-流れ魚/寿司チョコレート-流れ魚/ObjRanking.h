#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjRanking :public CObj
{
public:
	CObjRanking() {};
	~CObjRanking() {};
	void Init();
	void Action();
	void Draw();
private:
	//�����L���O�\�[�g���\�b�h
	void RankingSort(int rank[11]);
	bool D_flag;//�L�[�t���O(��)
	bool U_flag;//�L�[�t���O(��)
};