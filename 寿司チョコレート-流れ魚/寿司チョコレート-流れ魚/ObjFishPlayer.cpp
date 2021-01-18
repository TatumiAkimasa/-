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
#include <thread>
#include <chrono>
//使用するネームスペース
using namespace GameL;

bool CObjFishPlayer::heel_flag()
{
    return come_heel_flag;
}

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
    m_inv_time = 0;//無敵時間用タイム変数
    m_stop_time = 0;
    m_right_move = false;
    m_left_move = false;
    m_move = 0;
    m_damage = false;
    come_heel_flag = false;
    m_spin = 0.0f;
    cont = 0;
    m_not_move_time = false;//falseで操作可能・trueで操作不能
    
    srand(rand());

    //当たり判定用HitBoxを作成
    Hits::SetHitBox(this, m_px + 22, m_py + 16, 20, 45, ELEMENT_PLAYER, ELEMENT_PLAYER, 1);
}

//アクション
void CObjFishPlayer::Action()
{
    rand(); rand(); rand(); rand(); 
    
    float x = rand() % 122;

    //HitBoxの内容を更新
    CHitBox* hit = Hits::GetHitBox(this);  //作成したHitBox更新用の入り口を取り出す
    hit->SetPos(m_px + 22, m_py + 16);         //入口から新しい位置(主人公の位置)情報に置き換える
    
    m_ani_time++;

    //金魚のライフ1以上で金魚操作可能
    if (((UserData*)Save::GetData())->life_point > 0)
    {
        //金魚アニメ
        if (m_ani_time > 25 - ((UserData*)Save::GetData())->sp)
        {
            m_ani_time = 0;
            m_ani_frame += 1;
        }

        if (m_ani_frame == 4)
        {
            m_ani_frame = 0;
        }

        if (((UserData*)Save::GetData())->Ren_flag == true)
        {
            //右
            if (Input::GetVKey(VK_RIGHT) == true)
            {
                if (m_f == true)
                {
                    //連打の処理
                    if(m_f==true)
                    ((UserData*)Save::GetData())->ren--;

                    if (((UserData*)Save::GetData())->ren <= 0)
                    {
                        ((UserData*)Save::GetData())->Ren_flag = false;
                    }
                    m_f = false;
                }
            }
            //左
            else if (Input::GetVKey(VK_LEFT) == true)
            {
                //連打の処理
                if (m_f == true)
                    ((UserData*)Save::GetData())->ren--;

                if (((UserData*)Save::GetData())->ren <= 0)
                {
                    ((UserData*)Save::GetData())->Ren_flag = false;
                }
                m_f = false;
            }
            else
            {
                m_f = true;
            }
        }
        else
        {
            //キーの入力方向にベクトルの速度を入れる
            //右
            if (Input::GetVKey(VK_RIGHT) == true && m_not_move_time == false)
            {
                //操作反転モード：OFF
                if (((UserData*)Save::GetData())->start_control_mirror == true)
                {
                    if (m_f == true)
                    {
                        //trueの時操作反転
                        if (((UserData*)Save::GetData())->key_flag_mirror == true)
                        {
                            if (m_f == true)
                            {
                                m_left_move = true;
                            }
                        }
                        else
                        {
                            m_right_move = true;
                        }
                    }
                }
                //操作反転モード：ON
                else
                {
                    if (m_f == true)
                    {
                        //trueの時操作反転
                        if (((UserData*)Save::GetData())->key_flag_mirror == true)
                        {
                            if (m_f == true)
                            {
                                m_right_move = true;
                            }
                        }
                        else
                        {
                            m_left_move = true;
                        }
                    }
                }
            }
            //左
            else if (Input::GetVKey(VK_LEFT) == true && m_not_move_time == false)
            {
                //操作反転モード：OFF
                if (((UserData*)Save::GetData())->start_control_mirror == true)
                {
                    if (m_f == true)
                    {
                        //trueの時操作反転
                        if (((UserData*)Save::GetData())->key_flag_mirror == true)
                        {
                            //連打の処理
                            ((UserData*)Save::GetData())->ren--;

                            if (m_f == true)
                            {
                                m_right_move = true;
                            }
                        }
                        else
                        {
                            m_left_move = true;
                        }
                    }
                }
                //操作反転モード：ON
                else
                {
               
                    if (m_f == true)
                    {
                        //trueの時操作反転
                        if (((UserData*)Save::GetData())->key_flag_mirror == true)
                        {
                            //連打の処理
                            ((UserData*)Save::GetData())->ren--;

                            if (m_f == true)
                            {
                                m_left_move = true;
                            }
                        }
                        else
                        {
                            m_right_move = true;
                        }
                    }
                }
            }
            else
            {
                m_f = true;
            }
        }

        if (hit->CheckElementHit(ELEMENT_MIRROR) == true)
        {
            CObjPiyokoFish* df = new CObjPiyokoFish(m_px, m_py,90);
            Objs::InsertObj(df, NULL, 100);
        }

        //ベクトルを挿入
        //右
        if (m_right_move == true)
        {
            m_vx += 40;
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
        //左
        if (m_left_move == true)
        {
            m_vx -= 40;
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

        //sp20で流れる金魚オブジェクト連続生成
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
        Audio::Start(5);//やられ時SE
        m_time++;
       /*魚ふるわせてgameoverさせる用の処理 
       if (m_time % 4 == 0)
        {
            if (cont == 0)
            {
                m_vx += 5;
                cont++;
            }
            else if (cont == 1)
            {
                m_vx -= 15;
                cont = -1;
            }
            else if (cont == -1)
            {
                m_vx += 15;
                cont = 1;
            }
            m_time = 0;
        }*/
        m_spin += 15.0f;
        //m_px += 1 * m_vx;
        m_vy += 0.01;
        m_py += 1 * m_vy;
    }

    
    //主人公の移動ベクトルの初期化
    m_vx = 0.0f;

    //key_flag_mirrorがtrueの時
    if (((UserData*)Save::GetData())->key_flag_mirror == true)
    {
        m_key_time++;

        if (m_key_time == 540)
        {
            ((UserData*)Save::GetData())->key_flag_mirror = false;
            m_key_time = 0;
        }
    }

    //回復アイテムと接触したら回復＆削除
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


    //障害物オブジェクトと接触したら削除
    if (hit->CheckElementHit(ELEMENT_ENEMY) == true && m_damage == false)
    {
        //Armorフラグがtrueの時
        if (((UserData*)Save::GetData())->Armor_flag == true)
        {
            //ダメージ判定はなし、フラグのみ変更
            ((UserData*)Save::GetData())->Armor_flag = false;
        }
        //Armorフラグがfalseの時
        else
        {
            ((UserData*)Save::GetData())->life_point--;
            ((UserData*)Save::GetData())->sp_lv = 0;
            m_damage = true;

            Audio::Start(4);
        }
    }

    //画面外に出たらHitBoxを削除
    if (m_py > 600.0f)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);

        //主人公消滅でシーンをゲームオーバーに移行する
        Scene::SetScene(new CSceneResult());
        m_spin++;
    }
}

//ドロー
void CObjFishPlayer::Draw()
{
    //描写カラー情報
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    int AniData[4]{ 1,2,3,4 };

    static float r = 0.0f;

    RECT_F src;//描写元の切り取り位置
    RECT_F dst;//描画先の表示位置

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
            Draw::Draw(2, &src, &dst, c, 0.0f);
        }
        else
        {
            m_inv_time++;

            if (m_inv_time % 5 == 0)
            {
                Draw::Draw(2, &src, &dst, c, 0.0f);
            }
            else
            {
                c[0] = 1.0f;
                c[1] = 0.5f;
                c[2] = 0.0f;
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
        Draw::Draw(2, &src, &dst, c, m_spin);
    }
}