//使用するヘッダーファイル
#include "Objwater_flow.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include <stdlib.h>
#include <time.h>


//使用するネームスペース////////
using namespace GameL;

//イニシャライズ
void CObjwater_flow::Init()
{
	m_y1 = 0.0f;
	right = 0;
	right_d = 0;
	flow_flag = true;
}

//アクション
void CObjwater_flow::Action()
{
	srand(time(NULL)); // ランダム情報を初期化

	//乱数複雑化
	rand(); rand(); rand(); rand();

	right = rand() % 320;// このように記述するとnpc_handには0～2までの値が入ります

	if (m_y1 < 3.0f)
	{
		right_d = right;
		flow_flag = false;
	}

	//背景①の動作
	m_y1 += 10.0f;
	if (m_y1 > 650.0f)
	{
		this->SetStatus(false);//自身に削除命令
		flow_flag = true;
		return;
	}

}

//ドロー
void CObjwater_flow::Draw()
{
	//描写カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //描画元切り取り位置
	RECT_F dst;  //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 60.0f;
	src.m_right = 500.0f;
	src.m_bottom = 512.0f;

	//背景①の位置設定し描画
	if (flow_flag == true)
	{
		dst.m_top = -200.0f + m_y1;
		dst.m_left = 360.0f + right;
		dst.m_right = 380.0f + right;
		dst.m_bottom = -10.0f + m_y1;
	}
	else if (flow_flag == false)
	{
		dst.m_top = -200.0f + m_y1;
		dst.m_left = 360.0f + right_d;
		dst.m_right = 380.0f + right_d;
		dst.m_bottom = -10.0f + m_y1;
	}

	//1番目に登録したグラフィックをsrc・dst・cの情報をもとに描画
	Draw::Draw(1, &src, &dst, c, 0.0f);



}
