//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"
#include <stdlib.h>//ランダム用
#include <time.h>//ランダム用

#include "GameHead.h"
#include "ObjMain.h"

using namespace GameL;

//イニシャライズ
void CObjMain::Init()
{
	f = 0;//フレーム計算!
	s_time = 0;
	m_time = 0;

	fps = 0;//操作反転時間の表示
	i = 1;//操作反転時間の表示
	second = 10;//操作反転時間の表示
	((UserData*)Save::GetData())->save_s_time = 0;//セーブ用m_time初期化
	((UserData*)Save::GetData())->save_m_time = 0;//セーブ用s_time初期化
	((UserData*)Save::GetData())->life_point = 3;//セーブ用life_point初期化
	random = 0;
	life = 3;
	come_flag = false;
	life_flag = false;
	heel_flag = false;
	mirrior_flag = false;
	ren_flag=false;
	((UserData*)Save::GetData())->save_s_time = 0;//セーブ用m_time初期化
	((UserData*)Save::GetData())->save_m_time = 0;//セーブ用s_time初期化
	((UserData*)Save::GetData())->life_point = 3;//セーブ用life_point初期化
	((UserData*)Save::GetData())->key_flag_mirror = false;//
	((UserData*)Save::GetData())->max_time = 0;//実績用のタイムの初期化
}

//アクション
void CObjMain::Action()
{
	//主人公から、回復したかどうかの受け取り
	CObjFishPlayer* obj = (CObjFishPlayer*)Objs::GetObj(OBJ_FISH_PLAYER);

	//フラグ受け渡し
	if (obj != nullptr)
		heel_flag = obj->heel_flag();

	//乱数複雑化
	rand(); rand(); rand(); rand(); rand();

	//ライフ増減チェック
	if (((UserData*)Save::GetData())->life_point != life)
		life_flag = true;
	else
		life_flag = false;

	//コメントを瞬時に一度だけ切り替え
	if (((UserData*)Save::GetData())->Ren_flag == true)
	{
		//連打（最優先）
		random = 13;
		come_flag = false;
		ren_flag = true;
	}
	else if (((UserData*)Save::GetData())->key_flag_mirror == true)
	{
		//反転（2番目）
		random = 10;
		come_flag = false;
		mirrior_flag = true;
	}
	else if (((UserData*)Save::GetData())->Tree_flag == true)
	{
		//目隠し（3番目）
		random = 11;
		come_flag = false;
	}
	else if (((UserData*)Save::GetData())->life_point == life - 1 && life_flag == true)
	{
		//全て4番目優先
		//ライフが1なら
		if (((UserData*)Save::GetData())->life_point == 1)
			//死にかけ
			random = 8;
		//2なら
		else
			//まだまだ
			random = 7;
		//if(((UserData*)Save::GetData())->save_s_time % 5 == 0)
		//ライフ更新
		life = ((UserData*)Save::GetData())->life_point;

		come_flag = false;
	}
	//回復フラグで判断
	else if (heel_flag == true)
	{
		//回復コメント（優先5番目）
		random = 6;
		life = ((UserData*)Save::GetData())->life_point;
		come_flag = false;
	}
	else if (((UserData*)Save::GetData())->key_flag_slow==true)
	{
		//鈍足（優先6番目）
		random = 15;
		come_flag = false;
	}
	//2000点を通過したら
	else if (((UserData*)Save::GetData())->save_score == 2000)
	{
		//なんかほざく（優先7番目）
		random = 5;
		come_flag = false;
	}
	//spが10～11の時
	else if (((UserData*)Save::GetData())->sp > 10 && ((UserData*)Save::GetData())->sp < 10.5)
	{
		//なんか言う（優先8番目）
		random = 4;
		come_flag = false;
	}
	//spが20の時
	else if (((UserData*)Save::GetData())->sp >= 20)
	{
		//限界みたいです（優先9番目）
		random = 3;
		come_flag = false;
	}
	//連打し終えたとき
	else if (ren_flag == true && come_flag == false&&((UserData*)Save::GetData())->ren == 0)
	{
		random = 14;
		ren_flag = false;
	}
	//反転終了宣言
	else if (mirrior_flag == true && come_flag == false)
	{
		random = 12;
		mirrior_flag = false;
	}
	//ヒント
	else if (((UserData*)Save::GetData())->save_s_time % 60 == 0)
	{
		//基本、すべて上が反映もし、何もなければ20秒ごとにセリフが変わる。
		if (come_flag == true)
		{
			//３パターン
			random = (rand() % 4) - 9;
			//random = -6~-8;
			come_flag = false;
		}
	}
	//日常会話
	else if (((UserData*)Save::GetData())->save_s_time % 20 == 0)
	{
		//基本、すべて上が反映もし、何もなければ20秒ごとにセリフが変わる。
		if (come_flag == true)
		{
			//３パターン
			random = (rand() % 8)-5;
			//random = -5;
			come_flag = false;
		}
	}
	//消さないでね💛
	else
	{
		come_flag = true;
	}

	if (((UserData*)Save::GetData())->life_point > 0)
	{
		f++;
		//fが60回回ると1秒カウント
		if (f == 60)
		{
			f = 0;
			s_time++;
			//s_time++の時点でセーブ用s_timeもインクリメント
			((UserData*)Save::GetData())->save_s_time++;
		}
		//s_timeが60で1分です
		if (s_time == 60)
		{
			s_time = 0;
			m_time++;
			//m_time++の時点でセーブ用m_timeもインクリメント
			((UserData*)Save::GetData())->save_m_time++;
			((UserData*)Save::GetData())->save_s_time = 0;
		}
	}

	if (((UserData*)Save::GetData())->sp >= 19.0)
	{
		//int i = 0;
		((UserData*)Save::GetData())->max_time++;
		if (((UserData*)Save::GetData())->max_time >= 600)
		{
			((UserData*)Save::GetData())->Achievement_flag[29] = true;
		}
	}

	if (((UserData*)Save::GetData())->life_point == 0)
	{
		//死亡（最優先）
		random = 99;
	}
}

//ドロー
void CObjMain::Draw()
{
	float c[4] = { 1,1,1,1 };

	//タイムの表示
	wchar_t str[256];
	swprintf_s(str, L"タイム　%02d:%02d", m_time, s_time);
	Font::StrDraw(str, 20, 40, 40, c);

	//スコアの表示
	swprintf_s(str, L"魚力　　%05d", ((UserData*)Save::GetData())->save_score);
	Font::StrDraw(str, 20, 100, 40, c);

	//速度の表示
	swprintf_s(str, L"速度  　%3.1f", ((UserData*)Save::GetData())->sp);
	Font::StrDraw(str, 20, 160, 40, c);

	//反転時間の表示
	if (((UserData*)Save::GetData())->key_flag_mirror == true)
	{
		fps++;
		if (fps % 6 == 0)
		{
			i--;
			if (i == 0)
			{
				second--;
				i = 9;
			}
		}
		swprintf_s(str, L"反転時間　%d.%d",second,i);
		Font::StrDraw(str, 20, 220, 40, c);
	}
	else
	{
		fps = 0;
		i = 1;
		second = 10;
	}

	//スピードの表示
	swprintf_s(str, L"速度　　%3.1f", ((UserData*)Save::GetData())->sp);
	Font::StrDraw(str, 20, 160, 40, c);

	//コメントの表示
	float k[4] = { 0.1f,0.1f,0.1f,1.0f };
	if (random == -9)
	{
		swprintf_s(str, L"僕の速度が20の時");
		Font::StrDraw(str, 50, 430, 30, k);
		swprintf_s(str, L"10秒耐えると30が");
		Font::StrDraw(str, 50, 470, 30, k);
		swprintf_s(str, L"開くんだって！");
		Font::StrDraw(str, 50, 510, 30, k);
	}
	else if (random == -8)
	{
		swprintf_s(str, L"そうめんにわざと");
		Font::StrDraw(str, 50, 430, 30, k);
		swprintf_s(str, L"当たって速度を");
		Font::StrDraw(str, 50, 470, 30, k);
		swprintf_s(str, L"調節してみよう!");
		Font::StrDraw(str, 30, 510, 30, k);
	}
	else if (random == -7)
	{
		swprintf_s(str, L"操作反転中は点数");
		Font::StrDraw(str, 45, 430, 30, k);
		swprintf_s(str, L"が二倍増えるピンチ");
		Font::StrDraw(str, 25, 470, 30, k);
		swprintf_s(str, L"がチャンスへ！");
		Font::StrDraw(str, 40, 510, 30, k);
	}
	else if (random == -6)
	{
		swprintf_s(str, L"長く生き残れば");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"獲得魚力がより");
		Font::StrDraw(str, 60, 470, 30, k);
		swprintf_s(str, L"多くもらえるよ！");
		Font::StrDraw(str, 25, 510, 30, k);
	}
	else if (random == -5)
	{
	swprintf_s(str, L"世界最小の魚は");
	Font::StrDraw(str, 60, 430, 30, k);
	swprintf_s(str, L"ドワーフフェアリー");
	Font::StrDraw(str, 15, 470, 30, k);
	swprintf_s(str, L"ミノーだよ");
	Font::StrDraw(str, 70, 510, 30, k);
	}
	else if (random == -4)
	{
	swprintf_s(str, L"ハリセンボン");
	Font::StrDraw(str, 60, 430, 30, k);
	swprintf_s(str, L"実は、針は");
	Font::StrDraw(str, 50, 470, 30, k);
	swprintf_s(str, L"400本くらい");
	Font::StrDraw(str, 50, 510, 30, k);
	}
	else if (random == -3)
	{
	    swprintf_s(str, L"ドイツでは");
	    Font::StrDraw(str, 60, 430, 30, k);
	    swprintf_s(str, L"釣りに免許が");
	    Font::StrDraw(str, 60, 470, 30, k);
		swprintf_s(str, L"いるらしいよ");
		Font::StrDraw(str, 60, 510, 30, k);
	}
	else if (random == -2)
	{
		swprintf_s(str, L"サーモンは");
		Font::StrDraw(str, 80, 430, 30, k);
		swprintf_s(str, L"白身魚だよ");
		Font::StrDraw(str, 80, 470, 30, k);
	}
	else if (random == -1)
	{
		swprintf_s(str, L"トビウオって最大");
		Font::StrDraw(str, 33, 430, 30, k);
		swprintf_s(str, L"400m飛ぶらしいよ！");
		Font::StrDraw(str, 25, 470, 30, k);
	}
	else if (random == 0)
	{
		swprintf_s(str, L"さぁ、魚力を");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"上げよう！");
		Font::StrDraw(str, 60, 470, 30, k);
	}
	else if (random == 1)
	{
		swprintf_s(str, L"知ってる？");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"僕って金魚なんだ！");
		Font::StrDraw(str, 25, 470, 30, k);
	}
	else if (random == 2)
	{
		swprintf_s(str, L"因みに今泳いで");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"いるところは流し");
		Font::StrDraw(str, 30, 470, 30, k);
		swprintf_s(str, L"そうめん台だよ");
		Font::StrDraw(str, 30, 510, 30, k);
	}
	else if (random == 3)
	{
		swprintf_s(str, L"これが僕の");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"全力のスピードだ!");
		Font::StrDraw(str, 25, 470, 30, k);
	}
	else if (random == 4)
	{
		swprintf_s(str, L"肩慣らしは完了!");
		Font::StrDraw(str, 55, 430, 30, k);
		swprintf_s(str, L"どんどん行こう!");
		Font::StrDraw(str, 55, 470, 30, k);
	}
	else if (random == 5)
	{
		swprintf_s(str, L"僕の魚力が");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"みなぎってる！");
		Font::StrDraw(str, 60, 470, 30, k);
		swprintf_s(str, L"どんどん行こう！");
		Font::StrDraw(str, 25, 510, 30, k);
	}
	else if (random == 6)
	{
		swprintf_s(str, L"あぁ、癒される");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"ありがとう！");
		Font::StrDraw(str, 60, 470, 30, k);
		swprintf_s(str, L"この調子！");
		Font::StrDraw(str, 60, 510, 30, k);
	}
	else if (random == 7)
	{
		swprintf_s(str, L"");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"まだまだ！");
		Font::StrDraw(str, 85, 470, 30, k);
		swprintf_s(str, L"");
		Font::StrDraw(str, 25, 510, 30, k);
	}
	else if (random == 8)
	{
		swprintf_s(str, L"");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"死にそう...！");
		Font::StrDraw(str, 65, 470, 30, k);
		swprintf_s(str, L"");
		Font::StrDraw(str, 25, 510, 30, k);
	}
	else if (random == 10)
	{
		float k[4] = { 0.9f,0.1f,0.1f,1.0f };
		swprintf_s(str, L"");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"操作反転中！");
		Font::StrDraw(str, 70, 470, 30, k);
		swprintf_s(str, L"");
		Font::StrDraw(str, 25, 510, 30, k);
	}
	else if (random == 11)
	{
		swprintf_s(str, L"");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"前が見えない！？");
		Font::StrDraw(str, 40, 470, 30, k);
		swprintf_s(str, L"");
		Font::StrDraw(str, 25, 510, 30, k);
	}
	else if (random == 12)
	{
		float k[4] = { 0.1f,0.9f,0.1f,1.0f };
		swprintf_s(str, L"");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"操作反転終了！");
		Font::StrDraw(str, 55, 470, 30, k);
		swprintf_s(str, L"");
		Font::StrDraw(str, 25, 510, 30, k);
	}
	else if (random == 13)
	{
	float k[4] = { 0.1f,0.1f,0.9f,1.0f };
	swprintf_s(str, L"体が動かない!?");
	Font::StrDraw(str, 55, 450, 30, k);
	swprintf_s(str, L"あと%d回連打だ!", ((UserData*)Save::GetData())->ren);
	Font::StrDraw(str, 55, 490, 30, k);
	swprintf_s(str, L"");
	Font::StrDraw(str, 25, 510, 30, k);
    }
	else if (random == 14)
	{
	float k[4] = { 0.1f,0.9f,0.1f,1.0f };
	swprintf_s(str, L"");
	Font::StrDraw(str, 60, 430, 30, k);
	swprintf_s(str, L"脱出だ！");
	Font::StrDraw(str, 65, 460, 50, k);
	swprintf_s(str, L"");
	Font::StrDraw(str, 25, 510, 30, k);
    }
	else if (random == 15)
	{
		swprintf_s(str, L"");
		Font::StrDraw(str, 50, 430, 30, k);
		swprintf_s(str, L" 体が...重い!?");
		Font::StrDraw(str, 50, 470, 30, k);
		swprintf_s(str, L"");
		Font::StrDraw(str, 30, 510, 30, k);
	}
	else if (random == 99)
	{
		float k[4] = { 0.9f,0.1f,0.1f,1.0f };
		swprintf_s(str, L"");
		Font::StrDraw(str, 60, 430, 30, k);
		swprintf_s(str, L"次こそは！");
		Font::StrDraw(str, 85, 460, 30, k);
		swprintf_s(str, L"必ず強くなる！");
		Font::StrDraw(str, 50, 490, 30, k);
	}
	

	//ライフの表示
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	swprintf_s(str, L"ライフ");
	Font::StrDraw(str, 20, 280, 40, c);

	RECT_F src;
	RECT_F dst;

	//ライフ1
	if (((UserData*)Save::GetData())->life_point >= 1)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		dst.m_top = 320.0f;
		dst.m_left = 20.0f;
		dst.m_right = 64.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		Draw::Draw(10, &src, &dst, d, 0.0f);
	}

	//ライフ2
	if (((UserData*)Save::GetData())->life_point >= 2)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		dst.m_top = 320.0f;
		dst.m_left = 100.0f;
		dst.m_right = 64.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		Draw::Draw(10, &src, &dst, d, 0.0f);
	}

	//ライフ3
	if (((UserData*)Save::GetData())->life_point >= 3)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		dst.m_top = 320.0f;
		dst.m_left = 180.0f;
		dst.m_right = 64.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		Draw::Draw(10, &src, &dst, d, 0.0f);
	}
}