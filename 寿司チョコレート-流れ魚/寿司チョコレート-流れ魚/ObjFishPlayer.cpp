//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjFishPlayer.h"

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

    //当たり判定用HitBoxを作成
    Hits::SetHitBox(this, m_px, m_py, 64, 128, ELEMENT_PLAYER, OBJ_FISH_PLAYER, 1);

}

//アクション
void CObjFishPlayer::Action()
{
    //主人公機の移動ベクトルの初期化
    m_vx = 0.0f;
    

    //キーの入力方向にベクトルの速度を入れる
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

    //移動ベクトルを座標に加算する
    m_px += 1 * m_vx;
    m_py += 1 * m_vy;

    if (m_px> 640.0f)
    {
        m_px = 640.0f;//はみ出ない位置に移動させる
    }
    if (m_px < 400.0f)
    {
        m_px = 400.0f;
    }

    //HitBoxの内容を更新
    CHitBox* hit = Hits::GetHitBox(this);  //作成したHitBox更新用の入り口を取り出す
    hit->SetPos(m_px, m_py);                 //入口から新しい位置(主人公機の位置)情報に置き換える
    
    //障害物オブジェクトと接触したら削除
    if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
    {
        this->SetStatus(false);    //自身に削除命令を出す
        Hits::DeleteHitBox(this);  //主人公機が所有するHitBoxに削除する


        //主人公消滅でシーンをゲームオーバーに移行する
        Scene::SetScene(new CSceneResult());
    }
}

//ドロー
void CObjFishPlayer::Draw()
{
    //描写カラー情報
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//描写元の切り取り位置
    RECT_F dst;//描画先の表示位置


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