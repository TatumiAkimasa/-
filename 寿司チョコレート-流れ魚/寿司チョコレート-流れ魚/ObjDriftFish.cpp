//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjDriftFish.h"
#include "GameL\Audio.h"
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <time.h>
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void ObjDriftFish::Init()
{
    m_vx = 0.0f;     //�ړ��x�N�g��
    m_vy = 0.0f;
    m_px = 520.0f;     //�ʒu
    m_py = 450.0f;
    m_f = true;      //�ړ�����
    m_time = 0;
    m_right_move = false;
    m_left_move = false;
    srand(time(NULL));

    //�����蔻��pHitBox���쐬
    Hits::SetHitBox(this, m_px + 22, m_py + 16, 20, 45, NULL, NULL, 1);
}

//�R���X�g���N�^
ObjDriftFish::ObjDriftFish(float x, float y)
{
    m_px = x;
    m_py = y;
}

//�A�N�V����
void ObjDriftFish::Action()
{
    CObjFishPlayer* obj = (CObjFishPlayer*)Objs::GetObj(OBJ_FISH_PLAYER);

    //��l���̈ړ��x�N�g���̏�����
    m_vx = 0.0f;

    //key_flag_mirror��true�̎�
    if (((UserData*)Save::GetData())->key_flag_mirror == true)
    {
        m_key_time++;

        if (m_key_time == 540)
        {
            ((UserData*)Save::GetData())->key_flag_mirror = false;
            m_key_time = 0;
        }
    }

    /*m_px = obj->GetX();
    m_py = obj->GetY();*/

    if (((UserData*)Save::GetData())->sp == 20)
    {
        m_vy += 5;
    }

    //�ړ��x�N�g�������W�ɉ��Z����
    m_px += 1 * m_vx;
    m_py += 1 * m_vy;

    //HitBox�̓��e���X�V
    CHitBox* hit = Hits::GetHitBox(this);  //�쐬����HitBox�X�V�p�̓���������o��
    hit->SetPos(m_px + 22, m_py + 16);         //��������V�����ʒu(��l���̈ʒu)���ɒu��������

    if (m_px > 640.0f)
    {
        m_px = 640.0f;//�͂ݏo�Ȃ��ʒu�Ɉړ�������
    }
    if (m_px < 400.0f)
    {
        m_px = 400.0f;
    }

    //��ʊO�ɏo����HitBox���폜
    if (m_py > 600.0f)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);
    }

}

//�h���[
void ObjDriftFish::Draw()
{
    //�`�ʃJ���[���
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//�`�ʌ��̐؂���ʒu
    RECT_F dst;//�`���̕\���ʒu

    dst.m_top = -0.0f + m_py;
    dst.m_left = -0.0f + m_px;
    dst.m_right = 16.0f + dst.m_left;
    dst.m_bottom = 16.0f + dst.m_top;

    src.m_top = 0.0f;
    src.m_left = 0.0f;
    src.m_right = 64.0f;
    src.m_bottom = 64.0f;

    if (((UserData*)Save::GetData())->sp <= 20.0)
    {
        Draw::Draw(19, &src, &dst, c, 0.0f);
    }
}