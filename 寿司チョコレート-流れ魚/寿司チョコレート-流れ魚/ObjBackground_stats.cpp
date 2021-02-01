//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "ObjBackground_stats.h"
#include "GameHead.h"



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
	src.m_bottom = 560.0f;

	//6番目に登録したグラフィックをsrc・dst・cの情報をもとに描画
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f;
	dst.m_right = 490.0f;
	dst.m_bottom = 600.0f ;

	if (((UserData*)Save::GetData())->space_flag == true)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 300.0f;
		src.m_bottom = 500.0f;

		//6番目に登録したグラフィックをsrc・dst・cの情報をもとに描画
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 300.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(26, &src, &dst, c, 0.0f);
	}
	else
	    Draw::Draw(6, &src, &dst, c, 0.0f);
	

}
