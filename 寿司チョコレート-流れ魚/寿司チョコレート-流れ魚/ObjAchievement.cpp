//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjAchievement.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjAchievement::Init()
{
	//実績解放用フラグの初期化
	for (int i = 0; i < 30; i++)
	{
		if (((UserData*)Save::GetData())->Achievement_flag[i] == true)
		{
			;
		}
		else
		{
			((UserData*)Save::GetData())->Achievement_flag[i] = false;
		}
	}
	/*for (int i = 0; i < 30; i++)
	{
		((UserData*)Save::GetData())->Achievement_flag[i] = true;
		
	}*/
	/*for (int i = 0; i < 30; i++)
	{
		((UserData*)Save::GetData())->Achievement_flag[i] = false;

	}*/
}
//アクション
void CObjAchievement::Action()
{
	//上下キーを押してシーン：タイトルに移行する。/
	if (Input::GetVKey(VK_UP) == true)
	{
		Scene::SetScene(new CSceneRanking());
	}
}
//ドロー
void CObjAchievement::Draw()
{
	wchar_t str[256];
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float b[4] = { 0.3f,0.3f,2.5f,1.0f };

	Font::StrDraw(L"実績", 340, 25, 50, r);
	Font::StrDraw(L"上ボタンでランキングに戻る", 25, 550, 17, r);

	swprintf_s(str, L" 1位  %4d魚力", ((UserData*)Save::GetData())->Ranking[0]);
	Font::StrDraw(str, 190, 95, 50, c);

	achi Achi[58] =
	{
		{"1.魚の風上にも置けない…",100},{"0魚力",100},
		{"2.稚魚",100},{"2.1～499魚力",100},
		{"3.もっとがんばろう！",100},{"3.500～999魚力",100},
		{"4.命とは儚いものだね",100},{"4.1000～2499魚力",100},
		{"5.成魚",100},{"5.2500～4999魚力",100},
		{"6.まるで魚",100},{"6.5000～7499魚力",100},
		{"7.ぎょぎょぎょ",100},{"7.7500～9999魚力",100},
		{"8.もはや魚",100},{"8.10000～19999魚力",100},
		{"9.魚魚魚～♪",100},{"9.20000～29999魚力",100},
		{"10.センスの塊",100},{"10.30000～39999魚力",100},

		{"11.狂気的にすごい！",100},{"11.40000～49999魚力",100},
		{"12.魚とは",100},{"12.50000～59999魚力",100},
		{"13.もはやサメ",100},{"13.60000～69999魚力",100},
		{"14.もはや戦艦",100},{"14.70000～79999魚力",100},
		{"15.魚の王",100},{"15.80000～89999魚力",100},
		{"16.制作者の人ですか？",100},{"16.90000～99999魚力",100},
		{"17.100000～109999魚力",100},{"17.100000～109999魚力",100},
		{"18.制作者でも厳しい…",100},{"18.110000～119999魚力",100},
		{"19.制作者より上手い！",100},{"19.120000～129999魚力",100},
		{"20.制作者でも無理……",100},{"20.130000～139999魚力",100},

		{"21.三倍役満",100},{"21.140000～149999魚力",100},
		{"22.しゃかにゃ",100},{"22.150000～159999魚力",100},
		{"23.初任給16万はちょっと…",100},{"23.160000～169999魚力",100},
		{"24.実は制作者全員彼女いません",100},{"24.170000～179999魚力",100},
		{"25.サケの切り身、実は生なんだ",100},{"25.180000～189999魚力",100},
		{"26.やりこんでくれてありがとう",100},{"26.190000～199999魚力",100},
		{"27.ギャラクティックフィッシュ",100},{"27.190000～529999魚力",100},
		{"28.魚力53万越えだと",100},{"28.530000～999999魚力",100},
		{"29.チートが検出されました",100},{"29.1000000魚力",100},

	};

	for (int i = 0; i < 58; i += 2)
	{
		if (((UserData*)Save::GetData())->Achievement_flag[0] == true)
		{
			swprintf_s(str, L"%s", Achi[i].coment);
			Font::StrDraw(str, ACHIEVEMENT_POS_L, Achi[0].hight + (30 * i), ACHIEVEMENT_SIZE, c);
		}
		else
		{
			swprintf_s(str, L"%s", Achi[i + 1].coment);
			Font::StrDraw(str, ACHIEVEMENT_POS_L, Achi[0].hight + (30 * (i - 1)), ACHIEVEMENT_SIZE, c);
		}
		
	}

	//0
	//if (((UserData*)Save::GetData())->Achievement_flag[0] == true)
	//{
	//	Font::StrDraw(L"1.魚の風上にも置けない…", ACHIEVEMENT_POS_L, 100, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"1.0魚力", ACHIEVEMENT_POS_L, 100, ACHIEVEMENT_SIZE, c);
	//}
	////0～500ドゥエース
	//if (((UserData*)Save::GetData())->Achievement_flag[1] == true)
	//{
	//	Font::StrDraw(L"2.稚魚", ACHIEVEMENT_POS_L, 130, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"2.1～499魚力", ACHIEVEMENT_POS_L, 130, ACHIEVEMENT_SIZE, c);
	//}
	////500～1000
	//if (((UserData*)Save::GetData())->Achievement_flag[2] == true)
	//{
	//	Font::StrDraw(L"3.もっとがんばろう！", ACHIEVEMENT_POS_L, 160, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"3.500～999魚力", ACHIEVEMENT_POS_L, 160, ACHIEVEMENT_SIZE, c);
	//}
	////1000～2500
	//if (((UserData*)Save::GetData())->Achievement_flag[3] == true)
	//{
	//	Font::StrDraw(L"4.命とは儚いものだね", ACHIEVEMENT_POS_L, 190, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"4.1000～2499魚力", ACHIEVEMENT_POS_L, 190, ACHIEVEMENT_SIZE, c);
	//}
	////2500～5000
	//if (((UserData*)Save::GetData())->Achievement_flag[4] == true)
	//{
	//	Font::StrDraw(L"5.成魚", ACHIEVEMENT_POS_L, 220, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"5.2500～4999魚力", ACHIEVEMENT_POS_L, 220, ACHIEVEMENT_SIZE, c);
	//}
	////5000～7500
	//if (((UserData*)Save::GetData())->Achievement_flag[5] == true)
	//{
	//	Font::StrDraw(L"6.まるで魚", ACHIEVEMENT_POS_L, 250, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"6.5000～7499魚力", ACHIEVEMENT_POS_L, 250, ACHIEVEMENT_SIZE, c);
	//}
	////7500～10000
	//if (((UserData*)Save::GetData())->Achievement_flag[6] == true)
	//{
	//	Font::StrDraw(L"7.ぎょぎょぎょ", ACHIEVEMENT_POS_L, 280, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"7.7500～9999魚力", ACHIEVEMENT_POS_L, 280, ACHIEVEMENT_SIZE, c);
	//}
	////10000～20000
	//if (((UserData*)Save::GetData())->Achievement_flag[7] == true)
	//{
	//	Font::StrDraw(L"8.もはや魚", ACHIEVEMENT_POS_L, 310, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"8.10000～19999魚力", ACHIEVEMENT_POS_L, 310, ACHIEVEMENT_SIZE, c);
	//}
	////20000～30000
	//if (((UserData*)Save::GetData())->Achievement_flag[8] == true)
	//{
	//	Font::StrDraw(L"9.魚魚魚～♪", ACHIEVEMENT_POS_L, 340, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"9.20000～29999魚力", ACHIEVEMENT_POS_L, 340, ACHIEVEMENT_SIZE, c);
	//}
	////30000～40000
	//if (((UserData*)Save::GetData())->Achievement_flag[9] == true)
	//{
	//	Font::StrDraw(L"10.センスの塊", ACHIEVEMENT_POS_L, 370, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"10.30000～39999魚力", ACHIEVEMENT_POS_L, 370, ACHIEVEMENT_SIZE, c);
	//}
	////40000～50000
	//if (((UserData*)Save::GetData())->Achievement_flag[10] == true)
	//{
	//	Font::StrDraw(L"11.狂気的にすごい！", ACHIEVEMENT_POS_L, 400, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"11.40000～49999魚力", ACHIEVEMENT_POS_L, 400, ACHIEVEMENT_SIZE, c);
	//}
	////50000～60000
	//if (((UserData*)Save::GetData())->Achievement_flag[11] == true)
	//{
	//	Font::StrDraw(L"12.魚とは", ACHIEVEMENT_POS_L, 430, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"12.50000～59999魚力", ACHIEVEMENT_POS_L, 430, ACHIEVEMENT_SIZE, c);
	//}
	////60000～70000
	//if (((UserData*)Save::GetData())->Achievement_flag[12] == true)
	//{
	//	Font::StrDraw(L"13.もはやサメ", ACHIEVEMENT_POS_L, 460, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"13.60000～69999魚力", ACHIEVEMENT_POS_L, 460, ACHIEVEMENT_SIZE, c);
	//}
	////70000～80000
	//if (((UserData*)Save::GetData())->Achievement_flag[13] == true)
	//{
	//	Font::StrDraw(L"14.もはや戦艦", ACHIEVEMENT_POS_L, 490, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"14.70000～79999魚力", ACHIEVEMENT_POS_L, 490, ACHIEVEMENT_SIZE, c);
	//}
	////80000～90000
	//if (((UserData*)Save::GetData())->Achievement_flag[14] == true)
	//{
	//	Font::StrDraw(L"15.魚の王", ACHIEVEMENT_POS_L, 520, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"15.80000～89999魚力", ACHIEVEMENT_POS_L, 520, ACHIEVEMENT_SIZE, c);
	//}
	////90000～100000
	//if (((UserData*)Save::GetData())->Achievement_flag[15] == true)
	//{
	//	Font::StrDraw(L"16.制作者の人ですか？", ACHIEVEMENT_POS_R, 100, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"16.90000～99999魚力", ACHIEVEMENT_POS_R, 100, ACHIEVEMENT_SIZE, c);
	//}
	////100000～110000
	//if (((UserData*)Save::GetData())->Achievement_flag[16] == true)
	//{
	//	Font::StrDraw(L"17.制作者の人ですね！", ACHIEVEMENT_POS_R, 130, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"17.100000～109999魚力", ACHIEVEMENT_POS_R, 130, ACHIEVEMENT_SIZE, c);
	//}
	////110000～120000
	//if (((UserData*)Save::GetData())->Achievement_flag[17] == true)
	//{
	//	Font::StrDraw(L"18.制作者でも厳しい…", ACHIEVEMENT_POS_R, 160, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"18.110000～119999魚力", ACHIEVEMENT_POS_R, 160, ACHIEVEMENT_SIZE, c);
	//}
	////120000～130000
	//if (((UserData*)Save::GetData())->Achievement_flag[18] == true)
	//{
	//	Font::StrDraw(L"19.制作者より上手い！", ACHIEVEMENT_POS_R, 190, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"19.120000～129999魚力", ACHIEVEMENT_POS_R, 190, ACHIEVEMENT_SIZE, c);
	//}
	////130000～140000
	//if (((UserData*)Save::GetData())->Achievement_flag[19] == true)
	//{
	//	Font::StrDraw(L"20.制作者でも無理……", ACHIEVEMENT_POS_R, 220, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"20.130000～139999魚力", ACHIEVEMENT_POS_R, 220, ACHIEVEMENT_SIZE, c);
	//}
	////140000～150000
	//if (((UserData*)Save::GetData())->Achievement_flag[20] == true)
	//{
	//	Font::StrDraw(L"21.三倍役満", ACHIEVEMENT_POS_R, 250, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"21.140000～149999魚力", ACHIEVEMENT_POS_R, 250, ACHIEVEMENT_SIZE, c);
	//}
	////150000～160000
	//if (((UserData*)Save::GetData())->Achievement_flag[21] == true)
	//{
	//	Font::StrDraw(L"22.しゃかにゃ", ACHIEVEMENT_POS_R, 280, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"22.150000～159999魚力", ACHIEVEMENT_POS_R, 280, ACHIEVEMENT_SIZE, c);
	//}
	////160000～170000
	//if (((UserData*)Save::GetData())->Achievement_flag[22] == true)
	//{
	//	Font::StrDraw(L"23.初任給16万はちょっと…", ACHIEVEMENT_POS_R, 310, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"23.160000～169999魚力", ACHIEVEMENT_POS_R, 310, ACHIEVEMENT_SIZE, c);
	//}
	////170000～180000
	//if (((UserData*)Save::GetData())->Achievement_flag[23] == true)
	//{
	//	Font::StrDraw(L"24.実は制作者全員彼女いません", ACHIEVEMENT_POS_R, 340, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"24.170000～179999魚力", ACHIEVEMENT_POS_R, 340, ACHIEVEMENT_SIZE, c);
	//}
	////180000～190000
	//if (((UserData*)Save::GetData())->Achievement_flag[24] == true)
	//{
	//	Font::StrDraw(L"25.サケの切り身、実は生なんだ", ACHIEVEMENT_POS_R, 370, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"25.180000～189999魚力", ACHIEVEMENT_POS_R, 370, ACHIEVEMENT_SIZE, c);
	//}
	////190000～200000
	//if (((UserData*)Save::GetData())->Achievement_flag[25] == true)
	//{
	//	Font::StrDraw(L"26.やりこんでくれてありがとう", ACHIEVEMENT_POS_R, 400, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"26.190000～199999魚力", ACHIEVEMENT_POS_R, 400, ACHIEVEMENT_SIZE, c);
	//}
	////200000～530000
	//if (((UserData*)Save::GetData())->Achievement_flag[26] == true)
	//{
	//	Font::StrDraw(L"27.ギャラクティックフィッシュ", ACHIEVEMENT_POS_R, 430, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"27.190000～529999魚力", ACHIEVEMENT_POS_R, 430, ACHIEVEMENT_SIZE, c);
	//}
	////530000～1000000
	//if (((UserData*)Save::GetData())->Achievement_flag[27] == true)
	//{
	//	Font::StrDraw(L"28.魚力53万越えだと", ACHIEVEMENT_POS_R, 460, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"28.530000～999999魚力", ACHIEVEMENT_POS_R, 460, ACHIEVEMENT_SIZE, c);
	//}
	////1000000～
	//if (((UserData*)Save::GetData())->Achievement_flag[28] == true)
	//{
	//	Font::StrDraw(L"29.チートが検出されました", ACHIEVEMENT_POS_R, 490, ACHIEVEMENT_SIZE, b);
	//}
	//else
	//{
	//	Font::StrDraw(L"29.1000000魚力", ACHIEVEMENT_POS_R, 490, ACHIEVEMENT_SIZE, c);
	//}
	//速度20かつ10秒以上耐久
	if (((UserData*)Save::GetData())->Achievement_flag[29] == true)
	{
		if (((UserData*)Save::GetData())->m_max_time < ((UserData*)Save::GetData())->max_time)
			((UserData*)Save::GetData())->m_max_time = ((UserData*)Save::GetData())->max_time;
		//なぜか数字か増えるバグ修正
		if (((UserData*)Save::GetData())->m_max_time / 60 < 29)
		{
			swprintf_s(str, L"30.逆ら魚 : %0.1f秒", (((UserData*)Save::GetData())->m_max_time / 60) );
			Font::StrDraw(str, ACHIEVEMENT_POS_R, 520, ACHIEVEMENT_SIZE, b);
		}
		else
		{
			swprintf_s(str, L"30.逆ら魚 : %0.1f秒", ((UserData*)Save::GetData())->m_max_time / 60);
			Font::StrDraw(str, ACHIEVEMENT_POS_R, 520, ACHIEVEMENT_SIZE, b);
		}
		
	}
	else
	{
		Font::StrDraw(L"30.???????????", ACHIEVEMENT_POS_R, 520, ACHIEVEMENT_SIZE, c);
	}

}