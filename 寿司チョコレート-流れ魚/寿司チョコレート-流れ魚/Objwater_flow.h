#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�FObjBackground
class CObjwater_flow : public CObj
{
public:
	CObjwater_flow(float a) ;
	~CObjwater_flow() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	int right; //�E�ɂǂꂾ������Ă邩
	int right_d;//right�̕ϐ��ۑ��p
	float m_y1; //�w�i�@�̕`����
	float flow_flag;//�r���Ő����ς��Ȃ��p�B
	float speed;//����
};