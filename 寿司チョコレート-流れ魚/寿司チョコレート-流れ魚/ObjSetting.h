#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjSetting :public CObj
{
public:
	CObjSetting() {};
	~CObjSetting() {};
	void Init();
	void Action();
	void Draw();
private:
	bool R_flag;//�L�[�t���O(�E�j
	bool L_flag;//�L�[�t���O�i���j
	bool U_flag;//�L�[�t���O(�E�j
	bool D_flag;//�L�[�t���O�i���j
	bool S_flag;//�������x�����������邽�߂̃t���O
	bool M_flag;//���씽�]���[�h�����������邽�߂̃t���O
	int setting_pos;//�������ݒ肵�������ւ̈ړ�
};