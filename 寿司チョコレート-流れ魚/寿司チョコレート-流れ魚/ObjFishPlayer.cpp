//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjFishPlayer.h"
#include "GameL\Audio.h"
//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjFishPlayer::Init()
{
    m_vx = 0.0f;     //移動ベクトル
    m_vy = 0.0f;
    m_px = 520.0f;     //位置
    m_py = 450.0f;
    m_f = true;      //移動制御
    m_ani_time = 0;
    m_ani_frame = 0;
    m_time = 0;
    m_right_move = false;
    m_left_move = false;
    m_move = 0;
    i = false;

    //当たり判定用HitBoxを作成
    Hits::SetHitBox(this, m_px + 22, m_py + 16, 20, 45, ELEMENT_PLAYER, OBJ_FISH_PLAYER, 1);

}

//アクション
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

    //主人公の移動ベクトルの初期化
    m_vx = 0.0f;

    //HitBoxの内容を更新
    CHitBox* hit = Hits::GetHitBox(this);  //作成したHitBox更新用の入り口を取り出す
    hit->SetPos(m_px + 22, m_py + 16);         //入口から新しい位置(主人公の位置)情報に置き換える

    //key_flag_mirrorがtrueの時
    if (((UserData*)Save::GetData())->key_flag_mirror == true)
    {
        m_key_time++;

        if (m_key_time == 600)
        {
            ((UserData*)Save::GetData())->key_flag_mirror = false;
            m_key_time = 0;
        }
    }

    //キーの入力方向にベクトルの速度を入れる
    if (Input::GetVKey(VK_RIGHT) == true)
    {
        if (m_f == true)
        {
            //trueの時操作反転
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
            //trueの時操作反転
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

    //移動ベクトルを座標に加算する
    m_px += 1 * m_vx;
    m_py += 1 * m_vy;

    if (m_px > 640.0f)
    {
        m_px = 640.0f;//はみ出ない位置に移動させる
    }
    if (m_px < 400.0f)
    {
        m_px = 400.0f;
    }

    //回復アイテムと接触したら回復＆削除
    if (hit->CheckElementHit(ELEMENT_HEAL) == true)
    {
        Audio::Start(1);

        if (((UserData*)Save::GetData())->life_point < 3)
        {
            ((UserData*)Save::GetData())->life_point++;
        }
    }


    //障害物オブジェクトと接触したら削除
    if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
    {
        ((UserData*)Save::GetData())->life_point--;
        ((UserData*)Save::GetData())->sp_lv = 0;
        i = true;

        Audio::Start(2);
        if (((UserData*)Save::GetData())->life_point == 0)
        {
            this->SetStatus(false);    //自身に削除命令を出す
            Hits::DeleteHitBox(this);  //主人公機が所有するHitBoxに削除する

            //主人公消滅でシーンをゲームオーバーに移行する
            Scene::SetScene(new CSceneResult());

        }
    }
}

//ドロー
void CObjFishPlayer::Draw()
{
    //描写カラー情報
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    int AniData[4]{ 1,2,3,4 };

    RECT_F src;//描写元の切り取り位置
    RECT_F dst;//描画先の表示位置


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