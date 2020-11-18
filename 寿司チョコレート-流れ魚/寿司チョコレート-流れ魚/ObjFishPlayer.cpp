//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjFishPlayer.h"
#include "GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjFishPlayer::Init()
{
    m_vx = 0.0f;     //�ړ��x�N�g��
    m_vy = 0.0f;
    m_px = 520.0f;     //�ʒu
    m_py = 450.0f;
    m_f = true;      //�ړ�����
    m_ani_time = 0;
    m_ani_frame = 0;
    m_time = 0;
    m_right_move = false;
    m_left_move = false;
    m_move = 0;
    i = false;

    //�����蔻��pHitBox���쐬
    Hits::SetHitBox(this, m_px + 22, m_py + 16, 20, 45, ELEMENT_PLAYER, OBJ_FISH_PLAYER, 1);

}

//�A�N�V����
void CObjFishPlayer::Action()
{
    m_ani_time++;
    m_time++;

    if (m_ani_time > 10)
    {
        m_ani_time = 0;
        m_ani_frame += 1;
    }

    if (m_ani_frame == 4)
    {
        m_ani_frame = 0;
    }

    //��l���̈ړ��x�N�g���̏�����
    m_vx = 0.0f;

    //HitBox�̓��e���X�V
    CHitBox* hit = Hits::GetHitBox(this);  //�쐬����HitBox�X�V�p�̓���������o��
    hit->SetPos(m_px + 22, m_py + 16);         //��������V�����ʒu(��l���̈ʒu)���ɒu��������

    //key_flag_mirror��true�̎�
    if (((UserData*)Save::GetData())->key_flag_mirror == true)
    {
        m_key_time++;

        if (m_key_time == 600)
        {
            ((UserData*)Save::GetData())->key_flag_mirror = false;
            m_key_time = 0;
        }
    }

    //�L�[�̓��͕����Ƀx�N�g���̑��x������
    if (Input::GetVKey(VK_RIGHT) == true)
    {
        if (m_f == true)
        {
            //true�̎����씽�]
            if (((UserData*)Save::GetData())->key_flag_mirror == true)
            {
                if (m_f == true)
                {
                    m_left_move = true;
                    m_f = false;

                }
            }
            else
            {
                m_right_move = true;
                m_f = false;
            }
        }
    }
    else if (Input::GetVKey(VK_LEFT) == true)
    {
        if (m_f == true)
        {
            //true�̎����씽�]
            if (((UserData*)Save::GetData())->key_flag_mirror == true)
            {
                if (m_f == true)
                {
                    m_right_move = true;
                    m_f = false;
                }
            }
            else
            {
                m_left_move = true;
                m_f = false;
            }
        }
    }
    else
    {
        m_f = true;
    }

    if (m_right_move == true)
    {
        m_vx += 40;
        m_move++;
        if (m_move == 3)
        {
            m_move = 0;
            m_right_move = false;
        }
    }

    if (m_left_move == true)
    {
        m_vx -= 40;
        m_move++;
        if (m_move == 3)
        {
            m_move = 0;
            m_left_move = false;
        }
    }

    //�ړ��x�N�g�������W�ɉ��Z����
    m_px += 1 * m_vx;
    m_py += 1 * m_vy;

    if (m_px > 640.0f)
    {
        m_px = 640.0f;//�͂ݏo�Ȃ��ʒu�Ɉړ�������
    }
    if (m_px < 400.0f)
    {
        m_px = 400.0f;
    }

    //�񕜃A�C�e���ƐڐG������񕜁��폜
    if (hit->CheckElementHit(ELEMENT_HEAL) == true)
    {
        Audio::Start(1);

        if (((UserData*)Save::GetData())->life_point < 3)
        {
            ((UserData*)Save::GetData())->life_point++;
        }
    }


    //��Q���I�u�W�F�N�g�ƐڐG������폜
    if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
    {
        ((UserData*)Save::GetData())->life_point--;
        ((UserData*)Save::GetData())->sp_lv = 0;
        i = true;

        Audio::Start(2);
        if (((UserData*)Save::GetData())->life_point == 0)
        {
            this->SetStatus(false);    //���g�ɍ폜���߂��o��
            Hits::DeleteHitBox(this);  //��l���@�����L����HitBox�ɍ폜����

            //��l�����łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
            Scene::SetScene(new CSceneResult());

        }
    }
}

//�h���[
void CObjFishPlayer::Draw()
{
    //�`�ʃJ���[���
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    int AniData[4]{ 1,2,3,4 };

    RECT_F src;//�`�ʌ��̐؂���ʒu
    RECT_F dst;//�`���̕\���ʒu


    src.m_top = 0.0f;
    src.m_left = 0.0f + (AniData[m_ani_frame] - 1) * 828;
    src.m_right = 828.0f * AniData[m_ani_frame];
    src.m_bottom = 1792.0f;

    if (i == false)
    {
        dst.m_top = -75.0f + m_py;
        dst.m_left = -64.9f + m_px;
        dst.m_right = 192.0f + dst.m_left;
        dst.m_bottom = 384.0f + dst.m_top;
    }
    else
    {
        if (m_time % 2 == 0)
        {

        }
    }

    Draw::Draw(2, &src, &dst, c, 0.0f);

}