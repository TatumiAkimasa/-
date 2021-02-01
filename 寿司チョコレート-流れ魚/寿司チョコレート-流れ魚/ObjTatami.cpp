//使用するヘッダーファイル
#include "ObjBackground_stats.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTatami::Init()
{

}

//アクション
void CObjTatami::Action()
{

}

//ドロー
void CObjTatami::Draw()
{
	//描写カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //描画元切り取り位置
	RECT_F dst;  //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 200.0f;
	src.m_bottom = 150.0f;

	//背景①の位置設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}