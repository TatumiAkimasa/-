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
#include <thread>
#include <chrono>
//�g�p����l�[���X�y�[�X
using namespace GameL;

bool CObjFishPlayer::heel_flag()
{
    return come_heel_flag;
}

//�R���X�g���N�^
CObjFishPlayer::CObjFishPlayer()
{
    m_vx = 0.0f;     //�ړ��x�N�g��
    m_vy = 0.0f;
    m_px = 520.0f;     //�ʒu
    m_py = 450.0f;
    m_f = true;      //�ړ�����
    m_ani_time = 0;
    m_ani_frame = 0;
    m_ice_ani_frame = 0;
    m_time = 0;
    m_inv_time = 0;//���G���ԗp�^�C���ϐ�
    m_stop_time = 0;
    m_right_move = false;
    m_left_move = false;
    m_move = 0;
    m_damage = false;
    come_heel_flag = false;
    m_spin = 0.0f;
    cont = 0;
    m_not_move_time = false;//false�ő���\�Etrue�ő���s�\
    slow_right_move = false;
    slow_left_move = false;
    slow_count = 0;


    m_i = 0;
}

//�C�j�V�����C�Y
void CObjFishPlayer::Init()
{
    srand(rand());

    //�����蔻��pHitBox���쐬
    Hits::SetHitBox(this, m_px + 22, m_py + 16, 20, 45, ELEMENT_PLAYER, ELEMENT_PLAYER, 1);
}

//�A�N�V����
void CObjFishPlayer::Action()
{
    rand(); rand(); rand(); rand(); 
    
    float x = rand() % 122;

    //HitBox�̓��e���X�V
    CHitBox* hit = Hits::GetHitBox(this);  //�쐬����HitBox�X�V�p�̓���������o��
    hit->SetPos(m_px + 22, m_py + 16);         //��������V�����ʒu(��l���̈ʒu)���ɒu��������

    //�����̃��C�t1�ȏ�ŋ�������\
    if (((UserData*)Save::GetData())->life_point > 0)
    {

        if (((UserData*)Save::GetData())->Ren_flag == true)
        {
            m_ice_ani_frame = 4 - ((UserData*)Save::GetData())->ren;

            //�E
            if (Input::GetVKey(VK_RIGHT) == true)
            {
                if (m_f == true)
                {
                    //�A�ł̏���
                    if (m_f == true)
                    {
                        Audio::Start(16);
                        ((UserData*)Save::GetData())->ren--;
                    }

                    if (((UserData*)Save::GetData())->ren <= 0)
                    {
                        Audio::Start(17);
                        ((UserData*)Save::GetData())->Ren_flag = false;
                        m_ice_ani_frame = 0;
                    }
                    
                    m_f = false;
                }
            }
            //��
            else if (Input::GetVKey(VK_LEFT) == true)
            {
                if (m_f == true)
                {
                    //�A�ł̏���
                    if (m_f == true)
                    {
                        ((UserData*)Save::GetData())->ren--;
                        Audio::Start(16);
                    }

                    if (((UserData*)Save::GetData())->ren <= 0)
                    {
                        Audio::Start(17);
                        ((UserData*)Save::GetData())->Ren_flag = false;
                        m_ice_ani_frame = 0;
                    }
                    
                    m_f = false;
                }
            }
            else
            {
                m_f = true;
            }
        }
        else
        {
            m_ani_time++;
            //�����A�j��
            if (m_ani_time > 25 - ((UserData*)Save::GetData())->sp)
            {
                m_ani_time = 0;
                m_ani_frame += 1;
            }

            if (m_ani_frame == 4)
            {
                m_ani_frame = 0;
            }

            //�L�[�̓��͕����Ƀx�N�g���̑��x������
            //�E
            if (Input::GetVKey(VK_RIGHT) == true && m_not_move_time == false)
            {
                //���씽�]���[�h�FOFF
                if (((UserData*)Save::GetData())->start_control_mirror == true)
                {
                    if (m_f == true)
                    {
                        //true�̎����씽�]
                        if (((UserData*)Save::GetData())->key_flag_mirror == true)
                        {
                            if (m_f == true)
                            {
                                //��l���̍��E�ړ��ݑ���
                                if (((UserData*)Save::GetData())->key_flag_slow == true)
                                {
                                    slow_left_move = true;
                                }
                                else
                                {
                                    m_left_move = true;
                                }
                            }
                        }
                        else
                        {
                            //��l���̍��E�ړ��ݑ���
                            if (((UserData*)Save::GetData())->key_flag_slow == true)
                            {
                                slow_right_move = true;
                            }
                            else
                            {
                                m_right_move = true;
                            }
                        }
                    }
                }
                //���씽�]���[�h�FON
                else
                {
                    if (m_f == true)
                    {
                        //true�̎����씽�]
                        if (((UserData*)Save::GetData())->key_flag_mirror == true)
                        {
                            if (m_f == true)
                            {
                                //��l���̍��E�ړ��ݑ���
                                if (((UserData*)Save::GetData())->key_flag_slow == true)
                                {
                                    slow_right_move = true;
                                }
                                else
                                {
                                    m_right_move = true;
                                }
                            }
                        }
                        else
                        {
                            //��l���̍��E�ړ��ݑ���
                            if (((UserData*)Save::GetData())->key_flag_slow == true)
                            {
                                slow_left_move = true;
                            }
                            else
                            {
                                m_left_move = true;
                            }
                        }
                    }
                }
            }
            //��
            else if (Input::GetVKey(VK_LEFT) == true && m_not_move_time == false)
            {
                //���씽�]���[�h�FOFF
                if (((UserData*)Save::GetData())->start_control_mirror == true)
                {
                    if (m_f == true)
                    {
                        //true�̎����씽�]
                        if (((UserData*)Save::GetData())->key_flag_mirror == true)
                        {
                            
                            if (m_f == true)
                            {
                                //��l���̍��E�ړ��ݑ���
                                if (((UserData*)Save::GetData())->key_flag_slow == true)
                                {
                                    slow_right_move = true;
                                }
                                else
                                {
                                    m_right_move = true;
                                }
                            }
                        }
                        else
                        {
                            //��l���̍��E�ړ��ݑ���
                            if (((UserData*)Save::GetData())->key_flag_slow == true)
                            {
                                slow_left_move = true;
                            }
                            else
                            {
                                m_left_move = true;
                            }
                        }
                    }
                }
                //���씽�]���[�h�FON
                else
                {
               
                    if (m_f == true)
                    {
                        //true�̎����씽�]
                        if (((UserData*)Save::GetData())->key_flag_mirror == true)
                        {
                            
                            if (m_f == true)
                            {
                                //��l���̍��E�ړ��ݑ���
                                if (((UserData*)Save::GetData())->key_flag_slow == true)
                                {
                                    slow_left_move = true;
                                }
                                else
                                {
                                    m_left_move = true;
                                }
                            }
                        }
                        else
                        {
                            //��l���̍��E�ړ��ݑ���
                            if (((UserData*)Save::GetData())->key_flag_slow == true)
                            {
                                slow_right_move = true;
                            }
                            else
                            {
                                m_right_move = true;
                            }
                        }
                    }
                }
            }
            else
            {
                m_f = true;
            }
        }

        if (hit->CheckElementHit(ELEMENT_MIRROR) == true && ((UserData*)Save::GetData())->key_flag_mirror == false)
        {
            CObjPiyokoFish* pf;
            for (m_i = 0; m_i < 3; m_i++)
            {
                switch (m_i)
                {
                case 0:
                     pf = new CObjPiyokoFish(0.0f, m_py, 0.0f);
                    Objs::InsertObj(pf, NULL, 100);
                case 1:
                    pf = new CObjPiyokoFish(0.0f + 45, m_py + 45, 90.0f);
                    Objs::InsertObj(pf, NULL, 100);
                case 2:
                    pf = new CObjPiyokoFish(0.0f, m_py + 90, 180.0f);
                    Objs::InsertObj(pf, NULL, 100);
                case 3:
                    pf = new CObjPiyokoFish(0.0f - 45, m_py + 45, 270.0f);
                    Objs::InsertObj(pf, NULL, 100);
                }
            }
        }

        //�x�N�g����}��
        //�E
        if (m_right_move == true)
        {
            m_vx += 40.0f;
            m_move++;
            m_not_move_time = true;
            m_f = false;
            if (m_move >= 3)
            {
                m_move = 0;
                m_right_move = false;
                m_not_move_time = false;
            }
        }
        //�E(����ݑ�)
        if (slow_right_move == true)
        {
            m_vx += 5;
            m_move++;
            m_not_move_time = true;
            m_f = false;
            if (slow_count >= 10)
            {
                ((UserData*)Save::GetData())->key_flag_slow = false;
                slow_count = 0;
            }
            if (m_move >= 24)
            {
                m_move = 0;
                slow_count++;
                slow_right_move = false;
                m_not_move_time = false;
            }
        }
        //��
        if (m_left_move == true)
        {
            m_vx -= 40.0f;
            m_move++;
            m_not_move_time = true;
            m_f = false;
            if (m_move >= 3)
            {
                m_move = 0;
                m_left_move = false;
                m_not_move_time = false;
            }
        }
        //��(����ݑ�)
        if (slow_left_move == true)
        {
            m_vx -= 5;
            m_move++;
            m_not_move_time = true;
            m_f = false;
            if (slow_count >= 10)
            {
                ((UserData*)Save::GetData())->key_flag_slow = false;
                slow_count = 0;
            }
            if (m_move >= 24)
            {
                m_move = 0;
                slow_count++;
                slow_left_move = false;
                m_not_move_time = false;
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

        //sp20�ŗ��������I�u�W�F�N�g�A������
        if (((UserData*)Save::GetData())->sp >= 20)
        {
            m_time++;
            if (m_time % 5 == 0)
            {
                ObjDriftFish* df = new ObjDriftFish(m_px+x, m_py);
                Objs::InsertObj(df, NULL, 100);
                m_time = 0;
            }
        }
    }
    else
    {
        ((UserData*)Save::GetData())->sp = 0;
        Audio::Stop(0);
        Audio::Stop(1);
        Audio::Stop(2);
        Audio::Stop(4);
        Audio::Start(5);//���ꎞSE
        m_time++;

        m_spin += 15.0f;
        //m_px += 1 * m_vx;
        m_vy += 0.01f;
        m_py += 1 * m_vy;
    }

    
    //��l���̈ړ��x�N�g���̏�����
    m_vx = 0.0f;

    //key_flag_mirror��true�̎�
    if (((UserData*)Save::GetData())->key_flag_mirror == true)
    {
        m_key_time++;
    
        if (m_key_time == 540)
        {
            Audio::Stop(18);
            ((UserData*)Save::GetData())->key_flag_mirror = false;
            m_key_time = 0;
        }
    }

    //�񕜃A�C�e���ƐڐG������񕜁��폜
    if (hit->CheckElementHit(ELEMENT_HEAL) == true)
    {
        Audio::Start(7);

        
        come_heel_flag = true;
        if (((UserData*)Save::GetData())->life_point < 3)
        {
            ((UserData*)Save::GetData())->life_point++;
        }
    }
    else
        come_heel_flag = false;


    //��Q���I�u�W�F�N�g�ƐڐG������폜
    if (hit->CheckElementHit(ELEMENT_ENEMY) == true && m_damage == false)
    {
        //Armor�t���O��true�̎�
        if (((UserData*)Save::GetData())->Armor_flag == true)
        {
            Audio::Start(13);
            //�_���[�W����͂Ȃ��A�t���O�̂ݕύX
            ((UserData*)Save::GetData())->Armor_flag = false;
        }
        //Armor�t���O��false�̎�
        else
        {
            ((UserData*)Save::GetData())->life_point--;
            ((UserData*)Save::GetData())->sp_lv = 0;
            m_damage = true;

            Audio::Start(4);
        }
    }

    //��ʊO�ɏo����HitBox���폜
    if (m_py > 600.0f)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);

        //��l�����łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
        Scene::SetScene(new CSceneResult());
        m_spin++;
    }
}

//�h���[
void CObjFishPlayer::Draw()
{
    //�`�ʃJ���[���
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    int AniData[4]{ 1,2,3,4 };

    static float r = 0.0f;

    RECT_F src;//�`�ʌ��̐؂���ʒu
    RECT_F dst;//�`���̕\���ʒu

    if (((UserData*)Save::GetData())->Armor_flag == true)
    {
        dst.m_top = -23.0f + m_py;
        dst.m_left = -62.5f + m_px;
        dst.m_right = 182.0f + dst.m_left;
        dst.m_bottom = 192.0f + dst.m_top;

        src.m_top = 0.0f;
        src.m_left = 0.0f;
        src.m_right = 64.0f;
        src.m_bottom = 64.0f;

        Draw::Draw(23, &src, &dst, c, 0);
    }

    dst.m_top = -23.0f + m_py;
    dst.m_left = -62.5f + m_px;
    dst.m_right = 182.0f + dst.m_left;
    dst.m_bottom = 192.0f + dst.m_top;

    src.m_top = 0.0f;
    src.m_left = 0.0f + (AniData[m_ani_frame] - 1) * 207;
    src.m_right = 207.0f * AniData[m_ani_frame];
    src.m_bottom = 224.0f;
    
    if (((UserData*)Save::GetData())->life_point > 0)
    {
        if (m_damage == false)
        {
            if (((UserData*)Save::GetData())->space_flag == true)
            {
                Draw::Draw(25, &src, &dst, c, 0.0f);
            }
            else if (((UserData*)Save::GetData())->space_flag == false)
                Draw::Draw(2, &src, &dst, c, 0.0f);
        }
        else
        {
            m_inv_time++;

            if (m_inv_time % 5 == 0)
            {
                if (((UserData*)Save::GetData())->Ren_flag == true)
                {
                    if (((UserData*)Save::GetData())->space_flag == true)
                        Draw::Draw(25, &src, &dst, c, 0.0f);
                    else
                        Draw::Draw(2, &src, &dst, c, 0.0f);
                }
                else
                {
                    if (((UserData*)Save::GetData())->space_flag == true)
                        Draw::Draw(25, &src, &dst, c, 0.0f);
                    else
                        Draw::Draw(2, &src, &dst, c, 0.0f);
                }

            }
            else
            {
                c[0] = 1.0f;
                c[1] = 0.5f;
                c[2] = 0.0f;
                if (((UserData*)Save::GetData())->space_flag == true)
                    Draw::Draw(25, &src, &dst, c, 0.0f);
                else
                    Draw::Draw(2, &src, &dst, c, 0.0f);
            }

            if (m_inv_time == 30)
            {
                m_inv_time = 0;
                m_damage = false;
            }
        }
    }
    else
    {
        if (((UserData*)Save::GetData())->space_flag == true)
            Draw::Draw(25, &src, &dst, c, m_spin);
        else
            Draw::Draw(2, &src, &dst, c, m_spin);
    }
    
    if (((UserData*)Save::GetData())->Ren_flag == true)
    {
        dst.m_top = 0.0f + m_py;
        dst.m_left = 0.0f - 32.0f + m_px;
        dst.m_right = 128.0f -32.0f+ m_px;
        dst.m_bottom = 128.0f + m_py;

        src.m_top = 0.0f;
        src.m_left = 0.0f + (AniData[m_ice_ani_frame] - 1) * 128;
        src.m_right = 128.0f * AniData[m_ice_ani_frame];
        src.m_bottom = 128.00f;

        Draw::Draw(21, &src, &dst, c, m_spin);
    }
    else
    {
        dst.m_top = 0.0f + m_py;
        dst.m_left = 0.0f - 32.0f + m_px;
        dst.m_right = 128.0f - 32.0f + m_px;
        dst.m_bottom = 128.0f + m_py;

        src.m_top = 0.0f;
        src.m_left = 0.0f;
        src.m_right = 128.0f;
        src.m_bottom = 128.00f;
    }
}