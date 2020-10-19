//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjFishPlayer.h"

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

    //�����蔻��pHitBox���쐬
    Hits::SetHitBox(this, m_px, m_py, 64, 128, ELEMENT_PLAYER, OBJ_FISH_PLAYER, 1);

}

//�A�N�V����
void CObjFishPlayer::Action()
{
    //��l���@�̈ړ��x�N�g���̏�����
    m_vx = 0.0f;
    

    //�L�[�̓��͕����Ƀx�N�g���̑��x������
    if (Input::GetVKey(VK_RIGHT) == true)
    {
        if (m_f == true)
        {
            m_vx += 120.0f;
            m_f = false;
            
        }
    }
    

    else if (Input::GetVKey(VK_LEFT) == true)
    {
        if (m_f == true)
        {
            m_vx -= 120.0f;
            m_f = false;

        }
    }
    else
    {
        m_f = true;

    }

    //�ړ��x�N�g�������W�ɉ��Z����
    m_px += 1 * m_vx;
    m_py += 1 * m_vy;

    if (m_px> 640.0f)
    {
        m_px = 640.0f;//�͂ݏo�Ȃ��ʒu�Ɉړ�������
    }
    if (m_px < 400.0f)
    {
        m_px = 400.0f;
    }

    //HitBox�̓��e���X�V
    CHitBox* hit = Hits::GetHitBox(this);  //�쐬����HitBox�X�V�p�̓���������o��
    hit->SetPos(m_px, m_py);                 //��������V�����ʒu(��l���@�̈ʒu)���ɒu��������
    
    //��Q���I�u�W�F�N�g�ƐڐG������폜
    if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
    {
        this->SetStatus(false);    //���g�ɍ폜���߂��o��
        Hits::DeleteHitBox(this);  //��l���@�����L����HitBox�ɍ폜����


        //��l�����łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
        Scene::SetScene(new CSceneResult());
    }
}

//�h���[
void CObjFishPlayer::Draw()
{
    //�`�ʃJ���[���
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//�`�ʌ��̐؂���ʒu
    RECT_F dst;//�`���̕\���ʒu


    src.m_top = 0.0f;
    src.m_left = 0.0f;
    src.m_right = 828.0f;
    src.m_bottom = 1792.0f;

    dst.m_top = 0.0f + m_py;
    dst.m_left = 0.0f + m_px;
    dst.m_right = 64.0f + dst.m_left;
    dst.m_bottom = 128.0f + dst.m_top;

    Draw::Draw(2, &src, &dst, c, 0.0f);


}