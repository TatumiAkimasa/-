//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMain::Init()
{
	f = 0;
	s_time = 0;
	m_time = 0;
}

//アクション
void CObjMain::Action()
{
	f++;
	//fが60回回ると1秒カウント
	if (f == 60)
	{
		f = 0;
		s_time++;
	}
	//s_timeが60で1分です
	if (s_time == 60)
	{
		s_time = 0;
		m_time++;
	}
}

//ドロー
void CObjMain::Draw()
{
	float c[4] = { 1,1,1,1 };

	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"タイム　%d:%d", m_time, s_time);
	Font::StrDraw(str, 20, 40, 40, c);

}