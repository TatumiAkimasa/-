#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�V�[���F���C��
class CObjMain :public CObj
{
public:
	CObjMain() {};
	~CObjMain() {};
	void Init();  //�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();  //�h���[
private:
	int f;
	int s_time;
	int m_time;
	int random;//�R�����g�p�����_���ϐ�
	int life;//�R�����g�p���C�t�Ǘ��ϐ�
	bool come_flag;//�R�����g�p�t���O
	bool life_flag;//�R�����g�p���C�t�Ǘ��t���O
	bool heel_flag;//�R�����g�p�񕜃t���O
	int fps = 0;//���씽�]�̎��g��
	int i = 9;//���씽�]�̎��g��
	int second = 10;//���씽�]�̎��g��
	
	bool mirrior_flag;//�R�����g�p���]�I����t���O
};