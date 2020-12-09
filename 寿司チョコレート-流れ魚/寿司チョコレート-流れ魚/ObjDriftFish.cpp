//使用するヘッダーファイル
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
//使用するネームスペース
using namespace GameL;

//イニシャライズ
void ObjDriftFish::Init()
{
    m_vx = 0.0f;     //移動ベクトル
    m_vy = 0.0f;

    //当たり判定用HitBoxを作成
    Hits::SetHitBox(this, m_px + 22, m_py + 16, 0,0, NULL, NULL, 1);
}

//コンストラクタ
ObjDriftFish::ObjDriftFish(float x, float y)
{
    m_px = x;
    m_py = y;
}

//アクション
void ObjDriftFish::Action()
{  
    m_vy += 0.1;
    m_spin += 30.0f;

    //移動ベクトルを座標に加算する
    m_px += 1 * m_vx;
    m_py += 1 * m_vy;

    //HitBoxの内容を更新
    CHitBox* hit = Hits::GetHitBox(this);  //作成したHitBox更新用の入り口を取り出す
    hit->SetPos(m_px + 22, m_py + 16);         //入口から新しい位置(主人公の位置)情報に置き換える

    //画面外に出たらHitBoxを削除
    if (m_py > 600.0f)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);
    }
}

//ドロー
void ObjDriftFish::Draw()
{
    //描写カラー情報
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//描写元の切り取り位置
    RECT_F dst;//描画先の表示位置

    dst.m_top = 80.0f + m_py;
    dst.m_left = -40.0f + m_px;
    dst.m_right = 16.0f + dst.m_left;
    dst.m_bottom = 16.0f + dst.m_top;

    src.m_top = 0.0f;
    src.m_left = 0.0f;
    src.m_right = 64.0f;
    src.m_bottom = 64.0f;

    Draw::Draw(19, &src, &dst, c, m_spin);
}