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
	void SetS_time(int);
	void SetM_time(int);
	int GetS_time();
	int GetM_time();
private:
	int f;
	int s_time;
	int m_time;
	
};