#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�FObjBackground
class CObjwater_flow : public CObj
{
public:
	CObjwater_flow() {};
	~CObjwater_flow() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	int right;
	float m_y1; //�w�i�@�̕`����
};