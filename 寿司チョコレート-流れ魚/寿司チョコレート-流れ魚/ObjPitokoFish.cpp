//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitboxManager.h"
#include "GameHead.h"
#include "ObjPiyokoFish.h"
#include "GameL/WinInputs.h"
#include "GameL/UserData.h"


//使用するゲームスペース
using namespace GameL;

//コンストラクタ
CObjPiyokoFish::CObjPiyokoFish(float x, float y, float r)
{
	m_px = x;
	m_py = y;
	m_r = r;
}

//イニシャライズ
void CObjPiyokoFish::Init()
{
	m_vx = cos(3.14 / 180 * m_r);
	m_vy = sin(3.14 / 180 * m_r);
	//当たり判定用ヒットボックスを作成
	Hits::SetHitBox(this, m_px, m_py, 0, 0, NULL, NULL, 1);

}

//アクション
void CObjPiyokoFish::Action()
{


	//敵機拡散弾のHitBox用ポインターを取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);
}

//ドロー
void CObjPiyokoFish::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画切り取り位置
	RECT_F dst;//描画表示位置


	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 32.0f + m_px;
	dst.m_bottom = 32.0f + m_py;

	
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 96.0f;
	src.m_right = 126.0f;
	src.m_bottom = 32.0f;
	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(20, &src, &dst, c, m_r);
}
