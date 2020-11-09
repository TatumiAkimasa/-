//使用するヘッダーファイル
#include "ObjBackground_stats.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBackground_stats::Init()
{
	
}

//アクション
void CObjBackground_stats::Action()
{
	
}

//ドロー
void CObjBackground_stats::Draw()
{
	//描写カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //描画元切り取り位置
	RECT_F dst;  //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//1番目に登録したグラフィックをsrc・dst・cの情報をもとに描画
	//背景①の位置設定し描画
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f;
	dst.m_right = 490.0f;
	dst.m_bottom = 600.0f ;

	Draw::Draw(6, &src, &dst, c, 0.0f);
	

}
